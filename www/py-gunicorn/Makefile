# Created by: Kristaps Kulis <kristaps.kulis@gmail.com>
# $FreeBSD$

PORTNAME=	gunicorn
PORTVERSION=	0.15.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	Python WSGI server for unix

LICENSE=	MIT

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:${PORTSDIR}/devel/py-nose

USE_PYTHON=		-2.7
USE_PYDISTUTILS=	easy_install

OPTIONS_DEFINE=	EVENTLET GEVENT TORNADO SETPROC TESTS
EVENTLET_DESC=	Add Eventlet async worker
GEVENT_DESC=	Add Gevent async worker
TORNADO_DESC=	Add Tornado async worker
SETPROC_DESC=	Support changing process title (setproctitle)
TESTS_DESC=	Install nose for running unittests

OPTIONSFILE=		${PORT_DBDIR}/py-${PORTNAME}/options
NO_OPTIONS_SORT=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEVENTLET}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}eventlet>=0.9:${PORTSDIR}/net/py-eventlet
.endif

.if ${PORT_OPTIONS:MGEVENT}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gevent>0:${PORTSDIR}/devel/py-gevent
.endif

.if ${PORT_OPTIONS:MTORNADO}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tornado>=2.2:${PORTSDIR}/www/py-tornado
.endif

.if ${PORT_OPTIONS:MSETPROC}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}setproctitle>0:${PORTSDIR}/devel/py-setproctitle
.endif

.if ${PORT_OPTIONS:MTESTS}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}nose>0:${PORTSDIR}/devel/py-nose
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} nosetests

.include <bsd.port.mk>
