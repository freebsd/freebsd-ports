# Created by: Kristaps Kulis <kristaps.kulis@gmail.com>
# $FreeBSD$

PORTNAME=	gunicorn
PORTVERSION=	18.0
PORTREVISION=	1
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python WSGI server for UNIX

LICENSE=	MIT

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:${PORTSDIR}/devel/py-pytest

OPTIONS_DEFINE=		SETPROC TESTS
OPTIONS_GROUP=		WORKERS
OPTIONS_GROUP_WORKERS=	EVENTLET GEVENT TORNADO

EVENTLET_DESC=	Eventlet async worker support
GEVENT_DESC=	Gevent async worker support
TORNADO_DESC=	Tornado async worker support
SETPROC_DESC=	Support custom process names (setproctitle)
TESTS_DESC=	Install pytest for unit tests

EVENTLET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}eventlet>=0.9.7:${PORTSDIR}/net/py-eventlet
GEVENT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gevent>=0.12.2:${PORTSDIR}/devel/py-gevent
TORNADO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tornado>=2.2:${PORTSDIR}/www/py-tornado
SETPROC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setproctitle>0:${PORTSDIR}/devel/py-setproctitle
TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

USE_GITHUB=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

GH_ACCOUNT=	benoitc
GH_COMMIT=	24fe380

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
