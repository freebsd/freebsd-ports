PORTNAME=	axis2
PORTVERSION=	1.8.0
CATEGORIES=	www java
MASTER_SITES=	APACHE/axis/${PORTNAME}/java/core/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Provides a Web Services,SOAP and WSDL engine from Apache

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe zip
CPE_VENDOR=	apache
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_SINGLE=	AS
OPTIONS_SINGLE_AS=	TOMCAT7 TOMCAT85 TOMCAT9 TOMCAT10
OPTIONS_DEFAULT=	TOMCAT85

OPTIONS_DEFINE=	EXAMPLES

TOMCAT7_VARS=	APPHOME=${LOCALBASE}/apache-tomcat-7.0
TOMCAT7_RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:www/tomcat7

TOMCAT85_VARS=	APPHOME=${LOCALBASE}/apache-tomcat-8.5
TOMCAT85_RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:www/tomcat85

TOMCAT9_VARS=	APPHOME=${LOCALBASE}/apache-tomcat-9.0
TOMCAT9_RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:www/tomcat9

TOMCAT10_VARS=	APPHOME=${LOCALBASE}/apache-tomcat-10.0
TOMCAT10_RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:www/tomcat10

USE_JAVA=	yes
SHAREOWN=	www
SHAREGRP=	www

PLIST_SUB+=	APPHOME=${APPHOME:S|^${PREFIX}/||} \
	PORTVERSION=${PORTVERSION}

do-install:
	( ${MKDIR} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF && cd ${WRKSRC}/webapp/WEB-INF && ${COPYTREE_SHARE} \* ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF )
	( cd ${WRKSRC}/lib && ${COPYTREE_SHARE} \* ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/lib )
	( ${MKDIR} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/axis2-web && cd ${WRKSRC}/webapp/axis2-web && ${COPYTREE_SHARE} \* ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/axis2-web )
	( cd ${WRKSRC}/repository && ${COPYTREE_SHARE} \* ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF )
	${MKDIR} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/conf
.for f in axis2.policy axis2.xml commons-logging.properties log4j2.xml
	${INSTALL_DATA} ${WRKSRC}/conf/${f} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/conf/${f}.sample
.endfor
	${MV} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/web.xml ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/web.xml.sample

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
