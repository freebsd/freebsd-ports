#!/bin/sh

# Use this script to bind ffmpegthumbnailer to nautilus.

type="application@x-extension-webm video/3gpp video/3gpp2 video@avi \
video@flv video@mkv video@mp4 video@mpeg video@ogg video@quicktime video@webm \
video@x-avi video@x-flv video@x-m4v video@x-matroska video@x-mkv video@x-mp4 \
video@x-mpeg video@x-ms-asf video@x-ms-wmv video@x-ms-wvx video@x-msvideo \
video@x-msvideo@avi video@x-theora@ogg video@x-theora@ogv video@x-webm"

cmd="/usr/bin/ffmpegthumbnailer -s %s -i %i -o %o -f"

for i in $type; do
gconftool-2 -s "/desktop/gnome/thumbnailers/$i/command" -t string "$cmd"
gconftool-2 -s "/desktop/gnome/thumbnailers/$i/enable" -t boolean "true"
done
