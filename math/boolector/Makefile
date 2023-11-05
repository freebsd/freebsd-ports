PORTNAME=	boolector
DISTVERSION=	3.2.3
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Satisfiability Modulo Theories (SMT) solver
WWW=		https://boolector.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/lib/libcadical.a:math/cadical \
		${LOCALBASE}/lib/liblgl.a:math/lingeling
LIB_DEPENDS=	libbtor2parser.so:math/btor2tools \
		libcryptominisat5.so:math/cryptominisat \
		libminisat.so:math/minisat \
		libpicosat.so:math/picosat \
		libgmp.so:math/gmp
TEST_DEPENDS=	bash:shells/bash

USES=		cmake:noninja,testing compiler:c++11-lang cpe python:test # ninja fails to build tests

CPE_VENDOR=	boolector_project

USE_GITHUB=	yes
GH_ACCOUNT=	Boolector

CMAKE_ON=	BUILD_SHARED_LIBS \
		USE_GMP
CMAKE_OFF=	TESTING
CMAKE_TESTING_ON=	TESTING # tests fail to comile, see https://github.com/Boolector/boolector/issues/216
CMAKE_ARGS=	-DCaDiCaL_INCLUDE_DIR=${LOCALBASE}/include

.include <bsd.port.mk>
