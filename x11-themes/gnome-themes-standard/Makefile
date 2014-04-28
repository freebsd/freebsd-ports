# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/x11-themes/gnome-themes-standard/Makefile 19307 2014-03-25 07:34:54Z gusi $

PORTNAME=	gnome-themes-standard
PORTVERSION=	3.12.0
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Standard themes for GNOME

CONFLICTS=	gnome-themes-2.[0-9]*

USES=		gettext:build gmake pathfix pkgconfig tar:xz
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix gtk30 intlhack librsvg2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/3.0.0/theming-engines/libadwaita.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gtk-2.0/2.10.0/engines/libadwaita.so

.include <bsd.port.mk>
