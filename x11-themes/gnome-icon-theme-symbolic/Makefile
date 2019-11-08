# Created by: gnome@freebsd.org
# $FreeBSD$
#   $MCom: ports/trunk/x11-themes/gnome-icon-theme-symbolic/Makefile 19571 2014-04-25 18:12:46Z kwm $

PORTNAME=	gnome-icon-theme-symbolic
PORTVERSION=	3.12.0
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Symbolic Icons

BUILD_DEPENDS=	icon-naming-utils>=0.8.7:x11-themes/icon-naming-utils

INSTALLS_ICONS=	yes
USES=		gmake gnome pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_GIT="" \
		ac_cv_path_INKSCAPE=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|(GTK_UPDATE_ICON_CACHE) -q |(GTK_UPDATE_ICON_CACHE) -q -t -f |'g \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
