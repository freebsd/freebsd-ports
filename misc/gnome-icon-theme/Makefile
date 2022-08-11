PORTNAME=	gnome-icon-theme
PORTVERSION=	3.12.0
PORTREVISION=	1
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of icons for the GNOME desktop

LICENSE=	LGPL3 CC-BY-SA-3.0
LICENSE_COMB=	dual
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING_LGPL
LICENSE_FILE_CC-BY-SA-3.0=	${WRKSRC}/COPYING_CCBYSA3

BUILD_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme \
		icon-naming-utils>=0.8.7:x11-themes/icon-naming-utils
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme \
		gnome-icon-theme-symbolic>=0:x11-themes/gnome-icon-theme-symbolic

GNU_CONFIGURE=	yes
USES=		gettext-tools gmake gnome localbase pathfix pkgconfig tar:xz
USE_GNOME=	intlhack
CONFIGURE_ARGS=	--enable-icon-mapping
CONFIGURE_ENV=	ac_cv_path_GTK_UPDATE_ICON_CACHE=/usr/bin/true
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
