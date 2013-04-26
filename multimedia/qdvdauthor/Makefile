# Created by: oz@nixil.net
# $FreeBSD$

PORTNAME=	qdvdauthor
PORTVERSION=	1.1.0
PORTREVISION=	11
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	oz@nixil.net
COMMENT=	Qt graphical frontend for dvdauthor

BUILD_DEPENDS=	dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		dvd-slideshow:${PORTSDIR}/multimedia/dvd-slideshow \
		qmake:${PORTSDIR}/devel/qmake

RUN_DEPENDS=	dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		dvd-slideshow:${PORTSDIR}/multimedia/dvd-slideshow \
		dv2sub:${PORTSDIR}/multimedia/dv2sub \
		bash:${PORTSDIR}/shells/bash

DATA_FILES=	silence.mp2 html/en/audio_streams.html html/en/system_register.html \
		qdvdauthor_ca.qm qdvdauthor_de.qm qdvdauthor_eo.qm \
		qdvdauthor_es.qm qdvdauthor_fr.qm qdvdauthor_it.qm \
		qdvdauthor_pl.qm qplayer_ca.qm qplayer_de.qm \
		qplayer_es.qm qplayer_fr.qm qslideshow_ca.qm \
		qslideshow_de.qm qslideshow_es.qm qslideshow_fr.qm \
		qslideshow_it.qm qrender_ca.qm qrender_de.qm \
		qrender_es.qm

PLIST_FILES=	bin/qdvdauthor \
		bin/qslideshow \
		bin/qplayer \
		bin/qrender \
		share/pixmaps/qdvdauthor.png \
		${DATA_FILES:S,^,%%DATADIR%%/,}
PLIST_DIRS=	%%DATADIR%%/html/en %%DATADIR%%/html %%DATADIR%%

DESKTOP_ENTRIES="QDVDAuthor" \
		"DVD Author GUI" \
		"${PREFIX}/share/pixmaps/qdvdauthor.png" \
		"QDVDAuthor" \
		"AudioVideo;Qt;" \
		"false"

HAS_CONFIGURE=	yes
USE_QT_VER=	3
QT_NONSTANDARD=	yes
CONFIGURE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
CONFIGURE_ARGS=	--prefix=${PREFIX} --qt-dir=${LOCALBASE} --with-qt-lib=qt-mt \
		--build-qslideshow --build-qplayer
NO_BUILD=	yes

OPTIONS_DEFINE=	NETPBM MJPEGTOOLS CDRTOOLS TRANSCODE DVDRWTOOLS MPLAYER TOOLAME MCTOOLAME
OPTIONS_DEFAULT=	NETPBM MJPEGTOOLS CDRTOOLS TRANSCODE
NETPBM_DESC=		Create mpeg2 streams for movie menus
MJPEGTOOLS_DESC=	Convert background images into mpeg2 movie
CDRTOOLS_DESC=		Create iso images of DVD on the Hard Drive
TRANSCODE_DESC=		Support for movie format conversion
DVDRWTOOLS_DESC=	Optional DVD recording/burning prog
MPLAYER_DESC=		Optional support for mplayer playback
TOOLAME_DESC=		Optional support for audio conversion
MCTOOLAME_DESC=		Optional support for audio conversion

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNETPBM}
RUN_DEPENDS+=	pngtopnm:${PORTSDIR}/graphics/netpbm
.endif
.if ${PROT_OPTIONS:MMJPEGTOOLS}
RUN_DEPENDS+=	mpeg2enc:${PORTSDIR}/multimedia/mjpegtools
.endif
.if ${PORT_OPTIONS:MCDRTOOLS}
RUN_DEPENDS+=	cdrecord:${PORTSDIR}/sysutils/cdrtools
.endif
.if ${PORT_OPTIONS:MDVDRWTOOLS}
RUN_DEPENDS+=	growisofs:${PORTSDIR}/sysutils/dvd+rw-tools
.endif
.if ${PORT_OPTIONS:MLIBXINE}
LIB_DEPENDS+=	xine.2:${PORTSDIR}/multimedia/libxine
CONFIGURE_ARGS+=--with-xine-support
.endif
.if ${PORT_OPTIONS:MMPLAYER}
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
CONFIGURE_ARGS+=--with-mplayer-support
.endif
.if ${PORT_OPTIONS:MTRANSCODE}
RUN_DEPENDS+=	transcode:${PORTSDIR}/multimedia/transcode
.endif
.if ${PORT_OPTIONS:MTOOLAME}
RUN_DEPENDS+=	toolame:${PORTSDIR}/audio/toolame
.endif
.if ${PORT_OPTIONS:MMCTOOLAME}
RUN_DEPENDS+=	mctoolame:${PORTSDIR}/audio/mctoolame-encoder
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qdvdauthor ${PREFIX}/bin/qdvdauthor
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qslideshow ${PREFIX}/bin/qslideshow
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qplayer    ${PREFIX}/bin/qplayer
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qrender    ${PREFIX}/bin/qrender

	@${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/qdvdauthor.png ${PREFIX}/share/pixmaps

	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/silence.mp2    ${DATADIR}

	@${MKDIR} ${DATADIR}/html/en
	${INSTALL_DATA} ${WRKSRC}/doc/html/en/audio_streams.html   ${DATADIR}/html/en
	${INSTALL_DATA} ${WRKSRC}/doc/html/en/system_register.html ${DATADIR}/html/en

.for locale in ca de eo es fr it pl
	${INSTALL_DATA} ${WRKSRC}/qdvdauthor/i18n/qdvdauthor_${locale}.qm  ${DATADIR}
.endfor
.for locale in ca de es fr
	${INSTALL_DATA} ${WRKSRC}/qdvdauthor/i18n/qplayer_${locale}.qm     ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/qdvdauthor/i18n/qslideshow_${locale}.qm  ${DATADIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/qdvdauthor/i18n/qslideshow_it.qm  ${DATADIR}
.for locale in ca de es
	${INSTALL_DATA} ${WRKSRC}/qdvdauthor/i18n/qrender_${locale}.qm  ${DATADIR}
.endfor
.include <bsd.port.mk>
