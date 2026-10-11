PORTNAME=	google-ai-generativelanguage
DISTVERSION=	0.12.1
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Google's Python Client for Generative Language API
WWW=		https://github.com/googleapis/google-cloud-python/tree/main/packages/google-ai-generativelanguage

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-core>=2.28.0:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=2.14.1:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio>=1.59.0:devel/py-grpcio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}proto-plus>=1.26.1:devel/py-proto-plus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=6.33.5:devel/py-protobuf@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

TEST_ARGS=	--disable-plugin-autoload \
		-p asyncio

NO_ARCH=	yes

# tests as of 0.12.1: 7176 passed, 783 warnings in 10.71s

.include <bsd.port.mk>
