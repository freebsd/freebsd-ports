PORTNAME=	google-cloud-appengine-logging
PORTVERSION=	1.3.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Client for Google Cloud Appengine Logging
WWW=		https://github.com/googleapis/google-cloud-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-core>=2.10.0<3.0.0:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}proto-plus>=1.22.2<2.0.0:devel/py-proto-plus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=4.21.6,1<5.0.0,1:devel/py-protobuf@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
