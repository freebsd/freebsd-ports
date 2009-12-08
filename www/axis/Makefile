# New ports collection makefile for:	AXIS
# Date created:				6 JUNE 2003
# Whom:					Kensaku MASUDA <greg@greg.rim.or.jp>
#
# $FreeBSD$

PORTNAME=		axis
PORTVERSION=		1.4
PORTREVISION=	4
CATEGORIES=		www java
MASTER_SITES=		${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	ws/axis/${PORTVERSION:S,.,_,g}
DISTNAME=		axis-bin-${PORTVERSION:S,.,_,g}

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Java SOAP implementation by Apache

#
# Change webapp directory by TOMCAT version
#
.if exists(${LOCALBASE}/tomcat5.5/webapps)
WEBAPPDIR=	${PREFIX}/tomcat5.5/webapps
BUILD_DEPENDS+=	${LOCALBASE}/tomcat5.5:${PORTSDIR}/www/tomcat55
RUN_DEPENDS+=	${LOCALBASE}/tomcat5.5:${PORTSDIR}/www/tomcat55
.elif exists(${LOCALBASE}/jakarta-tomcat5/webapps)
WEBAPPDIR=	${PREFIX}/jakarta-tomcat5/webapps
BUILD_DEPENDS+=	${LOCALBASE}/jakarta-tomcat5:${PORTSDIR}/www/jakarta-tomcat5
RUN_DEPENDS+=	${LOCALBASE}/jakarta-tomcat5:${PORTSDIR}/www/jakarta-tomcat5
.elif exists(${LOCALBASE}/jakarta-tomcat4.1/webapps)
WEBAPPDIR=	${PREFIX}/jakarta-tomcat4.1/webapps
BUILD_DEPENDS+=	${LOCALBASE}/jakarta-tomcat4.1:${PORTSDIR}/www/tomcat41
RUN_DEPENDS+=	${LOCALBASE}/jakarta-tomcat4.1:${PORTSDIR}/www/tomcat41
.else
WEBAPPDIR=	${PREFIX}/tomcat5.5/webapps
BUILD_DEPENDS+=	${LOCALBASE}/tomcat5.5:${PORTSDIR}/www/tomcat55
RUN_DEPENDS+=	${LOCALBASE}/tomcat5.5:${PORTSDIR}/www/tomcat55
.endif

NO_BUILD=	YES
USE_JAVA=	yes
JAVA_VERSION=	1.4+
USER=		www
GROUP=		www

WRKSRC=		${WRKDIR}/axis-${PORTVERSION:S,.,_,g}

.include <bsd.port.pre.mk>

#
# Install procedure
#
SYSTEM_JARS=	axis.jar jaxrpc.jar saaj.jar
PLIST_SUB+=	WEBAPPS=${WEBAPPDIR:S|^${PREFIX}/||} USER=${USER} GROUP=${GROUP}

do-install:
.for i in ${SYSTEM_JARS}
	${INSTALL_DATA} ${WRKSRC}/lib/${i} ${JAVAJARDIR}
.endfor
	cd ${WRKSRC}/webapps && ${FIND} axis -type d -exec ${INSTALL} -d -g ${GROUP} -o ${USER} -m 755 ${WEBAPPDIR}/{} \;
	cd ${WRKSRC}/webapps && ${FIND} axis -type f -exec ${INSTALL} -g ${GROUP} -o ${USER} -m 444 {} ${WEBAPPDIR}/{} \;
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/docs && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	cd ${WRKSRC}/docs && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	cd ${WRKSRC}/samples && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \;
	cd ${WRKSRC}/samples && ${FIND} . -type f -not -name '*.class' -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
.endif

.include <bsd.port.post.mk>
