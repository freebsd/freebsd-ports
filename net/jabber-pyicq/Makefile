# New ports collection makefile for:	Jabber Python ICQ Transport
# Date created:				2005-06-07
# Whom:					Renato Botelho <freebsd@galle.com.br>
#
# $FreeBSD$

PORTNAME=	pyicq
PORTVERSION=	0.6
CATEGORIES=	net
MASTER_SITES=	http://www.blathersource.org/download.php/pyicq-t/
PKGNAMEPREFIX=	jabber-
PKGNAMESUFFIX=	-transport
DISTNAME=	${PORTNAME}-t-${PORTVERSION}
DIST_SUBDIR=	jabber

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Python ICQ-Transport for Jabber

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:${PORTSDIR}/security/py-openssl \
		${PYTHON_SITELIBDIR}/twisted/__init__.py:${PORTSDIR}/devel/py-twisted

NO_BUILD=	yes
USE_PYTHON=	yes
USE_REINPLACE=	yes
USE_RC_SUBR=	jabber-pyicq-transport.sh

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

INST_DIR=	${PREFIX}/lib/jabber/${PORTNAME}

PORTDOCS=	COPYING README TODO

post-extract:
	@${FIND} ${WRKSRC}/src -type d -name '.svn' | ${XARGS} ${RM} -rf

post-patch:
	@${REINPLACE_CMD} -e '/spooldir/s|\.|/var/spool/jabber|' \
		-e '/pid/s|PyICQt.pid|/var/jabberd/pid/${PORTNAME}.pid|' \
		-e '/<debugOn>/s|<debugOn>|<!--<debugOn>-->|' \
		${WRKSRC}/config_example.xml
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g; s|%%PYTHON_CMD%%|${PYTHON_CMD}|g' \
		${WRKSRC}/src/main.py
	@${RM} ${WRKSRC}/src/main.py.*
	@${MV} ${WRKSRC}/src/config.py ${WRKSRC}/src/config.py.sample

do-install:
	${INSTALL} -d ${INST_DIR}
	${CP} -pPR ${WRKSRC}/src/* ${INST_DIR}/
	${CHMOD} 755 ${INST_DIR}/main.py
	[ -f ${INST_DIR}/config.py ] || ${CP} ${INST_DIR}/config.py.sample ${INST_DIR}/config.py
	${INSTALL_SCRIPT} -m 751 ${WRKDIR}/${PKGBASE}.sh ${PREFIX}/etc/rc.d/${PKGBASE}.sh
	@${MKDIR} ${EXAMPLESDIR}/etc
	${INSTALL_DATA} ${WRKSRC}/config_example.xml ${EXAMPLESDIR}/etc/jabber-pyicq.xml
	[ -f ${PREFIX}/etc/jabber-pyicq.xml ] || ${CP} ${EXAMPLESDIR}/etc/jabber-pyicq.xml ${PREFIX}/etc/jabber-pyicq.xml
.if !defined(NOPORTDOCS)
.for portdoc in ${PORTDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${portdoc} ${DOCSDIR}/
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
