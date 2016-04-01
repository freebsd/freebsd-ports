# Created by: Christer Edwards <christer.edwards@gmail.com>
# $FreeBSD$

PORTNAME=	halite
PORTVERSION=	0.1.15
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	SaltStack Web UI

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}salt>=0.17.0:sysutils/py-salt \
		${PYTHON_PKGNAMEPREFIX}cherrypy>0:www/py-cherrypy

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
