# New ports collection makefile for:	jakarta-tomcat-devel
# Date created:		Tue Aug 12 23:26:32 CST 2003
# Whom:			Kang Liu <liukang@bjpu.edu.cn>
#
# $FreeBSD$
#

PORTNAME=	tomcat
PORTVERSION=	5.5.28
PORTREVISION=	1
CATEGORIES=	www java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	tomcat/tomcat-5/v${PORTVERSION}/bin
DISTFILES=	apache-tomcat-${PORTVERSION}.tar.gz

MAINTAINER=	tomasv@megalogika.lt
COMMENT=	Open-source Java web server by Apache, 5.5.x branch

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	YES

USE_RC_SUBR=	tomcat55.sh
SUB_FILES=	pkg-install pkg-deinstall

MAJOR_VER=	${PORTVERSION:R}
APP_HOME?=	${PREFIX}/${PKGBASE}${PORTVERSION:R}
LOG_DIR=	${APP_HOME}/logs
APP_TITLE=	Apache Tomcat
APP_SHORTNAME=	tomcat${MAJOR_VER:S/.//}
TOMCAT_USER?=	www
TOMCAT_GROUP?=	www
HTTP_PORT?=	8180
SHUTDOWN_PORT?=	8005
AJP_1_3_PORT?=	8009
STDOUT_LOG=	${LOG_DIR}/stdout.log
STDERR_LOG=	${LOG_DIR}/stderr.log
PID_FILE=	/var/run/${APP_SHORTNAME}.pid
REPLACE_FILES=	${WRKSRC}/conf/server.xml
REPLACE_LIST_TEMP=	${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/}
JAR_FILE=	bin/bootstrap.jar
WRKDIR?=	${WRKDIRPREFIX}${.CURDIR}/work
WRKSRC=		${WRKDIR}/apache-tomcat-${PORTVERSION}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///} WWWOWN=${TOMCAT_USER} WWWGRP=${TOMCAT_GROUP}
LATEST_LINK=	${APP_SHORTNAME}
CONF_EXT=	sample
PLIST_SUB+=	CONF_EXT=${CONF_EXT}

SUB_LIST=	AJP_1_3_PORT=${AJP_1_3_PORT} \
		APP_HOME=${APP_HOME} \
		APP_SHORTNAME=${APP_SHORTNAME} \
		APP_TITLE="${APP_TITLE}" \
		GROUP=${TOMCAT_GROUP} \
		HTTP_PORT=${HTTP_PORT} \
		JAR_FILE=${JAR_FILE} \
		PID_FILE=${PID_FILE} \
		SHUTDOWN_PORT=${SHUTDOWN_PORT} \
		STDERR_LOG=${STDERR_LOG} \
		STDOUT_LOG=${STDOUT_LOG} \
		TOMCAT_HOME=${APP_HOME} \
		TOMCAT_VERSION=${MAJOR_VER:S/.//} \
		USER=${TOMCAT_USER}

.include <bsd.port.pre.mk>

.if ${JAVA_PORT_VERSION:C/^([0-9])\.([0-9])(.*)$/\1.\2/} == "1.4"
DISTFILES+=	apache-tomcat-${PORTVERSION}-compat.tar.gz
PLIST_SUB+=	JAVA14=""
.else
PLIST_SUB+=	JAVA14="@comment "
.endif

pre-patch:
	@${ECHO_MSG} "Installation settings:"
	@${ECHO_MSG} "   Destination directory:    ${APP_HOME}"
	@${ECHO_MSG} "   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_MSG} "   Location of Java port:    ${JAVA_PORT}"
	@${ECHO_MSG} "   Running as (user/group):  ${TOMCAT_USER}/${TOMCAT_GROUP}"
	@${ECHO_MSG} "   HTTP port:                ${HTTP_PORT}"
	@${ECHO_MSG} "   Shutdown listener port:   ${SHUTDOWN_PORT}"
	@${ECHO_MSG} "   AJP 1.3 connector port:   ${AJP_1_3_PORT}"
	@${ECHO_MSG} "   Logfile stdout:           ${STDOUT_LOG}"
	@${ECHO_MSG} "   Logfile stderr:           ${STDERR_LOG}"

post-patch:
	@${ECHO_MSG} -n ">> Removing unneeded files..."
	@${RM} -f `${FIND} ${WRKSRC} -name '*.bat'` `${FIND} ${WRKSRC} -name '*.orig'` `${FIND} ${WRKSRC} -name '*.exe'`
	@${ECHO_MSG} " [ DONE ]"

.for file in ${REPLACE_FILES}
	@${ECHO_MSG} -n ">> Customizing `basename ${file}`..."
	@${SED} ${REPLACE_LIST_TEMP} ${file} > ${WRKDIR}/`basename ${file}`
	@${ECHO_MSG} " [ DONE ]"
.endfor

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${ECHO_MSG} -n ">> Creating destination directory..."
	@${MKDIR} ${APP_HOME}
	@${MKDIR} ${LOG_DIR}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} ">> Copying files to destination directory..."
	@${CP} ${WRKDIR}/server.xml ${WRKSRC}/conf/
	@(cd ${WRKSRC};${FIND} conf -type f | ${SED} -e '/${CONF_EXT}/d') \
		| while read a; do \
			${MV} ${WRKSRC}/$$a ${WRKSRC}/$$a.${CONF_EXT}; \
			if [ ! -e "${APP_HOME}/$$a" ]; then \
				${ECHO_MSG} "	Installing local configuration file: ${APP_HOME}/$$a"; \
				${CP} ${WRKSRC}/$$a.${CONF_EXT} ${WRKSRC}/$$a; \
			else \
				${ECHO_MSG} "	Preserving local configuration file: ${APP_HOME}/$$a"; \
			fi; \
		done
	@${CP} -R ${WRKSRC}/* ${APP_HOME}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Creating log files..."
	@${INSTALL} -m 664 -o ${TOMCAT_USER} -g ${TOMCAT_GROUP} /dev/null ${STDOUT_LOG}
	@${INSTALL} -m 664 -o ${TOMCAT_USER} -g ${TOMCAT_GROUP} /dev/null ${STDERR_LOG}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Creating symlink to tools.jar..."
	@${LN} -sf ${JAVA_HOME}/lib/tools.jar ${APP_HOME}/common/lib/tools.jar
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Fixing ownership settings..."
	@${CHOWN} -R ${TOMCAT_USER}:${TOMCAT_GROUP} ${APP_HOME}/conf ${APP_HOME}/logs \
		${APP_HOME}/temp ${APP_HOME}/work ${APP_HOME}/webapps
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Fixing permissions..."
	@${FIND} ${APP_HOME} -type d | while read a; do\
		${CHMOD} 755 "$$a"; \
	done
	@${ECHO_MSG} " [ DONE ]"

post-install:
	@${ECHO_MSG} "${APP_TITLE} ${PORTVERSION} has been installed in ${APP_HOME}."
.include <bsd.port.post.mk>
