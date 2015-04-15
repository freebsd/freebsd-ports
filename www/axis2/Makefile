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

USES=		cpe zip
CPE_VENDOR=	apache
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes

OPTIONS_SINGLE=	AS
OPTIONS_SINGLE_AS=	TOMCAT6 TOMCAT7
OPTIONS_DEFAULT=	TOMCAT6

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
	( ${MKDIR} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/lib && cd ${WRKSRC}/lib && ${COPYTREE_SHARE} \* ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/lib)
	( ${MKDIR} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/classes && cd ${WRKSRC}/webapp/WEB-INF/classes && ${COPYTREE_SHARE} \* ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/classes )$
	( ${MKDIR} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/axis2-web && cd ${WRKSRC}/webapp/axis2-web && ${COPYTREE_SHARE} \* ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/axis2-web )
	( cd ${WRKSRC}/repository && ${COPYTREE_SHARE} \* ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF )
	@${CHOWN} ${SHAREGRP}:${SHAREOWN} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}
	@${INSTALL} -d -g ${SHAREGRP} -o ${SHAREOWN} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/conf
	@(cd ${WRKSRC};${FIND} conf -type f | ${SED} -e '/${CONF_EXT}/d') \
		| while read a; do \
			${MV} ${WRKSRC}/$$a ${WRKSRC}/$$a.${CONF_EXT}; \
			${ECHO_CMD} "@unexec if cmp -s ${APPHOME}/webapps/${PORTNAME}/WEB-INF/$$a ${APPHOME}/webapps/${PORTNAME}/WEB-INF/$$a.${CONF_EXT}; then rm -f ${APPHOME}/webapps/${PORTNAME}/WEB-INF/$$a; fi" >> ${TMPPLIST}; \
			${ECHO_CMD} "@exec cp -n ${APPHOME}/webapps/${PORTNAME}/WEB-INF/$$a.${CONF_EXT} ${APPHOME}/webapps/${PORTNAME}/WEB-INF/$$a" >> ${TMPPLIST}; \
		done
	${INSTALL_DATA} ${WRKSRC}/conf/*.${CONF_EXT} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF/conf
	${MV} ${WRKSRC}/webapp/WEB-INF/web.xml ${WRKSRC}/webapp/WEB-INF/web.xml.${CONF_EXT}
	${INSTALL_DATA} ${WRKSRC}/webapp/WEB-INF/web.xml.${CONF_EXT} ${STAGEDIR}${APPHOME}/webapps/${PORTNAME}/WEB-INF
	${ECHO_CMD} "${APPHOME}/webapps/${PORTNAME}/WEB-INF/web.xml.${CONF_EXT}"
	${ECHO_CMD} "@unexec if cmp -s ${APPHOME}/webapps/axis2/WEB-INF/web.xml ${APPHOME}/webapps/axis2/WEB-INF/web.xml.${CONF_EXT}; then rm -f ${APPHOME}/webapps/axis2/WEB-INF/web.xml; fi" >> ${TMPPLIST}
	${ECHO_CMD} "@exec cp -n ${APPHOME}/webapps/axis2/WEB-INF/web.xml.${CONF_EXT} ${APPHOME}/webapps/axis2/WEB-INF/web.xml" >> ${TMPPLIST}
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/{} \;
	cd ${WRKSRC}/samples && ${FIND} . -type f -not -name '*.class' -exec ${INSTALL_DATA} {} ${STAGEDIR}${EXAMPLESDIR}/{} \;
.endif

.include <bsd.port.mk>
