# New ports collection makefile for:	avifile
# Date created: 	16 September 2000
# Whom: 		Holger Lamm
#
# $FreeBSD$
#

PORTNAME=	win32-codecs
PORTVERSION=	${CODEC_VERSION}.0.${CODEC_MPLAYER_VERSION}
CATEGORIES=	graphics audio
MASTER_SITES=	http://avifile.sourceforge.net/ \
		http://www.toon.eu.org/divx/ \
		http://ernie.eit.uni-kl.de/avifile/ \
		http://mplayerhq.hu/MPlayer/releases/ \
		ftp://mplayerhq.hu/MPlayer/releases/ \
		http://www2.mplayerhq.hu/MPlayer/releases/ \
		http://ftp.mplayerhq.hu/MPlayer/releases/ \
		http://ftp2.mplayerhq.hu/MPlayer/releases/
DISTFILES=	w32codec-${CODEC_MPLAYER_VERSION}.tar.bz2 \
		binaries-${CODEC_VERSION}.tgz \
		wmvds32.ax.gz
EXTRACT_ONLY=	${DISTFILES:S/wmvds32.ax.gz//:S/binaries-${CODEC_VERSION}.tgz//}

MAINTAINER=	holger@eit.uni-kl.de

RESTRICTED=	Unsure of codec\'s license

ONLY_FOR_ARCHS=	i386
USE_BZIP2=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/w32codec-${CODEC_MPLAYER_VERSION}

PLIST_SUB=	PKGNAME=${PKGNAME}

CODEC_VERSION=	011002
CODEC_MPLAYER_VERSION=	0.60
# Used by other ports to detect if this is installed
CODEC_DETECTION_FILE=	${LOCALBASE}/lib/win32/${PKGNAME}

post-extract:
	@cd ${WRKDIR} && ${TAR} xfz \
		${DISTDIR}/binaries-${CODEC_VERSION}.tgz
	@${INSTALL} ${WRKDIR}/win32/* ${WRKSRC}
	@${GZCAT} ${DISTDIR}/wmvds32.ax.gz > ${WRKSRC}/wmvds32.ax

do-install:
	@${MKDIR} ${PREFIX}/lib/win32
	@${CHMOD} 0555 ${PREFIX}/lib/win32
	@${INSTALL_DATA} ${WRKSRC}/* ${PREFIX}/lib/win32
# marker file
	@${CP} /dev/null ${PREFIX}/lib/win32/${PKGNAME}
	@${CHMOD} 0444 ${PREFIX}/lib/win32/${PKGNAME}

.include <bsd.port.mk>
