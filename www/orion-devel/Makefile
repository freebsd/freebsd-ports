# New ports collection makefile for:   orion
# Date created:        22 December 2000
# Whom:                Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	orion
PORTVERSION=	1.5.2
PORTREVISION=	7
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
ADMIN_PASSWORD?=	admin
DEFAULT_USER_PASSWORD?=	passw0rd
APP_TITLE=	Orion Server
APP_SHORTNAME=	${PORTNAME}
CONTROL_SCRIPT_NAME=	${APP_SHORTNAME}ctl
CONTROL_SCRIPT=	${PREFIX}/bin/${CONTROL_SCRIPT_NAME}
STARTUP_ORDER=	020
STARTUP_SCRIPT_NAME=	${PORTNAME}.sh
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/${STARTUP_ORDER}.${STARTUP_SCRIPT_NAME}
JAVA_HOME?=	${LOCALBASE}/jdk1.3.1
JAVA_PORT?=	${PORTSDIR}/java/jdk13
JIKES_LOCATION=	${LOCALBASE}/bin/jikes
WITH_JIKES?=	YES
.if ${WITH_JIKES} == "YES"
RUN_DEPENDS+=	${JIKES_LOCATION}:${PORTSDIR}/java/jikes
.endif
USER=	www
GROUP=	www
PW?=		/usr/sbin/pw
HTTP_PORT?=	8090
RMI_PORT?=	23791
STDOUT_LOG=	${LOG_DIR}/stdout.log
STDERR_LOG=	${LOG_DIR}/stderr.log
AUTO_START?=	NO
PID_FILE=	/var/run/orion.pid

pre-install:
	@${ECHO_CMD} "Installation settings:"
	@${ECHO_CMD} "   Destination directory:   ${APP_HOME}"
	@${ECHO_CMD} "   Control script location: ${CONTROL_SCRIPT}"
	@${ECHO_CMD} "   Startup script location: ${STARTUP_SCRIPT}"
	@${ECHO_CMD} "   Location of JDK:         ${JAVA_HOME}"
	@${ECHO_CMD} "   Location of Java port:   ${JAVA_PORT}"
	@${ECHO_CMD} "   Using Jikes:             ${WITH_JIKES}"
	@${ECHO_CMD} "   Running as (user/group): ${USER}/${GROUP}"
	@${ECHO_CMD} "   HTTP port:               ${HTTP_PORT}"
	@${ECHO_CMD} "   RMI port:                ${RMI_PORT}"
	@${ECHO_CMD} "   Starting after install:  ${AUTO_START}"
	@${ECHO_CMD} "   Password for 'admin':    ${ADMIN_PASSWORD}"
	@${ECHO_CMD} "   Password for 'user':     ${DEFAULT_USER_PASSWORD}"
	@PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

do-install:
	@# Remove all .bat and .orig files from the work directory
	${RM} -f `${FIND} ${WRKSRC} -name '*.bat'`
	${RM} -f `${FIND} ${WRKSRC} -name '*.orig'`

	@# Create the destination directory
	${MKDIR} ${APP_HOME}

	@# Copy all files to the target directory
	${CP} -R ${WRKSRC}/* ${APP_HOME}

	@# Fix the permissions for all directories
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

	@# Apply all text replacements
.for f in ${CONTROL_SCRIPT_NAME} ${CONTROL_SCRIPT_NAME}.1 ${STARTUP_SCRIPT_NAME} principals.xml
	@${ECHO_CMD} -n "Applying text replacements to $f..."
	@${SED} \
	-e "/%%ADMIN_PASSWORD%%/s//${ADMIN_PASSWORD}/" \
	-e "/%%APP_HOME%%/s//${APP_HOME:S/\//\\\//g}/" \
	-e "/%%APP_SHORTNAME%%/s//${APP_SHORTNAME}/" \
	-e "/%%APP_TITLE%%/s//${APP_TITLE}/" \
	-e "/%%CONTROL_SCRIPT%%/s//${CONTROL_SCRIPT:S/\//\\\//g}/" \
	-e "/%%CONTROL_SCRIPT_NAME%%/s//${CONTROL_SCRIPT_NAME}/" \
	-e "/%%DEFAULT_USER_PASSWORD%%/s//${DEFAULT_USER_PASSWORD}/" \
	-e "/%%GROUP%%/s//${GROUP}/" \
	-e "/%%JAVA_HOME%%/s//${JAVA_HOME:S/\//\\\//g}/" \
	-e "/%%LOG_DIR%%/s//${LOG_DIR:S/\//\\\//g}/" \
	-e "/%%PORTNAME%%/s//${PORTNAME}/" \
	-e "/%%PORTVERSION%%/s//${PORTVERSION}/" \
	-e "/%%STARTUP_SCRIPT_NAME%%/s//${STARTUP_SCRIPT_NAME}/" \
	-e "/%%STDERR_LOG%%/s//${STDERR_LOG:S/\//\\\//g}/" \
	-e "/%%STDOUT_LOG%%/s//${STDOUT_LOG:S/\//\\\//g}/" \
	-e "/%%PREFIX%%/s//${PREFIX:S/\//\\\//g}/" \
	-e "/%%PID_FILE%%/s//${PID_FILE:S/\//\\\//g}/" \
	-e "/%%USER%%/s//${USER}/" \
	${FILESDIR}/$f > ${WRKDIR}/$f
	@${ECHO_CMD} " [ DONE ]"
.endfor

	@# Install the control script
	${CP} ${WRKDIR}/${CONTROL_SCRIPT_NAME} ${CONTROL_SCRIPT}
	${CHMOD} 0755 ${CONTROL_SCRIPT}

.if !defined(NOPORTDOCS)
	@# Install the man page
	${INSTALL_MAN} ${WRKDIR}/${CONTROL_SCRIPT_NAME}.1 ${MANPREFIX}/man/man1
.endif

	@# Install the startup script
	${CP} ${WRKDIR}/${STARTUP_SCRIPT_NAME} ${STARTUP_SCRIPT}
	${CHMOD} 0544 ${STARTUP_SCRIPT}

	@# Install the principals.xml file
	${CP} ${WRKDIR}/principals.xml ${APP_HOME}/config/

	@# Create any directories the application will create it at the
	@# first run
	${MKDIR} ${APP_HOME}/application-deployments

	@# Change ownership for the files
	${CHOWN} -R ${USER}:${GROUP} ${APP_HOME}

	@# Link the tools.jar file from the JDK, since it is needed by Orion
	${LN} -sf ${JAVA_HOME}/lib/tools.jar ${APP_HOME}/tools.jar

	@# Create the PID file
	${TOUCH} ${PID_FILE}
	${CHOWN} ${USER}:${GROUP} ${PID_FILE}
	${CHMOD} 0600 ${PID_FILE}

post-install:
	@${ECHO_CMD} "${APP_TITLE} ${PORTVERSION} has been installed in ${APP_HOME}."
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} "Use 'man ${CONTROL_SCRIPT_NAME}' for information about starting and stopping ${APP_TITLE}."
.endif
.if ${AUTO_START} == "YES"
	@${CONTROL_SCRIPT} start || true
.endif

.include <bsd.port.mk>
