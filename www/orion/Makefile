# New ports collection makefile for:   orion
# Date created:        22 December 2000
# Whom:                Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	orion
PORTVERSION=	1.4.5
PORTREVISION=	7
CATEGORIES=	www java
MASTER_SITES=	ftp://ftp.sunet.se/pub/database/utils/orionserver/ \
		http://www.metaverse.nl/~ernst/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sobomax
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	znerd@FreeBSD.org

BUILD_DEPENDS=	${JAVA_HOME}/bin/java:${PORTSDIR}/java/jdk13
RUN_DEPENDS=	${JAVA_HOME}/bin/java:${PORTSDIR}/java/jdk13

USE_ZIP=	YES
NO_BUILD=	YES

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB+=	T=${ORION_HOME:S/^${PREFIX}\///}
ORION_HOME?=	${PREFIX}/${PKGBASE}${PORTVERSION}
PORTTITLE=	Orion Server
ORIONCTL_NAME=	orionctl
ORIONCTL_DEST=	${PREFIX}/bin/${ORIONCTL_NAME}
RC_SCRIPT=	${PREFIX}/etc/rc.d/${PORTNAME}.sh
JAVA_HOME?=	${LOCALBASE}/jdk1.3.1
JIKES_LOCATION=	${LOCALBASE}/bin/jikes
WITH_JIKES?=	YES
.if ${WITH_JIKES} == "YES"
RUN_DEPENDS+=	${JIKES_LOCATION}:${PORTSDIR}/java/jikes
.endif
USER_NAME?=	${PORTNAME}
GROUP_NAME?=	${USER_NAME}
USER_ID?=	7104
GROUP_ID?=	${USER_ID}
PW?=		/usr/sbin/pw
LISTEN_PORT?=	8090
AUTO_START?=	YES

.include <bsd.port.pre.mk>

pre-install:
	@${ECHO} "Installation settings:"
	@${ECHO} "   Destination directory:   ${ORION_HOME}"
	@${ECHO} "   Control script location: ${ORIONCTL_DEST}"
	@${ECHO} "   Startup script location: ${RC_SCRIPT}"
	@${ECHO} "   Startup script location: ${RC_SCRIPT}"
	@${ECHO} "   Location of JDK:         ${JAVA_HOME}"
	@${ECHO} "   Using Jikes:             ${WITH_JIKES}"
	@${ECHO} "   Running as (user/group): ${USER_NAME}/${GROUP_NAME} (${USER_ID}:${GROUP_ID})"
	@${ECHO} "   Port to listen at:       ${LISTEN_PORT}"
	@${ECHO} "   Starting after install:  ${AUTO_START}"

do-install:
	@# Add the group and the user if they do not exist
	${PW} groupadd -n ${GROUP_NAME} -g ${GROUP_ID} || true
	${PW} useradd -n ${USER_NAME} -u ${USER_ID} -g ${GROUP_NAME} -c "Orion Server account" -d ${ORION_HOME} -s ${SH} -h - || true

	@# Create the destination directory for Orion
	${MKDIR} ${ORION_HOME}

	@# Copy all files and make them rwxr-xr-x
	${CP} -R ${WRKSRC}/* ${ORION_HOME}
	${CHMOD} 755 `find ${ORION_HOME} -type d`

	@# Configure for use of Jikes, if necessary
.if ${WITH_JIKES} == "YES"
	${CAT} ${WRKSRC}/config/server.xml \
	| ${SED} "/\<!-- \<compiler executable=\"jikes\" classpath=\"\/myjdkdir\/jre\/lib\/rt.jar\" \/\> -->/s//\<compiler executable=\"${JIKES_LOCATION:S/\//\\\//g}\" classpath=\"${JAVA_HOME:S/\//\\\//g}\/jre\/lib\/rt.jar\"\/\>/" \
	> ${ORION_HOME}/config/server.xml
.endif

	@# Configure the port to listen to
	${CAT} ${WRKSRC}/config/default-web-site.xml \
	| ${SED} "/port=\"80\"/s//port=\"${LISTEN_PORT}\"/" \
	> ${ORION_HOME}/config/default-web-site.xml

	@# Install the 'orionctl' script
	${CAT} ${FILESDIR}/${ORIONCTL_NAME} \
	| ${SED} "/%%PORTNAME%%/s//${PORTNAME}/" \
	| ${SED} "/%%PORTVERSION%%/s//${PORTVERSION}/" \
	| ${SED} "/%%ORION_HOME%%/s//${ORION_HOME:S/\//\\\//g}/" \
	| ${SED} "/%%RC_SCRIPT_NAME%%/s//${PORTNAME}.sh/" \
	| ${SED} "/%%JAVA_HOME%%/s//${JAVA_HOME:S/\//\\\//g}/" \
	| ${SED} "/%%USER_NAME%%/s//${USER_NAME}/" \
	> ${ORIONCTL_DEST}
	${CHMOD} 755 ${ORIONCTL_DEST}

	@# Fix a small typo in the index.html served as the root
	${CAT} ${WRKSRC}/default-web-app/index.html \
	| ${SED} "/1\.4\.0/s//${PORTVERSION}/" \
	> ${ORION_HOME}/default-web-app/index.html

	@# Install the startup script
	${LN} -sf ${ORIONCTL_DEST} ${RC_SCRIPT}

	@# Create the 'application-deployments' directory, since Orion will
	@# otherwise create it when it is first run
	${MKDIR} ${ORION_HOME}/application-deployments

	@# Install the tools.jar file from the JDK, since it is needed by Orion
	${LN} -sf ${JAVA_HOME}/lib/tools.jar ${ORION_HOME}/tools.jar

	@# Change ownership for the files
	${CHOWN} -R ${USER_NAME}:${GROUP_NAME} ${ORION_HOME}

	@# Install the man page
.if !defined(NOPORTDOCS)
	${CAT} ${FILESDIR}/${ORIONCTL_NAME}.1 \
	| ${SED} "/%%PREFIX%%/s//${PREFIX:S/\//\\\//g}/" \
	> ${WRKDIR}/${ORIONCTL_NAME}.1
	${INSTALL_MAN} ${WRKDIR}/${ORIONCTL_NAME}.1 ${MANPREFIX}/man/man1
.endif

post-install:
	@${ECHO} "${PORTTITLE} ${PORTVERSION} has been installed in ${ORION_HOME}."
.if !defined(NOPORTDOCS)
	@${ECHO} "Use 'man orionctl' for information about starting and stopping Orion."
.endif
.if ${AUTO_START} == "YES"
	@${ECHO} -n "Starting..."
	@${RC_SCRIPT} start
	@${ECHO} ""
.endif

.include <bsd.port.post.mk>
