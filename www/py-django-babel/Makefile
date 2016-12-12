# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	django-babel
PORTVERSION=	0.5.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	Utilities for using Babel in django

LICENSE=	BSD

RUN_DEPENDS=    ${PYTHON_PKGNAMEPREFIX}django18>=0:www/py-django18 \
		${PYTHON_PKGNAMEPREFIX}Babel>=0:devel/py-babel

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
