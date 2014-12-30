# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-themes/gnome-themes-standard/Makefile 20069 2014-11-12 08:32:24Z gusi $

PORTNAME=	gnome-themes-standard
PORTVERSION=	3.14.2.3
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Standard themes for GNOME

CONFLICTS=	gnome-themes-2.[0-9]*

USES=		gettext-tools gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 intlhack librsvg2
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
