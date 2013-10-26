# Created by: Kristaps Kulis <kristaps.kulis@gmail.com>
# $FreeBSD$

PORTNAME=	gunicorn
PORTVERSION=	18.0
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python WSGI server for UNIX

LICENSE=	MIT

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:${PORTSDIR}/devel/py-pytest

USE_GITHUB=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes

GH_ACCOUNT=	benoitc
GH_COMMIT=	24fe380

OPTIONS_DEFINE=	EVENTLET GEVENT TORNADO SETPROC TESTS
EVENTLET_DESC=	Add Eventlet async worker
GEVENT_DESC=	Add Gevent async worker
TORNADO_DESC=	Add Tornado async worker
SETPROC_DESC=	Support changing process title (setproctitle)
TESTS_DESC=	Install pytest for unit tests

OPTIONSFILE?=		${PORT_DBDIR}/py-${PORTNAME}/options
NO_OPTIONS_SORT=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEVENTLET}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}eventlet>=0.9.7:${PORTSDIR}/net/py-eventlet
.endif

.if ${PORT_OPTIONS:MGEVENT}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gevent>=0.12.2:${PORTSDIR}/devel/py-gevent
.endif

.if ${PORT_OPTIONS:MTORNADO}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tornado>=2.2:${PORTSDIR}/www/py-tornado
.endif

.if ${PORT_OPTIONS:MSETPROC}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}setproctitle>0:${PORTSDIR}/devel/py-setproctitle
.endif

.if ${PORT_OPTIONS:MTESTS}
RUN_DEPENDS+=	${TEST_DEPENDS}
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
