# Created by: Christer Edwards <christer.edwards@gmail.com>
# $FreeBSD$

PORTNAME=	halite
PORTVERSION=	0.1.17
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	SaltStack Web UI

LICENSE=	APACHE20

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}salt>=0.17.0:sysutils/py-salt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cherrypy>0:www/py-cherrypy@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
