#!/bin/sh

MOZILLA_DIR="%%PREFIX%%/lib/%%MOZILLA%%"
MOZILLA_EXEC="mozilla"
LOCATION='new-tab'

cd $MOZILLA_DIR                                     || exit 1

# catch calls for mozilla mail
if [ "$1" = "-mail" ]; then
   REMOTE_COMMAND="xfeDoCommand (openInbox)"
else
   REMOTE_COMMAND="openURL($@, $LOCATION)"
fi

# process found
./$MOZILLA_EXEC -remote "ping()"                    &&
./$MOZILLA_EXEC -remote "$REMOTE_COMMAND"           && exit 0

# no existing process
exec ./$MOZILLA_EXEC "$@"

