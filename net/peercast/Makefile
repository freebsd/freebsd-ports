# New ports collection makefile for:	peercast
# Date created:			21 Dec 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	peercast
PORTVERSION=	0.1212
CATEGORIES=	net multimedia
MASTER_SITES=	http://www.peercast.org/
DISTNAME=	peercast-linux
EXTRACT_SUFX=	.tgz

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A peer-to-peer network for broadcasting and listening to streams

USE_LINUX=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
STRIP=		# empty: do not strip linux binaries

SUB_FILES=	peercast.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/peercast.sh ${PREFIX}/bin/peercast
	${INSTALL_PROGRAM} ${WRKSRC}/peercast ${PREFIX}/libexec
.for lang in de en fr ja
	${MKDIR} ${DATADIR}/html/${lang}
	${INSTALL_DATA} ${WRKSRC}/html/${lang}/*.* ${DATADIR}/html/${lang}
	${MKDIR} ${DATADIR}/html/${lang}/images
	${INSTALL_DATA} ${WRKSRC}/html/${lang}/images/*.* ${DATADIR}/html/${lang}/images
.endfor

.include <bsd.port.mk>
