# New ports collection makefile for:	Jabber Python ICQ Transport
# Date created:				2005-06-07
# Whom:					Renato Botelho <freebsd@galle.com.br>
#
# $FreeBSD$

PORTNAME=	pyicq
PORTVERSION=	0.8.1.3
PORTEPOCH=	1
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	jabber-
PKGNAMESUFFIX=	-transport
DISTNAME=	${PORTNAME}t-${PORTVERSION}
DIST_SUBDIR=	jabber

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Python ICQ-Transport for Jabber

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:${PORTSDIR}/security/py-openssl \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging

PROJECTHOST=	pyicqt
OPTIONS=	JABBER "Use with jabberd14 (net-im/jabber)" off \
		JABBERD "Use with jabberd 2.x (net-im/jabberd)" off \
		EJABBERD "Use with ejabberd (net-im/ejabberd)" off \
		TWISTED1 "Use old py-twisted 1.x" off \
		MYSQL "Support MySQL storage" off

NO_BUILD=	yes
USE_PYTHON=	yes
USE_RC_SUBR=	jabber-pyicq-transport.sh
LOCAL_PYTHON=	${PYTHON_CMD}

SUB_FILES=	pkg-message README.jabberd14 README.jabberd2 README.external
SUB_LIST=	PYTHON_CMD=${LOCAL_PYTHON}

INST_DIR=	${PREFIX}/lib/jabber/${PORTNAME}

PORTDOCS=	COPYING NEWS README README.jabberd14 README.jabberd2 README.external

.include <bsd.port.pre.mk>

.if (defined(WITH_JABBERD) && (defined(WITH_JABBER) || defined(WITH_EJABBERD))) || \
	defined(WITH_JABBER) && defined(WITH_EJABBERD)
IGNORE=	options WITH_JABBER, WITH_JABBERD and WITH_EJABBERD are mutually exclusive
.endif

.if defined(WITH_JABBER)
JABBER_REQUIRE?=	jabber
JABBER_USER?=		jabber
JABBER_PIDDIR?=		/var/run/jabberd
JABBER_SPOOLDIR?=	/var/spool/jabberd
RUN_DEPENDS+=		jabberd14:${PORTSDIR}/net-im/jabber
.elif defined(WITH_JABBERD)
JABBER_REQUIRE?=	jabberd
JABBER_USER?=		jabber
JABBER_PIDDIR?=		/var/jabberd/pid
JABBER_SPOOLDIR?=	/var/spool/jabber
RUN_DEPENDS+=		jabberd:${PORTSDIR}/net-im/jabberd
.elif defined(WITH_EJABBERD)
JABBER_REQUIRE?=	ejabberd
JABBER_USER?=		ejabberd
JABBER_PIDDIR?=		/var/jabberd/pid
JABBER_SPOOLDIR?=	/var/spool/jabber
RUN_DEPENDS+=		ejabberdctl:${PORTSDIR}/net-im/ejabberd
.else
JABBER_REQUIRE?=	DAEMON
JABBER_USER?=		nobody
JABBER_PIDDIR?=		/var/run/pyicq
JABBER_SPOOLDIR?=	/var/spool/pyicq
.endif

SUB_LIST+=	JABBER_REQUIRE="${JABBER_REQUIRE}" \
		JABBER_PIDDIR="${JABBER_PIDDIR}" \
		JABBER_SPOOLDIR="${JABBER_SPOOLDIR}"

.if defined(WITH_TWISTED1)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/__init__.py:${PORTSDIR}/devel/py-twisted
.else
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/__init__.py:${PORTSDIR}/devel/py-twistedCore \
		${PYTHON_SITELIBDIR}/twisted/web/__init__.py:${PORTSDIR}/www/py-twistedWeb \
		${PYTHON_SITELIBDIR}/twisted/words/__init__.py:${PORTSDIR}/net-im/py-twistedWords
.endif

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/MySQLdb/__init__.py:${PORTSDIR}/databases/py-MySQLdb
.endif

SUB_LIST+=	JABBER_USER=${JABBER_USER}

post-patch:
	@${REINPLACE_CMD} -i "" -e '/spooldir/s|\.|${JABBER_SPOOLDIR}|' \
		-e '/pid/s|PyICQt.pid|${JABBER_PIDDIR}/PyICQt.pid|' \
		${WRKSRC}/config_example.xml
	@${REINPLACE_CMD} -i "" -e 's,"config.xml","${PREFIX}/etc/jabber-pyicq.xml",' \
		${WRKSRC}/src/main.py
	@${REINPLACE_CMD} -i "" 's|^#!.*$$|#!${LOCAL_PYTHON}|' \
		${WRKSRC}/PyICQt.py

do-install:
	@${MKDIR} ${INST_DIR}/src ${INST_DIR}/data
	${INSTALL_SCRIPT} ${WRKSRC}/PyICQt.py ${INST_DIR}
	${INSTALL_DATA} ${WRKSRC}/data/defaultAIMAvatar.png ${INST_DIR}/data
	${INSTALL_DATA} ${WRKSRC}/data/defaultICQAvatar.png ${INST_DIR}/data
	@${CP} -Rv ${WRKSRC}/src/* ${INST_DIR}/src
	@${FIND} ${INST_DIR}/src/ -type d -exec ${CHMOD} 755 "{}" \;
	@${FIND} ${INST_DIR}/src/ -type f -exec ${CHMOD} 644 "{}" \;
	@${MKDIR} ${EXAMPLESDIR}/etc
	${INSTALL_DATA} ${WRKSRC}/config_example.xml ${EXAMPLESDIR}/etc/jabber-pyicq.xml
	${INSTALL_DATA} ${WRKSRC}/tools/db-setup.mysql ${EXAMPLESDIR}
	@[ -f ${PREFIX}/etc/jabber-pyicq.xml ] || \
		${CP} -v ${EXAMPLESDIR}/etc/jabber-pyicq.xml ${PREFIX}/etc/jabber-pyicq.xml
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for portdoc in ${PORTDOCS}
	@if [ -f ${WRKDIR}/${portdoc} ]; then \
		${INSTALL_DATA} -v ${WRKDIR}/${portdoc} ${DOCSDIR}/;  \
	else \
		${INSTALL_DATA} -v ${WRKSRC}/${portdoc} ${DOCSDIR}/;  \
	fi
. endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
