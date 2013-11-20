# $FreeBSD$
#   $MCom: ports/trunk/x11-themes/gnome-icon-theme-symbolic/Makefile 18433 2013-05-06 21:03:32Z kwm $

PORTNAME=	gnome-icon-theme-symbolic
PORTVERSION=	3.6.2
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Symbolic Icons

BUILD_DEPENDS=	icon-naming-utils>=0.8.7:${PORTSDIR}/x11-themes/icon-naming-utils

NO_STAGE=	yes
USE_XZ=		yes
INSTALLS_ICONS=	yes
USES=		gmake pathfix pkgconfig
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
