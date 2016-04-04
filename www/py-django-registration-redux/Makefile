# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	django-registration-redux
PORTVERSION=	1.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	User-registration application for Django

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django18>=1.4:www/py-django18

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

CONFLICTS_INSTALL=	pootle-* py-django-registration

.include <bsd.port.mk>
