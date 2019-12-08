# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jsonfield2
PORTVERSION=	3.1.0
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj22-django-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Reusable Django field to store validated JSON in your model

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=2.2:www/py-django22@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

GH_ACCOUNT=	rpkilby
USE_GITHUB=	yes

.include <bsd.port.mk>
