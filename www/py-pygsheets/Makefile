PORTNAME=	pygsheets
PORTVERSION=	2.0.6
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Spreadsheets Python API v4
WWW=		https://github.com/nithinmurali/pygsheets

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-python-client>=2.50.0:www/py-google-api-python-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth-oauthlib>=0.7.1:security/py-google-auth-oauthlib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
