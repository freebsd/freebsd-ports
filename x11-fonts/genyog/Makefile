PORTNAME=	genyog
PORTVERSION=	1.501
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-fonts

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Free Gothic font family derived from Adobe Source Han Sans

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/SIL_Open_Font_License_1.1.txt

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

GH_ACCOUNT=	ButTaiwan
GH_PROJECT=	genyog-font
USE_GITHUB=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/ttc/*.ttc ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
