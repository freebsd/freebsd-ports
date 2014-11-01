# $FreeBSD$

PORTNAME=	rundeck
PORTVERSION=	2.2.3
CATEGORIES=	sysutils java
MASTER_SITES=	http://dl.bintray.com/rundeck/rundeck-maven/
DISTNAME=	rundeck-launcher-${PORTVERSION}
EXTRACT_SUFX=	.jar

MAINTAINER=	c.kworr@gmail.com
COMMENT=	Web-console for dispatching commands and scripts to your nodes

LICENSE=	APACHE20

USE_JAVA=	yes
JAVA_VERSION=	1.6+

NO_BUILD=	yes
PLIST_FILES=	rundeck/server/lib/.keep \
		share/rundeck/rundeck-launcher.jar

USE_RC_SUBR=	rundeck

RUNDECK_HOME=	${PREFIX}/rundeck
RUNDECK_USER?=	rundeck
RUNDECK_GROUP?=	rundeck
RUNDECK_LOG_FILE?=	/var/log/rundeck.log

.if ${RUNDECK_USER} == "rundeck"
USERS=	rundeck
.endif
.if ${RUNDECK_GROUP} == "rundeck"
GROUPS=	rundeck
.endif

SUB_LIST+=	RUNDECK_HOME=${RUNDECK_HOME} RUNDECK_USER=${RUNDECK_USER} \
		RUNDECK_GROUP=${RUNDECK_GROUP} JAVA_HOME=${JAVA_HOME} \
		RUNDECK_LOG_FILE=${RUNDECK_LOG_FILE}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${RUNDECK_HOME}/server/lib
	${TOUCH} ${STAGEDIR}${RUNDECK_HOME}/server/lib/.keep
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${DATADIR}/rundeck-launcher${EXTRACT_SUFX}

.include <bsd.port.mk>
