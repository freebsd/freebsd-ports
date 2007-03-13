# New ports collection makefile for:	avifile
# Date created: 	16 September 2000
# Whom: 		Holger Lamm
#
# $FreeBSD$
#

PORTNAME=	win32-codecs
DISTVERSION=	3.${CODEC_MPLAYER_VERSION}
PORTEPOCH=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www1.mplayerhq.hu/MPlayer/releases/codecs/ \
		http://www2.mplayerhq.hu/MPlayer/releases/codecs/ \
		http://www4.mplayerhq.hu/MPlayer/releases/codecs/ \
		http://ftp.lug.udel.edu/MPlayer/releases/codecs/ \
		http://www.mplayerhq.hu/MPlayer/releases/codecs/ \
		ftp://ftp1.mplayerhq.hu/MPlayer/releases/codecs/ \
		ftp://ftp2.mplayerhq.hu/MPlayer/releases/codecs/ \
		ftp://ftp.lug.udel.edu/MPlayer/releases/codecs/
DISTFILES=	all-20061022.tar.bz2 \
		${ADDITIONAL_CODECS_DISTFILES}
DIST_SUBDIR=	win32
EXTRACT_ONLY=	all-20061022.tar.bz2

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Huge compilation of Win32 binary video codecs

RESTRICTED=	Unsure of codec's license			# '

ONLY_FOR_ARCHS=	i386
USE_BZIP2=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/w32codec-${CODEC_MPLAYER_VERSION:S/pre7//}

PLIST_SUB=	PKGNAME=${PKGNAME}

CODEC_MPLAYER_VERSION=	1.0rc1
# Used by other ports to detect if this is installed
CODEC_DETECTION_FILE=	${LOCALBASE}/lib/win32/${PKGNAME}

# additional codec packs
ADDITIONAL_CODECS_DISTFILES=	xanimdlls-20040626.tar.bz2

# extraction wrksrc
ADDITIONAL_CODECS_WRKSRC=	${DISTFILES:S/.tar.bz2//}

# list of quicktime codecs that will be removed
REMOVE_CODECS_FILES=	AvidQTAVUICodec.qtx QuickTimeEssentials.qtx QuickTime.qts \
			QuickTimeInternetExtras.qtx qtmlClient.dll BeHereiVideo.qtx

OPTIONS=	REALPLAYER	"Install realplayer codec"	on

.include <bsd.port.pre.mk>

#.if defined(WITH_QUICKTIME)
#FORBIDDEN=	Remote code execution: http://vuxml.FreeBSD.org/24f6b1eb-43d5-11db-81e1-000e0c2e438a.html
#ADDITIONAL_CODECS_DISTFILES+=	qt63dlls-20050115.tar.bz2 \
#				qtextras-20041107.tar.bz2
#PLIST_SUB+=	QUICKTIME=""
#.else
PLIST_SUB+=	QUICKTIME="@comment "
#.endif

.if !defined(WITHOUT_REALPLAYER)
ADDITIONAL_CODECS_DISTFILES+=	rp9codecs-20050115.tar.bz2 \
				rp9codecs-win32-20050115.tar.bz2
PLIST_SUB+=	REALPLAYER=""
.else
PLIST_SUB+=	REALPLAYER="@comment "
.endif

post-extract:
	@cd ${WRKDIR}/all-20061022 && \
		${RM} ${REMOVE_CODECS_FILES}
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
.if !defined(WITHOUT_REALPLAYER)
	@${INSTALL_DATA} ${WRKSRC}/* ${PREFIX}/lib/win32
.else
	@${INSTALL_DATA} ${WRKSRC}/*[^0] ${PREFIX}/lib/win32
.endif
# marker file
	@${CP} /dev/null ${PREFIX}/lib/win32/${PKGNAME}
	@${CHMOD} 0444 ${PREFIX}/lib/win32/${PKGNAME}

.include <bsd.port.post.mk>
