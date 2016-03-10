# Created by: Thomas Bartelmess <thomas@bartelmess.io>
# $FreeBSD$

PORTNAME=	graylog
PORTVERSION=	1.3.3
CATEGORIES=	sysutils java
MASTER_SITES=	https://packages.graylog2.org/releases/graylog2-server/ \
		http://packages.graylog2.org/releases/graylog2-server/

MAINTAINER=	thomas@bartelmess.io
COMMENT=	Tool for centralized log collection

LICENSE=	GPLv3+

USES=		tar:tgz
USE_JAVA=	yes
JAVA_VERSION=	1.7+
JAVA_EXTRACT=	yes
JAVA_RUN=	yes
NO_BUILD=	yes

GRAYLOG_DIR=	${PREFIX}/${PORTNAME}

USE_RC_SUBR=	graylog

GRAYLOGUSER?=	graylog
GRAYLOGGROUP?=	${GRAYLOGUSER}
USERS=		${GRAYLOGUSER}
GROUPS=		${GRAYLOGGROUP}

SUB_LIST=	GRAYLOGUSER=${GRAYLOGUSER} \
		GRAYLOGGROUP=${GRAYLOGGROUP} \
		JAVA_HOME=${JAVA_HOME} \
		GRAYLOG_DIR=${GRAYLOG_DIR} \
		ETCDIR=${ETCDIR}

do-install:
	${MKDIR} ${STAGEDIR}${GRAYLOG_DIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/graylog.jar ${STAGEDIR}${GRAYLOG_DIR}
	${INSTALL_DATA} ${WRKSRC}/graylog.conf.example ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/graylog_logging.xml ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
