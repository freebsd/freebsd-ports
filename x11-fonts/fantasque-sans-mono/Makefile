# $FreeBSD$

PORTNAME=	fantasque-sans-mono
PORTVERSION=	1.7.2
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/belluzj/fantasque-sans/releases/download/v${PORTVERSION}/
DISTNAME=	FantasqueSansMono-Normal

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Programming font, designed with functionality in mind

LICENSE=	OFL11

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USES=		fonts

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC}/OTF && \
		${INSTALL_DATA} *.otf ${STAGEDIR}${FONTSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
