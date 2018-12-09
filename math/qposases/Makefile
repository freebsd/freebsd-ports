# $FreeBSD$

PORTNAME=	qpOASES
DISTVERSION=	3.2.1
CATEGORIES=	math
MASTER_SITES=	https://www.coin-or.org/download/source/${PORTNAME}/
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for online active set strategy quadratic programming problems

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:outsource tar:tgz
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	QPOASES_BUILD_EXAMPLES

.include <bsd.port.mk>
