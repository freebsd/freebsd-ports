# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	webhelpers
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	WebHelpers-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Python helper functions for writing templates in web applications

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}routes>=1.1:www/py-routes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.11:textproc/py-MarkupSafe@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
