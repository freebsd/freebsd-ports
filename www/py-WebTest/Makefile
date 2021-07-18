# Created by: Wen Heping

PORTNAME=	WebTest
PORTVERSION=	2.0.32
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Helper to test WSGI applications

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}waitress>0:www/py-waitress@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2:www/py-webob@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}waitress>0:www/py-waitress@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2:www/py-webob@${PY_FLAVOR}

USE_GITHUB=	yes

GH_ACCOUNT=	Pylons
GH_PROJECT=	webtest
USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
