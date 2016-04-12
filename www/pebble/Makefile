# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pebble
PORTVERSION=	2.3.2
PORTREVISION=	2
CATEGORIES=	www java
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight, open source, Java EE blogging tool

PATCH_DEPENDS=	zip:archivers/zip \
		unzip:archivers/unzip
RUN_DEPENDS=	${LOCALBASE}/apache-tomcat-6.0/bin/catalina.sh:www/tomcat6

USES=		cpe zip:infozip
CPE_VENDOR=	simon_brown

NO_BUILD=	yes

WEBAPP_SUBDIR=	apache-tomcat-6.0/webapps
WEBAPP_DIR=	${PREFIX}/${WEBAPP_SUBDIR}

PEBBLE_HOME?=	/var/lib/${PORTNAME}
PEBBLE_PROPERTIES=	${PREFIX}/etc/pebble.properties
SUB_LIST+=	PEBBLE_HOME=${PEBBLE_HOME} PEBBLE_PROPERTIES=${PEBBLE_PROPERTIES}
SUB_FILES=	pebble.properties pkg-message

PKGMESSAGE=	${WRKSRC}/pkg-message

OPTIONS_DEFINE=	DOCS

PORTDOCS=	configuration.html credits.html images index.html \
		installation.html license.txt multiblog.html screen.css \
		screenshots.html security.html upgrading1x.html \
		upgrading2x.html
PLIST_FILES=	${WEBAPP_SUBDIR}/${PORTNAME}.war
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
PEBBLE_CONTEXT=	WEB-INF/applicationContext-pebble.xml

do-patch:
	cd ${WRKSRC} && ${UNZIP_CMD} -o pebble.war "${PEBBLE_CONTEXT}"
	${SED} -i.bak 's,/WEB-INF/pebble\.properties,file:${PEBBLE_PROPERTIES},' "${WRKSRC}/${PEBBLE_CONTEXT}"
	cd ${WRKSRC} && ${LOCALBASE}/bin/zip -u pebble.war ${PEBBLE_CONTEXT}

do-install:
	@${MKDIR} "${STAGEDIR}${PEBBLE_HOME}"
	${INSTALL_DATA} ${WRKDIR}/pebble.properties ${STAGEDIR}${PEBBLE_PROPERTIES}.sample
	@${MKDIR} ${STAGEDIR}${WEBAPP_DIR}
	${INSTALL_DATA} ${WRKSRC}/pebble.war ${STAGEDIR}${WEBAPP_DIR}/${PORTNAME}.war
	cd ${WRKSRC}/docs && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/{} \;
	cd ${WRKSRC}/docs && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/{} \;

.include <bsd.port.mk>
