# Created by: Tom Judge <tj@FreeBSD.org>

PORTNAME=	django-sudo
PORTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Sudo mode is an extra layer of security for Django

LICENSE=	BSD3CLAUSE

DEPRECATED=	Abandoned upstream, not compatible with newer versions of Django
EXPIRATION_DATE=	2022-06-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=0:www/py-django22@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
