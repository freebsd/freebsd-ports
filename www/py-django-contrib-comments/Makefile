# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	django-contrib-comments
PORTVERSION=	2.2.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Code formerly known as django.contrib.comments

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# Supports all Django version. Bump when DEFAULT Django is changed
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=2.2:www/py-django22@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${SETENV} TZ=UTC ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
