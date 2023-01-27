#!/bin/sh
SIGNAL_VERS=v6.3.0-beta.1

ringrtc_version=$(fetch -qo - https://raw.githubusercontent.com/signalapp/Signal-Desktop/${SIGNAL_VERS}/package.json | grep '@signalapp/ringrtc"' | awk -F ":" '{print $2}' | sed -E 's#("|,| )##g')
echo "RINGRTC_VERSION= ${ringrtc_version}"

webrtc_version=$(fetch -qo - https://raw.githubusercontent.com/signalapp/ringrtc/v${ringrtc_version}/config/version.properties | grep 'webrtc.version' | awk -F '=' '{print $2}')
echo "WEBRTC_REV= ${webrtc_version} ; https://raw.githubusercontent.com/signalapp/ringrtc/v${ringrtc_version}/config/version.properties"

libsignalclient_version=$(fetch -qo - https://raw.githubusercontent.com/signalapp/Signal-Desktop/${SIGNAL_VERS}/yarn.lock | grep 'signalapp/libsignal-client@' | awk -F '@' '{print $3}' | sed 's#", "##')
echo "LIBSIGNAL_VERSION= ${libsignalclient_version}"
