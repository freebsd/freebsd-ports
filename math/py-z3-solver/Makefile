PORTNAME=	z3-solver
DISTVERSIONPREFIX=	z3-
DISTVERSION=	4.14.1
PORTREVISION=	1
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for Z3 Theorem Prover
WWW=		https://github.com/Z3Prover/z3

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../../../LICENSE.txt

LIB_DEPENDS=	libz3.so:math/z3

USES=		cmake python
USE_PYTHON=	flavors autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	Z3Prover
GH_PROJECT=	z3

WRKSRC_SUBDIR=	src/api/python
WRKSRC_top=	${WRKSRC}/../../..

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

post-patch:
	@${RLN} ${WRKSRC_top}/scripts ${WRKSRC}/scripts
	@${RLN} ${WRKSRC_top}/src/api ${WRKSRC}/api

do-test:
.for t in z3 z3num
	@cd ${WRKSRC_top} && \
		${CP} ${WRKSRC}/z3test.py . && \
		${ECHO} "==> running the test ${t}" && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} z3test.py ${t} && \
		${ECHO} "... test ${t} succeeded"
.endfor
.for e in kinematics power-of-two dog-cat-mouse sudoku eight-queens
	@cd ${WRKSRC}/../../.. && \
		${ECHO} "==> running the example ${e}" && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/example-${e}.py && \
		${ECHO} "... example ${e} succeeded"
	@${ECHO} "All tests succeeded."
.endfor

.include <bsd.port.mk>
