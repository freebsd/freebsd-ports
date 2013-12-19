# Created by: rene@FreeBSD.org
# $FreeBSD$

PORTNAME=	ws4py
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://www.defuze.org/oss/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	WebSocket package for Python

LICENSE=	BSD3CLAUSE

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

NO_ARCH=	yes

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	CHERRYPY GEVENT TORNADO
OPTIONS_DEFAULT=	CHERRYPY GEVENT
CHERRYPY_DESC=	CherryPy server support
GEVENT_DESC=	gevent-based client/server support
TORNADO_DESC=	Tornado client support

CHERRYPY_RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cherrypy>=3.2.2:${PORTSDIR}/www/py-cherrypy
GEVENT_RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gevent>=0.13.8:${PORTSDIR}/devel/py-gevent
TORNADO_RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tornado>=3.1:${PORTSDIR}/www/py-tornado

.include <bsd.port.options.mk>

# Do not install files which will not work
post-patch:
.if ! ${PORT_OPTIONS:MCHERRYPY}
.for f in test/test_cherrypy.py ws4py/server/cherrypyserver.py
	${RM} ${WRKSRC}/${f}
.endfor
.endif
.if ! ${PORT_OPTIONS:MGEVENT}
.for f in ws4py/client/geventclient.py ws4py/server/geventserver.py
	${RM} ${WRKSRC}/${f}
.endfor
.endif
.if ! ${PORT_OPTIONS:MTORNADO}
.for f in ws4py/client/tornadoclient.py
	${RM} ${WRKSRC}/${f}
.endfor
.endif

.include <bsd.port.mk>
