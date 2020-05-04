# Created by: René Ladan <rene@freebsd.org>
# $FreeBSD$

PORTNAME=	django-contact-form
PORTVERSION=	1.8.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generic contact-form application for Django

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=2.2<3.1:www/py-django22@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} runtests.py

.include <bsd.port.mk>
