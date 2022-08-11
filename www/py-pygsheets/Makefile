PORTNAME=	pygsheets
PORTVERSION=	2.0.5
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Spreadsheets Python API v4

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-python-client>=1.5.5:www/py-google-api-python-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth-oauthlib>=0:security/py-google-auth-oauthlib@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
