# New ports collection makefile for:	jakarta-tomcat
# Date created:		20 Oct 2000
# Whom:			des
#
# $FreeBSD$
#

PORTNAME=	jakarta-tomcat
PORTVERSION=	3.3.2
PORTREVISION=	1
CATEGORIES=	www java
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	tomcat-3/v${PORTVERSION}/bin

MAINTAINER=	liukang@bjut.edu.cn
COMMENT=	Open-source Java web server by Apache, stable 3.x branch

.if !defined(NOPORTDOCS)
MAN1=	${CONTROL_SCRIPT_NAME}.1
.endif

USE_JAVA=	YES
JAVA_VERSION=	1.2+
NO_BUILD=	YES
LATEST_LINK=	${APP_SHORTNAME}

MAJOR_VER=	${PORTVERSION:R:R}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
APP_HOME?=	${PREFIX}/${PKGBASE}${PORTVERSION:R}
LOG_DIR=	${APP_HOME}/logs
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///} WWWOWN=${USER} WWWGRP=${GROUP}
APP_TITLE=	Jakarta Tomcat
APP_SHORTNAME=	tomcat${MAJOR_VER}
CONTROL_SCRIPT_NAME=	${APP_SHORTNAME}ctl
CONTROL_SCRIPT=	${PREFIX}/bin/${CONTROL_SCRIPT_NAME}
CONTROL_SCRIPT_MANPAGE_TITLE=	${CONTROL_SCRIPT_NAME:U}
STARTUP_ORDER?=	020
STARTUP_SCRIPT_NAME=	${PORTNAME}${MAJOR_VER}.sh
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/${STARTUP_ORDER}.${STARTUP_SCRIPT_NAME}
USER=		www
GROUP=		www
PW?=		/usr/sbin/pw
HTTP_PORT?=	8080
STDOUT_LOG=	${LOG_DIR}/stdout.log
STDERR_LOG=	${LOG_DIR}/stderr.log
AUTO_START?=	NO
STOP_TIMEOUT?=	5
PID_FILE=	/var/run/${APP_SHORTNAME}.pid
REPLACE_FILES=	${PORTSDIR}/www/jakarta-tomcat4/files/daemonctl.c \
		${PORTSDIR}/www/jakarta-tomcat4/files/daemonctl.1 \
		${PORTSDIR}/www/jakarta-tomcat4/files/startup.sh \
		${WRKSRC}/conf/server.xml
JAR_FILE=	lib/tomcat.jar
CONF_EXT=	sample
PLIST_SUB+=	CONF_EXT=${CONF_EXT}
.include <bsd.port.pre.mk>

pre-patch:
	@${ECHO_MSG} "Installation settings:"
	@${ECHO_MSG} "   Destination directory:    ${APP_HOME}"
	@${ECHO_MSG} "   Control program location: ${CONTROL_SCRIPT}"
	@${ECHO_MSG} "   Startup script location:  ${STARTUP_SCRIPT}"
	@${ECHO_MSG} "   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_MSG} "   Location of Java port:    ${JAVA_PORT}"
	@${ECHO_MSG} "   Running as (user/group):  ${USER}/${GROUP}"
	@${ECHO_MSG} "   HTTP port:                ${HTTP_PORT}"
	@${ECHO_MSG} "   Logfile stdout:           ${STDOUT_LOG}"
	@${ECHO_MSG} "   Logfile stderr:           ${STDERR_LOG}"
	@${ECHO_MSG} "   Starting after install:   ${AUTO_START}"
	@${ECHO_MSG} "   Stop time-out:            ${STOP_TIMEOUT} sec."
	@PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

post-patch:
	@${ECHO_MSG} -n ">> Removing unneeded files..."
	@${RM} -f `${FIND} ${WRKSRC} -name '*.bat'` `${FIND} ${WRKSRC} -name '*.orig'` `${FIND} ${WRKSRC} -name '*.exe'`
	@${ECHO_MSG} " [ DONE ]"

