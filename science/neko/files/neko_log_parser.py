import re
import argparse
from pprint import pprint
import json
import os


def parse_neko_log(log_lines):
    data = {}
    step_data = {}
    current_step = None

    for line in log_lines:
        # Step and time value
        step_match = re.match(r"\s*Step\s*=\s*(\d+)\s*t\s*=\s*([\d.Ee+-]+)", line)

        # CFL and dt
        cfl_match = re.match(r"\s*CFL:\s*([\d.Ee+-]+)\s+dt:\s*([\d.Ee+-]+)", line)

        # Field residuals
        field_match = re.match(
            r"\s*(\d+)\s+\|\s+(\S+)\s+(\d+)\s+([\d.Ee+-]+)\s+([\d.Ee+-]+)", line
        )

        # Total time for step
        total_step_time_match = re.match(
            r"\s*Total time for step\s+\d+\s+\(s\):\s+([\d.Ee+-]+)", line
        )

        if step_match:
            if current_step is not None:
                data[current_step] = step_data
            current_step = int(step_match.group(1))
            time_value = float(step_match.group(2))
            step_data = {
                "time": time_value,
                "CFL": None,
                "dt": None,
                "total_step_time": None,
                "fields": {},
            }

        elif cfl_match and current_step is not None:
            step_data["CFL"] = float(cfl_match.group(1))
            step_data["dt"] = float(cfl_match.group(2))

        elif total_step_time_match and current_step is not None:
            step_data["total_step_time"] = float(total_step_time_match.group(1))

        elif field_match:
            _, field_name, iters, start_res, final_res = field_match.groups()
            field_info = {
                "iters": int(iters),
                "start_residual": float(start_res),
                "final_residual": float(final_res),
            }
            step_data["fields"][field_name.lower()] = field_info

    if current_step is not None:
        data[current_step] = step_data

    return data


def flatten_parsed_data(parsed_data):
    import numpy as np

    first_step = next(iter(parsed_data.values()))
    all_fields = sorted(first_step["fields"].keys())

    # Define the full list of column names
    columns = ["step", "time", "CFL", "dt", "total_step_time"]
    for field in all_fields:
        columns += [
            f"{field}_iters",
            f"{field}_start_residual",
            f"{field}_final_residual",
        ]

    # Create rows
    rows = []
    for step_num, step in sorted(parsed_data.items()):
        row = [
            step_num,
            step.get("time"),
            step.get("CFL"),
            step.get("dt"),
            step.get("total_step_time"),
        ]
        for field in all_fields:
            field_data = step["fields"].get(field)
            if field_data:
                row.extend(
                    [
                        field_data["iters"],
                        field_data["start_residual"],
                        field_data["final_residual"],
                    ]
                )
            else:
                row.extend([np.nan, np.nan, np.nan])
        rows.append(row)

    # Create and return the structured array
    return np.array(rows), columns


def save_as_csv(array, columns, output_file):
    import numpy as np

    header = ",".join(columns)
    np.savetxt(
        output_file, array, delimiter=",", header=header, comments="", fmt="%.17e"
    )
    print(f"Saved CSV to {output_file}")


def save_as_hdf5(parsed_data, output_file):
    import h5py

    array, columns = flatten_parsed_data(parsed_data)
    num_rows = array.shape[0]

    # Separate root-level and field-level columns
    root_keys = {"step", "time", "CFL", "dt", "total_step_time"}
    field_data = {}  # {field: {subkey: col_index}}

    for i, col in enumerate(columns):
        if col in root_keys:
            continue
        parts = col.split("_")
        if len(parts) == 2:
            field, dataset = parts
        elif (
            len(parts) == 3
            and parts[1] in {"start", "final"}
            and parts[2] == "residual"
        ):
            field = parts[0]
            dataset = f"{parts[1]}_residual"
        else:
            raise ValueError(f"Unrecognized column format: {col}")
        field_data.setdefault(field, {})[dataset] = i

    with h5py.File(output_file, "w") as f:
        # Write root-level datasets
        for i, col in enumerate(columns):
            if col in root_keys and col != "step":
                f.create_dataset(col, data=array[:, i])

        # Write field-specific groups and datasets
        for field, subfields in field_data.items():
            grp = f.create_group(field)
            for subkey, col_index in subfields.items():
                # Dataset names: iters, start_residual, final_residual
                dataset_name = subkey
                grp.create_dataset(dataset_name, data=array[:, col_index])

    print(f"Saved HDF5 to {output_file}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Parse a Neko log file.")
    parser.add_argument("logfile", help="Path to the Neko log file")
    parser.add_argument(
        "-o",
        "--output",
        help="Output filename (supports .json, .csv, or .hdf5)",
        required=True,
    )

    args = parser.parse_args()
    output_ext = os.path.splitext(args.output)[1].lower()

    with open(args.logfile, "r") as f:
        log_lines = f.readlines()

    parsed_data = parse_neko_log(log_lines)

    if output_ext == ".json":
        with open(args.output, "w") as f:
            json.dump(parsed_data, f, indent=2)
        print(f"Saved JSON to {args.output}")

    elif output_ext == ".csv":
        array, columns = flatten_parsed_data(parsed_data)
        save_as_csv(array, columns, args.output)
    elif output_ext == ".hdf5" or output_ext == ".h5":
        save_as_hdf5(parsed_data, args.output)

    else:
        print(f"Unsupported output format: {args.output} (use .json or .csv)")
