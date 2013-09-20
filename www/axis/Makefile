# Created by: Kensaku MASUDA <greg@greg.rim.or.jp>
# $FreeBSD$

PORTNAME=		axis
PORTVERSION=		1.4
PORTREVISION=	6
CATEGORIES=		www java
MASTER_SITES=		${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	ws/axis/${PORTVERSION:S,.,_,g}
DISTNAME=		axis-bin-${PORTVERSION:S,.,_,g}

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Java SOAP implementation by Apache

OPTIONS_SINGLE=	AS
OPTIONS_SINGLE_AS=	TOMCAT6 TOMCAT7
OPTIONS_DEFAULT=	TOMCAT6

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTOMCAT6}
WEBAPPDIR=	${PREFIX}/apache-tomcat-6.0/webapps
BUILD_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
RUN_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
.endif

.if ${PORT_OPTIONS:MTOMCAT7}
WEBAPPDIR=	${PREFIX}/apache-tomcat-7.0/webapps
BUILD_DEPENDS+=	${LOCALBASE}/apache-tomcat-7.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat7
RUN_DEPENDS+=	${LOCALBASE}/apache-tomcat-7.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat7
.endif

NO_BUILD=	YES
USE_JAVA=	yes
JAVA_VERSION=	1.6+
USER=		www
GROUP=		www

WRKSRC=		${WRKDIR}/axis-${PORTVERSION:S,.,_,g}

#
# Install procedure
#
SYSTEM_JARS=	axis.jar jaxrpc.jar saaj.jar
PLIST_SUB+=	WEBAPPS=${WEBAPPDIR:S|^${PREFIX}/||} USER=${USER} GROUP=${GROUP}

PORTDOCS=	*
PORTEXAMPLES=	*

do-install:
.for i in ${SYSTEM_JARS}
	${INSTALL_DATA} ${WRKSRC}/lib/${i} ${JAVAJARDIR}
.endfor
	cd ${WRKSRC}/webapps && ${FIND} axis -type d -exec ${INSTALL} -d -g ${GROUP} -o ${USER} -m 755 ${WEBAPPDIR}/{} \;
	cd ${WRKSRC}/webapps && ${FIND} axis -type f -exec ${INSTALL} -g ${GROUP} -o ${USER} -m 444 {} ${WEBAPPDIR}/{} \;
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC}/docs && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	cd ${WRKSRC}/docs && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	cd ${WRKSRC}/samples && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \;
	cd ${WRKSRC}/samples && ${FIND} . -type f -not -name '*.class' -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
.endif

.include <bsd.port.post.mk>
