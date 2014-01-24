# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-themes/gnome-themes-standard/Makefile 18572 2013-06-18 10:03:30Z kwm $
# Updated by Joe Maloney to support GTK 3.10 <pkgdemonteam@gmail.com>

PORTNAME=       gnome-themes-standard
PORTVERSION=    3.10.0
PORTREVISION=   1
CATEGORIES=     x11-themes gnome
MASTER_SITES=   GNOME
DIST_SUBDIR=    gnome3

MAINTAINER=     gnome@FreeBSD.org
COMMENT=        Standard themes for GNOME

CONFLICTS=      gnome-themes-2.[0-9]*

NO_STAGE=       yes
USE_XZ=         yes
USES=           gettext:build gmake pathfix pkgconfig
INSTALLS_ICONS= yes
USE_GNOME=      gnomeprefix gtk30 intlhack librsvg2
GNU_CONFIGURE=  yes
CPPFLAGS+=      -I${LOCALBASE}/include
LDFLAGS+=       -L${LOCALBASE}/lib

LIBTOOL_FLAGS=  --tag-disable-static
CONFIGURE_ARGS= --disable-static

.include <bsd.port.mk>
