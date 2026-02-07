# Copyright 2018 The Bazel Authors. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# This becomes the BUILD file for @local_config_cc// under FreeBSD and OpenBSD.
load(":cc_toolchain_config.bzl", "cc_toolchain_config")
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_toolchain", "cc_toolchain_suite")
load("@bazel_tools//tools/python:toolchain.bzl", "py_runtime_pair")

package(default_visibility = ["//visibility:public"])
cc_library(
    name = "malloc",
)
filegroup(
    name = "empty",
    srcs = [],
)

# Hardcoded toolchain, legacy behaviour.
cc_toolchain_suite(
    name = "freebsd_clang",
    toolchains = {
        "k8": ":cc-compiler-freebsd",
	"freebsd": ":cc-compiler-freebsd",
    },
)

cc_toolchain(
    name = "cc-compiler-freebsd",
    all_files = ":empty",
    ar_files = ":empty",
    as_files = ":empty",
    compiler_files = ":empty",
    dwp_files = ":empty",
    linker_files = ":empty",
    objcopy_files = ":empty",
    strip_files = ":empty",
    supports_param_files = 0,
    toolchain_config = ":local_freebsd",
    toolchain_identifier = "local_freebsd",
)
cc_toolchain_config(
    name = "local_freebsd",
    cpu = "freebsd",
)

toolchain(
    name = "cc-toolchain-freebsd",
    exec_compatible_with = [
        "@platforms//cpu:x86_64",
        "@platforms//os:freebsd",
    ],
    target_compatible_with = [
        "@platforms//cpu:x86_64",
        "@platforms//os:freebsd",
    ],
    toolchain = ":cc-compiler-freebsd",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
)

py_runtime(
    name = "freebsd_python",
    interpreter_path = "/usr/local/bin/python3.9",
    python_version = "PY3",
    visibility = ["//visibility:public"],
)

py_runtime_pair(
    name = "bsd_py_runtime_pair",
    py2_runtime = None,
    py3_runtime = ":freebsd_python",
)

toolchain(
    name = "freebsd_py_toolchain",
    toolchain = ":bsd_py_runtime_pair",
    toolchain_type = "@bazel_tools//tools/python:toolchain_type",
)

