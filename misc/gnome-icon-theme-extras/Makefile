# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/misc/gnome-icon-theme-extras/Makefile 19329 2014-03-25 14:54:05Z gusi $

PORTNAME=	gnome-icon-theme-extras
PORTVERSION=	3.12.0
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional collection of icons for the GNOME desktop

BUILD_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme \
		icon-naming-utils>=0.8.7:x11-themes/icon-naming-utils
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme

USES=		gmake gnome pathfix pkgconfig tar:xz
USE_GNOME=	intlhack gtk-update-icon-cache
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-icon-mapping
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
