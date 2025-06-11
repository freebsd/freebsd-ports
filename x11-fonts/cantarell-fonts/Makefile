PORTNAME=	cantarell-fonts
DISTVERSION=	0.303.1
CATEGORIES=	x11-fonts gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Cantarell, a Humanist sans-serif font family
WWW=		https://cantarell.gnome.org/

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USES=		gettext-tools fonts meson tar:xz
FONTSDIR=	share/fonts/cantarell
NO_ARCH=	yes

MESON_ARGS=	-Duseprebuilt=true

.include <bsd.port.mk>
