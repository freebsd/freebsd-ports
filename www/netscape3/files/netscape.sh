#!/bin/sh
export XKEYSYMDB ; XKEYSYMDB=@X11BASE@/lib/X11/XKeysymDB
export XNLSPATH  ; XNLSPATH=@X11BASE@/lib/X11/nls
export XAPPLRESDIR ; XAPPLRESDIR=@X11BASE@/lib/X11/app-defaults
exec /usr/local/lib/netscape/netscape.bin $*
