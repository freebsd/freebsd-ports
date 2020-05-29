# Created by: Alfred Perlstein <alfred@freebsd.org>
# $FreeBSD$

PORTNAME=	djangorestframework
PORTVERSION=	3.6.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	36

MAINTAINER=	alfred@FreeBSD.org
COMMENT=	Django REST framework

LICENSE=	BSD2CLAUSE

DEPRECATED=	Not compatible with Django 2.0+, please use www/py-djangorestframework instead
EXPIRATION_DATE=	2020-06-15

USES=		python
USE_PYTHON=	distutils autoplist

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}djangorestframework \
			${PYTHON_PKGNAMEPREFIX}dj21-djangorestframework

.include <bsd.port.mk>
