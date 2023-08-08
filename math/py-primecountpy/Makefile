PORTNAME=	primecountpy
PORTVERSION=	0.1.0
PORTREVISION=	4
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
USE_PYTHON=	cython distutils
.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

PYDEPS=	${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}

.include <bsd.port.mk>
