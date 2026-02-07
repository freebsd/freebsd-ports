#!/bin/sh

##
## report-test-results.sh - script to report number of successes and failures in the NWChem QA log file
##

LOG=$1

echo "The log file $LOG has:"
echo " - $(grep "^OK$" $LOG | wc -l) successes"
echo " - $(grep "^Failed$" $LOG | wc -l) failures"
