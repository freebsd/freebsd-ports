PORTNAME=	essentials-openapi
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
CATEGORIES=	www python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Classes to generate OpenAPI Documentation v3 and v2
WWW=		https://github.com/Neoteroi/essentials-openapi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}essentials>=1.1.5:devel/py-essentials@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=3.0.0:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6:devel/py-pyyaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest
USE_GITHUB=	yes
GH_ACCOUNT=	Neoteroi

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 1.2.1: 157 passed in 8.00s

.include <bsd.port.mk>
