# New ports collection makefile for:	ru-linux-mozillafirebird
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

CATEGORIES=		russian www linux
MASTER_SITE_SUBDIR=	firebird/releases/${PORTVERSION}/contrib-localized
PKGNAMEPREFIX=		ru-linux-
DISTNAME=		MozillaFirebird-${PORTVERSION}-i686-pc-linux-gnu-ruRU

COMMENT=		Firebird Web browser:  Russian Linux/i386 version

RUN_DEPENDS=	\
${LINUXBASE}/lib/libc-2.3.2.so:${PORTSDIR}/emulators/linux_base-8 \
${LINUXBASE}/usr/X11R6/lib/libXrandr.so.2:${PORTSDIR}/x11/linux-XFree86-libs \
${LINUXBASE}/usr/lib/libatk-1.0.so.0:${PORTSDIR}/accessibility/linux-atk \
${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig \
${LINUXBASE}/usr/lib/libgobject-2.0.so.0:${PORTSDIR}/devel/linux-glib2 \
${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0:${PORTSDIR}/x11-toolkits/linux-gtk2 \
${LINUXBASE}/usr/lib/libpango-1.0.so.0:${PORTSDIR}/x11-toolkits/linux-pango \
${LINUXBASE}/usr/share/fonts/default:${PORTSDIR}/x11-fonts/linux-urw-fonts

USE_BZIP2=	yes

.include "../../www/linux-mozillafirebird/Makefile"
