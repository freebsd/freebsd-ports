# New ports collection makefile for:	jbidwatcher
# Date Created:		24 July 2004
# Whom:			Jose Rodriguez <king@v2project.com>
#
# $FreeBSD$
#

PORTNAME=	jbidwatcher
PORTVERSION=	0.9.5
CATEGORIES=	misc java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	JBidWatcher-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	king@v2project.com
COMMENT=	A Java-based application allowing you to monitor eBay auctions

USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar \
		bin/${PORTNAME}

do-install:
	@${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${JAVAJARDIR}/${PORTNAME}.jar
	@${SED} -e "s:%%LOCALBASE%%:${LOCALBASE}:" \
		-e "s:%%JAVAJARDIR%%:${JAVAJARDIR}:" \
		${FILESDIR}/jbidwatcher.sh > ${PREFIX}/bin/${PORTNAME}
	@${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/bin/${PORTNAME}
	@${CHMOD} a+rx ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
