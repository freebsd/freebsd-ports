PORTNAME=	sphinxext-opengraph
PORTVERSION=	0.8.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexis.praga@free.fr
COMMENT=	Sphinx extension to generate OpenGraph metadata
WWW=		https://pypi.org/project/sphinxext-opengraph

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=2.0:textproc/py-sphinx@${PY_FLAVOR}

USES=		python
# LICENSE and tests are not packaged yet, using github as a fallback
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	cd ${WRKSRC}/ && ${PYTHON_CMD} -m pytest -v -rs -o addopts=

.include <bsd.port.mk>
