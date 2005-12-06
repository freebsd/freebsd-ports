# New ports collection makefile for:	Jabber Python MSN Transport
# Date created:				Tue Nov 23 16:42:07 CET 2004
# Whom:					Martijn Lina <martijn@pacno.net>
#
# $FreeBSD$

PORTNAME=	pymsn
PORTVERSION=	0.10.2
CATEGORIES=	net-im
MASTER_SITES=	http://msn-transport.jabberstudio.org/tarballs/
PKGNAMEPREFIX=	jabber-
PKGNAMESUFFIX=	-transport
DISTNAME=	${PORTNAME}t-${PORTVERSION}
DIST_SUBDIR=	jabber

MAINTAINER=	martijn@pacno.net
COMMENT=	Python MSN-Transport for Jabber

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:${PORTSDIR}/security/py-openssl \
		${PYTHON_SITELIBDIR}/twisted/__init__.py:${PORTSDIR}/devel/py-twisted

NO_BUILD=	yes
USE_PYTHON=	yes
USE_REINPLACE=	yes
USE_RC_SUBR=	jabber-pymsn-transport.sh

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

INST_DIR=	${PREFIX}/lib/jabber/${PORTNAME}

PORTDOCS=	COPYING README TODO

post-extract:
	@${FIND} ${WRKSRC}/ -type d \( -name CVS -or -name .svn \) | ${XARGS} ${RM} -rf

post-patch:
	@${REINPLACE_CMD} -i "" '/spooldir/s|/path/to/data|/var/spool/jabber|' \
		${WRKSRC}/config-example.xml
	@${REINPLACE_CMD} -i "" 's|../config.xml|${PREFIX}/etc/jabber-pymsn.xml|g' \
		${WRKSRC}/src/xmlconfig.py
	@${REINPLACE_CMD} -i "" 's|src/legacy|legacy|g' \
		${WRKSRC}/src/legacy/glue.py \
		${WRKSRC}/src/legacy/legacylist.py
	@${REINPLACE_CMD} -i "" 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/src/config.py
	@${RM} -f ${WRKSRC}/src/*.orig
	@${ECHO} '#!${PYTHON_CMD}' > ${WRKSRC}/src/main.py.new
	@${CAT} ${WRKSRC}/src/main.py >> ${WRKSRC}/src/main.py.new
	@${MV} ${WRKSRC}/src/main.py.new ${WRKSRC}/src/main.py
	@${MV} ${WRKSRC}/src/config.py ${WRKSRC}/src/config.py.sample

do-install:
	${INSTALL} -d ${INST_DIR}
	${CP} -pPR ${WRKSRC}/src/* ${INST_DIR}/
	${CHMOD} 755 ${INST_DIR}/main.py
	[ -f ${INST_DIR}/config.py ] || ${CP} ${INST_DIR}/config.py.sample ${INST_DIR}/config.py
	${INSTALL_SCRIPT} -m 751 ${WRKDIR}/${PKGBASE}.sh ${PREFIX}/etc/rc.d/${PKGBASE}.sh
	@${MKDIR} ${EXAMPLESDIR}/etc
	${INSTALL_DATA} ${WRKSRC}/config-example.xml ${EXAMPLESDIR}/etc/jabber-pymsn.xml
	[ -f ${PREFIX}/etc/jabber-pymsn.xml ] || ${CP} ${EXAMPLESDIR}/etc/jabber-pymsn.xml ${PREFIX}/etc/jabber-pymsn.xml
.if !defined(NOPORTDOCS)
.for portdoc in ${PORTDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${portdoc} ${DOCSDIR}/
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
