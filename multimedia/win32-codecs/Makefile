# Created by: Holger Lamm
# $FreeBSD$

PORTNAME=	win32-codecs
DISTVERSION=	20110131
PORTEPOCH=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	${MASTER_SITE_MPLAYERHQ} \
		http://ftp.lug.udel.edu/MPlayer/releases/codecs/ \
		ftp://ftp.lug.udel.edu/MPlayer/releases/codecs/
MASTER_SITE_SUBDIR=	releases/codecs
DISTFILES=	all-${DISTVERSION}.tar.bz2 \
		${ADDITIONAL_CODECS_DISTFILES}
DIST_SUBDIR=	win32
EXTRACT_ONLY=	all-${DISTVERSION}.tar.bz2

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Huge compilation of Win32 binary video codecs

RESTRICTED=	Unsure of codec's license

ONLY_FOR_ARCHS=	i386
USE_BZIP2=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/w32codec-${DISTVERSION}

PLIST_SUB=	PKGNAME=${PKGNAME}

# Used by other ports to detect if this is installed
CODEC_DETECTION_FILE=	${LOCALBASE}/lib/win32/${PKGNAME}

# additional codec packs
ADDITIONAL_CODECS_DISTFILES=	xanimdlls-20040626.tar.bz2

# extraction wrksrc
ADDITIONAL_CODECS_WRKSRC=	${DISTFILES:S/.tar.bz2//}

# list of quicktime codecs that will be removed
REMOVE_CODECS_FILES=	AvidQTAVUICodec.qtx QuickTimeEssentials.qtx QuickTime.qts \
			QuickTimeInternetExtras.qtx qtmlClient.dll BeHereiVideo.qtx

OPTIONS_DEFINE=	REALPLAYER
OPTIONS_DEFAULT=	REALPLAYER
REALPLAYER_DESC=	Install realplayer codec

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREALPLAYER}
ADDITIONAL_CODECS_DISTFILES+=	rp9codecs-20050115.tar.bz2 \
				rp9codecs-win32-20050115.tar.bz2
PLIST_SUB+=	REALPLAYER=""
.else
PLIST_SUB+=	REALPLAYER="@comment "
.endif

post-extract:
	@cd ${WRKDIR}/all-${DISTVERSION} && \
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

.include <bsd.port.mk>
