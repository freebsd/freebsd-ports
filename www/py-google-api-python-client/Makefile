# $FreeBSD$

PORTNAME=	google-api-python-client
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Google API Client Library for Python

LICENSE=	APACHE20

#BUILD_DEPENDS=	${PKGNAMEPREFIX}oauth2client>=1.4.6:security/py-oauth2client
RUN_DEPENDS=	${PKGNAMEPREFIX}httplib2>=0.8:www/py-httplib2 \
		${PKGNAMEPREFIX}oauth2client>=1.4.6:security/py-oauth2client \
		${PYTHON_PKGNAMEPREFIX}six>=1.6.1:devel/py-six \
		${PKGNAMEPREFIX}uritemplate>=0.6:net/py-uritemplate

DJANGO_DESC=	Use the library with Django
DJANGO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django18>=1.3:www/py-django18

GAE_DESC=	Use the library with Google App Engine
GAE_RUN_DEPENDS=	google-appengine>=1.4.3:www/google-appengine

OPTIONS_DEFINE=	DJANGO GAE WEBTEST

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

WEBTEST_DESC=	Use WebTest helper to test WSGI apps
WEBTEST_RUN_DEPENDS=	${PKGNAMEPREFIX}WebTest>=1.3.3:www/py-WebTest \
			${PKGNAMEPREFIX}openssl>=0.13:security/py-openssl

.include <bsd.port.mk>
