# New ports collection makefile for: dvbcut
# Date created:		Mon Dec 19 23:20:01 CET 2005
# Whom:			se@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	dvbcut
PORTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.mr511.de/dvbcut/

MAINTAINER=	se@FreeBSD.org
COMMENT=	Qt application for cutting of MPEG PS and MPEG TS streams (DVB)

LICENSE=	GPLv2

BUILD_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer
LIB_DEPENDS=	a52:${PORTSDIR}/audio/liba52 \
		ao:${PORTSDIR}/audio/libao \
		mad:${PORTSDIR}/audio/libmad \
		avutil:${PORTSDIR}/multimedia/ffmpeg

RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GCC=	any
USES=		cmake
USE_QT4=  gui qt3support xml  moc_build qmake_build rcc_build uic_build
CXXFLAGS+=	-I${PREFIX}/include \
		-I${PREFIX}/include/libavcodec \
		-I${PREFIX}/include/libavformat \
		-I${PREFIX}/include/libswscale

MAN1=		dvbcut.1
PLIST_FILES=	bin/dvbcut

#post-extract:
#		${RM} ${WRKSRC}/src/mplayererrorbase.h

pre-patch:
		cd ${WRKSRC} && ${BZCAT} ${FILESDIR}/use-qt4.diff.bz2 | ${PATCH} -p2

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/dvbcut ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/dvbcut.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
