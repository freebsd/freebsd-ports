PORTNAME=	sphinxext-opengraph
PORTVERSION=	0.6.3
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexis.praga@free.fr
COMMENT=	Sphinx extension to generate OpenGraph metadata

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=2.0:textproc/py-sphinx@${PY_FLAVOR}

USES=		python:3.6+
# LICENSE and tests are not packaged yet, using github as a fallback
USE_GITHUB=	yes
GH_ACCOUNT=	wpilibsuite
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	cd ${WRKSRC}/ && ${PYTHON_CMD} -m pytest -v -rs -o addopts=

.include <bsd.port.mk>
