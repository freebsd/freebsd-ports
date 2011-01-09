# New ports collection makefile for:	www/bigbluebutton
# Date created:				23 October 2010
# Whom:					alex.deiter@gmail.com
#
# $FreeBSD$
#

PORTNAME=		bigbluebutton
PORTVERSION=		0.71
CATEGORIES=		www java
MASTER_SITES=		http://bigbluebutton.org/downloads/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION} ${PORTVERSION}/packages 0.70 0.64/blank
DISTFILES=		bbb_extensions.conf bbb_sip.conf blank-slide.swf \
			blank-thumb.png nginx-bigbluebutton.conf \
			${EXTRACT_FILES}
EXTRACT_ONLY=		${EXTRACT_FILES}

MAINTAINER=		alex.deiter@gmail.com
COMMENT=		Web conferencing system for distance education

BUILD_DEPENDS=		${LOCALBASE}/bin/pdf2swf:${PORTSDIR}/graphics/swftools \
			${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick \
			${LOCALBASE}/etc/rc.d/activemq:${PORTSDIR}/net/activemq \
			${LOCALBASE}/sbin/nginx:${PORTSDIR}/www/nginx \
			${LOCALBASE}/etc/rc.d/tomcat6:${PORTSDIR}/www/tomcat6 \
			${LOCALBASE}/etc/rc.d/red5:${PORTSDIR}/www/red5
RUN_DEPENDS=		${BUILD_DEPENDS}

EXTRACT_FILES=		bigbluebutton.tar.gz freeswitch-config.tar.gz \
			red5-0.9.1.tar.gz

USE_DOS2UNIX=		yes
DOS2UNIX_REGEX=		.+\.(conf|jsp|properties|xml)$

USE_JAVA=		yes
JAVA_VERSION=		1.5+
JAVA_EXTRACT=		yes
USE_MYSQL=		yes
NO_BUILD=		yes
NO_WRKSUBDIR=		yes
DIST_SUBDIR=		${PORTNAME}
USE_RC_SUBR=    	openoffice
SOFFICEBIN?=		${PREFIX}/openoffice.org-3.2.1/openoffice.org3/program/soffice.bin
RED5_HOME?=		${PREFIX}/red5
RED5_HOME_REL=		${RED5_HOME:S,^${PREFIX}/,,}
RED5_LOGS?=		${RED5_HOME}/log
RED5_USER?=		www
RED5_GROUP?=		${RED5_USER}
TOMCAT_HOME?=		${PREFIX}/apache-tomcat-6.0
TOMCAT_HOME_REL=	${TOMCAT_HOME:S,^${PREFIX}/,,}
TOMCAT_LOGS?=		${TOMCAT_HOME}/logs
TOMCAT_USER?=		www
TOMCAT_GROUP?=		${TOMCAT_USER}
WWWROOT?=		${WWWDIR:S|/${PORTNAME}$||}
WWWROOT_REL=		${WWWROOT:S,^${PREFIX}/,,}

OPTIONS=		MEETME "meetme Asterisk module" off \
			KONFERENCE "konference Asterisk module" on \
			FREESWITCH "mod_conference FreeSWITCH module" off \
			OPENOFFICE "Include OpenOffice support" off

PLIST_SUB+=		RED5_HOME=${RED5_HOME_REL} \
			TOMCAT_HOME=${TOMCAT_HOME_REL} \
			WWWROOT=${WWWROOT_REL}

SUB_LIST+=		PORTNAME=${PORTNAME} \
			SOFFICEBIN=${SOFFICEBIN} \
			RED5_HOME=${RED5_HOME} \
			RED5_LOGS=${RED5_LOGS} \
			RED5_USER=${RED5_USER} \
			RED5_GROUP=${RED5_GROUP} \
			TOMCAT_HOME=${TOMCAT_HOME} \
			TOMCAT_LOGS=${TOMCAT_LOGS} \
			TOMCAT_USER=${TOMCAT_USER} \
			TOMCAT_GROUP=${TOMCAT_GROUP} \
			WWWROOT=${WWWROOT} \
			WWWDIR=${WWWDIR}

SUB_FILES=		pkg-message openoffice nginx.conf-dist bbb-conf

.include <bsd.port.pre.mk>

.if defined(WITH_MEETME) || defined(WITH_KONFERENCE)
BUILD_DEPENDS+=${LOCALBASE}/sbin/asterisk:${PORTSDIR}/net/asterisk16
.if  defined(WITH_MEETME)
.if !exists(${LOCALBASE}/lib/asterisk/modules/app_meetme.so)
IGNORE=Option meetme requires app_meetme.so from asterisk port. Rebuild net/asterisk16 with WITH_ZAPTEL=yes
.endif
.endif
.if  defined(WITH_KONFERENCE)
BUILD_DEPENDS+=${LOCALBASE}/lib/asterisk/modules/app_konference.so:${PORTSDIR}/net/appkonference
.endif
.endif

.if defined(WITH_FREESWITCH)
BROKEN=freeswitch 1.0.6 does not work with BigBlueButton
BUILD_DEPENDS+=${LOCALBASE}/bin/freeswitch:${PORTSDIR}/net/freeswitch
.endif

.if defined(WITH_OPENOFFICE)
BUILD_DEPENDS+=	${LOCALBASE}/bin/openoffice.org-3.2.1:${PORTSDIR}/editors/openoffice.org-3
.endif

post-extract:
.for f in bbb_extensions.conf bbb_sip.conf nginx-bigbluebutton.conf
	@${INSTALL_DATA} ${_DISTDIR}/${f} ${WRKDIR}
.endfor
.for f in bbb-default bigbluebutton-webapps client deskshare sip video
	@cd ${WRKDIR} && ${TAR} xf ${f}${EXTRACT_SUFX}
.endfor
	@cd ${WRKDIR}/client && ${MV} client/* . && ${RMDIR} client
	@${MKDIR} ${WRKDIR}/bigbluebutton-tomcat
	@cd ${WRKDIR}/bigbluebutton-tomcat && ${JAR} xf \
		${WRKDIR}/bigbluebutton.war
	@cd ${WRKDIR} && ${FIND} . -name .gitignore -delete

post-patch:
	@${RM} ${WRKDIR}/deskshare/WEB-INF/deskshare.conf.orig
	@${FIND} ${WRKDIR} -type f -name '*.orig' -execdir ${SH} -c \
		'f={} && ${MV} $${f%.orig} $${f%.orig}-dist && ${RM} $$f' ';'

pre-install:
.for d in RED5_HOME TOMCAT_HOME
	@if [ ! -d "${${d}}/webapps" ]; then \
		${ECHO_MSG} ""; \
		${ECHO_MSG} "Path ${${d}}/webapps not found"; \
		${ECHO_MSG} "Please check and set correct ${d} variable in make env"; \
		${ECHO_MSG} ""; \
		${FALSE}; \
	fi
.endfor
	@if ! ${GREP} -q 'Connector\ port=\"8080\"\ protocol=\"HTTP\/1\.1\"\ *$$' \
		${TOMCAT_HOME}/conf/server.xml; then \
		${ECHO_MSG} ""; \
		${ECHO_MSG} "Please reinstall www/tomcat6 port with HTTP_PORT=8080"; \
		${ECHO_MSG} ""; \
		${FALSE}; \
	fi

do-install:
	@${MKDIR} ${DATADIR} ${WWWDIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/bbb-conf ${PREFIX}/bin
.for d in asterisk blank freeswitch nginx
	@${MKDIR} ${DATADIR}/${d}
.endfor
	@${INSTALL_DATA} ${FILESDIR}/nopdfmark.ps ${DATADIR}/blank
.for f in blank-slide.swf blank-thumb.png
	@${INSTALL_DATA} ${_DISTDIR}/${f} ${DATADIR}/blank
.endfor
.for f in bbb_extensions.conf bbb_sip.conf
	@${INSTALL_DATA} ${WRKDIR}/${f}-dist ${DATADIR}/asterisk
.endfor
.for f in nginx.conf nginx-bigbluebutton.conf
	@${INSTALL_DATA} ${WRKDIR}/${f}-dist ${DATADIR}/nginx
.endfor
	@cd ${WRKDIR} && ${COPYTREE_SHARE} conf ${DATADIR}/freeswitch
	@${MKDIR} ${TOMCAT_HOME}/webapps/bigbluebutton
	@cd ${WRKDIR}/bigbluebutton-tomcat && \
		${COPYTREE_SHARE} . ${TOMCAT_HOME}/webapps/bigbluebutton
	@${CHOWN} ${TOMCAT_USER}:${TOMCAT_GROUP} \
		${TOMCAT_HOME}/webapps/bigbluebutton
	@cd ${WRKDIR} && ${COPYTREE_SHARE} bigbluebutton-default ${WWWROOT}
	@cd ${WRKDIR} && ${COPYTREE_SHARE} client ${WWWDIR}
	@cd ${WRKDIR} && ${COPYTREE_SHARE} 'bigbluebutton deskshare sip video' \
		${RED5_HOME}/webapps
	@cd ${RED5_HOME} && ${CHOWN} -R ${RED5_USER}:${RED5_GROUP} \
		webapps
.for f in aopalliance-1.0.jar spring-aop-3.0.0.jar
	@${INSTALL_DATA} ${WRKDIR}/red5-0.9.1/lib/${f} ${RED5_HOME}/lib
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
