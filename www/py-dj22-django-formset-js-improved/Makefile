# $FreeBSD$

PORTNAME=	django-formset-js-improved
PORTVERSION=	0.5.0.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj22-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fork of django-formset-js that adds support for reordering and nested formsets

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=1.8:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-jquery-js>=0.:www/py-dj22-django-jquery-js@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
