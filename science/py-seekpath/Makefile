PORTNAME=	seekpath
DISTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	science # chemistry
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Obtain, visualize k-vector coefficients in crystal Brillouin zone
WWW=		https://github.com/giovannipizzi/seekpath

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}spglib>=1.15.1:science/py-spglib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes

# tests as of 2.1.0:
# Results (3.57s):
#       76 passed

.include <bsd.port.mk>
