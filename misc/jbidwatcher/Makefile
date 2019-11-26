# Created by: Jose Rodriguez <king@v2project.com>
# $FreeBSD$

PORTNAME=	jbidwatcher
PORTVERSION=	2.5.6
PORTREVISION=	1
CATEGORIES=	misc java
MASTER_SITES=	http://www.jbidwatcher.com/download/

MAINTAINER=	shurd@FreeBSD.org
COMMENT=	Java-based application allowing you to monitor eBay auctions

USES=	tar:bzip2
USE_JAVA=	yes
USE_ANT=	yes
ALL_TARGET=	jar

SUB_FILES=	jbidwatcher
SUB_LIST+=	PORTVERSION=${PORTVERSION}
PLIST_FILES=	%%JAVAJARDIR%%/JBidwatcher-${PORTVERSION}.jar \
		bin/${PORTNAME}

do-install:
	@${INSTALL_DATA} ${WRKSRC}/JBidwatcher-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
