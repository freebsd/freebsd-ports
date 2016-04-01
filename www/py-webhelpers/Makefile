# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	webhelpers
PORTVERSION=	1.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	WebHelpers-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Python helper functions for writing templates in web applications

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}routes>=1.1:www/py-routes \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.11:textproc/py-MarkupSafe

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
