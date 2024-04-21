PORTNAME=	clingcon
DISTVERSIONPREFIX=	v
DISTVERSION=	5.2.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extension of clingo to handle constraints over integers
WWW=		https://potassco.org/clingcon/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libclingo.so:math/clingo

USES=		cmake:testing compiler:c++17-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	potassco

CMAKE_OFF=	PYCLINGCON_ENABLE
CMAKE_TESTING_ON=	CLINGCON_BUILD_TESTS

.include <bsd.port.mk>
