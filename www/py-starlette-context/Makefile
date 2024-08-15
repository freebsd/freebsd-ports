PORTNAME=	starlette-context
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.6
CATEGORIES=	www python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Starlette: store and access the context data of a request
WWW=		https://starlette-context.readthedocs.io/en/latest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}starlette>0:www/py-starlette@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}codecov>=2.1.12:devel/py-codecov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=7.0.2:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.23.2:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0.20.3:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=4.0.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-sugar>=0.9.6:devel/py-pytest-sugar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.1.0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	tomwojcik

NO_ARCH=	yes

.include <bsd.port.mk>
