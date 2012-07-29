# New ports collection makefile for:	WowzaMediaServerPro
# Date created:				October 07, 2009
# Whom:					meritus@innervision.pl
#
# $FreeBSD$
#

PORTNAME=	WowzaMediaServerPro
PORTVERSION=	1.7.2
CATEGORIES=	net
MASTER_SITES=	http://www.wowzamedia.com/downloads/WowzaMediaServer-1-7-2/
EXTRACT_SUFX=	.tar.bin

MAINTAINER=	meritus@innervision.pl
COMMENT=	Commercial flash media server written in Java

RESTRICTED=	Redistribution not allowed

IS_INTERACTIVE=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_EXTRACT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+

WOWZA_USER?=	www
WOWZA_GROUP?=	www
APP_HOME?=	${PREFIX}/${PORTNAME}
LOG_DIR=	${APP_HOME}/logs
STDOUT_LOG=	${LOG_DIR}/stdout.log
STDERR_LOG=	${LOG_DIR}/stderr.log

WMP_CONF_FILES=	Application.xml MediaCasters.xml RTP.xml VHost.xml jmxremote.password \
		Authentication.xml MediaReaders.xml Server.xml VHosts.xml log4j.properties \
		MP3Tags.xml MediaWriters.xml Streams.xml jmxremote.access rtp.password
CONF_EXT=	sample
PLIST_SUB=	W=${APP_HOME:S/^${PREFIX}\///} CONF_EXT=${CONF_EXT} \
		WWWOWN=${WOWZA_USER} WWWGRP=${WOWZA_GROUP}

USE_RC_SUBR=	wowza

SUB_LIST=	STDERR_LOG=${STDERR_LOG} \
		STDOUT_LOG=${STDOUT_LOG} \
		USER=${WOWZA_USER}

.include <bsd.port.pre.mk>

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} \
	&& ${HEAD} -n 700 ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > ${WRKDIR}/wowza-licence.sh \
	&& ${TAIL} -n +748 ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > ${WRKDIR}/wowza.tgz \
	&& ${TAR} xzf ${WRKDIR}/wowza.tgz

post-extract:
	${SH} ${WRKDIR}/wowza-licence.sh

post-patch:
.for f in ${WMP_CONF_FILES}
	@${MV} ${WRKSRC}/conf/${f} ${WRKSRC}/conf/${f}.${CONF_EXT}
.endfor

do-install:
	@${ECHO_MSG} -n ">> Creating destination directory..."
	@${MKDIR} ${APP_HOME}
	@${MKDIR} ${APP_HOME}/conf
	@${MKDIR} ${APP_HOME}/applications
	@${MKDIR} ${APP_HOME}/logs
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Copying files to destination directory..."
	@${CP} ${WRKSRC}/NOTICE.txt ${APP_HOME}
	@${CP} ${WRKSRC}/QUICKSTART.html ${APP_HOME}
	@${CP} ${WRKSRC}/README.html ${APP_HOME}
	@${CP} -R ${WRKSRC}/bin ${APP_HOME}
	@${CP} -R ${WRKSRC}/conf/*.${CONF_EXT} ${APP_HOME}/conf/

.for f in ${WMP_CONF_FILES}
.	if !exists(${APP_HOME}/conf/${f})
		@${CP} ${APP_HOME}/conf/${f}.${CONF_EXT} ${APP_HOME}/conf/${f}
.	else
		@${ECHO_MSG} ">> Preserving local configuration file: ${f} [ DONE ]"
.	endif
.endfor

	@${CP} -R ${WRKSRC}/content ${APP_HOME}
	@${CP} -R ${WRKSRC}/documentation ${APP_HOME}
	@${CP} -R ${WRKSRC}/examples ${APP_HOME}
	@${CP} -R ${WRKSRC}/lib ${APP_HOME}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Fixing ownership settings..."
	@${CHOWN} -R ${WOWZA_USER}:${WOWZA_GROUP} ${APP_HOME}/conf ${APP_HOME}/logs \
		${APP_HOME}/applications
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Fixing permissions..."
	@${FIND} ${APP_HOME} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${FIND} ${APP_HOME} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${ECHO_MSG} " [ DONE ]"

post-install:
.if !defined(BATCH)
	@${SED} -e 's|%%APP_HOME%%|${APP_HOME}|' ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
