# Created by: thierry@pompo.net

PORTNAME=	fpylll
PORTVERSION=	0.5.6
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python interface for fplll

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYNUMPY}	\
		cython:lang/cython	\
		${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}
LIB_DEPENDS=	libfplll.so:math/fplll	\
		libgmp.so:math/gmp	\
		libmpfr.so:math/mpfr	\
		libpari.so:math/pari	\
		libqd.so:math/qd
RUN_DEPENDS=	${PYNUMPY}	\
		${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}
TEST_DEPENDS=	py.test:devel/py-pytest@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	fplll

USES=		compiler:c++11-lang python:3.6+
USE_PYTHON=	distutils
.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

OPTIONS_DEFINE=		DOCS
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.6,1:textproc/py-sphinx@${PY_FLAVOR}
DOCS_USES=		gmake
PORTDOCS=		*

PLIST_SUB=	VER=${PORTVERSION:R}

do-build-DOCS-on:
	(cd ${WRKSRC}/docs && ${GMAKE} html)

post-build-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/_build/html/* ${STAGEDIR}${DOCSDIR}

do-test: install
	(cd ${WRKSRC} && PY_IGNORE_IMPORTMISMATCH=1 py.test)

.include <bsd.port.mk>
