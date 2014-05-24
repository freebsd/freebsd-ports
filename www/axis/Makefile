# Created by: Kensaku MASUDA <greg@greg.rim.or.jp>
# $FreeBSD$

PORTNAME=		axis
PORTVERSION=		1.4
PORTREVISION=	6
CATEGORIES=		www java
MASTER_SITES=		${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	ws/axis/${PORTVERSION:S,.,_,g}
DISTNAME=		axis-bin-${PORTVERSION:S,.,_,g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java SOAP implementation by Apache

LICENSE=	APACHE20

OPTIONS_SINGLE=		AS
OPTIONS_SINGLE_AS=	TOMCAT6 TOMCAT7
OPTIONS_DEFAULT=	TOMCAT6

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTOMCAT6}
WEBAPPDIR=	${PREFIX}/apache-tomcat-6.0/webapps
RUN_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
.endif

.if ${PORT_OPTIONS:MTOMCAT7}
WEBAPPDIR=	${PREFIX}/apache-tomcat-7.0/webapps
RUN_DEPENDS+=	${LOCALBASE}/apache-tomcat-7.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat7
.endif

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
USER=		www
GROUP=		www

WRKSRC=		${WRKDIR}/axis-${PORTVERSION:S,.,_,g}

PORTDOCS=	*
PORTEXAMPLES=	*

SYSTEM_JARS=	axis.jar jaxrpc.jar saaj.jar
PLIST_SUB+=	WEBAPPS=${WEBAPPDIR:S|^${PREFIX}/||} USER=${USER} GROUP=${GROUP}

do-install:
	${INSTALL_DATA} ${SYSTEM_JARS:S|^|${WRKSRC}/lib/|} ${STAGEDIR}${JAVAJARDIR}
	@${MKDIR} ${STAGEDIR}${WEBAPPDIR}
	(cd ${WRKSRC}/webapps && ${COPYTREE_SHARE} axis ${STAGEDIR}${WEBAPPDIR})

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/ "! -name *.class")

.include <bsd.port.mk>
