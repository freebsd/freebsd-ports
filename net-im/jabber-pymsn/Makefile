# New ports collection makefile for:	Jabber Python MSN Transport
# Date created:				Tue Nov 23 16:42:07 CET 2004
# Whom:					Martijn Lina <martijn@pacno.net>
#
# $FreeBSD$

PORTNAME=	pymsn
DISTVERSION=	0.11.3
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net-im
MASTER_SITES=	http://delx.net.au/projects/pymsnt/tarballs/
PKGNAMEPREFIX=	jabber-
PKGNAMESUFFIX=	-transport
DISTNAME=	${PORTNAME}t-${DISTVERSION}
DIST_SUBDIR=	jabber

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python MSN-Transport for Jabber

DEPRECATED=	Primary MSN Messenger service terminated 30 APR 2013
EXPIRATION_DATE=2013-10-31

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:${PORTSDIR}/security/py-openssl \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging

OPTIONS_DEFINE=	TWISTED1
OPTIONS_DEFAULT=DAEMON
OPTIONS_SINGLE=	SERVER
OPTIONS_SINGLE_SERVER=	JABBER JABBERD EJABBERD DAEMON
JABBER_DESC=	Use with jabberd14 (net-im/jabber)
JABBERD_DESC=	Use with jabberd 2.x (net-im/jabberd)
EJABBERD_DESC=	Use with ejabberd (net-im/ejabberd)
DAEMON_DESC=	Use builtin daemon
TWISTED1_DESC=	Use old py-twisted 1.x

NO_BUILD=	yes
USE_PYTHON=	yes
USE_RC_SUBR=	jabber-pymsn-transport
LOCAL_PYTHON=	${PYTHON_CMD}

SUB_FILES=	pkg-message README.jabberd14 README.jabberd2 README.external
SUB_LIST=	PYTHON_CMD=${LOCAL_PYTHON}

INST_DIR=	${PREFIX}/lib/jabber/${PORTNAME}

PORTDOCS=	COPYING README README.jabberd14 README.jabberd2 README.external

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJABBER}
JABBER_REQUIRE?=	jabber
JABBER_USER?=		jabber
JABBER_PIDDIR?=		/var/run/jabberd
JABBER_SPOOLDIR?=	/var/spool/jabberd
RUN_DEPENDS+=		jabberd14:${PORTSDIR}/net-im/jabber
.elif ${PORT_OPTIONS:MJABBERD}
JABBER_REQUIRE?=	jabberd
JABBER_USER?=		jabber
JABBER_PIDDIR?=		/var/jabberd/pid
JABBER_SPOOLDIR?=	/var/spool/jabber
RUN_DEPENDS+=		jabberd:${PORTSDIR}/net-im/jabberd
.elif ${PORT_OPTIONS:MEJABBERD}
JABBER_REQUIRE?=	ejabberd
JABBER_USER?=		ejabberd
JABBER_PIDDIR?=		/var/jabberd/pid
JABBER_SPOOLDIR?=	/var/spool/jabber
RUN_DEPENDS+=		ejabberdctl:${PORTSDIR}/net-im/ejabberd
.elif ${PORT_OPTIONS:MDAEMON}
JABBER_REQUIRE?=	DAEMON
JABBER_USER?=		nobody
JABBER_PIDDIR?=		/var/run/pymsn
JABBER_SPOOLDIR?=	/var/spool/pymsn
.endif

SUB_LIST+=	JABBER_REQUIRE="${JABBER_REQUIRE}" JABBER_PIDDIR="${JABBER_PIDDIR}" \
		JABBER_SPOOLDIR="${JABBER_SPOOLDIR}"

.if ${PORT_OPTIONS:MTWISTED1}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/__init__.py:${PORTSDIR}/devel/py-twisted
.else
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/__init__.py:${PORTSDIR}/devel/py-twistedCore \
		${PYTHON_SITELIBDIR}/twisted/web/__init__.py:${PORTSDIR}/www/py-twistedWeb \
		${PYTHON_SITELIBDIR}/twisted/words/__init__.py:${PORTSDIR}/net-im/py-twistedWords
.endif

SUB_LIST+=	JABBER_USER=${JABBER_USER}

post-extract:
	@${FIND} ${WRKSRC}/ -type d \( -name CVS -or -name .svn \) | ${XARGS} ${RM} -rf

post-patch:
	@${REINPLACE_CMD} -i "" -e '/spooldir/s|/path/to/data|${JABBER_SPOOLDIR}|' \
				-e 's|PyMSNt.pid|${JABBER_PIDDIR}/PyMSNt.pid|' \
		${WRKSRC}/config-example.xml
	@${REINPLACE_CMD} -i "" 's|../config.xml|${PREFIX}/etc/jabber-pymsn.xml|g' \
		${WRKSRC}/src/xmlconfig.py
	@${REINPLACE_CMD} -i "" -e 's|spooldir = ""|spooldir = "${JABBER_SPOOLDIR}"|g' \
				-e 's|pid = ""|pid = "${JABBER_PIDDIR}/PyMSNt.pid"|g' \
		${WRKSRC}/src/config.py
	@${REINPLACE_CMD} -i "" 's|"config.xml"|"${PREFIX}/etc/jabber-pymsn.xml"|' \
		${WRKSRC}/src/main.py
	@${RM} -f ${WRKSRC}/src/main.py.orig
	@${REINPLACE_CMD} -i "" 's|#!.*$$|#!${LOCAL_PYTHON}|' \
		${WRKSRC}/PyMSNt.py
	@${REINPLACE_CMD} -i "" '/MSN_PROTOCOL_VERSION *= */s/MSNP11 CVR0/MSNP11/' \
		${WRKSRC}/src/legacy/msn/msn.py

do-install:
	@${MKDIR} ${INST_DIR}/src ${INST_DIR}/data
	${INSTALL_SCRIPT} ${WRKSRC}/PyMSNt.py ${INST_DIR}
	${INSTALL_DATA} ${WRKSRC}/data/defaultJabberAvatar.png ${INST_DIR}/data
	${INSTALL_DATA} ${WRKSRC}/data/defaultMSNAvatar.png ${INST_DIR}/data
	@${CP} -Rv ${WRKSRC}/src/* ${INST_DIR}/src/
	@${FIND} ${INST_DIR}/src/ -type d -exec ${CHMOD} 755 "{}" \;
	@${FIND} ${INST_DIR}/src/ -type f -exec ${CHMOD} 644 "{}" \;
	@${MKDIR} ${EXAMPLESDIR}/etc
	${INSTALL_DATA} ${WRKSRC}/config-example.xml ${EXAMPLESDIR}/etc/jabber-pymsn.xml
	@[ -f ${PREFIX}/etc/jabber-pymsn.xml ] || \
		${CP} -v ${EXAMPLESDIR}/etc/jabber-pymsn.xml ${PREFIX}/etc/jabber-pymsn.xml
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for portdoc in ${PORTDOCS}
	@if [ -f ${WRKDIR}/${portdoc} ]; then \
		${INSTALL_DATA} -v ${WRKDIR}/${portdoc} ${DOCSDIR}/; \
	else \
		${INSTALL_DATA} -v ${WRKSRC}/${portdoc} ${DOCSDIR}/; \
	fi
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
