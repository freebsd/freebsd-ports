# Created by: Diego Depaoli <trebestie@gmail.com>
# $FreeBSD$

PORTNAME=	2ManDVD
PORTVERSION=	1.8.4
PORTREVISION=	1
CATEGORIES=	multimedia kde
MASTER_SITES=	http://download.tuxfamily.org/2mandvd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DVD authoring and slideshow tool

LICENSE=	GPLv2

LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox \
		notify-send:${PORTSDIR}/devel/libnotify \
		exif:${PORTSDIR}/graphics/exif \
		netpbm>=10.26:${PORTSDIR}/graphics/netpbm \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		ffmpegthumbnailer:${PORTSDIR}/multimedia/ffmpegthumbnailer \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		ppmtoy4m:${PORTSDIR}/multimedia/mjpegtools \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		tcprobe:${PORTSDIR}/multimedia/transcode \
		xine:${PORTSDIR}/multimedia/xine \
		bash:${PORTSDIR}/shells/bash \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		cdrecord:${PORTSDIR}/sysutils/cdrtools

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		perl5 qmake gmake
USE_QT4=	corelib gui opengl \
		linguist_build moc_build qmake_build rcc_build uic_build
USE_GL=		glu
USE_SDL=	sdl
USE_PERL5=	run

DATADIR=	${PREFIX}/share/2ManDVD

LRELEASE=	${LOCALBASE}/bin/lrelease-qt4

post-extract:
	@${FIND} ${WRKSRC} -name "*~" -delete

post-patch:
	@${GREP} -lR "/bash" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|/bash|/sh|'
	@${GREP} -lR "cp -rf" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|cp -rf|cp -Rf|'
	@${REINPLACE_CMD} -e \
		's|/usr/include|${LOCALBASE}/include| ; \
		 s|/usr/share/2ManDVD|${DATADIR}| ; \
		 s|/usr/bin|${DATADIR}| ; \
		 s|/usr/share/applications|${PREFIX}/share/applications| ; \
		 s|^QMAKE_|#QMAKE_|' ${WRKSRC}/2ManDVD.pro
	@${REINPLACE_CMD} -e \
		's|/usr/bin/perl|${LOCALBASE}/bin/perl|' ${WRKSRC}/fake.pl
	@${REINPLACE_CMD} -e \
		's|/usr/share/2ManDVD|${PREFIX}/share/pixmaps| ; \
		 s|/usr/bin/||' ${WRKSRC}/2ManDVD.desktop
	@${REINPLACE_CMD} -e \
		's|Ne slideshow|New slidshow|' ${WRKSRC}/2mandvd_en.ts

pre-build:
	(cd ${WRKSRC} && ${LRELEASE} 2mandvd_en.ts)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/2ManDVD ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/fake.pl ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.qm ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} Bibliotheque ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/2ManDVD.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/Interface/mandvdico.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
