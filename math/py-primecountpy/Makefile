PORTNAME=	primecountpy
PORTVERSION=	0.1.1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Primecount Cython interface
WWW=		https://pypi.org/project/primecountpy/

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYDEPS}
LIB_DEPENDS=	libpari.so:math/pari			\
		libprimecount.so:math/primecount	\
		libprimesieve.so:math/primesieve
RUN_DEPENDS=	${PYDEPS}

USES=		localbase python
USE_PYTHON=	cython3 distutils
.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

PYDEPS=	${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}

post-build:
	${FIND} ${WRKSRC} -name "*gnu.so" -delete -o -name "*313.pyc" -delete

post-stage:
	${FIND} ${STAGEDIR} -name "*.cpp" -delete -o -name "*.pyx" -delete

.include <bsd.port.mk>
