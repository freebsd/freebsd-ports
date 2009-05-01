# New ports collection makefile for:    jspwiki
# Date created:         29 April, 2009
# Whom:                 wenheping@gmail.com
#
# $FreeBSD$
#

PORTNAME=	jspwiki
PORTVERSION=	2.8.2
CATEGORIES=	www java
MASTER_SITES=	http://www.ecyrd.com/~jalkanen/JSPWiki/${PORTVERSION}/
DISTNAME=	JSPWiki-${PORTVERSION}-bin

MAINTAINER=	wenheping@gmail.com
COMMENT=	A feature-rich and extensible Wiki engine built around J2EE

RUN_DEPENDS=	${TOMCATDIR}:${PORTSDIR}/www/tomcat55

USE_ZIP=	yes
USE_JAVA=	1.5+

NO_BUILD=	yes
TOMCATVER=	tomcat5.5
TOMCATDIR=	${PREFIX}/${TOMCATVER}
TOMCATOWN=	www
TOMCATGRP=	www
WEBAPPDIR=	${TOMCATDIR}/webapps
PORTDOCS=	LICENSE README ReleaseNotes
PLIST_FILES=	${TOMCATVER}/webapps/JSPWiki.war
WRKSRC=		${WRKDIR}/JSPWiki

do-install:
	cd ${WRKSRC} && \
		${INSTALL} -g ${TOMCATGRP} -o ${TOMCATOWN} -m 444 JSPWiki.war ${WEBAPPDIR};

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
