PORTNAME=	django-js-asset
DISTVERSION=	2.0.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj32-
DISTNAME=	django_js_asset-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Insert script tags with additional attributes for django.forms.Media

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>0:www/py-django32@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}dj31-django-js-asset \
			${PYTHON_PKGNAMEPREFIX}django-js-asset

NO_ARCH=		yes

.include <bsd.port.mk>
