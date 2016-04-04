# $FreeBSD$

PORTNAME=	axis2
PORTVERSION=	1.7.1
CATEGORIES=	www java
MASTER_SITES=	APACHE/axis/${PORTNAME}/java/core/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides a Web Services,SOAP and WSDL engine from Apache

LICENSE=	APACHE20

USES=		cpe zip
CPE_VENDOR=	apache
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes

OPTIONS_SINGLE=	AS
OPTIONS_SINGLE_AS=	TOMCAT6 TOMCAT7
OPTIONS_DEFAULT=	TOMCAT6

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTOMCAT6}
APPHOME=	${LOCALBASE}/apache-tomcat-6.0
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:www/tomcat6
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:www/tomcat6
.endif

.if ${PORT_OPTIONS:MTOMCAT7}
APPHOME=	${LOCALBASE}/apache-tomcat-7.0
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:www/tomcat7
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:www/tomcat7
.endif

USE_JAVA=	yes
JAVA_VERSION=	1.6+
SHAREOWN=	www
SHAREGRP=	www
PLIST_SUB+=	APPHOME=${APPHOME:S|^${PREFIX}/||} \
		CONF_EXT=${CONF_EXT} PORTVERSION=${PORTVERSION}
CONF_EXT=	sample

PORTEXAMPLES=	*

do-install:
	( ${MKDIR} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/lib && cd ${WRKSRC}/lib && ${COPYTREE_SHARE} \* ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/lib)
	( ${MKDIR} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/classes && cd ${WRKSRC}/webapp/WEB-INF/classes && ${COPYTREE_SHARE} \* ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/classes )$
	( ${MKDIR} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/axis2-web && cd ${WRKSRC}/webapp/axis2-web && ${COPYTREE_SHARE} \* ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/axis2-web )
	( cd ${WRKSRC}/repository && ${COPYTREE_SHARE} \* ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF )
	${MKDIR} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/conf
.for f in axis2.policy axis2.xml commons-logging.properties log4j.properties
	${INSTALL_DATA} ${WRKSRC}/conf/${f} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/conf/${f}.sample
.endfor
	${INSTALL_DATA} ${WRKSRC}/webapp/WEB-INF/web.xml ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/web.xml.sample
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/{} \;
#	cd ${WRKSRC}/samples && ${FIND} . -type f -not -name '*.class' -exec ${INSTALL_DATA} {} ${STAGEDIR}${EXAMPLESDIR}/{} \;
.endif

.include <bsd.port.mk>
