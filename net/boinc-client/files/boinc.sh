#!/bin/sh

export LD_LIBRARY_PATH=%%LOCALBASE%%/lib/boinc

args=${@+"$@"}
exec idprio 31 su - %%BOINC_USER%% -c "%%LOCALBASE%%/lib/boinc/%%BOINC_BINARY%% $args"

