# Created by: Nemo Liu <nemoliu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	geronimo
DISTVERSION=	3.0-beta-1
PORTREVISION=	1
CATEGORIES=	www devel java
MASTER_SITES=	APACHE/geronimo/${DISTVERSION}
DISTNAME=	${PORTNAME}-${WEBSERVER}-javaee6-${DISTVERSION}-bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source Java EE 5 application server

USES=		cpe
USE_JAVA=	yes
NO_BUILD=	yes

CPE_VENDOR=	apache
CPE_VERSION=	${DISTVERSION:C/-.*//}
CPE_UPDATE=	${DISTVERSION:C/[^-]*((-.*)?)/\1/:C/-//g}

USE_RC_SUBR=	geronimo3
SUB_FILES=	pkg-deinstall

OPTIONS_DEFINE=	TOMCAT7
TOMCAT7_DESC=	Use Tomcat instead of default Jetty

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTOMCAT7}
WEBSERVER=	tomcat7
.else
WEBSERVER=	jetty8
.endif

MAJOR_VER=	${PORTVERSION:C/\..*//}
APP_HOME?=	${PREFIX}/${PKGBASE}${MAJOR_VER}
LOG_DIR=	${APP_HOME}/var/log
APP_TITLE=	Geronimo
APP_SHORTNAME=	geronimo${MAJOR_VER}
.if defined(GERONIMO_USER)
IGNORE=	no longer allows customisation of GERONIMO_USER or GERONIMO_GROUP
.endif
GERONIMO_USER?=	www
GERONIMO_GROUP?=www
GERONIMO_OUT=	${LOG_DIR}/geronimo.out
PID_FILE=	/var/run/${APP_SHORTNAME}.pid
WRKDIR?=	${WRKDIRPREFIX}${.CURDIR}/${_WRKDIR}
WRKSRC=		${WRKDIR}/${DISTNAME:S/-bin//}
JAR_FILE=	bin/server.jar
PLIST_FILES=	"@(${GERONIMO_USER},${GERONIMO_GROUP},) ${GERONIMO_OUT:S,^${PREFIX}/,,}"

SUB_LIST=	GERONIMO_HOME=${APP_HOME} \
		APP_SHORTNAME=${APP_SHORTNAME} \
		APP_TITLE="${APP_TITLE}" \
		GROUP=${GERONIMO_GROUP} \
		HTTP_PORT=${HTTP_PORT} \
		JAR_FILE=${JAR_FILE} \
		PID_FILE=${PID_FILE} \
		GERONIMO_OUT=${GERONIMO_OUT} \
		USER=${GERONIMO_USER} \
		GERONIMO_VERSION=${MAJOR_VER} \
		GERONIMO_OUT=${GERONIMO_OUT} \
		JAVA_HOME=${JAVA_HOME}

pre-patch:
	@${ECHO_MSG} "Installation settings:"
	@${ECHO_MSG} "   Destination directory:    ${APP_HOME}"
	@${ECHO_MSG} "   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_MSG} "   Location of Java port:    ${JAVA_PORT}"
	@${ECHO_MSG} "   Running as (user/group):  ${GERONIMO_USER}/${GERONIMO_GROUP}"
	@${ECHO_MSG} "   Logfile:		   ${GERONIMO_OUT}"

post-patch:
	@${ECHO_MSG} -n ">> Removing unneeded files..."
	@${RM} `${FIND} ${WRKSRC} -name '*.bat'` `${FIND} ${WRKSRC} -name '*.orig'` `${FIND} ${WRKSRC} -name '*.exe'`
	@${ECHO_MSG} " [ DONE ]"
	@${REINPLACE_CMD} -e '/^activemq.data/s|= |= ${APP_HOME}/|' ${WRKSRC}/var/config/config-substitutions.properties

do-install:
	${MKDIR} ${STAGEDIR}${APP_HOME}
	@(cd ${WRKSRC} && ${FIND} . |\
		 ${CPIO} -pdmu ${STAGEDIR}${APP_HOME})
	${INSTALL} -m 0644 /dev/null ${STAGEDIR}${GERONIMO_OUT}

post-install:
	@${ECHO_MSG} "${APP_TITLE} ${PORTVERSION} has been installed in ${APP_HOME}."
	@${ECHO_CMD} -e '@owner ${GERONIMO_USER}\n@group ${GERONIMO_GROUP}' >> ${TMPPLIST}
	@${FIND} -s ${WRKSRC} -not -type d | \
		 ${SED} -ne 's,^${WRKSRC},${APP_HOME:S,${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC} -type d | \
		 ${SED} -ne 's,^${WRKSRC},@dir ${APP_HOME:S,${PREFIX}/,,},p' >> ${TMPPLIST}
	@${ECHO_CMD} -e '@owner root\n@group wheel' >> ${TMPPLIST}

.include <bsd.port.mk>
