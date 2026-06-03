"""Stub py_grpc_library for system gRPC."""

def py_grpc_library(name, srcs = [], deps = [], **kwargs):
    # Generate a minimal stub .py file so this target can appear in both
    # srcs and deps of the wrapper py_library created by tf_proto_library.
    # Actual gRPC Python stubs are not needed for the wheel build.
    gen_name = name + "_stub_gen"
    native.genrule(
        name = gen_name,
        outs = [name + "_grpc_pb2.py"],
        cmd = "echo '# gRPC stub placeholder' > $@",
        testonly = kwargs.get("testonly", False),
        compatible_with = kwargs.get("compatible_with"),
    )
    native.py_library(
        name = name,
        srcs = [":" + gen_name],
        testonly = kwargs.get("testonly", False),
        visibility = kwargs.get("visibility"),
        compatible_with = kwargs.get("compatible_with"),
    )
