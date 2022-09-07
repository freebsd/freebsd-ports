PORTNAME=	cantarell-fonts
DISTVERSION=	0.301
CATEGORIES=	x11-fonts gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Cantarell, a Humanist sans-serif font family
WWW=		https://wiki.gnome.org/Projects/CantarellFonts

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USES=		gettext-tools fonts meson tar:xz
FONTSDIR=	share/fonts/cantarell
NO_ARCH=	yes

.include <bsd.port.mk>
