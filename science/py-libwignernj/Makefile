PORTNAME=	wignernj
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for libwignernj
WWW=		https://github.com/susilehtola/libwignernj

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	susilehtola
GH_PROJECT=	libwignernj

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests/python

# tests as of 0.8.0: 58 passed in 0.45s

.include <bsd.port.mk>
