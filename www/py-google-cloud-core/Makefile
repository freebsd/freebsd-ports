PORTNAME=	google-cloud-core
PORTVERSION=	1.7.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	API Client library for Google Cloud: Core Helpers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-core>=1.21.0<2.0:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=1.24.0<2.0.0:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.12.0:devel/py-six@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
