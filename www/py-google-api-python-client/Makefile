PORTNAME=	google-api-python-client
PORTVERSION=	1.7.6
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Google API Client Library for Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httplib2>=0.9.2:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=0:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth-httplib2>=0.0.3:security/py-google-auth-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.6.1:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uritemplate>=3.0.0:net/py-uritemplate@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	DJANGO WEBTEST
DJANGO_DESC=		Use the library with Django
DJANGO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=1.3:www/py-django22@${PY_FLAVOR}
WEBTEST_DESC=		Use WebTest helper to test WSGI apps
WEBTEST_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}WebTest>=1.3.3:www/py-WebTest@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}openssl>=0.13:security/py-openssl@${PY_FLAVOR}

.include <bsd.port.mk>
