# New ports collection makefile for:    sakai
# Date created:         11 March 2008
# Whom:                 wenheping@gmail.com
#
# $FreeBSD$
#

PORTNAME=	sakai
PORTVERSION=	2.7.1
CATEGORIES=	www java
MASTER_SITES=	http://source.sakaiproject.org/release/${PORTVERSION}/artifacts/
DISTFILES=	${PORTNAME}-bin-${PORTVERSION}.tgz

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Sakai is an online Collaboration and Learning Environment

RUN_DEPENDS=	${LOCALBASE}/${TOMCAT}:${PORTSDIR}/www/tomcat55

USE_JAVA=	yes
JAVA_VERSION=	1.5+

NO_BUILD=	yes
WRKSRC=		${WRKDIR}
TOMCAT=		tomcat5.5
TOMCATOWN=	www
TOMCATGRP=	www
SYSTEM_DIR=	common components licenses server shared webapps
TOMCAT_DIR=	${PREFIX}/tomcat5.5
PLIST_SUB+=	SAKAI_VER="${PORTVERSION}"

do-install:

.for i in ${SYSTEM_DIR}
	cd ${WRKSRC}/${i} && ${FIND} . -type d \
		-exec ${INSTALL} -d ${TOMCAT_DIR}/${i}/{} \;
	cd ${WRKSRC}/${i} && ${FIND} . -type f \
		-exec ${INSTALL} -m 644 {} ${TOMCAT_DIR}/${i}/{} \;
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
