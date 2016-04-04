# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tvnamer
PORTVERSION=	2.3
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Automatically names downloaded/recorded TV-episode

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tvdb_api>=1.5:www/py-tvdb_api
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tvdb_api>=1.5:www/py-tvdb_api

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
