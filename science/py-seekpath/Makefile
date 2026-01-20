PORTNAME=	seekpath
DISTVERSION=	2.2.0
CATEGORIES=	science # chemistry
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Obtain, visualize k-vector coefficients in crystal Brillouin zone
WWW=		https://github.com/giovannipizzi/seekpath

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}spglib>=1.14.1:science/py-spglib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

# tests as of 2.2.0: 1 failed, 15 passed, 4 warnings, 19 errors in 2.00s

.include <bsd.port.mk>
