PORTNAME=	boolector
DISTVERSION=	3.2.4
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Satisfiability Modulo Theories (SMT) solver
WWW=		https://boolector.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/lib/liblgl.a:math/lingeling
LIB_DEPENDS=	libbtor2parser.so:math/btor2tools \
		libcadical.so:math/cadical \
		libcryptominisat5.so:math/cryptominisat \
		libminisat.so:math/minisat \
		libpicosat.so:math/picosat \
		libgmp.so:math/gmp
TEST_DEPENDS=	bash:shells/bash

USES=		cmake:noninja,testing compiler:c++11-lang cpe python:build,test shebangfix

CPE_VENDOR=	boolector_project

USE_GITHUB=	yes
GH_ACCOUNT=	Boolector

SHEBANG_GLOB=	*.sh

CFLAGS+=	-I${LOCALBASE}/include/cadical
CXXFLAGS+=	-I${LOCALBASE}/include/cadical

CMAKE_ON=	BUILD_SHARED_LIBS \
		USE_GMP
CMAKE_OFF=	TESTING
CMAKE_TESTING_ON=	TESTING # 1 test hangs, see https://github.com/Boolector/boolector/issues/227
CMAKE_ARGS=	-DCaDiCaL_INCLUDE_DIR=${LOCALBASE}/include

BINARY_ALIAS=	python=${PYTHON_CMD} python3=${PYTHON_CMD} # only for tests

.include <bsd.port.mk>
