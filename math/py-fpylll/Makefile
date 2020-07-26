# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	fpylll
DISTVERSION=	0.5.2dev
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
		libpari.so:math/pari
RUN_DEPENDS=	${PYNUMPY}	\
		${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}
TEST_DEPENDS=	py.test:devel/py-pytest@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	fplll

USES=		compiler:c++11-lang python:3.6+
USE_PYTHON=	distutils

OPTIONS_DEFINE=		DOCS
DOCS_BUILD_DEPENDS=	${PY_SPHINX}
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
