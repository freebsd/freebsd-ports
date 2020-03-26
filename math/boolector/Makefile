# $FreeBSD$

PORTNAME=	boolector
DISTVERSION=	3.2.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Satisfiability Modulo Theories (SMT) solver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	cadical>0:math/cadical
LIB_DEPENDS=	libbtor2parser.so:math/btor2tools \
		libminisat.so:math/minisat \
		libpicosat.so:math/picosat

USES=		cmake:noninja compiler:c++11-lang # ninja fails to build tests
USE_GITHUB=	yes
GH_ACCOUNT=	Boolector

CMAKE_ON=	BUILD_SHARED_LIBS

do-test: # tests assume that python-3.7 and bash are installed
	@${FIND} ${WRKDIR} -name "*.py" \
		| ${XARGS} ${REINPLACE_CMD} -e 's|#!/usr/bin/env python$$|#!${LOCALBASE}/bin/python3.7| ; s|#!/usr/bin/env python3$$|#!${LOCALBASE}/bin/python3.7|'
	@${FIND} ${WRKDIR} -name "*.sh" \
		| ${XARGS} ${REINPLACE_CMD} 's|#!/bin/bash$$|#!${LOCALBASE}/bin/bash|'
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
