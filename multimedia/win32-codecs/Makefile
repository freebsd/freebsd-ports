# New ports collection makefile for:	avifile
# Date created: 	16 September 2000
# Whom: 		Holger Lamm
#
# $FreeBSD$
#

PORTNAME=	win32-codecs
PORTVERSION=	${CODEC_VERSION}.1.${CODEC_MPLAYER_VERSION}
CATEGORIES=	graphics audio
MASTER_SITES=	http://ernie.eit.uni-kl.de/avifile/ \
		http://avifile.sourceforge.net/ \
		http://www.toon.eu.org/divx/ \
		http://mplayerhq.hu/MPlayer/releases/ \
		ftp://mplayerhq.hu/MPlayer/releases/ \
		http://www.stud.uni-karlsruhe.de/~uedc/mplayer/ \
		http://codeczone.virtualave.net/ \
		http://www.rrr.de/~riggs/mplayer/
DISTFILES=	w32codec-0.18.zip \
		w32codec-diff-0.18-${CODEC_MPLAYER_VERSION}.zip \
		binaries-${CODEC_VERSION}.zip \
		wmvds32.ax.gz
EXTRACT_ONLY=	${DISTFILES:S/wmvds32.ax.gz//}

MAINTAINER=	holger@eit.uni-kl.de

RESTRICTED=	Unsure of codec\'s license

ONLY_FOR_ARCHS=	i386
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-n -q
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_SUB=	PKGNAME=${PKGNAME}

CODEC_VERSION=	010122
CODEC_MPLAYER_VERSION=	0.50
# Used by other ports to detect if this is installed
CODEC_DETECTION_FILE=	${LOCALBASE}/lib/win32/${PKGNAME}

post-extract:
	@${GZCAT} ${DISTDIR}/wmvds32.ax.gz > ${WRKDIR}/wmvds32.ax

do-install:
	@${MKDIR} ${PREFIX}/lib/win32
	@${CHMOD} 0555 ${PREFIX}/lib/win32
	@${INSTALL_DATA} ${WRKDIR}/* ${PREFIX}/lib/win32
# marker file
	@${CP} /dev/null ${PREFIX}/lib/win32/${PKGNAME}
	@${CHMOD} 0444 ${PREFIX}/lib/win32/${PKGNAME}

.include <bsd.port.mk>
