# $FreeBSD$

PORTREVISION=	2

PKGNAMESUFFIX=	-gtk

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libnotify.so:devel/libnotify
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		desktop-file-utils gnome ssl
NLS_USES=	gettext-tools:build
USE_GNOME=	cairo gdkpixbuf2 gtk30 intlhack pango

MASTERDIR=	${.CURDIR}/../transmission-cli
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

SLAVEPORT=	gtk

.include "${MASTERDIR}/Makefile"
