#!/usr/bin/env python3

import argparse
import csv
import os
import subprocess
import sys
import time
from xml.dom.minidom import parseString


def check_pkg(vid, node, allpackages):
    name = str(node.getElementsByTagName('name')[0].firstChild.data)
    knownversion = allpackages.get(name, None)
    range = node.getElementsByTagName('range')[0]
    for r in range.childNodes:
        if r.nodeType == r.TEXT_NODE:
            continue
        if r.tagName not in ['eq', 'le', 'lt', 'ge', 'gt']:
            raise Exception('Unknown range type ' + r.tagName)
        version = r.firstChild.data
        if knownversion and ',' in knownversion and ',' not in version:
            print(vid + ' (' + name + ') might have a portepoch issue')


def read_index(path_to_index, max_age_secs, create_locally):
    if path_to_index is None:
        os_version = subprocess.check_output(['freebsd-version']).decode()
        os_major_version = os_version.split('.', 2)[0]
        index_file = "INDEX-" + os_major_version
        portsdir = os.getenv('PORTSDIR')
        if portsdir is None:
            portsdir = subprocess.check_output(
              ['make', '-V', 'PORTSDIR']).decode().strip()
        path_to_index = portsdir + "/" + index_file
        fetch_index = True
        if os.path.isfile(path_to_index):
            stat = os.stat(path_to_index)
            if time.time() - stat.st_ctime < max_age_secs and (
              stat.st_size > 1024 * 1024 * 4):  # 4mb
                fetch_index = False
        if fetch_index:
            cwd = os.getcwd()
            os.chdir(portsdir)
            if create_locally:
                subprocess.check_output(["make", "index"])
            else:
                subprocess.check_output(["make", "fetchindex"])
            os.chdir(cwd)

    ret = {}
    with open(path_to_index) as f:
        reader = csv.reader(f, delimiter='|')
        for row in reader:
            (name, ver) = row[0].rsplit('-', 1)
            ret[name] = ver
    return ret


def main():
    parser = argparse.ArgumentParser(
      prog=sys.argv[0],
      description='Check vuxml vuln file PORTEPOCH',
      epilog='Example: ' + sys.argv[0] + ' vuln/2026.xml')
    parser.add_argument(
      '-i', metavar='path_to_index',
      help='path to index file, disables automatic detection/updating.')
    parser.add_argument(
      '-l', action=argparse.BooleanOptionalAction,
      help='make index locally instead of fetching from cluster')
    parser.add_argument(
      '-m', metavar='index_max_age', default=3600, type=float,
      help='maximum age of index file before re-fetching (seconds)')
    parser.add_argument(
      'vuln_file',
      help='path to yearly vuln file to check, e.g., vuln/2026.xml')
    args = parser.parse_args(sys.argv[1:])

    with open(args.vuln_file) as f:
        doc = parseString(
          '<vuxml xmlns="http://www.vuxml.org/apps/vuxml-1">' +
          f.read()
          + "\n</vuxml>")
    allpackages = read_index(args.i, args.m, args.l)
    vulns = doc.getElementsByTagName('vuln')
    for vuln in vulns:
        vid = vuln.getAttribute('vid')
        packages = vuln.getElementsByTagName('package')
        for package in packages:
            check_pkg(vid, package, allpackages)


if __name__ == '__main__':
    main()
