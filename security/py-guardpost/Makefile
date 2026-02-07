PORTNAME=	guardpost
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.3
CATEGORIES=	security python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework to handle authentication and authorization
WWW=		https://github.com/Neoteroi/GuardPost

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rodi>=2.0.0:devel/py-rodi@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>0:www/py-pyjwt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	Neoteroi
GH_PROJECT=	GuardPost

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 1.0.3: 101 passed, 1 failed (test_jwt_validator_fetches_tokens_again_for_unknown_kid) in 11.37s

.include <bsd.port.mk>
