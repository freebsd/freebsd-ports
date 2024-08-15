PORTNAME=	aiohttp-session
DISTVERSION=	2.11.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Web sessions for aiohttp web
WWW=		https://github.com/aio-libs/aiohttp-session

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aioredis>0:databases/py-aioredis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiomcache>0:databases/py-aiomcache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>0:security/py-pycryptodome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}secure>0:security/py-secure@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>0:security/py-pynacl@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	${PORTNAME}_project
USE_PYTHON=	autoplist distutils cython

NO_ARCH=	yes

.include <bsd.port.mk>
