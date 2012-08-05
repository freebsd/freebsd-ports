# New ports collection makefile for:	Jabber Python AIM Transport
# Date created:		2006-06-06
# Whom:			Derek Kulinski <takeda@takeda.tk>
#
# $FreeBSD$
#

PORTNAME=	pyaim
PORTVERSION=	0.8a
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	jabber-
PKGNAMESUFFIX=	-transport
DISTNAME=	${PORTNAME}-t-${PORTVERSION}
DIST_SUBDIR=	jabber

MAINTAINER=	takeda@takeda.tk
COMMENT=	Python AIM-Transport for Jabber

PROJECTHOST=	pyaimt

OPTIONS=	EJABBERD "Use transport with ejabberd" off \
		TWISTED1 "Use old py-twisted 1.x" off

NO_BUILD=	yes
USE_PYTHON=	yes
USE_RC_SUBR=	jabber-pyaim-transport
LOCAL_PYTHON=	${PYTHON_CMD}

SUB_LIST=	PYTHON_CMD=${LOCAL_PYTHON}

INST_DIR=	${PREFIX}/lib/jabber/${PORTNAME}

PORTDOCS=	COPYING README NEWS AUTHORS INSTALL

.include <bsd.port.pre.mk>

.if defined(WITH_EJABBERD)
JABBER_USER?=	ejabberd
SUB_LIST+=	JABBER_REQUIRE=ejabberd
.else
JABBER_USER?=	jabber
SUB_LIST+=	JABBER_REQUIRE=jabberd
.endif

.if defined(WITH_TWISTED1)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/__init__.py:${PORTSDIR}/devel/py-twisted
.else
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/__init__.py:${PORTSDIR}/devel/py-twistedCore \
		${PYTHON_SITELIBDIR}/twisted/web/__init__.py:${PORTSDIR}/www/py-twistedWeb \
		${PYTHON_SITELIBDIR}/twisted/words/__init__.py:${PORTSDIR}/net-im/py-twistedWords
.endif

SUB_LIST+=	JABBER_USER=${JABBER_USER}

post-patch:
	@${RM} -f ${WRKSRC}/src/main.py.orig
	@${REINPLACE_CMD} -i "" -e '/spooldir/s|\.\.|/var/spool/jabber|' \
		-e 's|\.\./PyAIMt.pid|/var/jabberd/pid/PyAIMt.pid|' \
		${WRKSRC}/config_example.xml
	@${REINPLACE_CMD} -i "" -e 's|spooldir = "\.\."|spooldir = "/var/spool/jabber"|g' \
		-e 's|pid = ""|pid = "/var/jabberd/pid/PyAIMt.pid"|g' \
		${WRKSRC}/src/config.py
	@${REINPLACE_CMD} -i "" 's|"config\.xml"|"${PREFIX}/etc/jabber-pyaim.xml"|' \
		${WRKSRC}/src/main.py
	@${REINPLACE_CMD} -i "" 's|#!.*$$|#!${LOCAL_PYTHON}|' \
		${WRKSRC}/PyAIMt.py

do-install:
	${MKDIR} ${INST_DIR}/src ${INST_DIR}/data
	${INSTALL_SCRIPT} ${WRKSRC}/PyAIMt.py ${INST_DIR}
	@${CP} -Rv ${WRKSRC}/data/* ${INST_DIR}/data/
	@${CP} -Rv ${WRKSRC}/src/* ${INST_DIR}/src/
	${MKDIR} ${EXAMPLESDIR}/etc
	${INSTALL_DATA} ${WRKSRC}/config_example.xml ${EXAMPLESDIR}/etc/jabber-pyaim.xml
	@[ -f ${PREFIX}/etc/jabber-pyaim.xml ] || ${CP} -v ${EXAMPLESDIR}/etc/jabber-pyaim.xml ${PREFIX}/etc/jabber-pyaim.xml
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for portdoc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${portdoc} ${DOCSDIR}/
.endfor
.endif
	${LOCAL_PYTHON} ${PYTHON_LIBDIR}/compileall.py ${INST_DIR}/src

post-install:
	@${ECHO_CMD}
	@${ECHO_CMD} "**************************************************************************************"
	@${ECHO_CMD} "Remember to edit ${PREFIX}/etc/jabber-pyaim.xml to suit your needs."
	@${ECHO_CMD} "Follow the setup instructions at: http://wiki.blathersource.org/wiki/index.php/PyAIMt."
	@${ECHO_CMD} "**************************************************************************************"
	@${ECHO_CMD}

.include <bsd.port.post.mk>
