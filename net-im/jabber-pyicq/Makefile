# New ports collection makefile for:	Jabber Python ICQ Transport
# Date created:				2005-06-07
# Whom:					Renato Botelho <freebsd@galle.com.br>
#
# $FreeBSD$

PORTNAME=	pyicq
PORTVERSION=	0.8
CATEGORIES=	net-im
MASTER_SITES=	http://www.blathersource.org/download.php/pyicq-t/
PKGNAMEPREFIX=	jabber-
PKGNAMESUFFIX=	-transport
DISTNAME=	${PORTNAME}-t-${PORTVERSION}
DIST_SUBDIR=	jabber

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Python ICQ-Transport for Jabber

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:${PORTSDIR}/security/py-openssl \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging

OPTIONS=	EJABBERD "Use transport with ejabberd" off \
		TWISTED1 "Use old py-twisted 1.x" off

NO_BUILD=	yes
USE_PYTHON=	yes
USE_RC_SUBR=	jabber-pyicq-transport.sh
LOCAL_PYTHON=	${PYTHON_CMD}

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${LOCAL_PYTHON}

INST_DIR=	${PREFIX}/lib/jabber/${PORTNAME}

PORTDOCS=	COPYING README NEWS

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
	@${REINPLACE_CMD} -i "" -e '/spooldir/s|\.|/var/spool/jabber|' \
		-e '/pid/s|PyICQt.pid|/var/jabberd/pid/PyICQt.pid|' \
		${WRKSRC}/config_example.xml
	@${REINPLACE_CMD} -i "" -e 's,"config.xml","${PREFIX}/etc/jabber-pyicq.xml",' \
		${WRKSRC}/src/main.py
	@${REINPLACE_CMD} -i "" 's|^#!.*$$|#!${LOCAL_PYTHON}|' \
		${WRKSRC}/PyICQt.py

do-install:
	${MKDIR} ${INST_DIR}/src ${INST_DIR}/data
	${INSTALL_SCRIPT} ${WRKSRC}/PyICQt.py ${INST_DIR}
	${INSTALL_DATA} ${WRKSRC}/data/defaultAIMAvatar.png ${INST_DIR}/data
	${INSTALL_DATA} ${WRKSRC}/data/defaultICQAvatar.png ${INST_DIR}/data
	@${CP} -Rv ${WRKSRC}/src/* ${INST_DIR}/src
	@${FIND} ${INST_DIR}/src/ -type d -exec ${CHMOD} 755 "{}" \;
	@${FIND} ${INST_DIR}/src/ -type f -exec ${CHMOD} 644 "{}" \;
	@${MKDIR} ${EXAMPLESDIR}/etc
	${INSTALL_DATA} ${WRKSRC}/config_example.xml ${EXAMPLESDIR}/etc/jabber-pyicq.xml
	[ -f ${PREFIX}/etc/jabber-pyicq.xml ] || ${CP} ${EXAMPLESDIR}/etc/jabber-pyicq.xml ${PREFIX}/etc/jabber-pyicq.xml
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for portdoc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${portdoc} ${DOCSDIR}/
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
