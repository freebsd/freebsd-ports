# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jsonfield2
PORTVERSION=	3.0.2
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}django-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Reusable Django field to store validated JSON in your model

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>=0:www/py-django111@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

GH_ACCOUNT=	rpkilby
USE_GITHUB=	yes

.include <bsd.port.mk>
