# New ports collection makefile for:    jetspeed
# Date created:         30 July 2003
# Whom:                 francisco@gomezmarin.com
#
# $FreeBSD$
#

PORTNAME=	jetspeed
PORTVERSION=	1.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=jetspeed/binaries
DISTNAME=	${PORTNAME}-${PORTVERSION}-b4-war

MAINTAINER=	francisco@gomezmarin.com
COMMENT=	Jetspeed is an Open Source Portal, written in Java and XML

RUN_DEPENDS=	${LOCALBASE}/linux-sun-jdk1.4.2/bin/java:${PORTSDIR}/java/linux-sun-jdk14 \
		${LOCALBASE}/bin/ant:${PORTSDIR}/devel/apache-ant \
		${LOCALBASE}/bin/tomcat41ctl:${PORTSDIR}/www/jakarta-tomcat41

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-b4

USE_ZIP=	yes
NO_BUILD=	yes

JAKARTA_HOME=	${LOCALBASE}/jakarta-tomcat4.1

do-install:
	@${CP} ${WRKSRC}/jetspeed.war ${JAKARTA_HOME}/webapps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} ${WRKSRC}/* ${DOCSDIR}
.endif
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
