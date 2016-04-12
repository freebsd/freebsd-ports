# Created by: wenheping@gmail.com
# $FreeBSD$

PORTNAME=	jspwiki
PORTVERSION=	2.8.4
PORTREVISION=	2
CATEGORIES=	www java
MASTER_SITES=	http://www.ecyrd.com/~jalkanen/JSPWiki/${PORTVERSION}/
DISTNAME=	JSPWiki-${PORTVERSION}-bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Feature-rich and extensible Wiki engine built around J2EE

LICENSE=	APACHE20

USES=		zip
USE_JAVA=	1.6+
NO_BUILD=	yes

TOMCATDIR=	${PREFIX}/${TOMCATVER}
APPHOME=	${LOCALBASE}/${TOMCATVER}
WEBAPPDIR=	${TOMCATDIR}/webapps
WEBAPP=		JSPWiki

PORTDOCS=	ChangeLog README ReleaseNotes JSPWiki-*.zip

PLIST_SUB=	TOMCATDIR=${TOMCATDIR:S|^${PREFIX}/||}

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=	AS
OPTIONS_SINGLE_AS=	TOMCAT6 TOMCAT7
OPTIONS_DEFAULT=	TOMCAT6

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTOMCAT6}
TOMCATVER=	apache-tomcat-6.0
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:www/tomcat6
.endif

.if ${PORT_OPTIONS:MTOMCAT7}
TOMCATVER=	apache-tomcat-7.0
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:www/tomcat7
.endif

post-extract:
	@${MV} ${WRKDIR}/${WEBAPP} ${WRKDIR}/${PORTNAME}
	@${MKDIR} ${WRKDIR}/${WEBAPP}
	@${TAR} xf ${WRKDIR}/${PORTNAME}/JSPWiki.war -C ${WRKDIR}/${WEBAPP}
.for file in jspwiki.policy jspwiki.properties web.xml
	@${MV} ${WRKDIR}/${WEBAPP}/WEB-INF/${file} ${WRKDIR}/${WEBAPP}/WEB-INF/${file}.sample
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${WEBAPPDIR}/${WEBAPP}
	(cd ${WRKDIR}/${WEBAPP} && ${COPYTREE_SHARE} . ${STAGEDIR}${WEBAPPDIR}/${WEBAPP})

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKDIR}/${PORTNAME}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
