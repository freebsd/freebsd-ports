# New ports collection makefile for:	py-gunicorn
# Date created:		2010-03-03
# Whom:	Kristaps Kulis <kristaps.kulis@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gunicorn
PORTVERSION=	0.13.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kristaps.kulis@gmail.com
COMMENT=	Python WSGI server for unix

USE_PYTHON=	2.5-2.7
USE_PYDISTUTILS=	easy_install

OPTIONS=	EVENTLET "Add asynchronous worker Eventlet" off \
		GEVENT "Add asynchronous worker Gevent" off \
		SETPROC "Add support to change process name" off

.include <bsd.port.options.mk>

.if defined(WITH_EVENTLET)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}eventlet>=0.9:${PORTSDIR}/net/py-eventlet
.endif

.if defined(WITH_GEVENT)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gevent/__init__.py:${PORTSDIR}/devel/py-gevent
.endif

.if defined(WITH_SETPROC)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/setproctitle.so:${PORTSDIR}/devel/py-setproctitle
.endif

.include <bsd.port.mk>
