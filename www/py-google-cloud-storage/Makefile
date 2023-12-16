PORTNAME=	google-cloud-storage
PORTVERSION=	2.14.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Client for Google Cloud Storage
WWW=		https://github.com/googleapis/python-storage

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-core>=2.3.1<3.0:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=2.23.3<3.0:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-core>=2.3.0<3.0:www/py-google-cloud-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-crc32c>=1.0<2.0:devel/py-google-crc32c@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-resumable-media>=2.6.0:www/py-google-resumable-media@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.18.0<3.0.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	PROTOBUF
OPTIONS_DEFINE=	PROTOBUF
PROTOBUF_DESC=	Protocol buffers support

PROTOBUF_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>=0,1<5.0.0,1:devel/py-protobuf@${PY_FLAVOR}

.include <bsd.port.mk>
