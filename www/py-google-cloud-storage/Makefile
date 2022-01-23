PORTNAME=	google-cloud-storage
PORTVERSION=	1.44.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Client for Google Cloud Storage

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-core>=1.29.0<3.0:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=1.25.0<3.0:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-core>=1.6.0<3.0:www/py-google-cloud-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-resumable-media>=1.3.0<3.0:www/py-google-resumable-media@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=0,1:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.18.0<3.0.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
