PORTNAME=	numix-icon-theme
PORTVERSION=	21.10.31
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Official base icon theme from the Numix Project

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/license

USES=		gnome

USE_GITHUB=	yes
GH_ACCOUNT=	numixproject

NO_ARCH=	yes
NO_BUILD=	yes

ICONSDIR=	${PREFIX}/share/icons

do-install:
	${MKDIR} ${STAGEDIR}${ICONSDIR}
	${FIND} ${WRKSRC} -mindepth 1 -maxdepth 1 -type d -exec ${CP} -R {} \
		${STAGEDIR}${ICONSDIR}/ ';'

.include <bsd.port.mk>
