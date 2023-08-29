#!/bin/sh
#
# This script is just an example. Edit this to suit your needs.
# If ${HOME}/startwm.sh exists, xrdp-sesman will execute it instead of this.

#### load profile if necessary
# source /etc/profile

#### you can set environment variables here whatever you want
# export LANG=en_US.UTF-8
# export GTK_IM_MODULE=fcitx
# export XMODIFIERS=@im=fcitx

#### start desktop environment
# exec gnome-session
# exec mate-session
# exec start-lumina-desktop
# exec ck-launch-session startplasma-x11
# exec startxfce4
exec xterm
