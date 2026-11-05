PORTNAME=	iso3166
DISTVERSION=	3.0.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	takefu@airport.fm
COMMENT=	Standalone ISO 3166-1 country definitions
WWW=		https://pypi.python.org/pypi/iso3166

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0.12.5:devel/py-uv-build@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest
TEST_ENV=	PYTHONPATH=${WRKSRC}/src
NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs -o addopts=

.include <bsd.port.mk>
