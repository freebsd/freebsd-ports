# New ports collection makefile for:	avifile
# Date created: 	16 September 2000
# Whom: 		Holger Lamm
#
# $FreeBSD$
#

PORTNAME=	win32-codecs
PORTVERSION=	3.${CODEC_MPLAYER_VERSION:S/pre/.p/}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www1.mplayerhq.hu/MPlayer/releases/codecs/ \
		http://www2.mplayerhq.hu/MPlayer/releases/codecs/ \
		http://www.mplayerhq.hu/MPlayer/releases/codecs/ \
		http://www1.mplayerhq.hu/MPlayer/releases/codecs/ \
		http://www2.mplayerhq.hu/MPlayer/releases/codecs/ \
		ftp://ftp.mplayerhq.hu/MPlayer/releases/codecs/ \
		ftp://ftp.lug.udel.edu/MPlayer/releases/codecs/
DISTFILES=	win32codecs-20040703.tar.bz2 \
		${ADDITIONAL_CODECS_DISTFILES}
DIST_SUBDIR=	win32
EXTRACT_ONLY=	win32codecs-20040703.tar.bz2

MAINTAINER=	holger@e-gitt.net
COMMENT=	Huge compilation of Win32 binary codecs, including MPEG-4(DivX ;-))

RESTRICTED=	Unsure of codec\'s license

ONLY_FOR_ARCHS=	i386
USE_BZIP2=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/w32codec-${CODEC_MPLAYER_VERSION:S/pre7//}

PLIST_SUB=	PKGNAME=${PKGNAME}

CODEC_MPLAYER_VERSION=	1.0pre5
# Used by other ports to detect if this is installed
CODEC_DETECTION_FILE=	${LOCALBASE}/lib/win32/${PKGNAME}

# additional codec packs
ADDITIONAL_CODECS_DISTFILES=	qt63dlls-20050115.tar.bz2 \
				qtextras-20041107.tar.bz2 \
				rp9codecs-20050115.tar.bz2 \
				rp9codecs-win32-20050115.tar.bz2 \
				xanimdlls-20040626.tar.bz2

# extraction wrksrc
ADDITIONAL_CODECS_WRKSRC=	${DISTFILES:S/.tar.bz2//}

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
	@${CHMOD} 0755 ${PREFIX}/lib/win32
	@${INSTALL_DATA} ${WRKSRC}/* ${PREFIX}/lib/win32
# marker file
	@${CP} /dev/null ${PREFIX}/lib/win32/${PKGNAME}
	@${CHMOD} 0444 ${PREFIX}/lib/win32/${PKGNAME}

.include <bsd.port.mk>
