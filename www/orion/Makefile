# New ports collection makefile for:   orion
# Date created:        22 December 2000
# Whom:                Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	orion
PORTVERSION=	1.5.2
PORTREVISION=	5
CATEGORIES=	www java
MASTER_SITES=	http://www.orionserver.com/distributions/ \
		http://www.atlassian.com/software/orion/downloads/ \
		http://www.metaverse.nl/~ernst/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	znerd
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	znerd@FreeBSD.org

BUILD_DEPENDS=	${JAVA_HOME}/bin/javac:${JAVA_PORT}
RUN_DEPENDS=	${JAVA_HOME}/bin/javac:${JAVA_PORT}

USE_ZIP=	YES
NO_BUILD=	YES

WRKSRC=		${WRKDIR}/${PORTNAME}
APP_HOME?=	${PREFIX}/${PKGBASE}${PORTVERSION}
LOG_DIR=	${APP_HOME}/log
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///}
APP_TITLE=	Orion Server
APP_SHORTNAME=	${PORTNAME}
CONTROL_SCRIPT_NAME=	${APP_SHORTNAME}ctl
CONTROL_SCRIPT=	${PREFIX}/bin/${CONTROL_SCRIPT_NAME}
STARTUP_ORDER=	020
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/${STARTUP_ORDER}.${PORTNAME}.sh
JAVA_HOME?=	${LOCALBASE}/jdk1.3.1
JAVA_PORT?=	${PORTSDIR}/java/jdk13
JIKES_LOCATION=	${LOCALBASE}/bin/jikes
WITH_JIKES?=	YES
.if ${WITH_JIKES} == "YES"
RUN_DEPENDS+=	${JIKES_LOCATION}:${PORTSDIR}/java/jikes
.endif
USER_NAME=	www
GROUP_NAME=	www
PW?=		/usr/sbin/pw
HTTP_PORT?=	8090
RMI_PORT?=	23791
STDOUT_LOG=	${LOG_DIR}/stdout.log
STDERR_LOG=	${LOG_DIR}/stderr.log
AUTO_START?=	NO
PID_FILE=	/var/run/orion.pid

pre-install:
	@${ECHO} "Installation settings:"
	@${ECHO} "   Destination directory:   ${APP_HOME}"
	@${ECHO} "   Control script location: ${CONTROL_SCRIPT}"
	@${ECHO} "   Startup script location: ${STARTUP_SCRIPT}"
	@${ECHO} "   Location of JDK:         ${JAVA_HOME}"
	@${ECHO} "   Location of Java port:   ${JAVA_PORT}"
	@${ECHO} "   Using Jikes:             ${WITH_JIKES}"
	@${ECHO} "   Running as (user/group): ${USER_NAME}/${GROUP_NAME}"
	@${ECHO} "   HTTP port:               ${HTTP_PORT}"
	@${ECHO} "   RMI port:                ${RMI_PORT}"
	@${ECHO} "   Starting after install:  ${AUTO_START}"
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

