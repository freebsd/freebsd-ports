# $FreeBSD$

PORTNAME=	ecos
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.6
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight conic solver for second-order cone programming

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	embotech
ALL_TARGET=	shared
USE_LDCONFIG=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/ecos
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/include/ecos
	${INSTALL_LIB} ${WRKSRC}/libecos.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
