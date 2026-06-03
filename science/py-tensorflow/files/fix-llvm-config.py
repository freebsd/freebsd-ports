#!/usr/bin/env python3
"""Patch LLVM config.bzl to use @platforms//os:freebsd condition (idempotent)."""
import os
import sys

f = sys.argv[1]
r = os.path.realpath(f)
c = open(r).read()
# Replace old-style condition (idempotent: only matches original)
c = c.replace(
    '"@bazel_tools//src/conditions:freebsd": posix_defines,',
    '"@platforms//os:freebsd": posix_defines,')
# Add FreeBSD arch defines if not already present
freebsd_arch = ('"@platforms//os:freebsd": native_arch_defines("X86", "x86_64-unknown-freebsd14-elf"),\n'
                '    "//conditions:default": native_arch_defines("X86", "x86_64-unknown-linux-gnu"),')
if '"@platforms//os:freebsd": native_arch_defines' not in c:
    c = c.replace(
        '"//conditions:default": native_arch_defines("X86", "x86_64-unknown-linux-gnu"),',
        freebsd_arch)
os.chmod(r, 0o644)
open(r, 'w').write(c)
