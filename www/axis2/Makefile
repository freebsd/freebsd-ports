# $FreeBSD$

PORTNAME=	axis2
PORTVERSION=	1.7.3
CATEGORIES=	www java
MASTER_SITES=	APACHE/axis/${PORTNAME}/java/core/${PORTVERSION}/
DISTFILES=	${PORTNAME}-${PORTVERSION}-bin.zip ${PORTNAME}-${PORTVERSION}-war.zip

MAINTAINER=	dbaio@bsd.com.br
COMMENT=	Provides a Web Services,SOAP and WSDL engine from Apache

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe zip
CPE_VENDOR=	apache
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_SINGLE=	AS
OPTIONS_SINGLE_AS=	TOMCAT6 TOMCAT7
OPTIONS_DEFAULT=	TOMCAT6

OPTIONS_DEFINE=	EXAMPLES

TOMCAT6_VARS=	APPHOME=${LOCALBASE}/apache-tomcat-6.0
TOMCAT6_RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:www/tomcat6

TOMCAT7_VARS=	APPHOME=${LOCALBASE}/apache-tomcat-7.0
TOMCAT7_RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:www/tomcat7

USE_JAVA=	yes
JAVA_VERSION=	1.6+
SHAREOWN=	www
SHAREGRP=	www

PLIST_SUB+=	APPHOME=${APPHOME:S|^${PREFIX}/||} \
	PORTVERSION=${PORTVERSION}

do-install:
	( ${MKDIR} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/lib && cd ${WRKSRC}/lib && ${COPYTREE_SHARE} \* ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/lib )
	( ${MKDIR} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/classes && cd ${WRKSRC}/webapp/WEB-INF/classes && ${COPYTREE_SHARE} \* ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/classes )
	( ${MKDIR} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/axis2-web && cd ${WRKSRC}/webapp/axis2-web && ${COPYTREE_SHARE} \* ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/axis2-web )
	( cd ${WRKSRC}/repository && ${COPYTREE_SHARE} \* ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF )
	${MKDIR} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/conf
.for f in axis2.policy axis2.xml commons-logging.properties log4j.properties
	${INSTALL_DATA} ${WRKSRC}/conf/${f} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/conf/${f}.sample
.endfor
	${INSTALL_DATA} ${WRKSRC}/webapp/WEB-INF/web.xml ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/web.xml.sample
	@${TAR} -C ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/ \
		-xf ${WRKDIR}/${PORTNAME}.war WEB-INF/include/ WEB-INF/views/

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
