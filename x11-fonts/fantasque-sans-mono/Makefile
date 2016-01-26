# $FreeBSD$

PORTNAME=	fantasque-sans-mono
PORTVERSION=	1.6.5
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://fontlibrary.org/assets/downloads/${PORTNAME}/db52617ba875d08cbd8e080ca3d9f756/
DISTNAME=	fantasque-sans-mono

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Programming font, designed with functionality in mind

LICENSE=	OFL11

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USES=		fonts zip

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC}/OTF && \
		${INSTALL_DATA} *.otf ${STAGEDIR}${FONTSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
