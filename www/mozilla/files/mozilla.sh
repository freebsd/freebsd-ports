#!/bin/sh

MOZILLA_DIR="%%PREFIX%%/lib/%%MOZILLA%%"
MOZILLA_EXEC="./mozilla"
MOZILLA_REMOTE_EXEC="${MOZILLA_EXEC} -remote"
APPLICATION_ID="mozilla"

LOCATION='new-tab'
#MOZILLA_UILOCALE="en-US"
#MOZILLA_UIREGION="US"
#MOZILLA_DSP="auto"

cd $MOZILLA_DIR                                     || exit 1

# LANG, MOZILLA_UILOCALE, MOZILLA_UIREGION
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

# find a /dev/dsp handler
case "${MOZILLA_DSP}" in
#    [Ee][Ss][Dd]|esddsp) # Use the esd dsp wrapper
#	MOZILLA_DSP="esddsp"
#	;;
    [Aa][Rr][Tt][Ss]|artsdsp) # Use the arts dsp wrapper
	MOZILLA_DSP="artsdsp"
	;;
    [Nn][Oo][Nn][Ee]) # Direct dsp output
	MOZILLA_DSP=""
	;;
    *) # Guest one (auto)
	if [ -n "${KDE_FULL_SESSION}" ]; then
		MOZILLA_DSP="artsdsp"
#	elif [ -r ${HOME}/.esd_auth ]; then
#		MOZILLA_DSP="esddsp"
	else
		MOZILLA_DSP=""
	fi
	;;
esac

if [ -n "${MOZILLA_DSP}" ] && type "${MOZILLA_DSP}" > /dev/null 2>&1; then
	MOZILLA_EXEC="${MOZILLA_DSP} ${MOZILLA_EXEC}"
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
    	exec ${MOZILLA_EXEC} "$@"
	;;
    *)
	if [ -n "${LOCATION}" ]; then
    		REMOTE_COMMAND="openURL($@,$LOCATION)"
	else
		REMOTE_COMMAND="openURL($@)"
	fi
	;;
esac

# process found
${MOZILLA_REMOTE_EXEC} "ping()" >/dev/null 2>&1     &&
${MOZILLA_REMOTE_EXEC} "${REMOTE_COMMAND}"          && exit 0

# no existing process
exec ${MOZILLA_EXEC} "$@"

