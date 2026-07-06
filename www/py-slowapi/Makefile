PORTNAME=	slowapi
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.10
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rate limiting extension for Starlette and Fastapi
WWW=		https://github.com/laurents/slowapi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}limits>=2.3:www/py-limits@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette>0:www/py-starlette@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastapi>=0.89.0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.23.3:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=4.0.1:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.22.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	laurents
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

# tests as of 0.1.10: 2 passed, 2 errors in 3.77s (collection errors due to missing devel/py-hiro)

.include <bsd.port.mk>
