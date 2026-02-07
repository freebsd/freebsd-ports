PORTNAME=	pynrrd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.3
CATEGORIES=	science python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pure Python module for reading and writing NRRD files
WWW=		https://pynrrd.readthedocs.io/en/stable/ \
		https://github.com/mhe/pynrrd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	mhe

NO_ARCH=	yes

# tests as of 1.1.3: 159 passed in 3.03s

.include <bsd.port.mk>
