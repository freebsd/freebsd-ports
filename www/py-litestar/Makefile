PORTNAME=	litestar
DISTVERSION=	2.18.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Production-ready, highly performant, extensible ASGI API Framework
WWW=		https://litestar.dev/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.22:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgspec>=0.18.2:devel/py-msgspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multidict>=6.0.2:www/py-multidict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}polyfactory>=0:devel/py-polyfactory@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multipart>=0:devel/py-multipart@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich-click>=0:devel/py-rich-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0:www/py-uvicorn@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
