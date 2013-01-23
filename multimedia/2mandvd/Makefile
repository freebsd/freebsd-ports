# Created by: Diego Depaoli <trebestie@gmail.com>
# $FreeBSD$

PORTNAME=	2ManDVD
PORTVERSION=	1.3.5
PORTREVISION=	3
CATEGORIES=	multimedia kde
MASTER_SITES=	http://download.tuxfamily.org/2mandvd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DVD authoring and slideshow tool

RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		netpbm>=10.26:${PORTSDIR}/graphics/netpbm \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		ppmtoy4m:${PORTSDIR}/multimedia/mjpegtools \
		ffmpegthumbnailer:${PORTSDIR}/multimedia/ffmpegthumbnailer \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		notify-send:${PORTSDIR}/devel/libnotify \
		tcprobe:${PORTSDIR}/multimedia/transcode \
		xine:${PORTSDIR}/multimedia/xine \
		ffmpeg>=0.5:${PORTSDIR}/multimedia/ffmpeg

LICENSE=	GPLv2

USE_CDRTOOLS=	true
USE_PERL5_RUN=	yes
USE_QT4=	qmake_build gui corelib rcc_build moc_build uic_build webkit

MAKE_ENV=	QTDIR=${QT_PREFIX}
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES="2ManDVD" "DVD Maker" "${PREFIX}/share/pixmaps/mandvdico.png" \
		"2ManDVD" "AudioVideo;DiscBurning;Qt;" false

post-patch:
	@${REINPLACE_CMD} -e 's|bash|sh|' ${WRKSRC}/mainfrm.cpp \
		${WRKSRC}/rendering.cpp ${WRKSRC}/project.cpp \
		${WRKSRC}/media_browser.cpp
	@${REINPLACE_CMD} -e 's|cp -rf|cp -Rf|' ${WRKSRC}/project.cpp
	@${RM} -f ${WRKSRC}/ui_*.h ${WRKSRC}/moc_*.cpp ${WRKSRC}/qrc_*.cpp \
		${WRKSRC}/*/*/*/*~

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${QMAKE} -spec ${QMAKESPEC} 2ManDVD.pro

do-install:
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "Bibliotheque Interface" ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.qm ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/2ManDVD ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Interface/mandvdico.png \
		${PREFIX}/share/pixmaps
	${LN} -fs ${DATADIR}/2ManDVD ${PREFIX}/bin

.include <bsd.port.mk>
