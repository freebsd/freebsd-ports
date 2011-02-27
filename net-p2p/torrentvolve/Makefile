# New ports collection makefile for:	torrentvolve
# Date created:				2007-04-19
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	torrentvolve
DISTVERSION=	1.4-beta
PORTREVISION=	2
CATEGORIES=	net-p2p java www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Beta%201.4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform PHP-driven web-based BitTorrent client

RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

DEPRECATED=	development has ceased, and last release is beta
EXPIRATION_DATE=	2011-04-11

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_PHP=	simplexml
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

post-patch:
	@${RM} ${WRKSRC}/site/lib/torrentmodules/tvAzureusBridge/tvTelnetClient/client.php.orig

do-install:
	${MKDIR} ${WWWDIR}
	cd ${WRKSRC} && ${CP} -R config site ${WWWDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL.TXT ${DOCSDIR}
.endif

.include <bsd.port.mk>
