#!/bin/sh
SIGNAL_VERS=v6.1.0-beta.1

ringrtc_hash=$(fetch -qo - https://raw.githubusercontent.com/signalapp/Signal-Desktop/${SIGNAL_VERS}/package.json | grep '"ringrtc": "https' | awk -F "#" '{print $2}' | sed 's#",##')
# echo "RINGRTC_HASH= ${ringrtc_hash} ; https://raw.githubusercontent.com/signalapp/Signal-Desktop/${SIGNAL_VERS}/package.json"

ringrtc_version=$(fetch -qo - https://raw.githubusercontent.com/signalapp/signal-ringrtc-node/${ringrtc_hash}/package.json | grep '"version":' | awk -F ":" '{print $2}' | sed -e 's# "##' -e 's#",##')
echo "RINGRTC_VERSION= ${ringrtc_version} ; https://raw.githubusercontent.com/signalapp/signal-ringrtc-node/${ringrtc_hash}/package.json"

webrtc_version=$(fetch -qo - https://raw.githubusercontent.com/signalapp/ringrtc/v${ringrtc_version}/config/version.sh | awk -F '=' /WEBRTC_VERSION/'{print $2}')
echo "WEBRTC_REV= ${webrtc_version} ; https://raw.githubusercontent.com/signalapp/ringrtc/v${ringrtc_version}/config/version.sh"

libsignalclient_version=$(fetch -qo - https://raw.githubusercontent.com/signalapp/Signal-Desktop/${SIGNAL_VERS}/yarn.lock | grep 'signalapp/libsignal-client@' | awk -F '@' '{print $3}' | sed 's#", "##')
echo "LIBSIGNAL_VERSION= ${libsignalclient_version}"
