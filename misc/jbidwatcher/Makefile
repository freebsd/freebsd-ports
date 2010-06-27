# New ports collection makefile for:	jbidwatcher
# Date Created:		24 July 2004
# Whom:			Jose Rodriguez <king@v2project.com>
#
# $FreeBSD$
#

PORTNAME=	jbidwatcher
DISTVERSION=	2.1pre8
CATEGORIES=	misc java
MASTER_SITES=	http://www.jbidwatcher.com/download/
DISTNAME=	JBidwatcher-${DISTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	shurd@sasktel.net
COMMENT=	A Java-based application allowing you to monitor eBay auctions

USE_JAVA=	yes
JAVA_VERSION=	1.5+
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
