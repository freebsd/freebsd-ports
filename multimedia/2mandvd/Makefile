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

LIB_DEPENDS=	avcodec:${PORTSDIR}/multimedia/ffmpeg
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

USES=		perl5
USE_QT4=	corelib gui opengl \
		linguist_build moc_build qmake_build rcc_build uic_build
USE_GL=		glu
USE_SDL=	sdl
USE_PERL5=	run
USE_GMAKE=	yes
MAKE_ENV=	QTDIR="${QT_PREFIX}"

DATADIR=	${PREFIX}/share/2ManDVD

LRELEASE=	${LOCALBASE}/bin/lrelease-qt4

NO_STAGE=	yes
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

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS})

pre-build:
	(cd ${WRKSRC} && ${LRELEASE} 2mandvd_en.ts)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} 2ManDVD ${PREFIX}/bin)
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} fake.pl ${DATADIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} *.qm ${DATADIR})
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} Bibliotheque ${DATADIR})
	@${MKDIR} ${DESKTOPDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} 2ManDVD.desktop ${DESKTOPDIR})
	(cd ${WRKSRC}/Interface && ${INSTALL_DATA} mandvdico.png \
		${PREFIX}/share/pixmaps)

.include <bsd.port.mk>
