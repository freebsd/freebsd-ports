PORTNAME=	pplpy
PORTVERSION=	0.8.10
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python wrapper to the C++ Parma Polyhedra Library (PPL)
WWW=		https://www.labri.fr/perso/vdelecro/pplpy/latest/

LICENSE=	GPLv3

BROKEN_aarch64=	runaway build, 7200 seconds with no output

BUILD_DEPENDS=	${PY_SETUPTOOLS}	\
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}gmpy2>0:math/py-gmpy2@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}
LIB_DEPENDS=	libgmp.so:math/gmp	\
		libmpfr.so:math/mpfr	\
		libmpc.so:math/mpc	\
		libpari.so:math/pari	\
		libppl.so:devel/ppl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gmpy2>0:math/py-gmpy2@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}
TEST_DEPENDS=	py.test:devel/py-pytest@${PY_FLAVOR}

USES=		compiler:c++14-lang localbase python
USE_PYTHON=	cython3 pep517

CFLAGS+=	-std=c++14

.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

do-test: install
	(cd ${WRKSRC} && py.test)

.include <bsd.port.mk>
