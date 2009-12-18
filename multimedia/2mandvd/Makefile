# New ports collection makefile for: 2ManDVD
# Date created:		Mon 16 Mar 2009 19:23:00 CET
# Whom:                	Diego Depaoli <trebestie@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	2ManDVD
PORTVERSION=	1.2
CATEGORIES=	multimedia kde
MASTER_SITES=	http://download.tuxfamily.org/2mandvd/

MAINTAINER=	trebestie@gmail.com
COMMENT=	Create your own video dvd

RUN_DEPENDS=	sox>=14.0:${PORTSDIR}/audio/sox \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		netpbm>=10.26:${PORTSDIR}/graphics/netpbm \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		ppmtoy4m:${PORTSDIR}/multimedia/mjpegtools \
		ffmpegthumbnailer:${PORTSDIR}/multimedia/ffmpegthumbnailer \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		notify-send:${PORTSDIR}/devel/libnotify \
		tcprobe:${PORTSDIR}/multimedia/transcode \
		xine:${PORTSDIR}/multimedia/xine

USE_QT_VER=	4
USE_CDRTOOLS=	true
USE_PERL5_RUN=	yes
QT_COMPONENTS=	qmake_build gui corelib rcc_build moc_build uic_build \
		webkit

MAKE_ENV+=	QTDIR=${QT_PREFIX}
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES="2ManDVD" \
		"DVD Maker" \
		"mandvdico.png" \
		"2ManDVD" \
		"Application;AudioVideo;" \
		false

post-patch:
	@${REINPLACE_CMD} -e 's|bash|sh|g' ${WRKSRC}/mainfrm.cpp \
		${WRKSRC}/rendering.cpp ${WRKSRC}/project.cpp \
		${WRKSRC}/media_browser.cpp
	@${REINPLACE_CMD} -e 's|cp -rf|cp -Rf|g' ${WRKSRC}/project.cpp
	@${RM} -f ${WRKSRC}/ui_*.h ${WRKSRC}/moc_*.cpp ${WRKSRC}/qrc_*.cpp \
		${WRKSRC}/*/*/*/*~

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -spec ${QMAKESPEC} 2ManDVD.pro

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "Bibliotheque Interface" ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/*.qm ${DATADIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/2ManDVD ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/Interface/mandvdico.png ${PREFIX}/share/pixmaps/mandvdico.png
	${LN} -fs ${DATADIR}/2ManDVD ${PREFIX}/bin/

.include <bsd.port.mk>
