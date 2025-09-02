PORTNAME=	google-cloud-storage
PORTVERSION=	3.2.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	google_cloud_storage-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Client for Google Cloud Storage
WWW=		https://github.com/googleapis/python-storage

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-core>=2.15.0<3.0.0:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=2.26.1<3.0.0:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-core>=2.4.2<3.0.0:www/py-google-cloud-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-crc32c>=1.1.3<2.0.0:devel/py-google-crc32c@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-resumable-media>=2.7.2<3.0.0:www/py-google-resumable-media@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.22.0<3.0.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	PROTOBUF TRACING
OPTIONS_DEFINE=	PROTOBUF
PROTOBUF_DESC=	Protocol buffers support
TRACING_DESC=	Generate traces using OpenTelemetry

PROTOBUF_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>=3.20.2,1<7.0.0,1:devel/py-protobuf@${PY_FLAVOR}
TRACING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.1.0<2.0.0:devel/py-opentelemetry-api@${PY_FLAVOR}

.include <bsd.port.mk>
