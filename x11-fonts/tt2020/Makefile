PORTNAME=	tt2020
PORTVERSION=	0.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-fonts

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Advanced, hyperrealistic, multilingual typewriter font
WWW=		https://copypaste.wtf/TT2020/

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	ctrlcctrlv
GH_PROJECT=	TT2020

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
