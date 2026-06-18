PORTNAME=	graylog
DISTVERSION=	7.0.8
CATEGORIES=	sysutils java
MASTER_SITES=	https://downloads.graylog.org/releases/${PORTNAME}/ \
		LOCAL/vvd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for centralized log collection
WWW=		https://www.graylog.org/

LICENSE=	APACHE20 SSPLv1
LICENSE_COMB=	multi
LICENSE_NAME_SSPLv1=	Server Side Public License
LICENSE_FILE_SSPLv1=	${WRKSRC}/LICENSE
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe java:extract,run tar:tgz
JAVA_VERSION=	21+
USE_RC_SUBR=	${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

GRAYLOG_DATA_DIR=	/var/db/${PORTNAME}
GRAYLOG_LOGS_DIR=	/var/log/${PORTNAME}
SUB_FILES=	log4j2.xml pkg-message
SUB_LIST=	GRAYLOG_DATA_DIR=${GRAYLOG_DATA_DIR} \
		GRAYLOG_LOGS_DIR=${GRAYLOG_LOGS_DIR} \
		GRAYLOGGROUP=${GRAYLOGGROUP} \
		GRAYLOGUSER=${GRAYLOGUSER} \
		JAVA_HOME=${JAVA_HOME}

GRAYLOGUSER?=	${PORTNAME}
GRAYLOGGROUP?=	${GRAYLOGUSER}
.if ${GRAYLOGUSER} == ${PORTNAME}
USERS=		${GRAYLOGUSER}
.endif
.if ${GRAYLOGGROUP} == ${PORTNAME}
GROUPS=		${GRAYLOGGROUP}
.endif

PLIST_SUB=	DISTVERSION=${DISTVERSION} \
		GRAYLOG_DATA_DIR=${GRAYLOG_DATA_DIR} \
		GRAYLOG_LOGS_DIR=${GRAYLOG_LOGS_DIR} \
		GRAYLOGGROUP=${GRAYLOGGROUP} \
		GRAYLOGUSER=${GRAYLOGUSER} \
		PORTNAME=${PORTNAME}

post-patch:
	${REINPLACE_CMD} -E \
		-e 's,^bin_dir .+,bin_dir = ${PREFIX}/share/graylog/bin,' \
		-e 's,^data_dir .+,data_dir = ${GRAYLOG_DATA_DIR},' \
		-e 's,^message_journal_dir .+,message_journal_dir = ${GRAYLOG_DATA_DIR}/journal,' \
		-e 's,^node_id_file .+,node_id_file = ${ETCDIR}/server/node-id,' \
	${WRKSRC}/graylog.conf.example

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}/server \
		 ${STAGEDIR}${GRAYLOG_DATA_DIR}/journal \
		 ${STAGEDIR}${GRAYLOG_LOGS_DIR}
	(cd ${WRKSRC}/plugin && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/plugin)
	${INSTALL_DATA} ${WRKSRC}/graylog.jar ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/graylog.conf.example \
		${STAGEDIR}${ETCDIR}/graylog.conf.sample
	${INSTALL_DATA} ${WRKDIR}/log4j2.xml \
		${STAGEDIR}${ETCDIR}/log4j2.xml.sample

.include <bsd.port.mk>
