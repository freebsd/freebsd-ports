# New ports collection makefile for:	cdrkit
# Date created:				12 Dec 2007
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cdrkit
PORTVERSION=	1.1.9
CATEGORIES=	sysutils
MASTER_SITES=	http://cdrkit.org/releases/ \
		http://debburn.alioth.debian.org/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Command-line CD/DVD writing suite

USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
USE_ICONV=	yes

MAN1=		cdda2ogg.1 devdump.1 dirsplit.1 genisoimage.1 icedax.1 \
		isodebug.1 isodump.1 isoinfo.1 isovfy.1 list_audio_tracks.1 \
		pitchplay.1 readmult.1 readom.1 wodim.1
MAN5=		genisoimagerc.5

CONFLICTS=	cdrtools-[0-9]* cjk-cdrtools-[0-9]*

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800030
BROKEN=		does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/include/AddSchilyBits.cmake \
	    ${WRKSRC}/3rd-party/dirsplit/CMakeLists.txt

.include <bsd.port.post.mk>
