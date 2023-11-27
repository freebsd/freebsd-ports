PORTNAME=	httpcore
PORTVERSION=	1.0.2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Minimal low-level HTTP client
WWW=		https://www.encode.io/httpcore/ \
		https://github.com/encode/httpcore

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-fancy-pypi-readme>=0:devel/py-hatch-fancy-pypi-readme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h11>=0.13<0.15:net/py-h11@${PY_FLAVOR} \

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ASYNCIO HTTP2 SOCKS
OPTIONS_DEFAULT=ASYNCIO HTTP2
ASYNCIO_DESC=	Asynchronous support via anyio
HTTP2_DESC=	HTTP/2 support

ASYNCIO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=4.0<5.0:devel/py-anyio@${PY_FLAVOR}
HTTP2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h2>=3<5:www/py-h2@${PY_FLAVOR}
SOCKS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}socksio>=1<2:net/py-socksio@${PY_FLAVOR}

.include <bsd.port.mk>
