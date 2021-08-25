PORTNAME=	django-mptt
PORTVERSION=	0.13.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj32-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Utilities for implementing Modified Preorder Tree Traversal in Django

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=2.2:www/py-django32@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}dj32-django-js-asset>0:www/py-dj32-django-js-asset@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-happenings \
			${PYTHON_PKGNAMEPREFIX}dj31-django-mptt \
			${PYTHON_PKGNAMEPREFIX}django-mptt

NO_ARCH=		yes

.include <bsd.port.mk>
