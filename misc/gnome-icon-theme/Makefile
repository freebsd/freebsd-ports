# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/misc/gnome-icon-theme/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-icon-theme
PORTVERSION=	3.6.2
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of icons for the GNOME desktop

BUILD_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		icon-naming-utils>=0.8.7:${PORTSDIR}/x11-themes/icon-naming-utils
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_XZ=		yes
GNU_CONFIGURE=	yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	intlhack
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-icon-mapping
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.mk>
