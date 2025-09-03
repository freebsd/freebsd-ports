PORTNAME=	gunicorn
DISTVERSION=	23.0.0
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	WSGI HTTP Server for UNIX
WWW=		https://gunicorn.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.4.0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>0:www/py-aiohttp@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517 pytest
USE_RC_SUBR=	gunicorn

NO_ARCH=	yes
SUB_LIST=	USERS="${USERS}" GROUPS="${GROUPS}"

USERS=		gunicorn
GROUPS=		gunicorn

OPTIONS_DEFINE=		PROCTITLE
OPTIONS_DEFAULT=	PROCTITLE
OPTIONS_GROUP=		WORKERS
OPTIONS_GROUP_WORKERS=	EVENTLET GEVENT TORNADO

EVENTLET_DESC=	Eventlet async worker
GEVENT_DESC=	Greenlet worker
PROCTITLE_DESC=	Custom process titles with setproctitle(3)
TORNADO_DESC=	Tornado async worker

EVENTLET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}eventlet>=0.24.1:net/py-eventlet@${PY_FLAVOR}
GEVENT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gevent>=1.4.0:devel/py-gevent@${PY_FLAVOR}
PROCTITLE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setproctitle>0:devel/py-setproctitle@${PY_FLAVOR}
TORNADO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tornado>=0.2:www/py-tornado@${PY_FLAVOR}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/examples/example_config.py \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}/gunicorn.conf.py.sample
	@${ECHO} "@sample etc/gunicorn/gunicorn.conf.py.sample" >> ${TMPPLIST}

.include <bsd.port.mk>
