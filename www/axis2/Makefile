# $FreeBSD$

PORTNAME=	axis2
PORTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	www java
MASTER_SITES=	APACHE
MASTER_SITE_SUBDIR=	axis/${PORTNAME}/java/core/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides a Web Services,SOAP and WSDL engine from Apache

LICENSE=	APACHE20

USES=		zip
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes

OPTIONS_SINGLE=	AS
OPTIONS_SINGLE_AS=	TOMCAT6 TOMCAT7
OPTIONS_DEFAULT=	TOMCAT6

NO_STAGE=	yes

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTOMCAT6}
APPHOME=	${LOCALBASE}/apache-tomcat-6.0
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
.endif

.if ${PORT_OPTIONS:MTOMCAT7}
APPHOME=	${LOCALBASE}/apache-tomcat-7.0
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat7
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat7
.endif

USE_JAVA=	yes
JAVA_VERSION=	1.6+
SHAREOWN=	www
SHAREGRP=	www
PLIST_SUB+=	APPHOME=${APPHOME:S|^${PREFIX}/||} \
		CONF_EXT=${CONF_EXT}
CONF_EXT=	sample

PORTEXAMPLES=	*

do-install:
	( ${MKDIR} ${APPHOME}/webapps/${PORTNAME}/WEB-INF/lib && cd ${WRKSRC}/lib && ${COPYTREE_SHARE} \* ${APPHOME}/webapps/${PORTNAME}/WEB-INF/lib)
	( ${MKDIR} ${APPHOME}/webapps/${PORTNAME}/WEB-INF/classes && cd ${WRKSRC}/webapp/WEB-INF/classes && ${COPYTREE_SHARE} \* ${APPHOME}/webapps/${PORTNAME}/WEB-INF/classes )$
	( ${MKDIR} ${APPHOME}/webapps/${PORTNAME}/axis2-web && cd ${WRKSRC}/webapp/axis2-web && ${COPYTREE_SHARE} \* ${APPHOME}/webapps/${PORTNAME}/axis2-web )
	( cd ${WRKSRC}/repository && ${COPYTREE_SHARE} \* ${APPHOME}/webapps/${PORTNAME}/WEB-INF )
	@${CHOWN} ${SHAREGRP}:${SHAREOWN} ${APPHOME}/webapps/${PORTNAME}
	@${INSTALL} -d -g ${SHAREGRP} -o ${SHAREOWN} ${APPHOME}/webapps/${PORTNAME}/WEB-INF/conf
	@(cd ${WRKSRC};${FIND} conf -type f | ${SED} -e '/${CONF_EXT}/d') \
		| while read a; do \
			${MV} ${WRKSRC}/$$a ${WRKSRC}/$$a.${CONF_EXT}; \
			if [ ! -e "${APPHOME}/webapps/${PORTNAME}/WEB-INF/$$a" ]; then \
				${ECHO_MSG} "	Installing local configuration file: ${APPHOME}/webapps/${PORTNAME}/WEB-INF/$$a"; \
				${INSTALL_DATA} ${WRKSRC}/$$a.${CONF_EXT} ${APPHOME}/webapps/${PORTNAME}/WEB-INF/$$a; \
			else \
				${ECHO_MSG} "	Preserving local configuration file: ${APPHOME}/webapps/${PORTNAME}/WEB-INF/$$a"; \
			fi; \
		done
			${INSTALL_DATA} ${WRKSRC}/conf/*.${CONF_EXT} ${APPHOME}/webapps/${PORTNAME}/WEB-INF/conf
	${MV} ${WRKSRC}/webapp/WEB-INF/web.xml ${WRKSRC}/webapp/WEB-INF/web.xml.${CONF_EXT}
	@if [ ! -e "${APPHOME}/webapps/axis2/WEB-INF/web.xml" ]; then \
		${ECHO_MSG} "	Installing local configuration file: ${APPHOME}/webapps/WEB-INF/web.xml"; \
		${INSTALL_DATA} ${WRKSRC}/webapp/WEB-INF/web.xml.${CONF_EXT} ${APPHOME}/webapps/${PORTNAME}/WEB-INF/web.xml; \
	else \
		${ECHO_MSG} "	Preserving local configuration file: ${APPHOME}/webapps/${PORTNAME}/WEB-INF/web.xml"; \
	fi;
		${INSTALL_DATA} ${WRKSRC}/webapp/WEB-INF/web.xml.${CONF_EXT} ${APPHOME}/webapps/${PORTNAME}/WEB-INF
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \;
	cd ${WRKSRC}/samples && ${FIND} . -type f -not -name '*.class' -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
.endif

.include <bsd.port.mk>
