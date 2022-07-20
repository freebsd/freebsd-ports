PORTNAME=	ws4py
PORTVERSION=	0.5.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	WebSocket package for Python

LICENSE=	BSD3CLAUSE

DEPRECATED=	Upstream abandoned
EXPIRATION_DATE=	2022-09-30

USES=		python:3.6-3.9
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=		CHERRYPY GEVENT TORNADO
OPTIONS_DEFAULT=	CHERRYPY GEVENT
CHERRYPY_DESC=		CherryPy server support
GEVENT_DESC=		gevent-based client/server support
TORNADO_DESC=		Tornado client support

CHERRYPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cherrypy>=3.2.2:www/py-cherrypy@${PY_FLAVOR}
GEVENT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gevent>=0.13.8:devel/py-gevent@${PY_FLAVOR}
TORNADO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tornado>=3.1:www/py-tornado@${PY_FLAVOR}

# Do not install files which will not work
post-patch-CHERRYPY-off:
.for f in test/test_cherrypy.py ws4py/server/cherrypyserver.py
	@${RM} ${WRKSRC}/${f}
.endfor

post-patch-GEVENT-off:
.for f in ws4py/client/geventclient.py ws4py/server/geventserver.py
	@${RM} ${WRKSRC}/${f}
.endfor

post-patch-TORNADO-off:
.for f in ws4py/client/tornadoclient.py
	@${RM} ${WRKSRC}/${f}
.endfor

.include <bsd.port.mk>