.for f in ${REPLACE_FILES}
	@${ECHO_MSG} -n ">> Customizing `basename $f`..."
	@${SED} \
	-e "/%%APP_HOME%%/s//${APP_HOME:S/\//\\\//g}/g" \
	-e "/%%APP_SHORTNAME%%/s//${APP_SHORTNAME}/g" \
	-e "/%%APP_TITLE%%/s//${APP_TITLE}/g" \
	-e "/%%CONTROL_SCRIPT%%/s//${CONTROL_SCRIPT:S/\//\\\//g}/g" \
	-e "/%%CONTROL_SCRIPT_MANPAGE_TITLE%%/s//${CONTROL_SCRIPT_MANPAGE_TITLE}/g" \
	-e "/%%CONTROL_SCRIPT_NAME%%/s//${CONTROL_SCRIPT_NAME}/g" \
	-e "/%%GROUP%%/s//${GROUP}/g" \
	-e "/%%HTTP_PORT%%/s//${HTTP_PORT}/g" \
	-e "/%%JAVA_CMD%%/s//bin\/java/g" \
	-e "/%%JAVA_HOME%%/s//${JAVA_HOME:S/\//\\\//g}/g" \
	-e "/%%JAR_FILE%%/s//${JAR_FILE:S/\//\\\//g}/g" \
	-e "/%%LOG_DIR%%/s//${LOG_DIR:S/\//\\\//g}/g" \
	-e "/%%PID_FILE%%/s//${PID_FILE:S/\//\\\//g}/g" \
	-e "/%%PORTNAME%%/s//${PORTNAME}/g" \
	-e "/%%PORTVERSION%%/s//${PORTVERSION}/g" \
	-e "/%%PREFIX%%/s//${PREFIX:S/\//\\\//g}/g" \
	-e "/%%STARTUP_SCRIPT_NAME%%/s//${STARTUP_SCRIPT_NAME}/g" \
	-e "/%%STARTUP_SCRIPT%%/s//${STARTUP_SCRIPT:S/\//\\\//g}/g" \
	-e "/%%STDERR_LOG%%/s//${STDERR_LOG:S/\//\\\//g}/g" \
	-e "/%%STDOUT_LOG%%/s//${STDOUT_LOG:S/\//\\\//g}/g" \
	-e "/%%STOP_TIMEOUT%%/s//${STOP_TIMEOUT}/g" \
	-e "/%%USER%%/s//${USER}/g" \
	$f > ${WRKDIR}/`basename $f`
	@${ECHO_MSG} " [ DONE ]"
.endfor

do-install:
	@${ECHO_MSG} -n ">> Creating destination directory..."
	@${MKDIR} ${APP_HOME}
	@${MKDIR} ${LOG_DIR}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} ">> Copying files to destination directory..."
	@(cd ${WRKSRC};${FIND} conf -type f | ${SED} -e '/${CONF_EXT}/d') \
		| while read a; do \
			${MV} ${WRKSRC}/$$a ${WRKSRC}/$$a.${CONF_EXT}; \
			if [ ! -e "${APP_HOME}/$$a" ]; then \
				${ECHO_MSG} "	Installing local configuration file: $$a"; \
				${CP} ${WRKSRC}/$$a.${CONF_EXT} ${WRKSRC}/$$a; \
			else \
				${ECHO_MSG} "	Preserving local configuration file: $$a"; \
			fi; \
		done
	@${CP} -R ${WRKSRC}/* ${APP_HOME}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Compiling and installing control program..."
	@${SED} \
	-e "/%%JAVA_ARGS%%/s//\"-Dtomcat.install=${APP_HOME:S/\//\\\//g}\",/g" \
	-e "/%%JAR_ARGS%%/s//\"run\",/g" \
	${WRKDIR}/daemonctl.c > ${WRKDIR}/daemonctl_.c
	@cd ${WRKDIR} && ${CC} -ansi -o ${CONTROL_SCRIPT_NAME} daemonctl_.c
	@${CP} ${WRKDIR}/${CONTROL_SCRIPT_NAME} ${CONTROL_SCRIPT}
	@${CHOWN} ${USER}:${GROUP} ${CONTROL_SCRIPT}
	@${CHMOD} 6754 ${CONTROL_SCRIPT}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Installing startup script..."
	@${CP} ${WRKDIR}/startup.sh ${STARTUP_SCRIPT}
	@${CHMOD} 0544 ${STARTUP_SCRIPT}
	@${ECHO_MSG} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing man pages..."
	@${INSTALL_MAN} ${WRKDIR}/daemonctl.1 ${MANPREFIX}/man/man1/${CONTROL_SCRIPT_NAME}.1
	@${ECHO_MSG} " [ DONE ]"
.endif

	@${ECHO_MSG} -n ">> Creating log files..."
	@${INSTALL} /dev/null ${STDOUT_LOG}
	@${INSTALL} /dev/null ${STDERR_LOG}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Fixing ownership settings..."
	@${CHOWN} -R ${USER}:${GROUP} ${APP_HOME}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Fixing permissions..."
	@${CHMOD} 755 `${FIND} ${APP_HOME} -type d`
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Creating PID file..."
	@${TOUCH} ${PID_FILE}
	@${CHOWN} ${USER}:${GROUP} ${PID_FILE}
	@${CHMOD} 0600 ${PID_FILE}
	@${ECHO_MSG} " [ DONE ]"

post-install:
	@${ECHO_MSG} "${APP_TITLE} ${PORTVERSION} has been installed in ${APP_HOME}."
	@${ECHO_MSG} "If a user should be able to use ${CONTROL_SCRIPT_NAME}, then put this user in the group ${GROUP}."
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "Use 'man ${CONTROL_SCRIPT_NAME}' for information about starting and stopping ${APP_TITLE}."
.endif
.if ${AUTO_START} == "YES"
	@${CONTROL_SCRIPT} start || true
.endif

.include <bsd.port.post.mk>
