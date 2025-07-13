PORTNAME=	cinnamon-translations
DISTVERSION=	6.4.2
CATEGORIES=	misc x11 gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Translations for the cinnamon desktop
WWW=		https://github.com/linuxmint/cinnamon-translations

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext-tools

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

NO_BUILD=	yes
INSTALL_TARGET=	all
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|usr/share|${STAGEDIR}${PREFIX}/share|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
