# New ports collection makefile for:	pebble
# Date created:		2009-02-06
# Whom:			Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pebble
PORTVERSION=	2.3.2
CATEGORIES=	www java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	pebble

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Lightweight, open source, Java EE blogging tool

PATCH_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	${LOCALBASE}/apache-tomcat6.0/bin/catalina.sh:${PORTSDIR}/www/tomcat6

USE_ZIP=	yes

NO_BUILD=	yes

WEBAPP_SUBDIR=	apache-tomcat6.0/webapps
WEBAPP_DIR=	${PREFIX}/${WEBAPP_SUBDIR}

PEBBLE_HOME?=	/var/lib/${PORTNAME}
PEBBLE_PROPERTIES=	${PREFIX}/etc/pebble.properties
SUB_LIST+=	PEBBLE_HOME=${PEBBLE_HOME} PEBBLE_PROPERTIES=${PEBBLE_PROPERTIES}
SUB_FILES=	pebble.properties pkg-message

PKGMESSAGE=	${WRKSRC}/pkg-message

.if !defined(NOPORTDOCS)
PORTDOCS=	configuration.html credits.html images index.html \
		installation.html license.txt multiblog.html screen.css \
		screenshots.html security.html upgrading1x.html \
		upgrading2x.html
.endif
PLIST_FILES=	${WEBAPP_SUBDIR}/${PORTNAME}.war
PEBBLE_CONTEXT=	WEB-INF/applicationContext-pebble.xml

do-patch:
	cd ${WRKSRC} && ${LOCALBASE}/bin/unzip -o pebble.war "${PEBBLE_CONTEXT}"
	${SED} -i.bak 's,/WEB-INF/pebble\.properties,file:${PEBBLE_PROPERTIES},' "${WRKSRC}/${PEBBLE_CONTEXT}"
	cd ${WRKSRC} && ${LOCALBASE}/bin/zip -u pebble.war ${PEBBLE_CONTEXT}

do-install:
	${MKDIR} "${PEBBLE_HOME}"
	${CHOWN} "www:www" "${PEBBLE_HOME}"
	${INSTALL_DATA} ${WRKDIR}/pebble.properties ${PEBBLE_PROPERTIES}.sample
	if [ ! -f ${PEBBLE_PROPERTIES} ]; then ${INSTALL_DATA} ${WRKDIR}/pebble.properties ${PEBBLE_PROPERTIES} ; fi
	${INSTALL_DATA} ${WRKSRC}/pebble.war ${WEBAPP_DIR}/${PORTNAME}.war
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/docs && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	cd ${WRKSRC}/docs && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
