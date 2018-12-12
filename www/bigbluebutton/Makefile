# Created by: alex.deiter@gmail.com
# $FreeBSD$

PORTNAME=	bigbluebutton
PORTVERSION=	0.71
PORTREVISION=	8
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

BUILD_DEPENDS=	${LOCALBASE}/bin/pdf2swf:graphics/swftools \
		${LOCALBASE}/bin/convert:graphics/ImageMagick6 \
		${LOCALBASE}/etc/rc.d/activemq:net/activemq \
		${LOCALBASE}/sbin/nginx:www/nginx \
		${LOCALBASE}/etc/rc.d/tomcat6:www/tomcat6 \
		${LOCALBASE}/etc/rc.d/red5:www/red5
RUN_DEPENDS:=	${BUILD_DEPENDS}

MANUAL_PACKAGE_BUILD=	requires www/tomcat6 with HTTP_PORT=8080

USES=		dos2unix
DOS2UNIX_REGEX=	.+\.(conf|jsp|properties|xml)$

USE_JAVA=	yes
JAVA_EXTRACT=	yes
NO_BUILD=	yes
DIST_SUBDIR=	${PORTNAME}
USE_RC_SUBR=	openoffice
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

OPTIONS_DEFINE=	KONFERENCE OPENOFFICE
OPTIONS_DEFAULT=	KONFERENCE
KONFERENCE_DESC=	konference Asterisk module
OPENOFFICE_DESC=	Include OpenOffice support

PLIST_SUB+=	RED5_HOME=${RED5_HOME:S,^${PREFIX}/,,} \
		RED5_USER=${RED5_USER} \
		RED5_GROUP=${RED5_GROUP} \
		TOMCAT_HOME=${TOMCAT_HOME:S,^${PREFIX}/,,} \
		TOMCAT_USER=${TOMCAT_USER} \
		TOMCAT_GROUP=${TOMCAT_GROUP} \
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

.if  ${PORT_OPTIONS:MKONFERENCE}
BUILD_DEPENDS+=${LOCALBASE}/lib/asterisk/modules/app_konference.so:net/appkonference
.endif
.if ${PORT_OPTIONS:MOPENOFFICE}
BUILD_DEPENDS+=	${LOCALBASE}/bin/openoffice-4.0.1:editors/openoffice-4
.endif

post-extract:
	@${MKDIR} ${WRKSRC}
.for f in bbb_extensions.conf bbb_sip.conf nginx-bigbluebutton.conf
	@${INSTALL_DATA} ${_DISTDIR}/${f} ${WRKSRC}
.endfor
.for f in bbb-default bigbluebutton-webapps client deskshare sip video
	@cd ${WRKSRC} && ${TAR} xf ../${f}${EXTRACT_SUFX}
.endfor
	@cd ${WRKDIR} && ${MV} conf red5-0.9.1 ${WRKSRC}
	@cd ${WRKSRC}/client && ${MV} client/* . && ${RMDIR} client
	@${MKDIR} ${WRKSRC}/bigbluebutton-tomcat
	@cd ${WRKSRC}/bigbluebutton-tomcat && ${JAR} xf \
		${WRKDIR}/bigbluebutton.war
	@cd ${WRKSRC} && ${FIND} . -name .gitignore -delete

post-patch:
	@${RM} ${WRKSRC}/deskshare/WEB-INF/deskshare.conf.orig
	@${FIND} ${WRKSRC} -type f -name '*.orig' -execdir ${SH} -c \
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
	${INSTALL_SCRIPT} ${WRKDIR}/bbb-conf ${STAGEDIR}${PREFIX}/bin
	@(cd ${STAGEDIR}${DATADIR} && ${MKDIR} asterisk blank freeswitch nginx)
	${INSTALL_DATA} ${FILESDIR}/nopdfmark.ps ${STAGEDIR}${DATADIR}/blank
	(cd ${_DISTDIR} && ${INSTALL_DATA} blank-slide.swf blank-thumb.png \
		${STAGEDIR}${DATADIR}/blank)
	(cd ${WRKSRC} && ${INSTALL_DATA} bbb_*.conf-dist \
		${STAGEDIR}${DATADIR}/asterisk)
	${INSTALL_DATA} ${WRKSRC}/nginx-bigbluebutton.conf-dist \
		${WRKDIR}/nginx.conf-dist ${STAGEDIR}${DATADIR}/nginx
	(cd ${WRKSRC} && ${COPYTREE_SHARE} conf ${STAGEDIR}${DATADIR}/freeswitch)
	@${MKDIR} ${STAGEDIR}${TOMCAT_HOME}/webapps/bigbluebutton
	(cd ${WRKSRC}/bigbluebutton-tomcat && ${COPYTREE_SHARE} . \
		${STAGEDIR}${TOMCAT_HOME}/webapps/bigbluebutton)
	(cd ${WRKSRC} && ${COPYTREE_SHARE} bigbluebutton-default \
		${STAGEDIR}${WWWROOT})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} client ${STAGEDIR}${WWWDIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} 'bigbluebutton deskshare sip video' \
		${STAGEDIR}${RED5_HOME}/webapps)
	@${MKDIR} ${STAGEDIR}${RED5_HOME}/lib
	(cd ${WRKSRC}/red5-0.9.1/lib && ${INSTALL_DATA} aopalliance-1.0.jar \
		spring-aop-3.0.0.jar ${STAGEDIR}${RED5_HOME}/lib)

.include <bsd.port.mk>
