# Created by: Jose Rodriguez <king@v2project.com>
# $FreeBSD$

PORTNAME=	jbidwatcher
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	misc java
MASTER_SITES=	http://www.jbidwatcher.com/download/

MAINTAINER=	shurd@sasktel.net
COMMENT=	A Java-based application allowing you to monitor eBay auctions

USE_BZIP2=	yes
USE_JAVA=	yes
USE_ANT=	yes
ALL_TARGET=	jar
JAVA_VERSION=	1.6+

SUB_FILES=	jbidwatcher
SUB_LIST+=	PORTVERSION=${PORTVERSION}
PLIST_FILES=	%%JAVAJARDIR%%/JBidwatcher-${PORTVERSION}.jar \
		bin/${PORTNAME}

NO_STAGE=	yes
do-install:
	@${INSTALL_DATA} ${WRKSRC}/JBidwatcher-${PORTVERSION}.jar ${JAVAJARDIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
