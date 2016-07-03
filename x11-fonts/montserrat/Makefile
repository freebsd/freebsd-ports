# $FreeBSD$

PORTNAME=	montserrat
PORTVERSION=	3.100
CATEGORIES=	x11-fonts

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Sans-serif font inspired by the street signs of Montserrat

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		fonts

USE_GITHUB=	yes
GH_ACCOUNT=	JulietaUla
GH_PROJECT=	Montserrat
GH_TAGNAME=	59350832

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC}/otf && \
		${INSTALL_DATA} *.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
