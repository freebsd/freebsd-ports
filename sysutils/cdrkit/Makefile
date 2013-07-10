# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cdrkit
PORTVERSION=	1.1.11
CATEGORIES=	sysutils
MASTER_SITES=	http://cdrkit.org/releases/ \
		http://debburn.alioth.debian.org/

MAINTAINER=	jharris@widomaker.com
COMMENT=	Command-line CD/DVD writing suite

USES=		cmake iconv

MAN1=		cdda2ogg.1 devdump.1 dirsplit.1 genisoimage.1 icedax.1 \
		isodebug.1 isodump.1 isoinfo.1 isovfy.1 list_audio_tracks.1 \
		pitchplay.1 readmult.1 readom.1 wodim.1
MAN5=		genisoimagerc.5

CONFLICTS=	cdrtools-[0-9]* cjk-cdrtools-[0-9]* cdrtools-devel-[0-9]*

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/include/AddSchilyBits.cmake \
	    ${WRKSRC}/3rd-party/dirsplit/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|fexecve|librols_fexecve|g' \
	    ${WRKSRC}/librols/fexec.c \
	    ${WRKSRC}/include/schily.h
	@${REINPLACE_CMD} -e 's|getdelim|wodim_getdelim|g' ${WRKSRC}/wodim/cue.c

.include <bsd.port.mk>
