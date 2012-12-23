# Created by: rene@FreeBSD.org
# $FreeBSD$

PORTNAME=	ws4py
PORTVERSION=	0.2.4
CATEGORIES=	www python
MASTER_SITES=	http://www.defuze.org/oss/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rene@FreeBSD.org
# python@ is also OK with me
COMMENT=	WebSocket package for Python

LICENSE=	BSD

SUB_FILES=	pkg-message

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	CHERRYPY GEVENT TORNADO
OPTIONS_DEFAULT=	GEVENT
CHERRYPY_DESC=	CherryPy server support
GEVENT_DESC=	gevent-based client/server support
TORNADO_DESC=	Tornado client support

.include <bsd.port.options.mk>

CHERRYPY_FILES=	test/test_cherrypy.py ws4py/server/cherrypyserver.py
GEVENT_FILES=	ws4py/client/geventclient.py ws4py/server/geventserver.py
TORNADO_FILES=	ws4py/client/tornadoclient.py

.if ${PORT_OPTIONS:MCHERRYPY}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cherrypy>=3.2.2:${PORTSDIR}/www/py-cherrypy
SUB_LIST+=	MSG_NO_CHERRYPY=
.else
SUB_LIST+=	MSG_NO_CHERRYPY="${CHERRYPY_FILES}"
.endif

.if ${PORT_OPTIONS:MGEVENT}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gevent>=0.13.6:${PORTSDIR}/devel/py-gevent
SUB_LIST+=	MSG_NO_GEVENT=
.else
SUB_LIST+=	MSG_NO_GEVENT="${GEVENT_FILES}"
.endif

.if ${PORT_OPTIONS:MTORNADO}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tornado>=2.0:${PORTSDIR}/www/py-tornado
SUB_LIST+=	MSG_NO_TORNADO=
.else
SUB_LIST+=	MSG_NO_TORNADO="${TORNADO_FILES}"
.endif

.if ! ${PORT_OPTIONS:MCHERRYPY} || ! ${PORT_OPTIONS:MGEVENT} || \
	! ${PORT_OPTIONS:MTORNADO}
SUB_LIST+=	NOTE="Note that the following files are omitted from the package:"
.else
SUB_LIST+=	NOTE=
.endif

# Do not install files which will not work
post-patch:
.if ! ${PORT_OPTIONS:MCHERRYPY}
.for f in ${CHERRYPY_FILES}
	${RM} ${WRKSRC}/${f}
.endfor
.endif
.if ! ${PORT_OPTIONS:MGEVENT}
.for f in ${GEVENT_FILES}
	${RM} ${WRKSRC}/${f}
.endfor
.endif
.if ! ${PORT_OPTIONS:MTORNADO}
.for f in ${TORNADO_FILES}
	${RM} ${WRKSRC}/${f}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
