#!/bin/sh

MOZILLA_DIR="%%PREFIX%%/lib/%%MOZILLA%%"
MOZILLA_EXEC="mozilla"
LOCATION='new-tab'

cd $MOZILLA_DIR                                     || exit 1

# LANG, MOZILLA_UILOCALE, MOZILLA_REGION
if [ -n "$LANG" -a ! -n "${MOZILLA_UILOCALE}" ]; then
    _locale="${LANG%%.*}"
    if [ "${_locale}" != "en_US" -a "${_locale}" != "C" ]; then
	_region="${_locale##*_}"
	_locale="${_locale%_*}"
	[ -r chrome/${_locale}-${_region}.jar ] && \
	    MOZILLA_EXEC="${MOZILLA_EXEC} -UILocale ${_locale}-${_region}"
    fi
elif [ -n "${MOZILLA_UILOCALE}" ]; then
    MOZILLA_EXEC="${MOZILLA_EXEC} -UILocale ${MOZILLA_UILOCALE}"
    if [ -n "${MOZILLA_UIREGION}" ]; then
	MOZILLA_EXEC="${MOZILLA_EXEC} -UIRegion ${MOZILLA_UIREGION}"
    fi
fi

case $1 in
    -browser)
    	REMOTE_COMMAND="xfeDoCommand (openBrowser)"
	;;
    -mail)
    	REMOTE_COMMAND="xfeDoCommand (openInbox)"
	;;
    -compose)
    	REMOTE_COMMAND="xfeDoCommand (composeMessage)"
	;;
    -*)
    	exec ./$MOZILLA_EXEC "$@"
	;;
    *)
    	REMOTE_COMMAND="openURL($@,$LOCATION)"
	;;
esac

# process found
./$MOZILLA_EXEC -remote "ping()"                    &&
./$MOZILLA_EXEC -remote "$REMOTE_COMMAND"           && exit 0

# no existing process
exec ./$MOZILLA_EXEC "$@"

