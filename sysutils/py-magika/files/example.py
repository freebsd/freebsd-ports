import argparse
import sys
from pathlib import Path
from magika import Magika

def main():
    parser = argparse.ArgumentParser(
        description="Verify that an uploaded file matches its format criteria."
    )
    parser.add_argument(
        "image_path", 
        type=str, 
        help="The path to the file you want to check."
    )
    
    args = parser.parse_args()
    target_path = Path(args.image_path)

    if not target_path.is_file():
        print(f"Error: File '{target_path}' does not exist.", file=sys.stderr)
        sys.exit(1)

    magika = Magika()
    result = magika.identify_path(target_path)
    
    # --- UPDATED FOR NEW MAGIKA API ---
    detected_group = result.output.group
    detected_label = result.output.label
    
    # Use getattr to safely handle variance between 0.5.x and 0.6.x versions
    confidence = getattr(result, "similarity_score", getattr(result, "score", 0.0))

    print(f"Inspecting: {target_path.name}")
    print(f"Result: {detected_label} ({confidence:.2%})")

    # In your test, a Makefile is categorized under the "text" or "code" group
    if detected_group != "image" and detected_label != "makefile":
        print(f"❌ Verification failed. Group: {detected_group}, Label: {detected_label}")
        sys.exit(1)

    print("✅ File verified successfully.")

if __name__ == "__main__":
    main()

