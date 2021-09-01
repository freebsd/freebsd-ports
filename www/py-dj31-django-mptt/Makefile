# Created by: Carlo Strub

PORTNAME=	django-mptt
PORTVERSION=	0.13.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj31-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Utilities for implementing Modified Preorder Tree Traversal in Django

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django31>=2.2:www/py-django31@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}dj31-django-js-asset>0:www/py-dj31-django-js-asset@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=		yes
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-happenings \
			${PYTHON_PKGNAMEPREFIX}django-mptt \
			${PYTHON_PKGNAMEPREFIX}dj32-django-mptt

.include <bsd.port.mk>
