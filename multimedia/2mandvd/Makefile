# Created by: Diego Depaoli <trebestie@gmail.com>
# $FreeBSD$

PORTNAME=	2ManDVD
PORTVERSION=	1.8.4
CATEGORIES=	multimedia kde
MASTER_SITES=	http://download.tuxfamily.org/2mandvd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DVD authoring and slideshow tool

LICENSE=	GPLv2

LIB_DEPENDS=	avcodec:${PORTSDIR}/multimedia/ffmpeg
RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox \
		notify-send:${PORTSDIR}/devel/libnotify \
		netpbm>=10.26:${PORTSDIR}/graphics/netpbm \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		ffmpegthumbnailer:${PORTSDIR}/multimedia/ffmpegthumbnailer \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		ppmtoy4m:${PORTSDIR}/multimedia/mjpegtools \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		tcprobe:${PORTSDIR}/multimedia/transcode \
		xine:${PORTSDIR}/multimedia/xine \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_QT4=	corelib gui opengl \
		linguist_build moc_build qmake_build rcc_build uic_build
USE_GL=		glu
USE_SDL=	sdl
USE_PERL5_RUN=	yes
USE_CDRTOOLS=	yes
USE_GMAKE=	yes
MAKE_ENV=	QTDIR="${QT_PREFIX}"
MAKE_JOBS_SAFE=	yes

post-patch:
	@${GREP} -lR "/bash" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|/bash|/sh|'
	@${GREP} -lR "cp -rf" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|cp -rf|cp -Rf|'
	@${REINPLACE_CMD} -e \
		's|/usr/include|${LOCALBASE}/include| ; \
		 s|/usr/share/2ManDVD|${PREFIX}/lib/2ManDVD| ; \
		 s|/usr/bin|${PREFIX}/bin| ; \
		 s|/usr/share/applications|${PREFIX}/share/applications| ; \
		 s|^QMAKE_|#QMAKE_|' ${WRKSRC}/2ManDVD.pro
	@${REINPLACE_CMD} -e \
		's|/usr/bin/perl|${LOCALBASE}/bin/perl|' ${WRKSRC}/fake.pl
	@${REINPLACE_CMD} -e \
		's|/usr/share/2ManDVD|${PREFIX}/share/pixmaps| ; \
		 s|/usr/bin/||' ${WRKSRC}/2ManDVD.desktop

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS})

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} 2ManDVD ${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} fake.pl ${PREFIX}/bin)
	@${MKDIR} ${PREFIX}/lib/2ManDVD
	(cd ${WRKSRC} && ${INSTALL_DATA} *.qm ${PREFIX}/lib/2ManDVD)
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} Bibliotheque ${PREFIX}/lib/2ManDVD)
	@${MKDIR} ${DESKTOPDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} 2ManDVD.desktop ${DESKTOPDIR})
	(cd ${WRKSRC}/Interface && ${INSTALL_DATA} mandvdico.png \
		${PREFIX}/share/pixmaps)

.include <bsd.port.mk>
