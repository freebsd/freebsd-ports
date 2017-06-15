# Created by: Wen Heping
# $FreeBSD$

PORTNAME=	WebTest
PORTVERSION=	2.0.23
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Helper to test WSGI applications

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4:www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}waitress>0:www/py-waitress \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2:www/py-webob
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4:www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}waitress>0:www/py-waitress \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2:www/py-webob

USE_GITHUB=	yes

GH_ACCOUNT=	Pylons
GH_PROJECT=	webtest
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
