# $FreeBSD$

PORTNAME=	django_csp
PORTVERSION=	3.5
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX= ${PYTHON_PKGNAMEPREFIX}dj22-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adds Content-Security-Policy headers to Django

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=1.8:www/py-django22@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
