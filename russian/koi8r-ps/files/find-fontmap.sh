#!/bin/sh

if ! which gs > /dev/null ; then
	echo GhostScript not found in PATH >&2
	exit 1
fi

# Use the method suggested here:
# http://stackoverflow.com/questions/19958156/how-to-print-the-fontresourcedir-with-ghostscript-gs
# until a better way is proposed..
FONTPATH=`gs -dNODISPLAY -q -- /dev/stdin << EOSCRIPT
%!
/Font /Category findresource
begin
	/ 128 string ResourceFileName =
end
EOSCRIPT`

echo `dirname $FONTPATH`/Init/Fontmap.GS
