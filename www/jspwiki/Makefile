# Created by: wenheping@gmail.com

PORTNAME=	jspwiki
PORTVERSION=	2.8.4
PORTREVISION=	3
CATEGORIES=	www java
MASTER_SITES=	http://www.ecyrd.com/~jalkanen/JSPWiki/${PORTVERSION}/
DISTNAME=	JSPWiki-${PORTVERSION}-bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Feature-rich and extensible Wiki engine built around J2EE

LICENSE=	APACHE20
LICENSE_FILE=	${WRKDIR}/jspwiki/LICENSE

DEPRECATED=	Depends on expired www/tomcat7
EXPIRATION_DATE=2022-03-31

USES=		cpe zip
USE_JAVA=	yes
NO_BUILD=	yes
NO_ARCH=	yes

CPE_VENDOR=	apache

TOMCATDIR=	${PREFIX}/${TOMCATVER}
APPHOME=	${LOCALBASE}/${TOMCATVER}
WEBAPPDIR=	${TOMCATDIR}/webapps
WEBAPP=		JSPWiki

PORTDOCS=	ChangeLog README ReleaseNotes JSPWiki-*.zip

PLIST_SUB=	TOMCATDIR=${TOMCATDIR:S|^${PREFIX}/||}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

TOMCATVER=	apache-tomcat-7.0
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:www/tomcat7

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

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKDIR}/${PORTNAME}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
