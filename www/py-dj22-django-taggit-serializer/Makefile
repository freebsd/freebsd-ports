# $FreeBSD$

PORTNAME=	django-taggit-serializer
DISTVERSION=	0.1.7
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj22-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Django Taggit serializer for the Django REST Framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Obsolete, please use www/py-django-taggit-serializer instead

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj22-django-taggit>=0:www/py-dj22-django-taggit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist

NO_ARCH=		yes
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-taggit-serializer \
			${PYTHON_PKGNAMEPREFIX}dj21-django-taggit-serializer

.include <bsd.port.mk>
