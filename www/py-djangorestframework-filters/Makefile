PORTNAME=	djangorestframework-filters
PORTVERSION=	0.10.2
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alfred@FreeBSD.org
COMMENT=	Filtering extension to Django REST Framework
WWW=		https://github.com/philipn/django-rest-framework-filters

LICENSE=	BSD2CLAUSE

DEPRECATED=	Incompatible with Django 3.0+, inactive upstream
EXPIRATION_DATE=2026-11-30
BROKEN=		imports django.utils.six, removed in Django 3.0

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
