# Ports collection Makefile for:	GnomeICU
# Date created:				03/16/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		gnomeicu
PORTVERSION=		0.93
CATEGORIES=		net gnome
MASTER_SITES=		ftp://gnomeicu.gdev.net/pub/gnomeicu/ \
			ftp://ftp.vision.net.au/ftp7/linuxberg/files/gnome/com/ \
			ftp://ftp.datacomm.ch/.3/linuxberg/files/gnome/com/ \
			ftp://ftp.proxad.net/mirrors/ftp.linuxberg.com/files/gnome/com/

MAINTAINER=		nectar@FreeBSD.org

LIB_DEPENDS=		panel_applet.4:${PORTSDIR}/x11/gnomecore

GTK_CONFIG?=		${X11BASE}/bin/gtk12-config

USE_X_PREFIX=		YES
USE_BZIP2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV=		GTK_CONFIG="${GTK_CONFIG}" \
			CPPFLAGS="-I${LOCALBASE}/include" \
			LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=		--datadir=${PREFIX}/share/gnome

.include <bsd.port.mk>
