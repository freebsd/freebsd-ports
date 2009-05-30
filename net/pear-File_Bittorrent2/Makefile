# Ports collection makefile for:  pear-File_Bittorrent2
# Date created:			  28 Aug 2007
# Whom:				  Zhen REN <bg1tpt@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	File_Bittorrent2
DISTVERSION=	1.3.1
CATEGORIES=	net pear

MAINTAINER=	bg1tpt@gmail.com
COMMENT=	Decode and Encode data in Bittorrent format

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

CATEGORY=	File
FILES=		Bittorrent2/Decode.php Bittorrent2/Encode.php \
		Bittorrent2/Exception.php Bittorrent2/MakeTorrent.php

_EXAMPLESDIR=	.
EXAMPLES=	example.php example_mktorrent.php \
		install-x86-universal-2005.0.iso.torrent \
		scrape.php torrentinfo.php

_TESTSDIR=	Tests
TESTS=		AllTests.php Bug7406.php Bug8085.php Bug14013.php \
		Bug16148.php ticket-19.php FileBittorrent2.php

post-extract:
	@ cd ${WRKSRC}/File; ${MV} Bittorrent2 ${WRKSRC}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
