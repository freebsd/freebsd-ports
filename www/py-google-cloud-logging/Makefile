PORTNAME=	google-cloud-logging
PORTVERSION=	3.12.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	google_cloud_logging-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Stackdriver Logging API client library
WWW=		https://github.com/googleapis/python-logging

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-core>=2.11.0<3.0.0:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=2.14.1<3.0.0:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-appengine-logging>=0.1.3<2.0.0:www/py-google-cloud-appengine-logging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-audit-log>=0.3.1<1.0.0:www/py-google-cloud-audit-log@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-core>=2.0.0<3.0.0:www/py-google-cloud-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpc-google-iam-v1>=0.12.4<1.0.0:devel/py-grpc-google-iam-v1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.9.0:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}proto-plus>=1.25.0<2.0.0:devel/py-proto-plus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=4.21.6,1<7.0.0,1:devel/py-protobuf@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
