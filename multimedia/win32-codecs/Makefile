# New ports collection makefile for:	avifile
# Date created: 	16 September 2000
# Whom: 		Holger Lamm
#
# $FreeBSD$
#

PORTNAME=	win32-codecs
PORTVERSION=	2.${CODEC_MPLAYER_VERSION:S/pre/.p/}
PORTEPOCH=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www1.mplayerhq.hu/MPlayer/releases/codecs/:mplayer_extracodec \
		http://www2.mplayerhq.hu/MPlayer/releases/codecs/:mplayer_extracodec \
		http://www.mplayerhq.hu/MPlayer/releases/codecs/:w32codec \
		http://ftp.lug.udel.edu/MPlayer/releases/codecs/:mplayer_extracodec,w32codec \
		http://www1.mplayerhq.hu/MPlayer/releases/codecs/:mplayer_extracodec \
		http://www2.mplayerhq.hu/MPlayer/releases/codecs/:mplayer_extracodec \
		ftp://ftp.mplayerhq.hu/MPlayer/releases/codecs/:w32codec \
		ftp://ftp.lug.udel.edu/MPlayer/releases/codecs/:mplayer_extracodec,w32codec
DIST_SUBDIR=	win32
DISTFILES=	win32codecs.tar.bz2:w32codec \
		qt6dlls.tar.bz2:mplayer_extracodec \
		rp9codecs.tar.bz2:mplayer_extracodec \
		xanimdlls.tar.bz2:mplayer_extracodec
EXTRACT_ONLY=	win32codecs.tar.bz2

MAINTAINER=	holger@e-gitt.net
COMMENT=	Huge compilation of Win32 binary codecs, including MPEG-4(DivX ;-))

RESTRICTED=	Unsure of codec\'s license

ONLY_FOR_ARCHS=	i386
USE_BZIP2=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/w32codec-${CODEC_MPLAYER_VERSION:S/pre7//}

PLIST_SUB=	PKGNAME=${PKGNAME}

CODEC_MPLAYER_VERSION=	0.90
# Used by other ports to detect if this is installed
CODEC_DETECTION_FILE=	${LOCALBASE}/lib/win32/${PKGNAME}

# additional codec packs
ADDITIONAL_CODECS_DISTFILES=	qt6dlls.tar.bz2 xanimdlls.tar.bz2 \
				rp9codecs.tar.bz2
# extraction wrksrc
ADDITIONAL_CODECS_WRKSRC=	win32codecs \
				qt6dlls rp9codecs xanimdlls

post-extract:
.for file in ${ADDITIONAL_CODECS_DISTFILES}
	@cd ${WRKDIR} && ${TAR} xyf \
		${DISTDIR}/${DIST_SUBDIR}/${file}
.endfor
	@${MKDIR} ${WRKSRC}
.for dir in ${ADDITIONAL_CODECS_WRKSRC}
	@${INSTALL} ${WRKDIR}/${dir}/* ${WRKSRC}
.endfor

do-install:
	@${MKDIR} ${PREFIX}/lib/win32
	@${CHMOD} 0555 ${PREFIX}/lib/win32
	@${INSTALL_DATA} ${WRKSRC}/* ${PREFIX}/lib/win32
# marker file
	@${CP} /dev/null ${PREFIX}/lib/win32/${PKGNAME}
	@${CHMOD} 0444 ${PREFIX}/lib/win32/${PKGNAME}

.include <bsd.port.mk>
