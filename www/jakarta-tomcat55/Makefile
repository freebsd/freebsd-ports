# New ports collection makefile for:	jakarta-tomcat-devel
# Date created:		Tue Aug 12 23:26:32 CST 2003
# Whom:			Kang Liu <liukang@bjpu.edu.cn>
#
# $FreeBSD$
#

PORTNAME=	jakarta-tomcat
PORTVERSION=	5.0.18
PORTREVISION=	1
CATEGORIES=	www java
MASTER_SITES=	http://www.apache.org/dist/jakarta/tomcat-5/v${PORTVERSION}/bin/ \
		http://apache.lemon4ssc.org/dist/jakarta/tomcat-5/v${PORTVERSION}/bin/ \
		http://distfiles.coredump.cn/

MAINTAINER=	liukang@bjpu.edu.cn
COMMENT=	Open-source Java web server by Apache, 5.0.x branch

USE_JAVA=	1.3+
NO_BUILD=	YES

MAJOR_VER=	${PORTVERSION:R}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
APP_HOME?=	${PREFIX}/${PKGBASE}${PORTVERSION:R}
LOG_DIR=	${APP_HOME}/logs
APP_TITLE=	Jakarta Tomcat
APP_SHORTNAME=	tomcat${MAJOR_VER:S/.//}
CONTROL_SCRIPT_NAME=	${APP_SHORTNAME}ctl
CONTROL_SCRIPT=	${PREFIX}/bin/${CONTROL_SCRIPT_NAME}
CONTROL_SCRIPT_MANPAGE_TITLE=	${CONTROL_SCRIPT_NAME:U}
STARTUP_ORDER?=	020
STARTUP_SCRIPT_NAME=	${PORTNAME}${MAJOR_VER:S/.//}.sh
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/${STARTUP_ORDER}.${STARTUP_SCRIPT_NAME}
USER=		www
GROUP=		www
PW?=		/usr/sbin/pw
HTTP_PORT?=	8180
SHUTDOWN_PORT?=	8005
WARP_PORT?=	8008
AJP_1_3_PORT?=	8009
STDOUT_LOG=	${LOG_DIR}/stdout.log
STDERR_LOG=	${LOG_DIR}/stderr.log
AUTO_START?=	NO
STOP_TIMEOUT?=	5
PID_FILE=	/var/run/${APP_SHORTNAME}.pid
REPLACE_FILES=	${PORTSDIR}/www/jakarta-tomcat4/files/daemonctl.c \
		${PORTSDIR}/www/jakarta-tomcat4/files/daemonctl.1 \
		${PORTSDIR}/www/jakarta-tomcat4/files/startup.sh \
		${WRKSRC}/conf/server.xml
JAR_FILE=	bin/bootstrap.jar
WRKDIR?=	${WRKDIRPREFIX}${.CURDIR}/work
PLIST_SUB+=     T=${APP_HOME:S/^${PREFIX}\///} WWWOWN=${USER} WWWGRP=${GROUP}
.include <bsd.port.pre.mk>

pre-patch:
	@${ECHO_CMD} "Installation settings:"
	@${ECHO_CMD} "   Destination directory:    ${APP_HOME}"
	@${ECHO_CMD} "   Control program location: ${CONTROL_SCRIPT}"
	@${ECHO_CMD} "   Startup script location:  ${STARTUP_SCRIPT}"
	@${ECHO_CMD} "   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_CMD} "   Location of Java port:    ${JAVA_PORT}"
	@${ECHO_CMD} "   Running as (user/group):  ${USER}/${GROUP}"
	@${ECHO_CMD} "   HTTP port:                ${HTTP_PORT}"
	@${ECHO_CMD} "   Shutdown listener port:   ${SHUTDOWN_PORT}"
	@${ECHO_CMD} "   WARP port:                ${WARP_PORT}"
	@${ECHO_CMD} "   AJP 1.3 connector port:   ${AJP_1_3_PORT}"
	@${ECHO_CMD} "   Logfile stdout:           ${STDOUT_LOG}"
	@${ECHO_CMD} "   Logfile stderr:           ${STDERR_LOG}"
	@${ECHO_CMD} "   Starting after install:   ${AUTO_START}"
	@${ECHO_CMD} "   Stop time-out:            ${STOP_TIMEOUT} sec."
	@PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

post-patch:
	@${ECHO_CMD} -n ">> Removing unneeded files..."
	@${RM} -f `${FIND} ${WRKSRC} -name '*.bat'` `${FIND} ${WRKSRC} -name '*.orig'` `${FIND} ${WRKSRC} -name '*.exe'`
	@${ECHO_CMD} " [ DONE ]"

.for f in ${REPLACE_FILES}
	@${ECHO_CMD} -n ">> Customizing `basename $f`..."
	@${SED} \
	-e "/%%AJP_1_3_PORT%%/s//${AJP_1_3_PORT}/g" \
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
	-e "/%%SHUTDOWN_PORT%%/s//${SHUTDOWN_PORT}/g" \
	-e "/%%STARTUP_SCRIPT_NAME%%/s//${STARTUP_SCRIPT_NAME}/g" \
	-e "/%%STARTUP_SCRIPT%%/s//${STARTUP_SCRIPT:S/\//\\\//g}/g" \
	-e "/%%STDERR_LOG%%/s//${STDERR_LOG:S/\//\\\//g}/g" \
	-e "/%%STDOUT_LOG%%/s//${STDOUT_LOG:S/\//\\\//g}/g" \
	-e "/%%STOP_TIMEOUT%%/s//${STOP_TIMEOUT}/g" \
	-e "/%%USER%%/s//${USER}/g" \
	-e "/%%WARP_PORT%%/s//${WARP_PORT}/g" \
	$f > ${WRKDIR}/`basename $f`
	@${ECHO_CMD} " [ DONE ]"
.endfor

do-install:
	@${ECHO_CMD} -n ">> Creating destination directory..."
	@${MKDIR} ${APP_HOME}
	@${MKDIR} ${LOG_DIR}
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Copying files to destination directory..."
	@${CP} -R ${WRKSRC}/* ${APP_HOME}
	@${CP} ${WRKDIR}/server.xml ${APP_HOME}/conf/
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Compiling and installing control program..."
	@${SED} \
	-e "/%%JAVA_ARGS%%/s//\"-Dcatalina.home=${APP_HOME:S/\//\\\//g}\",/g" \
	-e "/%%JAR_ARGS%%/s//\"start\",/g" \
	${WRKDIR}/daemonctl.c > ${WRKDIR}/daemonctl_.c
	@cd ${WRKDIR} && ${CC} -ansi -o ${CONTROL_SCRIPT_NAME} daemonctl_.c
	@${CP} ${WRKDIR}/${CONTROL_SCRIPT_NAME} ${CONTROL_SCRIPT}
	@${CHOWN} ${USER}:${GROUP} ${CONTROL_SCRIPT}
	@${CHMOD} 6754 ${CONTROL_SCRIPT}
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Installing startup script..."
	@${CP} ${WRKDIR}/startup.sh ${STARTUP_SCRIPT}
	@${CHMOD} 0544 ${STARTUP_SCRIPT}
	@${ECHO_CMD} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing man pages..."
	@${INSTALL_MAN} ${WRKDIR}/daemonctl.1 ${MANPREFIX}/man/man1/${CONTROL_SCRIPT_NAME}.1
	@${ECHO_CMD} " [ DONE ]"
.endif

	@${ECHO_CMD} -n ">> Creating log files..."
	@${INSTALL} /dev/null ${STDOUT_LOG}
	@${INSTALL} /dev/null ${STDERR_LOG}
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Creating symlink to tools.jar..."
	@${LN} -sf ${JAVA_HOME}/lib/tools.jar ${APP_HOME}/common/lib/tools.jar
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Fixing ownership settings..."
	@${CHOWN} -R ${USER}:${GROUP} ${APP_HOME}
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Fixing permissions..."
	@${CHMOD} 755 `${FIND} ${APP_HOME} -type d`
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Creating PID file..."
	@${TOUCH} ${PID_FILE}
	@${CHOWN} ${USER}:${GROUP} ${PID_FILE}
	@${CHMOD} 0600 ${PID_FILE}
	@${ECHO_CMD} " [ DONE ]"

post-install:
	@${ECHO_CMD} "${APP_TITLE} ${PORTVERSION} has been installed in ${APP_HOME}."
	@${ECHO_CMD} "If a user should be able to use ${CONTROL_SCRIPT_NAME}, then put this user in the group ${GROUP}."
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} "Use 'man ${CONTROL_SCRIPT_NAME}' for information about starting and stopping ${APP_TITLE}."
.endif
.if ${AUTO_START} == "YES"
	@${CONTROL_SCRIPT} start || true
.endif
.include <bsd.port.post.mk>
