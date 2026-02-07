PORTNAME=	cantarell-fonts
DISTVERSION=	0.310
CATEGORIES=	x11-fonts gnome
MASTER_SITES=	https://cantarell.gnome.org/releases/
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Cantarell, a Humanist sans-serif font family
WWW=		https://cantarell.gnome.org/

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fonts gettext-tools meson tar:xz
FONTSDIR=	share/fonts/cantarell
NO_ARCH=	yes

MESON_ARGS=	-Duseprebuilt=true

.include <bsd.port.mk>
