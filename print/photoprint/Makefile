# $FreeBSD$

PORTNAME=	photoprint
DISTVERSION=	0.4.2-pre2
CATEGORIES=	print graphics
MASTER_SITES=	http://www.blackfiveimaging.co.uk/photoprint/
#DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Utility to print multiple images per sheet

LIB_DEPENDS=	cups:${PORTSDIR}/print/cups-client \
		expat:${PORTSDIR}/textproc/expat2 \
		gdk_pixbuf-2.0:${PORTSDIR}/graphics/gdk-pixbuf2 \
		gutenprint:${PORTSDIR}/print/gutenprint \
		lcms:${PORTSDIR}/graphics/lcms \
		netpbm:${PORTSDIR}/graphics/netpbm \
		pcre:${PORTSDIR}/devel/pcre \
		pcre:${PORTSDIR}/devel/pcre \
		pixman:${PORTSDIR}/x11/pixman \
		png15:${PORTSDIR}/graphics/png \
		pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		tiff:${PORTSDIR}/graphics/tiff \
		xcb:${PORTSDIR}/x11/libxcb

LICENCE=	GPLv2

USE_GETTEXT=	yes
HAS_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS+=LDFLAGS=-L/usr/local/lib
USE_GNOME=	desktopfileutils pango
USE_XORG=	x11 xau xcomposite xcursor xdamage xdmcp xext \
		xfixes xi xinerama xrandr xrender

post-install:
		-@update-desktop-database

.include <bsd.port.mk>
