# New ports collection makefile for:    devel/red5
# Date created:         14 March 2008
# Whom:                 wenheping@gmail.com
#
# $FreeBSD$
#

PORTNAME=	red5
PORTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	www java
MASTER_SITES=	http://www.nielsenaa.com/red5-installers/   \
		http://www.red5.fr/release/0.7.0/war/
DISTNAME=	Red5War_${PORTVERSION}-java5

MAINTAINER=	wenheping@gmail.com
COMMENT=	Red5 is an Open Source flash server

OPTIONS=	TOMCAT4	"Use Tomcat 4.1" OFF \
		TOMCAT5 "Use Tomcat 5.5" OFF \
		TOMCAT6 "Use Tomcat 6.0" ON

WRKSRC=		${WRKDIR}
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if	(defined(WITH_TOMCAT4) && defined(WITH_TOMCAT5)) || \
	(defined(WITH_TOMCAT4) && defined(WITH_TOMCAT6)) || \
	(defined(WITH_TOMCAT5) && defined(WITH_TOMCAT6))
IGNORE=	please select only one version of Tomcat
.endif

.if defined(WITH_TOMCAT4)
RUN_DEPENDS+=	${LOCALBASE}/apache-tomcat4.1:${PORTSDIR}/www/tomcat41
WEBAPPDIR=	${PREFIX}/apache-tomcat4.1/webapps
.elif defined(WITH_TOMCAT5)
RUN_DEPENDS+=	${LOCALBASE}/tomcat5.5:${PORTSDIR}/www/tomcat55
WEBAPPDIR=	${PREFIX}/tomcat5.5/webapps
.elif defined(WITH_TOMCAT6)
RUN_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0:${PORTSDIR}/www/tomcat6
WEBAPPDIR=	${PREFIX}/apache-tomcat-6.0/webapps
.else
IGNORE=	please select one version of Tomcat
.endif

PLIST_FILES=	${WEBAPPDIR:S|^${PREFIX}/||}/red5.war

do-install:
	@${MKDIR} ${WEBAPPDIR}
	@${INSTALL_DATA} ${WRKSRC}/ROOT.war ${WEBAPPDIR}/red5.war
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${WEBAPPDIR}/red5.war

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
