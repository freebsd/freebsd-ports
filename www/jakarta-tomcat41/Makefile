# New ports collection makefile for:	jakarta-tomcat
# Date created:		20 Oct 2000
# Whom:			des
#
# $FreeBSD$
#

PORTNAME=	jakarta-tomcat
PORTVERSION=	3.2.3
PORTREVISION=	3
CATEGORIES=	www java
MASTER_SITES=	http://www.apache.org/dist/jakarta/jakarta-tomcat/release/v${PORTVERSION}/bin/ \
		http://www.metaverse.nl/~ernst/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	znerd
DIST_SUBDIR=	jakarta/tomcat/${PORTVERSION}

MAINTAINER=	znerd@FreeBSD.org

RUN_DEPENDS=	${JAVA_HOME}/bin/javac:${JAVA_PORT}

NO_BUILD=	YES

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
APP_HOME?=	${PREFIX}/${PKGBASE}${PORTVERSION}
LOG_DIR=	${APP_HOME}/logs
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///}
APP_TITLE=	Jakarta Tomcat
APP_SHORTNAME=	tomcat
APPCTL_NAME=	${APP_SHORTNAME}ctl
CTL_SCRIPT=	${PREFIX}/bin/${APPCTL_NAME}
STARTUP_ORDER?=	020
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/${STARTUP_ORDER}.${PORTNAME}.sh
JAVA_HOME?=	${LOCALBASE}/jdk1.3.1
JAVA_PORT?=	${PORTSDIR}/java/jdk13
USER_NAME?=	${APP_SHORTNAME}
GROUP_NAME?=	${USER_NAME}
USER_ID?=	7103
GROUP_ID?=	${USER_ID}
PW?=		/usr/sbin/pw
LISTEN_PORT?=	8080
STDOUT_LOG?=	${LOG_DIR}/stdout.log
STDERR_LOG?=	${LOG_DIR}/stderr.log
AUTO_START?=	NO

pre-install:
	@${ECHO_CMD} "Installation settings:"
	@${ECHO_CMD} "   Destination directory:   ${APP_HOME}"
	@${ECHO_CMD} "   Control script location: ${CTL_SCRIPT}"
	@${ECHO_CMD} "   Startup script location: ${STARTUP_SCRIPT}"
	@${ECHO_CMD} "   Location of JDK:         ${JAVA_HOME}"
	@${ECHO_CMD} "   Location of Java port:   ${JAVA_PORT}"
	@${ECHO_CMD} "   Running as (user/group): ${USER_NAME}/${GROUP_NAME} (${USER_ID}:${GROUP_ID})"
	@${ECHO_CMD} "   Port to listen at:       ${LISTEN_PORT}"
	@${ECHO_CMD} "   Logfile stdout:          ${STDOUT_LOG}"
	@${ECHO_CMD} "   Logfile stderr:          ${STDERR_LOG}"
	@${ECHO_CMD} "   Starting after install:  ${AUTO_START}"

do-install:
	@# Add the group and the user if they do not exist
	${PW} groupadd -n ${GROUP_NAME} -g ${GROUP_ID} || true
	${PW} useradd -n ${USER_NAME} -u ${USER_ID} -g ${GROUP_NAME} -c "${APP_TITLE} account" -d ${APP_HOME} -s ${SH} -h - || true

	@# Create the destination directory
	${MKDIR} ${APP_HOME}

	@# Copy all files except .bat and .orig files
	${RM} -f `${FIND} ${WRKSRC} -name '*.bat'`
	${RM} -f `${FIND} ${WRKSRC} -name '*.orig'`
	${CP} -R ${WRKSRC}/* ${APP_HOME}
	${CHMOD} 755 `find ${APP_HOME} -type d`

	@# Install the workers.properties file after processing it
	${CAT} ${WRKSRC}/conf/workers.properties \
	| ${SED} "/%%TOMCAT_HOME%%/s//${APP_HOME:S/\//\\\//g}/" \
	| ${SED} "/%%JAVA_HOME%%/s//${JAVA_HOME:S/\//\\\//g}/" \
	> ${WRKDIR}/workers.properties
	${MV} ${WRKDIR}/workers.properties ${APP_HOME}/conf/workers.properties

	@# Install the control script
	${CAT} ${FILESDIR}/${APPCTL_NAME} \
	| ${SED} "/%%PORTNAME%%/s//${PORTNAME}/" \
	| ${SED} "/%%PORTVERSION%%/s//${PORTVERSION}/" \
	| ${SED} "/%%APP_TITLE%%/s//${APP_TITLE}/" \
	| ${SED} "/%%APP_SHORTNAME%%/s//${APP_SHORTNAME}/" \
	| ${SED} "/%%APP_HOME%%/s//${APP_HOME:S/\//\\\//g}/" \
	| ${SED} "/%%LOG_DIR%%/s//${LOG_DIR:S/\//\\\//g}/" \
	| ${SED} "/%%STARTUP_SCRIPT_NAME%%/s//${PORTNAME}.sh/" \
	| ${SED} "/%%JAVA_HOME%%/s//${JAVA_HOME:S/\//\\\//g}/" \
	| ${SED} "/%%USER_NAME%%/s//${USER_NAME}/" \
	| ${SED} "/%%STDOUT_LOG%%/s//${STDOUT_LOG:S/\//\\\//g}/" \
	| ${SED} "/%%STDERR_LOG%%/s//${STDERR_LOG:S/\//\\\//g}/" \
	> ${CTL_SCRIPT}
	${CHOWN} ${USER_NAME}:${GROUP_NAME} ${CTL_SCRIPT}
	${CHMOD} 6554 ${CTL_SCRIPT}

	@# Install the startup script
	${CP} ${FILESDIR}/${PORTNAME}.sh ${STARTUP_SCRIPT}
	${CHMOD} 0554 ${STARTUP_SCRIPT}

	@# Create the directories that the application will create at the
	@# first run
	${MKDIR} ${LOG_DIR}
	${CHMOD} 6775 ${LOG_DIR}

	@# Install the server.xml file after processing it
	${CAT} ${WRKSRC}/conf/server.xml \
	| ${SED} "/%%LISTEN_PORT%%/s//${LISTEN_PORT}/" \
	> ${WRKDIR}/server.xml
	${MV} ${WRKDIR}/server.xml ${APP_HOME}/conf/server.xml

	@# Change ownership for the files
	${CHOWN} -R ${USER_NAME}:${GROUP_NAME} ${APP_HOME}

	@# Change the execute permissions for all shell scripts
	${CHMOD} 0554 ${APP_HOME}/bin/*

	@# Install the man page
.if !defined(NOPORTDOCS)
	${CAT} ${FILESDIR}/${APPCTL_NAME}.1 \
	| ${SED} "/%%PREFIX%%/s//${PREFIX:S/\//\\\//g}/" \
	> ${WRKDIR}/${APPCTL_NAME}.1
	${INSTALL_MAN} ${WRKDIR}/${APPCTL_NAME}.1 ${MANPREFIX}/man/man1
.endif

post-install:
	@${ECHO_CMD} "${APP_TITLE} ${PORTVERSION} has been installed in ${APP_HOME}."
	@${ECHO_CMD} "If you would like a user to be able to use ${APPCTL_NAME}, then put this user in the group ${GROUP_NAME}."
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} "Use 'man ${APPCTL_NAME}' for information about starting and stopping ${APP_TITLE}."
.endif
.if ${AUTO_START} == "YES"
	@${ECHO_CMD} "Starting ${APP_TITLE}..."
	@${CTL_SCRIPT} start || true
.endif

.include <bsd.port.mk>
