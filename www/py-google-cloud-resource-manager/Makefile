PORTNAME=	google-cloud-resource-manager
DISTVERSION=	1.19.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Google Cloud Resource Manager API client library
WWW=		https://github.com/googleapis/google-cloud-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-core>=2.28.0:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=2.14.1:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpc-google-iam-v1>=0.14.2:devel/py-grpc-google-iam-v1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio>=1.59.0:devel/py-grpcio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}proto-plus>=1.26.1:devel/py-proto-plus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=6.33.5:devel/py-protobuf@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

TEST_ARGS=	--disable-plugin-autoload

# tests as of 1.19.0: 403 failed, 1779 passed, 554 warnings in 4.50s

.include <bsd.port.mk>
