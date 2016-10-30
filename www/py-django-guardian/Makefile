# $FreeBSD$

PORTNAME=	django-guardian
PORTVERSION=	1.4.6
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Implementation of per object permissions for Django

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six

NO_ARCH=	yes
USES=		python:2.7+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
