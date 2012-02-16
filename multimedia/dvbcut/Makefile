# New ports collection makefile for: dvbcut
# Date created:		Mon Dec 19 23:20:01 CET 2005
# Whom:			se@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	dvbcut
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.mr511.de/dvbcut/

MAINTAINER=	se@FreeBSD.org
COMMENT=	Qt application for cutting of MPEG PS and MPEG TS streams (DVB)

BUILD_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer
LIB_DEPENDS=	a52.0:${PORTSDIR}/audio/liba52 \
		ao.4:${PORTSDIR}/audio/libao \
		mad.2:${PORTSDIR}/audio/libmad \
		avutil.1:${PORTSDIR}/multimedia/ffmpeg

RUN_DEPENDS:=	${BUILD_DEPENDS}

LICENSE=	GPLv2

OPTIONS=	QT3 "Use QT3 instead of QT4" off

.if defined (WITH_QT3)
PKGNAMESUFFIX=	-qt3
USE_QT_VER=	3
.else
USE_QT_VER=	4
.endif

.include <bsd.port.pre.mk>

.if defined (WITH_QT3)
BUILD_DEPENDS+=	moc:${PORTSDIR}/x11-toolkits/qt33
LIB_DEPENDS+=	qt-mt.3:${PORTSDIR}/x11-toolkits/qt33
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ffmpeg=${LOCALBASE}
MAKEFILE=	makefile
QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}
.else
USE_CMAKE=	yes
QT_COMPONENTS=  gui qt3support xml  moc_build qmake_build rcc_build uic_build
CXXFLAGS+=	-I${PREFIX}/include \
		-I${PREFIX}/include/libavcodec \
		-I${PREFIX}/include/libavformat \
		-I${PREFIX}/include/libswscale
.endif

MAN1=		dvbcut.1
PLIST_FILES=	bin/dvbcut

.if defined(WITHOUT_QT3)
#post-extract:
#		${RM} ${WRKSRC}/src/mplayererrorbase.h

pre-patch:
		cd ${WRKSRC} && uudecode -o /dev/stdout ${FILESDIR}/use-qt4.diff.bz2.uu | ${BZCAT} | ${PATCH} -p2
.endif

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/dvbcut ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/dvbcut.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
