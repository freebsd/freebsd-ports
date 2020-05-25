# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	recaptcha
PORTVERSION=	2.0.6
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}django-

MAINTAINER=	python@FreeBSD.org
COMMENT=	Django reCAPTCHA form field/widget integration app

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=1.11<4.0:www/py-django22@${PY_FLAVOR}

USES=		python:3.5+
USE_GITHUB=	yes
GH_ACCOUNT=	praekelt
GH_PROJECT=	django-recaptcha
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
