PORTNAME=	pplpy
PORTVERSION=	0.8.7
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python wrapper to the C++ Parma Polyhedra Library (PPL)

LICENSE=	GPLv3

BROKEN_aarch64=	runaway build, 7200 seconds with no output

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gmpy2>0:math/py-gmpy2@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}
LIB_DEPENDS=	libgmp.so:math/gmp	\
		libmpfr.so:math/mpfr	\
		libmpc.so:math/mpc	\
		libpari.so:math/pari	\
		libppl.so:devel/ppl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gmpy2>0:math/py-gmpy2@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}
TEST_DEPENDS=	py.test:devel/py-pytest@${PY_FLAVOR}

USES=		compiler:c++11-lang localbase python:3.6+
USE_PYTHON=	cython distutils

.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

OPTIONS_DEFINE=		DOCS
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
DOCS_USES=		gmake
PORTDOCS=		*

do-build-DOCS-on:
	(cd ${WRKSRC}/docs && ${GMAKE} html)

post-build-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/build/html/* ${STAGEDIR}${DOCSDIR}

do-test: install
	(cd ${WRKSRC} && py.test)

.include <bsd.port.mk>
