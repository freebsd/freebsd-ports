PORTNAME=	graylog
DISTVERSION=	6.3.2
CATEGORIES=	sysutils java
MASTER_SITES=	https://downloads.graylog.org/releases/
DISTFILES=	graylog/${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Tool for centralized log collection
WWW=		https://www.graylog.org/

LICENSE=	APACHE20 SSPLv1
LICENSE_COMB=	multi
LICENSE_NAME_SSPLv1=	Server Side Public License
LICENSE_FILE_SSPLv1=	${WRKSRC}/LICENSE
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe java:extract,run tar:tgz
JAVA_VERSION=	21+

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
		GRAYLOGUSER=${GRAYLOGUSER} \
		JAVA_HOME=${JAVA_HOME}

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
	cd ${WRKSRC}/plugin && \
	    ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/plugin/

.include <bsd.port.mk>
