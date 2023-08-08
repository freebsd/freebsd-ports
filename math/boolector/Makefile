PORTNAME=	boolector
DISTVERSION=	3.2.2
PORTREVISION=	2
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

USES=		cmake:noninja compiler:c++11-lang cpe python:test # ninja fails to build tests

CPE_VENDOR=	boolector_project

USE_GITHUB=	yes
GH_ACCOUNT=	Boolector

CMAKE_ON=	BUILD_SHARED_LIBS \
		USE_GMP
CMAKE_ARGS=	-DCaDiCaL_INCLUDE_DIR=${LOCALBASE}/include

do-test:
	@${FIND} ${WRKDIR} -name "*.py" \
		| ${XARGS} ${REINPLACE_CMD} -e 's|#!/usr/bin/env python$$|#!${PYTHON_CMD}| ; s|#!/usr/bin/env python3$$|#!${PYTHON_CMD}|'
	@${FIND} ${WRKDIR} -name "*.sh" \
		| ${XARGS} ${REINPLACE_CMD} 's|#!/bin/bash$$|#!${LOCALBASE}/bin/bash|'
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
