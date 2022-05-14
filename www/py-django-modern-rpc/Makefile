# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	django-modern-rpc
PORTVERSION=	0.12.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple and modern JSON-RPC/XML-RPC server implementation for Django

LICENSE=	MIT

DEPRECATED=	Not compatible with newer versions of Django
EXPIRATION_DATE=	2022-06-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=1.8.0:www/py-django22@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
