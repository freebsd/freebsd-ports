PORTNAME=	unyt
DISTVERSION=	2.9.5
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for handling numpy arrays with units
WWW=		https://github.com/yt-project/unyt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.5:math/py-sympy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/unyt/tests

.include <bsd.port.mk>
