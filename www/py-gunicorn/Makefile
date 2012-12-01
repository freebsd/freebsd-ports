# Created by: Kristaps Kulis <kristaps.kulis@gmail.com>
# $FreeBSD$

PORTNAME=	gunicorn
PORTVERSION=	0.16.1
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	Python WSGI server for unix

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	benoitc
GH_TAGNAME=	0.16.1
GH_COMMIT=	0d91a51

# Python3 Ready
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

OPTIONS_DEFINE=	EVENTLET GEVENT TORNADO SETPROC TESTS
EVENTLET_DESC=	Add Eventlet async worker
GEVENT_DESC=	Add Gevent async worker
TORNADO_DESC=	Add Tornado async worker
SETPROC_DESC=	Support changing process title (setproctitle)
TESTS_DESC=	Install tools for running unittests

OPTIONSFILE?=		${PORT_DBDIR}/py-${PORTNAME}/options
NO_OPTIONS_SORT=	yes

.include <bsd.port.pre.mk>

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
BUILD_DEPENDS:=	${TEST_DEPENDS} \
		${RUN_DEPENDS}
.endif

TEST_DEPENDS:=	${PYTHON_PKGNAMEPREFIX}pytest>0:${PORTSDIR}/devel/py-pytest

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.if ${PYTHON_REL} >= 320
.include "${PORTSDIR}/devel/py-virtualenv/files/py3k-fix-pkg-plist.inc"
.endif

.include <bsd.port.post.mk>
