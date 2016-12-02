# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	toronado
PORTVERSION=	0.0.11
CATEGORIES=	textproc www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Fast lxml-based CSS stylesheet inliner

RUN_DEPENDS:=	${PYTHON_PKGNAMEPREFIX}cssselect>=0:www/py-cssselect \
		${PYTHON_PKGNAMEPREFIX}cssutils>=0:www/py-cssutils \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
