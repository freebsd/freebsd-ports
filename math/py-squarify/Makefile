PORTNAME=	squarify
DISTVERSION=	0.4.5
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Squarify treemap layout algorithm
WWW=		https://github.com/laserson/squarify

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes
TEST_ARGS=	--disable-plugin-autoload

# tests as of 0.4.5: 1 passed in 0.01s

.include <bsd.port.mk>
