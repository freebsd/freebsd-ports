# $FreeBSD$

PORTNAME=	django-common-helpers
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Common things every Django app needs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=1.8:www/py-django22@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
