# $FreeBSD$

PORTNAME=	djangorestframework
PORTVERSION=	3.11.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj22-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Django REST framework

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

DEPRECATED=	Obsolete, please use www/py-djangorestframework instead

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=1.11:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}djangorestframework \
			${PYTHON_PKGNAMEPREFIX}djangorestframework3*

.include <bsd.port.mk>
