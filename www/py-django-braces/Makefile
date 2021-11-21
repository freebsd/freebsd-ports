# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	django-braces
PORTVERSION=	1.15.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Reusable, generic mixins for Django

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=2.2:www/py-django22@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
