# Created by: Thomas Bartelmess <thomas@bartelmess.io>
# $FreeBSD$

PORTNAME=	graylog
DISTVERSION=	4.0.5
CATEGORIES=	sysutils java
MASTER_SITES=	https://downloads.graylog.org/releases/
DISTFILES=	graylog/${DISTNAME}${EXTRACT_SUFX} \
		graylog-integrations/graylog-integrations-plugins-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Tool for centralized log collection

LICENSE=	SSPLv1 APACHE20
LICENSE_COMB=	multi
LICENSE_NAME_SSPLv1=	Server Side Public License
LICENSE_FILE_SSPLv1=	${WRKSRC}/LICENSE
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		tar:tgz
USE_JAVA=	yes

JAVA_VERSION=	1.8+
JAVA_EXTRACT=	yes
JAVA_RUN=	yes

NO_BUILD=	yes
NO_ARCH=	yes

USE_RC_SUBR=	graylog
SUB_FILES=	log4j2.xml pkg-message

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

PLIST_SUB=	DISTVERSION=${DISTVERSION} \
		GRAYLOG_DATA_DIR=${GRAYLOG_DATA_DIR} \
		GRAYLOG_LOGS_DIR=${GRAYLOG_LOGS_DIR} \
		GRAYLOGUSER=${GRAYLOGUSER} \
		GRAYLOGGROUP=${GRAYLOGGROUP} \
		PORTNAME=${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${GRAYLOG_DATA_DIR}
	@${MKDIR} ${STAGEDIR}${GRAYLOG_LOGS_DIR}
	${INSTALL_DATA} ${WRKSRC}/graylog.jar ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/graylog.conf.example ${STAGEDIR}${ETCDIR}/graylog.conf.example
	cd ${WRKDIR}/graylog-integrations-plugins-${DISTVERSION}/plugin && \
	    ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/plugin/
	cd ${WRKSRC}/plugin && \
	    ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/plugin/
	${INSTALL_DATA} ${WRKDIR}/log4j2.xml ${STAGEDIR}${ETCDIR}/log4j2.xml.example

.include <bsd.port.mk>
