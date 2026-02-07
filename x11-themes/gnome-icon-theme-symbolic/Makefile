PORTNAME=	gnome-icon-theme-symbolic
PORTVERSION=	3.12.0
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Symbolic Icons

LICENSE=	CC-BY-SA-3.0
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	icon-naming-utils>=0.8.7:x11-themes/icon-naming-utils

USES=		gmake localbase pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_GIT="" \
		ac_cv_path_INKSCAPE="" \
		ac_cv_path_GTK_UPDATE_ICON_CACHE=/usr/bin/true

.include <bsd.port.mk>
