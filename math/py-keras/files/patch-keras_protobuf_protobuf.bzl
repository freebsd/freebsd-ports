--- /dev/null	2022-09-08 10:18:38.049755000 +0100
+++ third_party/protobuf.bzl	2022-09-08 10:17:38.840977000 +0100
@@ -0,0 +1,217 @@
+def _GetPath(ctx, path):
+    if ctx.label.workspace_root:
+        return ctx.label.workspace_root + "/" + path
+    else:
+        return path
+
+def _IsNewExternal(ctx):
+    # Bazel 0.4.4 and older have genfiles paths that look like:
+    #   bazel-out/local-fastbuild/genfiles/external/repo/foo
+    # After the exec root rearrangement, they look like:
+    #   ../repo/bazel-out/local-fastbuild/genfiles/foo
+    return ctx.label.workspace_root.startswith("../")
+
+def _GenDir(ctx):
+    if _IsNewExternal(ctx):
+        # We are using the fact that Bazel 0.4.4+ provides repository-relative paths
+        # for ctx.genfiles_dir.
+        return ctx.genfiles_dir.path + (
+            "/" + ctx.attr.includes[0] if ctx.attr.includes and ctx.attr.includes[0] else ""
+        )
+
+    # This means that we're either in the old version OR the new version in the local repo.
+    # Either way, appending the source path to the genfiles dir works.
+    return ctx.var["GENDIR"] + "/" + _SourceDir(ctx)
+
+def _SourceDir(ctx):
+    if not ctx.attr.includes:
+        return ctx.label.workspace_root
+    if not ctx.attr.includes[0]:
+        return _GetPath(ctx, ctx.label.package)
+    if not ctx.label.package:
+        return _GetPath(ctx, ctx.attr.includes[0])
+    return _GetPath(ctx, ctx.label.package + "/" + ctx.attr.includes[0])
+
+def _PyOuts(srcs, use_grpc_plugin = False):
+    ret = [s[:-len(".proto")] + "_pb2.py" for s in srcs]
+    if use_grpc_plugin:
+        ret += [s[:-len(".proto")] + "_pb2_grpc.py" for s in srcs]
+    return ret
+
+def _proto_gen_impl(ctx):
+    """General implementation for generating protos"""
+    srcs = ctx.files.srcs
+    deps = []
+    deps += ctx.files.srcs
+    source_dir = _SourceDir(ctx)
+    gen_dir = _GenDir(ctx)
+    if source_dir:
+        import_flags = ["-I" + source_dir, "-I" + gen_dir]
+    else:
+        import_flags = ["-I."]
+
+    for dep in ctx.attr.deps:
+        import_flags += dep.proto.import_flags
+        deps += dep.proto.deps
+    import_flags = depset(import_flags).to_list()
+    deps = depset(deps).to_list()
+
+    args = []
+    if ctx.attr.gen_cc:
+        args += ["--cpp_out=" + gen_dir]
+    if ctx.attr.gen_py:
+        args += ["--python_out=" + gen_dir]
+
+    inputs = srcs + deps
+    tools = [ctx.executable.protoc]
+    if ctx.executable.plugin:
+        plugin = ctx.executable.plugin
+        lang = ctx.attr.plugin_language
+        if not lang and plugin.basename.startswith("protoc-gen-"):
+            lang = plugin.basename[len("protoc-gen-"):]
+        if not lang:
+            fail("cannot infer the target language of plugin", "plugin_language")
+
+        outdir = gen_dir
+        if ctx.attr.plugin_options:
+            outdir = ",".join(ctx.attr.plugin_options) + ":" + outdir
+        args += ["--plugin=protoc-gen-%s=%s" % (lang, plugin.path)]
+        args += ["--%s_out=%s" % (lang, outdir)]
+        tools.append(plugin)
+
+    if args:
+        ctx.actions.run(
+            inputs = inputs,
+            outputs = ctx.outputs.outs,
+            arguments = args + import_flags + [s.path for s in srcs],
+            executable = ctx.executable.protoc,
+            mnemonic = "ProtoCompile",
+            tools = tools,
+            use_default_shell_env = True,
+        )
+
+    return struct(
+        proto = struct(
+            srcs = srcs,
+            import_flags = import_flags,
+            deps = deps,
+        ),
+    )
+
+proto_gen = rule(
+    attrs = {
+        "srcs": attr.label_list(allow_files = True),
+        "deps": attr.label_list(providers = ["proto"]),
+        "includes": attr.string_list(),
+        "protoc": attr.label(
+            cfg = "host",
+            executable = True,
+            allow_single_file = True,
+            mandatory = True,
+        ),
+        "plugin": attr.label(
+            cfg = "host",
+            allow_files = True,
+            executable = True,
+        ),
+        "plugin_language": attr.string(),
+        "plugin_options": attr.string_list(),
+        "gen_cc": attr.bool(),
+        "gen_py": attr.bool(),
+        "outs": attr.output_list(),
+    },
+    output_to_genfiles = True,
+    implementation = _proto_gen_impl,
+)
+"""Generates codes from Protocol Buffers definitions.
+
+This rule helps you to implement Skylark macros specific to the target
+language. You should prefer more specific `cc_proto_library `,
+`py_proto_library` and others unless you are adding such wrapper macros.
+
+Args:
+  srcs: Protocol Buffers definition files (.proto) to run the protocol compiler
+    against.
+  deps: a list of dependency labels; must be other proto libraries.
+  includes: a list of include paths to .proto files.
+  protoc: the label of the protocol compiler to generate the sources.
+  plugin: the label of the protocol compiler plugin to be passed to the protocol
+    compiler.
+  plugin_language: the language of the generated sources
+  plugin_options: a list of options to be passed to the plugin
+  gen_cc: generates C++ sources in addition to the ones from the plugin.
+  gen_py: generates Python sources in addition to the ones from the plugin.
+  outs: a list of labels of the expected outputs from the protocol compiler.
+"""
+
+def py_proto_library(
+        name,
+        srcs = [],
+        deps = [],
+        py_libs = [],
+        py_extra_srcs = [],
+        include = None,
+        default_runtime = None,
+        protoc = "//third_party:protoc",
+        use_grpc_plugin = False,
+        **kwargs):
+    """Bazel rule to create a Python protobuf library from proto source files
+
+    NOTE: the rule is only an internal workaround to generate protos. The
+    interface may change and the rule may be removed when bazel has introduced
+    the native rule.
+
+    Args:
+      name: the name of the py_proto_library.
+      srcs: the .proto files of the py_proto_library.
+      deps: a list of dependency labels; must be py_proto_library.
+      py_libs: a list of other py_library targets depended by the generated
+          py_library.
+      py_extra_srcs: extra source files that will be added to the output
+          py_library. This attribute is used for internal bootstrapping.
+      include: a string indicating the include path of the .proto files.
+      default_runtime: the implicitly default runtime which will be depended on by
+          the generated py_library target.
+      protoc: the label of the protocol compiler to generate the sources.
+      use_grpc_plugin: a flag to indicate whether to call the Python C++ plugin
+          when processing the proto files.
+      **kwargs: other keyword arguments that are passed to py_library.
+
+    """
+    outs = _PyOuts(srcs, use_grpc_plugin)
+
+    includes = []
+    if include != None:
+        includes = [include]
+
+    grpc_python_plugin = None
+    if use_grpc_plugin:
+        grpc_python_plugin = "//external:grpc_python_plugin"
+        # Note: Generated grpc code depends on Python grpc module. This dependency
+        # is not explicitly listed in py_libs. Instead, host system is assumed to
+        # have grpc installed.
+
+    proto_gen(
+        name = name + "_genproto",
+        srcs = srcs,
+        deps = [s + "_genproto" for s in deps],
+        includes = includes,
+        protoc = protoc,
+        gen_py = 1,
+        outs = outs,
+        visibility = ["//visibility:public"],
+        plugin = grpc_python_plugin,
+        plugin_language = "grpc",
+    )
+
+    if default_runtime and not default_runtime in py_libs + deps:
+        py_libs = py_libs + [default_runtime]
+
+    native.py_library(
+        name = name,
+        srcs = outs + py_extra_srcs,
+        deps = py_libs + deps,
+        imports = includes,
+        **kwargs
+    )
+
