# Created by: alex.deiter@gmail.com
# $FreeBSD$

PORTNAME=	bigbluebutton
PORTVERSION=	0.71
PORTREVISION=	5
CATEGORIES=	www java
MASTER_SITES=	http://bigbluebutton.org/downloads/${PORTVERSION}/ \
		http://bigbluebutton.org/downloads/0.70/:2 \
		http://bigbluebutton.org/downloads/0.64/blank/:3
DISTFILES=	bigbluebutton.tar.gz freeswitch-config.tar.gz \
		nginx-bigbluebutton.conf bbb_extensions.conf:2 \
		bbb_sip.conf:2 red5-0.9.1.tar.gz:2 \
		blank-slide.swf:3 blank-thumb.png:3
EXTRACT_ONLY=	bigbluebutton.tar.gz red5-0.9.1.tar.gz freeswitch-config.tar.gz

MAINTAINER=	alex.deiter@gmail.com
COMMENT=	Web conferencing system for distance education

BUILD_DEPENDS=	${LOCALBASE}/bin/pdf2swf:${PORTSDIR}/graphics/swftools \
		${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick \
		${LOCALBASE}/etc/rc.d/activemq:${PORTSDIR}/net/activemq \
		${LOCALBASE}/sbin/nginx:${PORTSDIR}/www/nginx \
		${LOCALBASE}/etc/rc.d/tomcat6:${PORTSDIR}/www/tomcat6 \
		${LOCALBASE}/etc/rc.d/red5:${PORTSDIR}/www/red5
RUN_DEPENDS:=	${BUILD_DEPENDS}

MANUAL_PACKAGE_BUILD=	requires www/tomcat6 with HTTP_PORT=8080

USES=		dos2unix
DOS2UNIX_REGEX=	.+\.(conf|jsp|properties|xml)$

USE_JAVA=	yes
JAVA_EXTRACT=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
DIST_SUBDIR=	${PORTNAME}
USE_RC_SUBR=   	openoffice
SOFFICEBIN?=	${PREFIX}/bin/openoffice-4.0.1
RED5_HOME?=	${PREFIX}/red5
RED5_LOGS?=	${RED5_HOME}/log
RED5_USER?=	www
RED5_GROUP?=	${RED5_USER}
TOMCAT_HOME?=	${PREFIX}/apache-tomcat-6.0
TOMCAT_LOGS?=	${TOMCAT_HOME}/logs
TOMCAT_USER?=	www
TOMCAT_GROUP?=	${TOMCAT_USER}
FS_USER?=	freeswitch
FS_GROUP?=	${FS_USER}
WWWROOT?=	${WWWDIR:S|/${PORTNAME}$||}

OPTIONS_DEFINE=	MEETME KONFERENCE OPENOFFICE
OPTIONS_DEFAULT=	KONFERENCE
MEETME_DESC=	meetme Asterisk module
KONFERENCE_DESC=	konference Asterisk module
OPENOFFICE_DESC=	Include OpenOffice support

PLIST_SUB+=	RED5_HOME=${RED5_HOME:S,^${PREFIX}/,,} \
		TOMCAT_HOME=${TOMCAT_HOME:S,^${PREFIX}/,,} \
		WWWROOT=${WWWROOT:S,^${PREFIX}/,,}

SUB_LIST+=	PORTNAME=${PORTNAME} \
		SOFFICEBIN=${SOFFICEBIN} \
		RED5_HOME=${RED5_HOME} \
		RED5_LOGS=${RED5_LOGS} \
		RED5_USER=${RED5_USER} \
		RED5_GROUP=${RED5_GROUP} \
		TOMCAT_HOME=${TOMCAT_HOME} \
		TOMCAT_LOGS=${TOMCAT_LOGS} \
		TOMCAT_USER=${TOMCAT_USER} \
		TOMCAT_GROUP=${TOMCAT_GROUP} \
		FREESWITCH_USER=${FS_USER} \
		FREESWITCH_GROUP=${FS_GROUP} \
		WWWROOT=${WWWROOT} \
		WWWDIR=${WWWDIR}

SUB_FILES=	pkg-message openoffice nginx.conf-dist bbb-conf

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMEETME} || ${PORT_OPTIONS:MKONFERENCE}
BUILD_DEPENDS+=${LOCALBASE}/sbin/asterisk:${PORTSDIR}/net/asterisk
.if  ${PORT_OPTIONS:MMEETME}
.if !exists(${LOCALBASE}/lib/asterisk/modules/app_meetme.so)
IGNORE=Option meetme requires app_meetme.so from asterisk port. Rebuild net/asterisk with DAHDI option selected
.endif
.endif
.if  ${PORT_OPTIONS:MKONFERENCE}
BUILD_DEPENDS+=${LOCALBASE}/lib/asterisk/modules/app_konference.so:${PORTSDIR}/net/appkonference
.endif
.endif

.if ${PORT_OPTIONS:MOPENOFFICE}
BUILD_DEPENDS+=	${LOCALBASE}/bin/openoffice-4.0.1:${PORTSDIR}/editors/openoffice-4
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
	@${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${WWWDIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/bbb-conf ${STAGEDIR}${PREFIX}/bin
.for d in asterisk blank freeswitch nginx
	@${MKDIR} ${STAGEDIR}${DATADIR}/${d}
.endfor
	@${INSTALL_DATA} ${FILESDIR}/nopdfmark.ps ${STAGEDIR}${DATADIR}/blank
.for f in blank-slide.swf blank-thumb.png
	@${INSTALL_DATA} ${_DISTDIR}/${f} ${STAGEDIR}${DATADIR}/blank
.endfor
.for f in bbb_extensions.conf bbb_sip.conf
	@${INSTALL_DATA} ${WRKDIR}/${f}-dist ${STAGEDIR}${DATADIR}/asterisk
.endfor
.for f in nginx.conf nginx-bigbluebutton.conf
	@${INSTALL_DATA} ${WRKDIR}/${f}-dist ${STAGEDIR}${DATADIR}/nginx
.endfor
	@cd ${WRKDIR} && ${COPYTREE_SHARE} conf ${STAGEDIR}${DATADIR}/freeswitch
	@${MKDIR} ${STAGEDIR}${TOMCAT_HOME}/webapps/bigbluebutton
	@cd ${WRKDIR}/bigbluebutton-tomcat && \
		${COPYTREE_SHARE} . ${STAGEDIR}${TOMCAT_HOME}/webapps/bigbluebutton
	@${CHOWN} ${TOMCAT_USER}:${TOMCAT_GROUP} \
		${STAGEDIR}${TOMCAT_HOME}/webapps/bigbluebutton
	@cd ${WRKDIR} && ${COPYTREE_SHARE} bigbluebutton-default ${STAGEDIR}${WWWROOT}
	@cd ${WRKDIR} && ${COPYTREE_SHARE} client ${STAGEDIR}${WWWDIR}
	@cd ${WRKDIR} && ${COPYTREE_SHARE} 'bigbluebutton deskshare sip video' \
		${STAGEDIR}${RED5_HOME}/webapps
	@cd ${RED5_HOME} && ${CHOWN} -R ${RED5_USER}:${RED5_GROUP} \
		webapps
.for f in aopalliance-1.0.jar spring-aop-3.0.0.jar
	@${INSTALL_DATA} ${WRKDIR}/red5-0.9.1/lib/${f} ${STAGEDIR}${RED5_HOME}/lib
.endfor

.include <bsd.port.mk>
