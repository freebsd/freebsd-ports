# New ports collection makefile for:	avifile
# Date created: 	16 September 2000
# Whom: 		Holger Lamm
#
# $FreeBSD$
#

PORTNAME=	win32-codecs
PORTVERSION=	${CODEC_VERSION}.1.${CODEC_MPLAYER_VERSION:S/pre/.p/}
CATEGORIES=	multimedia audio
MASTER_SITES=	http://avifile.sourceforge.net/:binaries \
		http://ernie.eit.uni-kl.de/avifile/ \
		http://www1.mplayerhq.hu/MPlayer/releases/codecs/:mplayer_extracodec \
		http://www2.mplayerhq.hu/MPlayer/releases/codecs/:mplayer_extracodec \
		http://www.mplayerhq.hu/MPlayer/releases/:w32codec \
		http://ftp.lug.udel.edu/MPlayer/releases/%SUBDIR%/:mplayer_extracodec,w32codec \
		ftp://ftp1.mplayerhq.hu/MPlayer/releases/codecs/:mplayer_extracodec \
		ftp://ftp2.mplayerhq.hu/MPlayer/releases/codecs/:mplayer_extracodec \
		ftp://ftp.mplayerhq.hu/MPlayer/releases/:w32codec \
		ftp://ftp.lug.udel.edu/MPlayer/releases/%SUBDIR%/:mplayer_extracodec,w32codec
MASTER_SITE_SUBDIR=	codecs/:mplayer_extracodec
DISTFILES=	w32codec-${CODEC_MPLAYER_VERSION}.tar.bz2:w32codec \
		binaries-${CODEC_VERSION}.tgz:binaries,DEFAULT \
		Win32_dmo.tgz:binaries \
		qt5dlls.tar.bz2:mplayer_extracodec
EXTRACT_ONLY=	w32codec-${CODEC_MPLAYER_VERSION}.tar.bz2

MAINTAINER=	holger@e-gitt.net

RESTRICTED=	Unsure of codec\'s license

ONLY_FOR_ARCHS=	i386
USE_BZIP2=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/w32codec-${CODEC_MPLAYER_VERSION:S/pre7//}

PLIST_SUB=	PKGNAME=${PKGNAME}

CODEC_VERSION=	011002
CODEC_MPLAYER_VERSION=	0.90pre7
# Used by other ports to detect if this is installed
CODEC_DETECTION_FILE=	${LOCALBASE}/lib/win32/${PKGNAME}

# additional codec packs
ADDITIONAL_CODECS_DISTFILES=	binaries-${CODEC_VERSION}.tgz \
				Win32_dmo.tgz
# additional QuickTime(TM) codec packs
ADDITIONAL_CODECS_QT_DISTFILES=	qt5dlls.tar.bz2
# extraction wrksrc
ADDITIONAL_CODECS_WRKSRC=	Win32_dmo win32 \
				qt5dlls

post-extract:
.for file in ${ADDITIONAL_CODECS_DISTFILES}
	@cd ${WRKDIR} && ${TAR} xzf \
		${DISTDIR}/${file}
.endfor
.for file in ${ADDITIONAL_CODECS_QT_DISTFILES}
	@cd ${WRKDIR} && ${TAR} xyf \
		${DISTDIR}/${file}
.endfor
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
