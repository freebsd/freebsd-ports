# $FreeBSD$

PORTNAME=	digestpp
DISTVERSION=	g20200907
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Experimental C++11 header-only message digest library

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	kerukuro
GH_TAGNAME=	34ff2eeae397ed744d972d86b5a20f603b029fbd

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.hpp ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} algorithm ${STAGEDIR}${PREFIX}/include/${PORTNAME} && \
		${COPYTREE_SHARE} detail ${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
