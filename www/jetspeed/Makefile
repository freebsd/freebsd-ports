# New ports collection makefile for:    jetspeed
# Date created:         30 July 2003
# Whom:                 francisco@gomezmarin.com
#
# $FreeBSD$
#

PORTNAME=	jetspeed
PORTVERSION=	1.6
PORTREVISION=	3
CATEGORIES=	www java
MASTER_SITES=	http://www.apache.org/dist/portals/jetspeed-1/
#MASTER_SITE_SUBDIR=jetspeed/binaries
DISTNAME=	${PORTNAME}-${PORTVERSION}-war

MAINTAINER=	wenheping@gmail.com
COMMENT=	Jetspeed is an Open Source Portal, written in Java and XML

RUN_DEPENDS=	${LOCALBASE}/bin/ant:${PORTSDIR}/devel/apache-ant \
		${JAKARTA_HOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat41

WRKSRC=		${WRKDIR}/${DISTNAME:C/-war//}
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+

NO_BUILD=	yes

JAKARTA_HOME=	${LOCALBASE}/apache-tomcat4.1

do-install:
	@${INSTALL_DATA} ${WRKSRC}/jetspeed.war ${JAKARTA_HOME}/webapps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/* ${DOCSDIR}
.endif
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
