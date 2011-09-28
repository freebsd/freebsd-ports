# New ports collection makefile for:	axis2
# Date created:				28 July 2011
# Whom:					Jason Helfman <jhelfman@experts-exchange.com>
#
# $FreeBSD$

PORTNAME=		axis2
PORTVERSION=		1.6.1
CATEGORIES=		www java
MASTER_SITES=		${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	axis/${PORTNAME}/java/core/${PORTVERSION}/
DISTNAME=		${PORTNAME}-${PORTVERSION}-war

MAINTAINER=	jhelfman@experts-exchange.com
COMMENT=	Provides a Web Services,SOAP and WSDL engine from Apache

LICENSE=	ASL

USE_ZIP=	yes

OPTIONS=		TOMCAT5 "Enable Tomcat 5.x support"     on \
			TOMCAT6 "Enable Tomcat 6.x support"     off \
			TOMCAT7 "Enable Tomcat 7.x support"     off

.include <bsd.port.options.mk>

.if defined(WITH_TOMCAT5)
APPHOME=	${LOCALBASE}/tomcat5.5
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55
WEBAPPDIR=	${APPHOME}/webapps
.endif

.if defined(WITH_TOMCAT6)
APPHOME=	${LOCALBASE}/apache-tomcat-6.0
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
WEBAPPDIR=	${APPHOME}/webapps
.endif

.if defined(WITH_TOMCAT7)
APPHOME=	${LOCALBASE}/apache-tomcat-7.0
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat7
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat7
WEBAPPDIR=	${APPHOME}/webapps
.endif

.if ( defined(WITH_TOMCAT5) && defined(WITH_TOMCAT6) || defined(WITH_TOMCAT7) )
IGNORE=	you can only define one application server
.elif ( defined(WITH_TOMCAT6) && defined(WITH_TOMCAT7) )
IGNORE=	you can only define one application server
.elif !defined(WEBAPPDIR)
IGNORE=	you need at least one application server
.endif

USE_JAVA=	yes
JAVA_VERSION=	1.6+
SHAREOWN=	www
SHAREGRP=	www
PLIST_SUB+=	WEBAPPS=${WEBAPPDIR:S|^${PREFIX}/||}

do-build:
	@${MKDIR} ${WRKSRC}
	@(cd ${WRKSRC} && ${TAR} xf ${WRKDIR}/${PORTNAME}.war)

do-install:
	${MKDIR} ${WEBAPPDIR}/${PORTNAME}
	( cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WEBAPPDIR}/${PORTNAME} )

.include <bsd.port.mk>
