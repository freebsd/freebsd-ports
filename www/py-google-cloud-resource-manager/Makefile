PORTNAME=	google-cloud-resource-manager
DISTVERSION=	1.18.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Google Cloud Resource Manager API client library
WWW=		https://github.com/googleapis/google-cloud-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-core>=2.17.1:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=2.14.1:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpc-google-iam-v1>=0.14.0:devel/py-grpc-google-iam-v1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio>=1.59.0:devel/py-grpcio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}proto-plus>=1.22.3:devel/py-proto-plus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=4.25.8:devel/py-protobuf@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes

# tests as of 1.18.0: 1831 passed, 417 failed (environmental), 442 warnings in 5.91s

.include <bsd.port.mk>
