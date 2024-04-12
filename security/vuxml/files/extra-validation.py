#!/usr/bin/env python

import datetime
from lxml import etree as ET
import sys
import re

if len(sys.argv) != 2:
    print("Usage: %s vuln.xml" % (sys.argv[0]))
    sys.exit(1)

re_date = re.compile(r'^(19|20)[0-9]{2}-[0-9]{2}-[0-9]{2}$')
re_invalid_package_name = re.compile('[@!#$%^&*()<>?/\|}{~:]')

# warn if description has more than X characters
DESCRIPTION_LENGTH = 5000

parser = ET.XMLParser(dtd_validation=True)
tree = ET.parse(sys.argv[1], parser)
root = tree.getroot()

namespace = "{http://www.vuxml.org/apps/vuxml-1}"

ret = 0


def dateof(string):
    return datetime.datetime.strptime(string, "%Y-%m-%d")

all_vids = set()


for vuln in root:
    vid = vuln.get("vid")

    cancelled = False if vuln.find(namespace+"cancelled") is None else True
    if cancelled:
        continue

    # Validate Vids
    if vid in all_vids:
        print("Error: duplicate vid : {0}".format(vid))
    all_vids.add(vid)

    # Validate References
    references = vuln.findall(namespace+"references")
    if references is None:
        print("Error: references is None : {0}".format(vid))
        ret = 1
    else:
        prev = references[0]
        for reference in references[1:]:
            if reference.tag < prev.tag:
                #print("Warn: tags out of order ({1} and {2}): {0}".format(vid, prev.tag[len(namespace):], reference.tag[len(namespace):]))
                pass
            prev = reference

    # Validate Dates
    dates = vuln.find(namespace+"dates")
    if dates is None:
        print("Error: no date : {0}".format(vid))
        ret = 1
    else:
        discovery = dates.find(namespace+"discovery")
        entry = dates.find(namespace+"entry")
        modified = dates.find(namespace+"modified")
        if discovery is None:
            print("Error: discovery is None : {0}".format(vid))
            ret = 1
        elif entry is None:
            print("Error: entry is None : {0}".format(vid))
            ret = 1
        else:
            if modified is None:
                modified = entry
            if not (dateof(discovery.text) <= dateof(entry.text) <= dateof(modified.text)):
                print("Error: dates are insane : {0}".format(vid))
                ret = 1

        # Make sure the dates are in YYYY-MM-DD format
        datelist = [discovery.text, entry.text] + ([modified.text] if modified is not None else [])
        for d in datelist:
            if not re_date.match(d):
                print("Warning: dates must be in YYYY-MM-DD format: {0}".format(d))

        # Check description lengths
        description = vuln.find(namespace + "description")
        description_len = len(ET.tostring(description, encoding='unicode', method='text'))
        if description_len > DESCRIPTION_LENGTH:
            print("Warning: description too long ({0} chars, {1} is warning threshold): {2})" \
                  .format(description_len, DESCRIPTION_LENGTH, vid))

        # Walk and validate package names
        affects = vuln.find(namespace + "affects")
        packages = affects.findall(namespace + "package")
        for package in packages:
            names = package.findall(namespace + "name")

            for name in names:
                if (re_invalid_package_name.search(name.text) is not None):
                    print("Error: invalid package name: " + name.text + " for VID " + format(vid))
                    ret = 1

sys.exit(ret)
