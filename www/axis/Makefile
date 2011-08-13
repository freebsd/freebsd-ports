# New ports collection makefile for:	AXIS
# Date created:				6 JUNE 2003
# Whom:					Kensaku MASUDA <greg@greg.rim.or.jp>
#
# $FreeBSD$

PORTNAME=		axis
PORTVERSION=		1.4
PORTREVISION=	5
CATEGORIES=		www java
MASTER_SITES=		${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	ws/axis/${PORTVERSION:S,.,_,g}
DISTNAME=		axis-bin-${PORTVERSION:S,.,_,g}

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Java SOAP implementation by Apache

.include <bsd.port.pre.mk>

#
# Change webapp directory by TOMCAT version
#
.if exists(${LOCALBASE}/tomcat5.5/webapps)
WEBAPPDIR=	${PREFIX}/tomcat5.5/webapps
BUILD_DEPENDS+=	${LOCALBASE}/tomcat5.5/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55
RUN_DEPENDS+=	${LOCALBASE}/tomcat5.5/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55
.elif exists(${LOCALBASE}/apache-tomcat-6.0/webapps)
WEBAPPDIR=	${PREFIX}/apache-tomcat-6.0/webapps
BUILD_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
RUN_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
.else
WEBAPPDIR=	${PREFIX}/tomcat5.5/webapps
BUILD_DEPENDS+=	${LOCALBASE}/tomcat5.5/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55
RUN_DEPENDS+=	${LOCALBASE}/tomcat5.5/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55
.endif

NO_BUILD=	YES
USE_JAVA=	yes
JAVA_VERSION=	1.5+
USER=		www
GROUP=		www

WRKSRC=		${WRKDIR}/axis-${PORTVERSION:S,.,_,g}

#
# Install procedure
#
SYSTEM_JARS=	axis.jar jaxrpc.jar saaj.jar
PLIST_SUB+=	WEBAPPS=${WEBAPPDIR:S|^${PREFIX}/||} USER=${USER} GROUP=${GROUP}
.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif
.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	*
.endif

do-install:
.for i in ${SYSTEM_JARS}
	${INSTALL_DATA} ${WRKSRC}/lib/${i} ${JAVAJARDIR}
.endfor
	cd ${WRKSRC}/webapps && ${FIND} axis -type d -exec ${INSTALL} -d -g ${GROUP} -o ${USER} -m 755 ${WEBAPPDIR}/{} \;
	cd ${WRKSRC}/webapps && ${FIND} axis -type f -exec ${INSTALL} -g ${GROUP} -o ${USER} -m 444 {} ${WEBAPPDIR}/{} \;
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/docs && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	cd ${WRKSRC}/docs && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif
.if !defined(NOPORTEXAMPLES)
	cd ${WRKSRC}/samples && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \;
	cd ${WRKSRC}/samples && ${FIND} . -type f -not -name '*.class' -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
.endif

.include <bsd.port.post.mk>
