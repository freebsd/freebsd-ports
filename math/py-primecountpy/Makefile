PORTNAME=	primecountpy
PORTVERSION=	0.1.0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Primecount Cython interface

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYDEPS}
LIB_DEPENDS=	libpari.so:math/pari			\
		libprimecount.so:math/primecount	\
		libprimesieve.so:math/primesieve
RUN_DEPENDS=	${PYDEPS}

USES=		localbase python:3.7+
USE_PYTHON=	cython distutils

PYDEPS=	${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}

.include <bsd.port.mk>
