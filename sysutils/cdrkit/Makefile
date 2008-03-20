# New ports collection makefile for:	cdrkit
# Date created:				12 Dec 2007
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cdrkit
PORTVERSION=	1.1.7.1
CATEGORIES=	sysutils
MASTER_SITES=	http://cdrkit.org/releases/ \
		http://debburn.alioth.debian.org/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Command-line CD/DVD writing suite

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

USE_ICONV=	yes

MAN1=		cdda2ogg.1 devdump.1 dirsplit.1 genisoimage.1 icedax.1 \
		isodebug.1 isodump.1 isoinfo.1 isovfy.1 list_audio_tracks.1 \
		pitchplay.1 readmult.1 readom.1 wodim.1
MAN5=		genisoimagerc.5

CONFLICTS=	cdrtools-* cjk-cdrtools-*

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/include/AddSchilyBits.cmake ${WRKSRC}/3rd-party/dirsplit/CMakeLists.txt

do-configure:
	@(cd ${WRKSRC}; ${LOCALBASE}/bin/cmake -DCMAKE_INSTALL_PREFIX=${PREFIX} -DCMAKE_C_FLAGS:STRING="${CFLAGS} -I./libparanoia -I${LOCALBASE}/include -L${LOCALBASE}/lib" -DCMAKE_EXE_LINKER_FLAGS:STRING="-L${LOCALBASE}/lib")

.include <bsd.port.mk>
