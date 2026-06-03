PORTNAME=	fal-client
DISTVERSION=	1.0.0
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	fal_client-${DISTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Python client for fal.ai inference API
WWW=		https://github.com/fal-ai/fal/tree/main/projects/fal_client

LICENSE=	APACHE20

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=7:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiofiles>=23.2.1:devel/py-aiofiles@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asyncstdlib>=3.12.5<4:devel/py-asyncstdlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.21.0<1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx-sse>=0.4.0<0.5:www/py-httpx-sse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=1.0.7<2:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=12.0:devel/py-websockets@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}

NO_ARCH=	yes

.include <bsd.port.mk>
