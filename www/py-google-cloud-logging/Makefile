PORTNAME=	google-cloud-logging
PORTVERSION=	3.9.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Stackdriver Logging API client library
WWW=		https://github.com/googleapis/python-logging

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-core>=2.8.0<3.0.0:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-appengine-logging>=0.1.0<2.0.0:www/py-google-cloud-appengine-logging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-audit-log>=0.1.0<1.0.0:www/py-google-cloud-audit-log@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-core>=2.0.0<3.0.0:www/py-google-cloud-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpc-google-iam-v1>=0.12.4<1.0.0:devel/py-grpc-google-iam-v1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}proto-plus>=1.22.2<2.0.0:devel/py-proto-plus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=4.21.6,1<5.0.0,1:devel/py-protobuf@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
