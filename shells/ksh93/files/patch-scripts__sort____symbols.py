--- files/patch-scripts_sort__symbols.py.orig	2019-08-04 16:51:09 UTC
+++ files/patch-scripts_sort__symbols.py
@@ -0,0 +1,34 @@
+--- scripts/sort_symbols.py.orig	2019-04-16 20:04:19 UTC
++++ scripts/sort_symbols.py
+@@ -1,31 +0,0 @@
+-# This replaces the following pipeline in the original .../libast/comp.conf.sh
+-# script. We're now using a python program not for efficiency but because we
+-# need to sort the strings from longest to shortest to work around a bug with
+-# the macOS `fgrep -x -v` behavior.
+-#
+-# sed "s/[^_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789][^_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789]*/${snl}/g" $tmp.e |
+-# grep '^[_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz][_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789]*$' |
+-# sort -u > $tmp.n
+-#
+-from __future__ import print_function  # in case we're being run by python2
+-import re
+-import sys
+-
+-
+-def sort_key(k):
+-    return (len(k), k)
+-
+-
+-# Capture all the lines consisting solely of single tokens that are valid
+-# C symbols.
+-lines = []
+-for line in sys.stdin:
+-    m = re.match(r'^\s*(\w+),$', line)
+-    if m:
+-        lines.append(m.group(1))
+-
+-# Sort by line length then lexicographically for lines of the same length.
+-lines.sort(key=sort_key, reverse=True)
+-
+-for line in lines:
+-    print(line)
