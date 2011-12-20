# New ports collection makefile for:	axis2
# Date created:				28 July 2011
# Whom:					Jason Helfman <jhelfman@experts-exchange.com>
#
# $FreeBSD$

PORTNAME=	axis2
PORTVERSION=	1.6.1
PORTREVISION=	2
CATEGORIES=	www java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	axis/${PORTNAME}/java/core/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Provides a Web Services,SOAP and WSDL engine from Apache

LICENSE=	ASL

USE_ZIP=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes

OPTIONS=		TOMCAT5 "Enable Tomcat 5.x support"     on \
			TOMCAT6 "Enable Tomcat 6.x support"     off \
			TOMCAT7 "Enable Tomcat 7.x support"     off

.include <bsd.port.options.mk>

.if defined(WITH_TOMCAT5)
APPHOME=	${LOCALBASE}/tomcat5.5
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55
.endif

.if defined(WITH_TOMCAT6)
APPHOME=	${LOCALBASE}/apache-tomcat-6.0
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
.endif

.if defined(WITH_TOMCAT7)
APPHOME=	${LOCALBASE}/apache-tomcat-7.0
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat7
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat7
.endif

.if ( defined(WITH_TOMCAT5) && defined(WITH_TOMCAT6) || defined(WITH_TOMCAT7) )
IGNORE=	you can only define one application server
.elif ( defined(WITH_TOMCAT6) && defined(WITH_TOMCAT7) )
IGNORE=	you can only define one application server
.elif !defined(APPHOME)
IGNORE=	you need at least one application server
.endif

USE_JAVA=	yes
JAVA_VERSION=	1.6+
SHAREOWN=	www
SHAREGRP=	www
PLIST_SUB+=	APPHOME=${APPHOME:S|^${PREFIX}/||} \
		CONF_EXT=${CONF_EXT}
CONF_EXT=	sample

.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	*
.endif

do-install:
	( ${MKDIR} ${APPHOME}/webapps/${PORTNAME}/WEB-INF/lib && cd ${WRKSRC}/lib && ${COPYTREE_SHARE} \* ${APPHOME}/webapps/${PORTNAME}/WEB-INF/lib)
	( ${MKDIR} ${APPHOME}/webapps/${PORTNAME}/WEB-INF/classes && cd ${WRKSRC}/webapp/WEB-INF/classes && ${COPYTREE_SHARE} \* ${APPHOME}/webapps/${PORTNAME}/WEB-INF/classes )$
	( ${MKDIR} ${APPHOME}/webapps/${PORTNAME}/axis2-web && cd ${WRKSRC}/webapp/axis2-web && ${COPYTREE_SHARE} \* ${APPHOME}/webapps/${PORTNAME}/axis2-web )
	( cd ${WRKSRC}/repository && ${COPYTREE_SHARE} \* ${APPHOME}/webapps/${PORTNAME}/WEB-INF )
	@${CHOWN} ${SHAREGRP}:${SHAREOWN} ${APPHOME}/webapps/${PORTNAME}
	@install -d -g ${SHAREGRP} -o ${SHAREOWN} ${APPHOME}/webapps/${PORTNAME}/WEB-INF/conf
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
.if !defined(NOPORTEXAMPLES)
	cd ${WRKSRC}/samples && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \;
	cd ${WRKSRC}/samples && ${FIND} . -type f -not -name '*.class' -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
.endif

.include <bsd.port.mk>
