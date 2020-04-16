# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	django-happenings
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Event calendar app for Django

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Doesn't work with Django 2.2+, please use www/py-django-happenings-update instead
EXPIRATION_DATE=	2020-05-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>=0:www/py-django111@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}

CONFLICTS_INSTALL= ${PYTHON_PKGNAMEPREFIX}-django-mptt \
		   ${PYTHON_PKGNAMEPREFIX}-django-happenings-update

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
