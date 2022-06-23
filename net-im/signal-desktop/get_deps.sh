#!/bin/sh
SIGNAL_VERS=v5.46.0

ringrtc_hash=$(fetch -qo - https://raw.githubusercontent.com/signalapp/Signal-Desktop/${SIGNAL_VERS}/package.json | grep '"ringrtc": "https' | awk -F "#" '{print $2}' | sed 's#",##')
# echo "RINGRTC_HASH= ${ringrtc_hash}"

ringrtc_version=$(fetch -qo - https://raw.githubusercontent.com/signalapp/signal-ringrtc-node/${ringrtc_hash}/package.json | grep '"version":' | awk -F ":" '{print $2}' | sed -e 's# "##' -e 's#",##')
echo "RINGRTC_VERSION= ${ringrtc_version}"

webrtc_version=$(fetch -qo - https://raw.githubusercontent.com/signalapp/ringrtc/v${ringrtc_version}/config/version.sh | awk -F '=' /WEBRTC_VERSION/'{print $2}')
echo "WEBRTC_REV= ${webrtc_version}"

libsignalclient_version=$(fetch -qo - https://raw.githubusercontent.com/signalapp/Signal-Desktop/${SIGNAL_VERS}/yarn.lock | grep 'signalapp/libsignal-client@' | awk -F '@' '{print $3}' | sed 's#", "##')
echo "LIBSIGNAL_VERSION= ${libsignalclient_version}"
