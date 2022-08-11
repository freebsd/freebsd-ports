PORTNAME=	jf-openhuninn
PORTVERSION=	1.1
MASTER_SITES=	https://github.com/justfont/open-huninn-font/releases/download/v${PORTVERSION}/
CATEGORIES=	x11-fonts

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	jf Open Huninn by justfont

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/jf-openhuninn-${PORTVERSION}.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/jf-openhuninn-${PORTVERSION}.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
