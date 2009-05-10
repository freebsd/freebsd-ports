# New ports collection makefile for:    sakai
# Date created:         11 March 2008
# Whom:                 wenheping@gmail.com
#
# $FreeBSD$
#

PORTNAME=	sakai
PORTVERSION=	2.5.4
CATEGORIES=	www java
MASTER_SITES=	http://source.sakaiproject.org/release/${PORTVERSION}/artifacts/
DISTNAME=	${PORTNAME}-bin-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Sakai is an online Collaboration and Learning Environment

RUN_DEPENDS=	${TOMCAT}:${PORTSDIR}/www/tomcat55

USE_JAVA=	yes
JAVA_VERSION=	1.5

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-bin-${PORTVERSION}
TOMCAT=		${PREFIX}/tomcat5.5
TOMCATOWN=	www
TOMCATGRP=	www
WEBAPPDIR=	${PREFIX}/tomcat5.5/webapps
SYSTEM_DIR=	common components licenses server shared
TOMCAT_DIR=	${PREFIX}/tomcat5.5
LIC_DOC=	ECLv1.txt
PLIST_SUB+=	SAKAI_VER="${PORTVERSION}"

do-install:
	cd ${WRKSRC}/webapps && ${FIND} . -type f -exec ${INSTALL} -g \
		${TOMCATGRP} -o ${TOMCATOWN} -m 444 {} ${WEBAPPDIR}/{} \;

.for i in ${SYSTEM_DIR}
	cd ${WRKSRC}/${i} && ${FIND} . -type d \
		-exec ${INSTALL} -d ${TOMCAT_DIR}/${i}/{} \;
	cd ${WRKSRC}/${i} && ${FIND} . -type f \
		-exec ${INSTALL} -m 644 {} ${TOMCAT_DIR}/${i}/{} \;
.endfor
	${INSTALL_DATA} ${WRKSRC}/${LIC_DOC} ${TOMCAT_DIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