do-install:
	@# Create the destination directory
	${MKDIR} ${APP_HOME}

	@# Copy all files except .bat and .orig files
	${RM} -f `${FIND} ${WRKSRC} -name '*.bat'`
	${RM} -f `${FIND} ${WRKSRC} -name '*.orig'`
	${CP} -R ${WRKSRC}/* ${APP_HOME}
	${CHMOD} 755 `find ${APP_HOME} -type d`

	@# Configure for use of Jikes, if necessary
.if ${WITH_JIKES} == "YES"
	${CAT} ${WRKSRC}/config/server.xml \
	| ${SED} "/\<!-- \<compiler executable=\"jikes\" classpath=\"\/myjdkdir\/jre\/lib\/rt.jar\" \/\> -->/s//\<compiler executable=\"${JIKES_LOCATION:S/\//\\\//g}\" classpath=\"${JAVA_HOME:S/\//\\\//g}\/jre\/lib\/rt.jar\"\/\>/" \
	> ${APP_HOME}/config/server.xml
.endif

	@# Configure the port for the HTTP server
	${CAT} ${WRKSRC}/config/default-web-site.xml \
	| ${SED} "/port=\"80\"/s//port=\"${HTTP_PORT}\"/" \
	> ${APP_HOME}/config/default-web-site.xml

	@# Configure the port for the RMI server
	${CAT} ${WRKSRC}/config/rmi.xml \
	| ${SED} "/<rmi-server>/s//<rmi-server host=\"\[ALL\]\" port=\"${RMI_PORT}\">/" \
	> ${APP_HOME}/config/rmi.xml

	@# Install the control script
	${CAT} ${FILESDIR}/${CONTROL_SCRIPT_NAME} \
	| ${SED} "/%%PORTNAME%%/s//${PORTNAME}/" \
	| ${SED} "/%%PORTVERSION%%/s//${PORTVERSION}/" \
	| ${SED} "/%%APP_TITLE%%/s//${APP_TITLE}/" \
	| ${SED} "/%%APP_SHORTNAME%%/s//${APP_SHORTNAME}/" \
	| ${SED} "/%%APP_HOME%%/s//${APP_HOME:S/\//\\\//g}/" \
	| ${SED} "/%%LOG_DIR%%/s//${LOG_DIR:S/\//\\\//g}/" \
	| ${SED} "/%%RC_SCRIPT_NAME%%/s//${PORTNAME}.sh/" \
	| ${SED} "/%%JAVA_HOME%%/s//${JAVA_HOME:S/\//\\\//g}/" \
	| ${SED} "/%%USER_NAME%%/s//${USER_NAME}/" \
	| ${SED} "/%%GROUP_NAME%%/s//${GROUP_NAME}/" \
	| ${SED} "/%%STDOUT_LOG%%/s//${STDOUT_LOG:S/\//\\\//g}/" \
	| ${SED} "/%%STDERR_LOG%%/s//${STDERR_LOG:S/\//\\\//g}/" \
	| ${SED} "/%%PID_FILE%%/s//${PID_FILE:S/\//\\\//g}/" \
	> ${CONTROL_SCRIPT}
	${CHMOD} 755 ${CONTROL_SCRIPT}

	@# Install the startup script
	${CAT} ${FILESDIR}/${PORTNAME}.sh \
	| ${SED} "/%%USER_NAME%%/s//${USER_NAME}/" \
	| ${SED} "/%%APP_SHORTNAME%%/s//${APP_SHORTNAME}/" \
	| ${SED} "/%%CONTROL_SCRIPT%%/s//${CONTROL_SCRIPT:S/\//\\\//g}/" \
	> ${STARTUP_SCRIPT}
	${CHMOD} 0554 ${STARTUP_SCRIPT}

	@# Create the directories that the application will create it at the
	@# first run
	${MKDIR} ${APP_HOME}/application-deployments

	@# Install the tools.jar file from the JDK, since it is needed by Orion
	${LN} -sf ${JAVA_HOME}/lib/tools.jar ${APP_HOME}/tools.jar

	@# Change ownership for the files
	${CHOWN} -R ${USER_NAME}:${GROUP_NAME} ${APP_HOME}

	@# Install the man page
.if !defined(NOPORTDOCS)
	${CAT} ${FILESDIR}/${CONTROL_SCRIPT_NAME}.1 \
	| ${SED} "/%%APP_TITLE%%/s//${APP_TITLE}/" \
	| ${SED} "/%%PREFIX%%/s//${PREFIX:S/\//\\\//g}/" \
	| ${SED} "/%%CONTROL_SCRIPT_NAME%%/s//${CONTROL_SCRIPT_NAME}/" \
	| ${SED} "/%%STARTUP_ORDER%%/s//${STARTUP_ORDER}.sh/" \
	> ${WRKDIR}/${CONTROL_SCRIPT_NAME}.1
	${INSTALL_MAN} ${WRKDIR}/${CONTROL_SCRIPT_NAME}.1 ${MANPREFIX}/man/man1
.endif

post-install:
	@${ECHO} "${APP_TITLE} ${PORTVERSION} has been installed in ${APP_HOME}."
.if !defined(NOPORTDOCS)
	@${ECHO} "Use 'man ${CONTROL_SCRIPT_NAME}' for information about starting and stopping ${APP_TITLE}."
.endif
.if ${AUTO_START} == "YES"
	@${ECHO} "Starting ${APP_TITLE}..."
	@${CONTROL_SCRIPT} start || true
.endif

.include <bsd.port.mk>
