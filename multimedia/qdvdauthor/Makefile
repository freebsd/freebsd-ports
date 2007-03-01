# New ports collection makefile for:   qdvdauthor
# Date created:        05/07/04
# Whom:                oz@nixil.net
#
# $FreeBSD$
#

PORTNAME=	qdvdauthor
PORTVERSION=	0.1.5
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	oz@nixil.net
COMMENT=	QT graphical frontend for dvdauthor

BUILD_DEPENDS=	dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		dvd-slideshow:${PORTSDIR}/multimedia/dvd-slideshow \
		qmake:${PORTSDIR}/devel/qmake

RUN_DEPENDS=	dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		dvd-slideshow:${PORTSDIR}/multimedia/dvd-slideshow \
		bash:${PORTSDIR}/shells/bash

DATA_FILES=	silence.mp2 html/en/audio_streams.html html/en/system_register.html \
		qdvdauthor_de.qm qdvdauthor_es.qm qdvdauthor_fr.qm qdvdauthor_pl.qm \
		qplayer_de.qm qplayer_es.qm qplayer_fr.qm qslideshow_de.qm \
		qslideshow_es.qm qslideshow_fr.qm

PLIST_FILES=	bin/qdvdauthor \
		bin/qslideshow \
		bin/qplayer \
		${DATA_FILES:S,^,%%DATADIR%%/,}
PLIST_DIRS=	%%DATADIR%%/html/en %%DATADIR%%/html %%DATADIR%%

HAS_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_QT_VER=	3
QT_NONSTANDARD=	yes
CONFIGURE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
CONFIGURE_ARGS=	--prefix=${PREFIX} --qt-dir=${X11BASE} --with-qt-lib=qt-mt \
		--build-qslideshow --build-qplayer
NO_BUILD=	yes

OPTIONS=	NETPBM "Create mpeg2 streams for movie menus" on \
		MJPEGTOOLS "Convert background images into mpeg2 movie" on \
		CDRTOOLS "Create iso images of DVD on the Hard Drive" on \
		TRANSCODE "Support for movie format conversion" on \
		DVDRWTOOLS "Optional DVD recording/burning prog" off \
		MPLAYER "Optional support for mplayer playback" off \
		TOOLAME "Optional support for audio conversion" off \
		MCTOOLAME "Optional support for audio conversion" off

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/pngtopnm)
WITH_NETPBM=yes
.endif
.if exists(${LOCALBASE}/bin/mpeg2enc)
WITH_MJPEGTOOLS=yes
.endif
.if exists(${LOCALBASE}/bin/mkisofs)
WITH_CDRTOOLS=yes
.endif
.if exists(${LOCALBASE}/bin/growisofs)
WITH_DVDRWTOOLS=yes
.endif
.if exists(${LOCALBASE}/bin/mplayer)
WITH_MPLAYER=yes
.endif
.if exists(${LOCALBASE}/bin/transcode)
WITH_TRANSCODE=yes
.endif
.if exists(${LOCALBASE}/bin/toolame)
WITH_TOOLAME=yes
.endif
.if exists(${LOCALBASE}/bin/mctoolame)
WITH_MCTOOLAME=yes
.endif

.if !defined(WITHOUT_NETPBM)
RUN_DEPENDS+=	pngtopnm:${PORTSDIR}/graphics/netpbm
.endif
.if !defined(WITHOUT_MJPEGTOOLS)
RUN_DEPENDS+=	mpeg2enc:${PORTSDIR}/multimedia/mjpegtools
.endif
.if !defined(WITHOUT_CDRTOOLS)
USE_CDRTOOLS=	yes
.endif
.if defined(WITH_DVDRWTOOLS)
RUN_DEPENDS+=	growisofs:${PORTSDIR}/sysutils/dvd+rw-tools
.endif
.if !defined(WITHOUT_LIBXINE)
LIB_DEPENDS+=	xine.1:${PORTSDIR}/multimedia/libxine
CONFIGURE_ARGS+=--with-xine-support
.endif
.if defined(WITH_MPLAYER)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
CONFIGURE_ARGS+=--with-mplayer-support
.endif
.if !defined(WITHOUT_TRANSCODE)
RUN_DEPENDS+=	transcode:${PORTSDIR}/multimedia/transcode
.endif
.if defined(WITH_TOOLAME)
RUN_DEPENDS+=	toolame:${PORTSDIR}/audio/toolame
.endif
.if defined(WITH_MCTOOLAME)
RUN_DEPENDS+=	mctoolame:${PORTSDIR}/audio/mctoolame-encoder
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qdvdauthor ${PREFIX}/bin/qdvdauthor
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qslideshow ${PREFIX}/bin/qslideshow
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qplayer    ${PREFIX}/bin/qplayer

	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/silence.mp2    ${DATADIR}

	${MKDIR} ${DATADIR}/html/en
	${INSTALL_DATA} ${WRKSRC}/doc/html/en/audio_streams.html   ${DATADIR}/html/en
	${INSTALL_DATA} ${WRKSRC}/doc/html/en/system_register.html ${DATADIR}/html/en
.for locale in de es fr
	${INSTALL_DATA} ${WRKSRC}/qdvdauthor/i18n/qdvdauthor_${locale}.qm  ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/qdvdauthor/i18n/qplayer_${locale}.qm     ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/qdvdauthor/i18n/qslideshow_${locale}.qm  ${DATADIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/qdvdauthor/i18n/qdvdauthor_pl.qm  ${DATADIR}
.include <bsd.port.post.mk>
