# $FreeBSD$

PORTNAME=	sventon
PORTVERSION=	2.5.1
CATEGORIES=	www java
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin-svnkit

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Web client for browsing Subversion repositories

LICENSE=	GPLv3

USES=		zip
NO_BUILD=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_SINGLE=	AS
OPTIONS_SINGLE_AS=	TOMCAT6
OPTIONS_DEFAULT=	TOMCAT6

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTOMCAT6}
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
