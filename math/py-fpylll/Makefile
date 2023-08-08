PORTNAME=	fpylll
PORTVERSION=	0.5.9
PORTREVISION=	1
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python interface for fplll
WWW=		https://github.com/fplll/fpylll

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYNUMPY}	\
		cython:lang/cython	\
		${PYTHON_PKGNAMEPREFIX}black>0:devel/py-black@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}pythran>0:devel/py-pythran@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}
LIB_DEPENDS=	libfplll.so:math/fplll	\
		libgmp.so:math/gmp	\
		libmpfr.so:math/mpfr	\
		libpari.so:math/pari	\
		libqd.so:math/qd
RUN_DEPENDS=	${PYNUMPY}	\
		${PYTHON_PKGNAMEPREFIX}black>0:devel/py-black@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}pythran>0:devel/py-pythran@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}
TEST_DEPENDS=	py.test:devel/py-pytest@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	fplll

USES=		compiler:c++11-lang python
USE_PYTHON=	distutils
.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

OPTIONS_DEFINE=		TUTO
TUTO_DESC=		Build the tutorial
OPTIONS_SUB=		Yes
TUTO_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.6,1:textproc/py-sphinx@${PY_FLAVOR}
TUTO_USES=		gmake

PLIST_SUB=	VER=${PORTVERSION:R}

do-build-TUTO-on:
	(cd ${WRKSRC}/docs && ${GMAKE} html)

post-build-TUTO-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/_build/html/* ${STAGEDIR}${DOCSDIR}

do-test: install
	(cd ${WRKSRC} && PY_IGNORE_IMPORTMISMATCH=1 py.test)

.include <bsd.port.mk>
