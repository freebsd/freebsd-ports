# New ports collection makefile for:	py-gunicorn
# Date created:		2010-03-03
# Whom:	Kristaps Kulis <kristaps.kulis@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gunicorn
PORTVERSION=	0.14.5
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	Python WSGI server for unix

USE_PYTHON=	2.5-2.7
USE_PYDISTUTILS=	easy_install

OPTIONS_DEFINE= EVENTLET GEVENT SETPROC
EVENTLET_DESC=  Add Eventlet asynchronous worker
GEVENT_DESC=    Add Gevent asynchronous worker
SETPROC_DESC=   Change process name support

OPTIONSFILE?=   ${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEVENTLET}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}eventlet>=0.9:${PORTSDIR}/net/py-eventlet
.endif

.if ${PORT_OPTIONS:MGEVENT}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gevent/__init__.py:${PORTSDIR}/devel/py-gevent
.endif

.if ${PORT_OPTIONS:MSETPROC}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/setproctitle.so:${PORTSDIR}/devel/py-setproctitle
.endif

.include <bsd.port.mk>
