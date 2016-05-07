# Created by: Diego Depaoli <trebestie@gmail.com>
# $FreeBSD$

PORTNAME=	2ManDVD
PORTVERSION=	1.8.5
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://download.tuxfamily.org/2mandvd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DVD authoring and slideshow tool

LICENSE=	GPLv2

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
RUN_DEPENDS=	sox:audio/sox \
		notify-send:devel/libnotify \
		exif:graphics/exif \
		netpbm>=10.26:graphics/netpbm \
		dvdauthor:multimedia/dvdauthor \
		ffmpegthumbnailer:multimedia/ffmpegthumbnailer \
		mencoder:multimedia/mencoder \
		ppmtoy4m:multimedia/mjpegtools \
		mplayer:multimedia/mplayer \
		tcprobe:multimedia/transcode \
		xine:multimedia/xine \
		bash:shells/bash \
		cdrecord:sysutils/cdrtools \
		growisofs:sysutils/dvd+rw-tools

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		desktop-file-utils gmake perl5 qmake:norecursive shebangfix
SHEBANG_FILES=	fake.pl
USE_QT4=	corelib gui opengl \
		linguisttools_build moc_build rcc_build uic_build
USE_GL=		glu
USE_SDL=	sdl
USE_PERL5=	run

DATADIR=	${PREFIX}/share/2ManDVD

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
		's|/usr/share/2ManDVD|${PREFIX}/share/pixmaps| ; \
		 s|/usr/bin/||' ${WRKSRC}/2ManDVD.desktop
	@${REINPLACE_CMD} -e \
		's|Ne slideshow|New slideshow|' ${WRKSRC}/2mandvd_en.ts

pre-build:
	${LRELEASE} ${WRKSRC}/2mandvd_en.ts

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/2ManDVD ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/fake.pl ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.qm ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} Bibliotheque ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/2ManDVD.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/Interface/mandvdico.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
