# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	rekall_gui
DISTVERSION=	1.5.0.post4
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	GUI component of the Rekall framework

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rekall-core>=1.5.0.p:security/py-rekall-core \
		${PYTHON_PKGNAMEPREFIX}codegen>=1.0:devel/py-codegen \
		${PYTHON_PKGNAMEPREFIX}Flask>=0.10.1:www/py-flask \
		${PYTHON_PKGNAMEPREFIX}Flask-Sockets>=0:www/py-flask-sockets \
		${PYTHON_PKGNAMEPREFIX}gevent>=1.0.2:devel/py-gevent \
		${PYTHON_PKGNAMEPREFIX}gevent-websocket>=0.9.3:www/py-gevent-websocket

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS+=--install-data ${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.post.mk>
