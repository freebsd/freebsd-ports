# New ports collection makefile for:	torrentvolve
# Date created:				2007-04-19
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	torrentvolve
DISTVERSION=	1.4-beta
PORTREVISION=	1
CATEGORIES=	net-p2p java
MASTER_SITES=	SF

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Cross-platform PHP-driven web-based BitTorrent client

RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_PHP=	simplexml
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${WWWDIR}/${PORTNAME}

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${CP} -R config site ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL.TXT ${DOCSDIR}
.endif

.include <bsd.port.mk>
