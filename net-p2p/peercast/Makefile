# New ports collection makefile for:	peercast
# Date created:			21 Dec 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	peercast
PORTVERSION=	0.1218
CATEGORIES=	net-p2p multimedia
MASTER_SITES=	http://www.peercast.org/
DISTNAME=	peercast-linux
EXTRACT_SUFX=	.tgz

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	A peer-to-peer network for broadcasting and listening to streams

FORBIDDEN=	arbitrary code execution, http://www.vuxml.org/freebsd/402ae710-26a2-11dd-ae05-825f4c35000a.html
DEPRECATED=	has been forbidden for more than 6 months
EXPIRATION_DATE=2009-01-19

USE_LINUX=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SUB_FILES=	peercast.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/peercast.sh ${PREFIX}/bin/peercast
	${INSTALL_PROGRAM} ${WRKSRC}/peercast ${PREFIX}/libexec
.for lang in de en fr ja
	${MKDIR} ${DATADIR}/html/${lang}
	${INSTALL_DATA} ${WRKSRC}/html/${lang}/*.* ${DATADIR}/html/${lang}
	${MKDIR} ${DATADIR}/html/${lang}/images
	${INSTALL_DATA} ${WRKSRC}/html/${lang}/images/*.* \
		${DATADIR}/html/${lang}/images
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
