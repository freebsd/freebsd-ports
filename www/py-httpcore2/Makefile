PORTNAME=	httpcore2
PORTVERSION=	2.4.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Minimal low-level HTTP client
WWW=		https://github.com/pydantic/httpx2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-fancy-pypi-readme>0:devel/py-hatch-fancy-pypi-readme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uv-dynamic-versioning>=0.8.0:devel/py-uv-dynamic-versioning@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h11>=0.16:net/py-h11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}truststore>=0.10:security/py-truststore@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=		ASYNCIO HTTP2 SOCKS TRIO
OPTIONS_DEFAULT=	ASYNCIO HTTP2

ASYNCIO_DESC=		Asynchronous support via anyio
HTTP2_DESC=		HTTP/2 support
TRIO_DESC=		Asynchronous support via trio

ASYNCIO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=4.5.0<5.0:devel/py-anyio@${PY_FLAVOR}
HTTP2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h2>=3<5:www/py-h2@${PY_FLAVOR}
SOCKS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}socksio>=1<2:net/py-socksio@${PY_FLAVOR}
TRIO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}trio>=0.22.0<1.0:net/py-trio@${PY_FLAVOR}

.include <bsd.port.mk>
