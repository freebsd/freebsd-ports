# New ports collection makefile for:	jakarta-tomcat-devel
# Date created:		Tue Aug 12 23:26:32 CST 2003
# Whom:			Kang Liu <liukang@bjpu.edu.cn>
#
# $FreeBSD$
#

PORTNAME=	tomcat
PORTVERSION=	5.5.35
PORTREVISION=	2
CATEGORIES=	www java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	tomcat/tomcat-5/v${PORTVERSION}/bin
DISTNAME=	apache-tomcat-${PORTVERSION}

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Open-source Java web server by Apache, 5.5.x branch

OPTIONS_DEFINE=	LOG
OPTIONS_SINGLE=	LOG
OPTIONS_SINGLE_LOG= CRONOLOG CRONOLOG_DEVEL
LOG_DESC=	Use Log Pre-Processor
CRONOLOG_DESC=	Use Cronolog for Log Processing
CRONOLOG_DEVEL_DESC=	Use Cronlog-Devel for Log Processing

DEPRECATED=	EOL approaching, consider www/tomcat{6,7}
EXPIRATION_DATE=2012-12-31

USE_JAVA=	yes
JAVA_VERSION?=	1.5+
JAVA_VENDOR?=	freebsd
NO_BUILD=	YES

USE_RC_SUBR=	tomcat55
SUB_FILES=	pkg-install pkg-deinstall

MAJOR_VER=	${PORTVERSION:R}
APP_HOME?=	${PREFIX}/${PKGBASE}${PORTVERSION:R}
LOG_DIR=	${APP_HOME}/logs
APP_TITLE=	Apache Tomcat
APP_SHORTNAME=	tomcat${MAJOR_VER:S/.//}
TOMCAT_USER?=	www
TOMCAT_GROUP?=	www
TOMCAT_UID?=	80
HTTP_PORT?=	8180
HTTP_TIMEOUT?=	20000
SHUTDOWN_PORT?=	8005
AJP_1_3_PORT?=	8009
STDOUT_LOG=	${LOG_DIR}/stdout.log
STDERR_LOG=	${LOG_DIR}/stderr.log
PID_FILE=	/var/run/${APP_SHORTNAME}.pid
REPLACE_FILES=	${WRKSRC}/bin/catalina.sh \
		${WRKSRC}/conf/server.xml
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
		HTTP_TIMEOUT=${HTTP_TIMEOUT} \
		JAR_FILE=${JAR_FILE} \
		JAVA_HOME=${JAVA_HOME} \
		LOG_ARGS=${LOG_ARGS} \
		LOG_DIR=${LOG_DIR} \
		PID_FILE=${PID_FILE} \
		PORTNAME=${PORTNAME} \
		SHUTDOWN_PORT=${SHUTDOWN_PORT} \
		STDERR_LOG=${STDERR_LOG} \
		STDOUT_LOG=${STDOUT_LOG} \
		TOMCAT_HOME=${APP_HOME} \
		TOMCAT_VERSION=${MAJOR_VER:S/.//} \
		USER=${TOMCAT_USER} \
		UID=${TOMCAT_UID}

.include <bsd.port.pre.mk>

.if ${JAVA_PORT_VERSION:C/^([0-9])\.([0-9])(.*)$/\1.\2/} == "1.4"
DISTFILES+=	apache-tomcat-${PORTVERSION}-compat.tar.gz
PLIST_SUB+=	JAVA14=""
.else
PLIST_SUB+=	JAVA14="@comment "
.endif

.if ${PORT_OPTIONS:MCRONOLOG}
RUN_DEPENDS+=	cronolog:${PORTSDIR}/sysutils/cronolog
.endif

.if ${PORT_OPTIONS:MCRONOLOG_DEVEL}
RUN_DEPENDS+=	cronolog:${PORTSDIR}/sysutils/cronolog-devel
.endif

.if empty(PORT_OPTIONS:MLOG)
LOG_ARGS?=">> \$${tomcat\%\%TOMCAT_VERSION\%\%_stdout_log} 2>> \$${tomcat\%\%TOMCAT_VERSION\%\%_stderr_log}"
.else
LOG_ARGS?="2>\&1 | ${LOCALBASE}/sbin/cronolog --link \$${tomcat\%\%TOMCAT_VERSION\%\%_catalina_base}/logs/catalina.out \$${tomcat\%\%TOMCAT_VERSION\%\%_catalina_base}/logs/catalina.\%Y_\%m_\%d.out >/dev/null 2>\&1 \&"
.endif

pre-patch:
	@${ECHO_MSG} "Installation settings:"
	@${ECHO_MSG} "   Destination directory:    ${APP_HOME}"
	@${ECHO_MSG} "   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_MSG} "   Location of Java port:    ${JAVA_PORT}"
	@${ECHO_MSG} "   Running as (user/group/uid):  ${TOMCAT_USER}/${TOMCAT_GROUP}/${TOMCAT_UID}"
	@${ECHO_MSG} "   HTTP port:                ${HTTP_PORT}"
	@${ECHO_MSG} "   Shutdown listener port:   ${SHUTDOWN_PORT}"
	@${ECHO_MSG} "   AJP 1.3 connector port:   ${AJP_1_3_PORT}"
	@${ECHO_MSG} "   Logfile stdout:           ${STDOUT_LOG}"
	@${ECHO_MSG} "   Logfile stderr:           ${STDERR_LOG}"

	@${ECHO_MSG} -n ">> Removing unneeded files..."
	@${FIND} ${WRKSRC} -type f \( -name '*.bak' -or -name '*.bat' -or -name '*.dll' -or -name '*.exe' -or -name '*.orig' \) -delete
	@${RMDIR} ${WRKSRC}/bin/[i,x]64
	@${ECHO_MSG} " [ DONE ]"

.for file in ${REPLACE_FILES}
	@${ECHO_MSG} -n ">> Customizing `basename ${file}`..."
	@${SED} ${REPLACE_LIST_TEMP} ${file} > ${WRKDIR}/`basename ${file}`
	@${ECHO_MSG} " [ DONE ]"
.endfor

post-patch-script:
	@${ECHO_MSG} -n ">> Removing unneeded patched files..."
	@${FIND} ${WRKSRC} -type f \( -name '*.orig' \) -delete
	@${ECHO_MSG} " [ DONE ]"

do-install:
	@${ECHO_MSG} -n ">> Creating destination directory..."
	@${MKDIR} ${APP_HOME}
	@${MKDIR} ${LOG_DIR}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} ">> Copying files to destination directory..."
	@${CP} ${WRKDIR}/server.xml ${WRKSRC}/conf/
	@${CP} ${WRKDIR}/catalina.sh ${WRKSRC}/bin/
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

# create missing directories and fix permissions
post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_MSG} "${APP_TITLE} ${PORTVERSION} has been installed in ${APP_HOME}."
.include <bsd.port.post.mk>
