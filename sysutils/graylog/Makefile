PORTNAME=	graylog
DISTVERSION=	4.3.1
CATEGORIES=	sysutils java
MASTER_SITES=	https://downloads.graylog.org/releases/
DISTFILES=	graylog/${DISTNAME}${EXTRACT_SUFX} \
		graylog-integrations/graylog-integrations-plugins-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Tool for centralized log collection

LICENSE=	APACHE20 SSPLv1
LICENSE_COMB=	multi
LICENSE_NAME_SSPLv1=	Server Side Public License
LICENSE_FILE_SSPLv1=	${WRKSRC}/LICENSE
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe tar:tgz
USE_JAVA=	yes

JAVA_VERSION=	1.8+
JAVA_EXTRACT=	yes
JAVA_RUN=	yes

NO_BUILD=	yes
NO_ARCH=	yes

USE_RC_SUBR=	graylog
SUB_FILES=	log4j2.xml pkg-message

GRAYLOGUSER?=		graylog
GRAYLOGGROUP?=		${GRAYLOGUSER}
USERS=			${GRAYLOGUSER}
GROUPS=			${GRAYLOGGROUP}
GRAYLOG_DATA_DIR=	/var/db/graylog
GRAYLOG_LOGS_DIR=	/var/log/graylog

SUB_LIST=	GRAYLOG_DATA_DIR=${GRAYLOG_DATA_DIR} \
		GRAYLOG_LOGS_DIR=${GRAYLOG_LOGS_DIR} \
		GRAYLOGGROUP=${GRAYLOGGROUP} \
		GRAYLOGUSER=${GRAYLOGUSER}

PLIST_SUB=	DISTVERSION=${DISTVERSION} \
		GRAYLOG_DATA_DIR=${GRAYLOG_DATA_DIR} \
		GRAYLOG_LOGS_DIR=${GRAYLOG_LOGS_DIR} \
		GRAYLOGGROUP=${GRAYLOGGROUP} \
		GRAYLOGUSER=${GRAYLOGUSER} \
		PORTNAME=${PORTNAME}

post-extract:
	${REINPLACE_CMD} -E \
		-e 's,^bin_dir .+,bin_dir = ${LOCALBASE}/share/graylog/bin,' \
		-e 's,^data_dir .+,data_dir = /var/db/graylog,' \
		-e 's,^message_journal_dir .+,message_journal_dir = ${GRAYLOG_DATA_DIR}/journal,' \
		-e 's,^node_id_file .+,node_id_file = ${ETCDIR}/server/node-id,' \
		-e 's,^plugin_dir .+,plugin_dir = ${LOCALBASE}/share/graylog/plugin,' \
	${WRKSRC}/graylog.conf.example

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugin
	@${MKDIR} ${STAGEDIR}${ETCDIR}/server
	@${MKDIR} ${STAGEDIR}${GRAYLOG_DATA_DIR}/journal
	@${MKDIR} ${STAGEDIR}${GRAYLOG_LOGS_DIR}
	${INSTALL_DATA} ${WRKSRC}/graylog.jar ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/graylog.conf.example \
		${STAGEDIR}${ETCDIR}/graylog.conf.sample
	${INSTALL_DATA} ${WRKDIR}/log4j2.xml \
		${STAGEDIR}${ETCDIR}/log4j2.xml.sample
	cd ${WRKDIR}/graylog-integrations-plugins-${DISTVERSION}/plugin && \
	    ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/plugin/
	cd ${WRKSRC}/plugin && \
	    ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/plugin/

.include <bsd.port.mk>
