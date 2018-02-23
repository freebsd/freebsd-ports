# Created by: Thomas Bartelmess <thomas@bartelmess.io>
# $FreeBSD$

PORTNAME=	graylog
DISTVERSION=	2.4.3
CATEGORIES=	sysutils java
MASTER_SITES=	https://packages.graylog2.org/releases/graylog/ \
		http://packages.graylog2.org/releases/graylog/

MAINTAINER=	thomas@bartelmess.io
COMMENT=	Tool for centralized log collection

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:tgz
USE_JAVA=	yes
JAVA_VERSION=	1.8+
JAVA_EXTRACT=	yes
JAVA_RUN=	yes
NO_BUILD=	yes
NO_ARCH=	yes

USE_RC_SUBR=	graylog
SUB_FILES=	server.conf log4j2.xml pkg-message

GRAYLOGUSER?=	graylog
GRAYLOGGROUP?=	${GRAYLOGUSER}
USERS=		${GRAYLOGUSER}
GROUPS=		${GRAYLOGGROUP}
GRAYLOG_DATA_DIR=	/var/db/graylog
GRAYLOG_LOGS_DIR=	/var/log/graylog

SUB_LIST=	GRAYLOGUSER=${GRAYLOGUSER} \
		GRAYLOGGROUP=${GRAYLOGGROUP} \
		GRAYLOG_LOGS_DIR=${GRAYLOG_LOGS_DIR} \
		GRAYLOG_DATA_DIR=${GRAYLOG_DATA_DIR}

PLIST_SUB=	GRAYLOG_DATA_DIR=${GRAYLOG_DATA_DIR} \
		GRAYLOG_LOGS_DIR=${GRAYLOG_LOGS_DIR} \
		GRAYLOGUSER=${GRAYLOGUSER} \
		GRAYLOGGROUP=${GRAYLOGGROUP} \
		PORTVERSION=${PORTVERSION}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugin
	@${MKDIR} ${STAGEDIR}${ETCDIR}/server
	@${MKDIR} ${STAGEDIR}${GRAYLOG_DATA_DIR}
	@${MKDIR} ${STAGEDIR}${GRAYLOG_LOGS_DIR}
	${INSTALL_DATA} ${WRKSRC}/graylog.jar ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/plugin && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/plugin
	${INSTALL_DATA} ${WRKDIR}/server.conf ${STAGEDIR}${ETCDIR}/server/server.conf.sample
	${INSTALL_DATA} ${WRKDIR}/log4j2.xml ${STAGEDIR}${ETCDIR}/server/log4j2.xml.sample

.include <bsd.port.mk>
