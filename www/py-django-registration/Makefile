# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	django-registration
PORTVERSION=	2.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	User-registration application for Django

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django18>=1.4:www/py-django18@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

CONFLICTS_INSTALL=	pootle-[0-9]* py??-django-registration-redux-[0-9]*

.include <bsd.port.mk>
