# $FreeBSD$

PORTNAME=	pyicq
PORTVERSION=	0.8.1.5
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net-im
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	jabber-
PKGNAMESUFFIX=	-transport
DISTNAME=	${PORTNAME}t-${PORTVERSION}
DIST_SUBDIR=	jabber

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python ICQ-Transport for Jabber

LICENSE=	GPLv2

BROKEN=		Unfetchable (google code has gone away)

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow

PROJECTHOST=	pyicqt
OPTIONS_DEFINE=	DOCS EXAMPLES MYSQL TWISTED
OPTIONS_DEFAULT=DAEMON
OPTIONS_SINGLE=	SERVER
OPTIONS_SINGLE_SERVER=	JABBER JABBERD EJABBERD DAEMON
JABBER_DESC=	Use with jabberd14 (net-im/jabber)
JABBERD_DESC=	Use with jabberd 2.x (net-im/jabberd)
EJABBERD_DESC=	Use with ejabberd (net-im/ejabberd)
DAEMON_DESC=	Use builtin daemon
TWISTED_DESC=	Use py-twisted

NO_BUILD=	yes
USES=		python
USE_RC_SUBR=	jabber-pyicq-transport
LOCAL_PYTHON=	${PYTHON_CMD}

SUB_FILES=	pkg-message README.jabberd14 README.jabberd2 README.external
SUB_LIST=	PYTHON_CMD=${LOCAL_PYTHON}

INST_DIR=	${PREFIX}/lib/jabber/${PORTNAME}

PORTDOCS=	NEWS README
PORTEXAMPLES=	db-setup.mysql jabber-pyicq.xml

MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=0:databases/py-MySQLdb
TWISTED_USES=		twisted:web,words

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJABBER}
JABBER_REQUIRE?=	jabber
JABBER_USER?=		jabber
JABBER_PIDDIR?=		/var/run/jabberd
JABBER_SPOOLDIR?=	/var/spool/jabberd
RUN_DEPENDS+=		jabberd14:net-im/jabber
.elif ${PORT_OPTIONS:MJABBERD}
JABBER_REQUIRE?=	jabberd
JABBER_USER?=		jabber
JABBER_PIDDIR?=		/var/jabberd/pid
JABBER_SPOOLDIR?=	/var/spool/jabber
RUN_DEPENDS+=		jabberd:net-im/jabberd
.elif ${PORT_OPTIONS:MEJABBERD}
JABBER_REQUIRE?=	ejabberd
JABBER_USER?=		ejabberd
JABBER_PIDDIR?=		/var/jabberd/pid
JABBER_SPOOLDIR?=	/var/spool/jabber
RUN_DEPENDS+=		ejabberdctl:net-im/ejabberd
.elif ${PORT_OPTIONS:MDAEMON}
JABBER_REQUIRE?=	DAEMON
JABBER_USER?=		nobody
JABBER_PIDDIR?=		/var/run/pyicq
JABBER_SPOOLDIR?=	/var/spool/pyicq
.endif

SUB_LIST+=	JABBER_REQUIRE="${JABBER_REQUIRE}" \
		JABBER_PIDDIR="${JABBER_PIDDIR}" \
		JABBER_SPOOLDIR="${JABBER_SPOOLDIR}"

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
	${MKDIR} ${STAGEDIR}${INST_DIR}/data/ ${STAGEDIR}${INST_DIR}/src/
	${INSTALL_SCRIPT} ${WRKSRC}/PyICQt.py ${STAGEDIR}${INST_DIR}/
	${INSTALL_DATA} ${WRKSRC}/data/defaultAIMAvatar.png ${STAGEDIR}${INST_DIR}/data/
	${INSTALL_DATA} ${WRKSRC}/data/defaultICQAvatar.png ${STAGEDIR}${INST_DIR}/data/
	${CP} -Rv ${WRKSRC}/src/* ${STAGEDIR}${INST_DIR}/src/
	${FIND} ${STAGEDIR}${INST_DIR}/src/ -type d -exec ${CHMOD} 755 {} \;
	${FIND} ${STAGEDIR}${INST_DIR}/src/ -type f -exec ${CHMOD} 644 {} \;
	${INSTALL_DATA} ${WRKSRC}/config_example.xml ${STAGEDIR}${PREFIX}/etc/jabber-pyicq.xml.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/config_example.xml ${STAGEDIR}${EXAMPLESDIR}/jabber-pyicq.xml
	${INSTALL_DATA} ${WRKSRC}/tools/db-setup.mysql ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
