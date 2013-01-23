# Created by: Diego Depaoli <trebestie@gmail.com>
# $FreeBSD$

PORTNAME=	mandvd
DISTVERSION=	2.4
PORTREVISION=	12
CATEGORIES=	multimedia kde
MASTER_SITES=	http://csgib36.ifrance.com/FTP/
DISTNAME=	ManDVD
DISTFILES=	${PORTNAME}-${PORTVERSION}src${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DVD authoring and slideshow tool

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
RUN_DEPENDS=	dvd-slideshow>=0.7.5:${PORTSDIR}/multimedia/dvd-slideshow \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		cdrtools>=2.01:${PORTSDIR}/sysutils/cdrtools \
		xine>0.99.4:${PORTSDIR}/multimedia/xine \
		lame>=3.97:${PORTSDIR}/audio/lame \
		dvdauthor>=0.6.11:${PORTSDIR}/multimedia/dvdauthor \
		mjpegtools>=1.9.0:${PORTSDIR}/multimedia/mjpegtools \
		netpbm>10.29:${PORTSDIR}/graphics/netpbm \
		ImageMagick>=6.2.4:${PORTSDIR}/graphics/ImageMagick \
		transcode>=1.0.2:${PORTSDIR}/multimedia/transcode \
		dvd+rw-tools>=5.21.4:${PORTSDIR}/sysutils/dvd+rw-tools

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

PLIST_FILES=	bin/mandvd \
		share/pixmaps/mandvdico.png
PLIST_DIRS=	share/pixmaps

USE_QT_VER=	3
USE_KDELIBS_VER=3
MAKE_ENV=	QTDIR=${QT_PREFIX}
QMAKE=		${LOCALBASE}/bin/qmake
QMAKESPEC=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++
WRKSRC=		${WRKDIR}/${DISTNAME}-${DISTVERSION}src

DESKTOP_ENTRIES=	"ManDVD" "Create your DVD" \
			"${PREFIX}/share/pixmaps/mandvdico.png" \
			"${PORTNAME}" "AudioVideo;DiscBurning;Qt;" false

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -spec ${QMAKESPEC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mandvd ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/mandvdico.png ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
