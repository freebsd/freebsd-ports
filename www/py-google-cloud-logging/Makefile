PORTNAME=	google-cloud-logging
PORTVERSION=	2.5.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Stackdriver Logging API client library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-core>=1.22.2<2.0.0:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-appengine-logging>=0.1.0<1.0.0:www/py-google-cloud-appengine-logging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-audit-log>=0.1.0<1.0.0:www/py-google-cloud-audit-log@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-core>=1.4.1<2.0:www/py-google-cloud-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=14.3:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}proto-plus>=1.11.0:devel/py-proto-plus@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
