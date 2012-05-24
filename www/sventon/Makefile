# New ports collection makefile for:	sventon
# Date created:				22 May 2012
# Whom:					Jason Helfman <jgh@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	sventon
PORTVERSION=	2.5.1
CATEGORIES=	www java
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin-svnkit

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Web client for browsing Subversion repositories

LICENSE=	GPLv3

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS=	TOMCAT6 "Enable Tomcat 6.x support"     on

.include <bsd.port.options.mk>

.if defined(WITH_TOMCAT6)
APPHOME=	${LOCALBASE}/apache-tomcat-6.0
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
.endif

.if !defined(APPHOME)
IGNORE=	you need at least one application server
.endif

USE_JAVA=	yes
JAVA_VERSION=	1.6+
SHAREOWN=	www
SHAREGRP=	www
PLIST_SUB+=	APPHOME=${APPHOME:S|^${PREFIX}/||}

post-extract:
	@${MKDIR} ${WRKDIR}/${PORTDIRNAME}
	@${TAR} xf ${WRKSRC}/svn.war -C ${WRKDIR}/${PORTDIRNAME}

do-install:
	${INSTALL} -d -o ${WWWOWN} -g ${WWWGRP} ${APPHOME}/webapps/${PORTDIRNAME}
	cd ${WRKDIR}/${PORTDIRNAME} && ${COPYTREE_SHARE} \* ${APPHOME}/webapps/${PORTDIRNAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
