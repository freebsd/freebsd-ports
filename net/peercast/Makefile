# New ports collection makefile for:	peercast
# Date created:			21 Dec 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	peercast
PORTVERSION=	0.1211
CATEGORIES=	net multimedia
MASTER_SITES=	http://www.peercast.org/
DISTNAME=	peercast-linux
EXTRACT_SUFX=	.tgz

MAINTAINER=	jylefort@brutele.be
COMMENT=	A peer-to-peer network for broadcasting and listening to streams

RUN_DEPENDS=	${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base-8

USE_LINUX=	yes
NO_WRKSUBDIR=	yes

do-build:
	${SED} -e 's|@PREFIX@|${PREFIX}|g; s|@DATADIR@|${DATADIR}|g' \
		${FILESDIR}/peercast.in > ${WRKSRC}/peercast.sh

do-install:
	${MKDIR} ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/peercast ${PREFIX}/libexec
	# rebrand binary (INSTALL_PROGRAM has stripped it)
	${BRANDELF} -t Linux ${PREFIX}/libexec/peercast
.for lang in de en fr ja
	${MKDIR} ${DATADIR}/html/${lang}
	${INSTALL_DATA} ${WRKSRC}/html/${lang}/*.* ${DATADIR}/html/${lang}
	${MKDIR} ${DATADIR}/html/${lang}/images
	${INSTALL_DATA} ${WRKSRC}/html/${lang}/images/*.* ${DATADIR}/html/${lang}/images
.endfor
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/peercast.sh ${PREFIX}/bin/peercast

.include <bsd.port.mk>
