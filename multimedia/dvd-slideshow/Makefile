# Created by: Phil Oleson <oz@nixil.net>
# $FreeBSD$

PORTNAME=	dvd-slideshow
PORTVERSION=	0.8.4
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}-2:main \
		SF/${PORTNAME}/${PORTNAME}-themes/${THEMEVERSION}-1:themes
DISTFILES=	${PORTNAME}-${PORTVERSION}-2${EXTRACT_SUFX}:main
THEMEVERSION=	0.8.4

MAINTAINER=	oz@nixil.net
COMMENT=	Script that creates a slideshow-style DVD with some simple menus

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		identify:${PORTSDIR}/graphics/ImageMagick \
		mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
		sox:${PORTSDIR}/audio/sox \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		jhead:${PORTSDIR}/graphics/jhead \
		flvtool2:${PORTSDIR}/multimedia/rubygem-flvtool2 \
		${LOCALBASE}/lib/X11/fonts/urwfonts-ttf/README:${PORTSDIR}/x11-fonts/urwfonts-ttf \
		cdrecord:${PORTSDIR}/sysutils/cdrtools

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-2

NO_BUILD=	yes
DATADIR=	${PREFIX}/share/apps/${PORTNAME}

OPTIONS_DEFINE=	LAME THEMES TOOLAME VORBIS
THEMES_DESC=	Optional themes
TOOLAME_DESC=	Faster Optional mp3 audio support

MAN1=		dvd-slideshow.1 \
		dvd-menu.1 \
		dir2slideshow.1 \
		gallery1-to-slideshow.1 \
		jigl2slideshow.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLAME}
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif
.if ${PORT_OPTIONS:MVORBISTOOLS}
RUN_DEPENDS+=	oggdec:${PORTSDIR}/audio/vorbis-tools
.endif
.if ${PORT_OPTIONS:MTOOLAME}
RUN_DEPENDS+=	toolame:${PORTSDIR}/audio/toolame
.endif
.if ${PORT_OPTIONS:MTHEMES}
DISTFILES+=	${PORTNAME}-themes-${THEMEVERSION}-1${EXTRACT_SUFX}:themes
WRKSRC2=	${WRKDIR}/${PORTNAME}-themes-${THEMEVERSION}-1
PLIST_SUB+=	NOTHEMES=""
.else
PLIST_SUB+=	NOTHEMES="@comment "
.endif

post-patch:
.for FILE in dvd-slideshow dvd-menu dir2slideshow gallery1-to-slideshow jigl2slideshow
	@${REINPLACE_CMD} -e 's|!/bin/bash|!${PREFIX}/bin/bash|g ; \
			      s|/usr/share/fonts/|${LOCALBASE}/lib/X11/fonts/|g ; \
			      s|seq |seq2 |g' \
				 ${WRKSRC}/${FILE}
.if ${PORT_OPTIONS:MTHEMES}
	@${REINPLACE_CMD} -e 's|/opt/dvd-slideshow/themes|${DATADIR}/themes|g' \
				${WRKSRC}/${FILE}
.endif
.endfor

do-install:
	@${ECHO_MSG} "Installing scripts."
.for FILE in dvd-slideshow dvd-menu dir2slideshow gallery1-to-slideshow jigl2slideshow
	${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${PREFIX}/bin
.endfor
	@${ECHO_MSG} "Installing man files."
.for FILE in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/${FILE} ${PREFIX}/man/man1
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "Installing doc files."
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dvd-slideshowrc ${DOCSDIR}
.for FILE in changelog.html gallery1-to-slideshow.html dir2slideshow.html jigl2slideshow.html dvd-menu.html dvd-slideshow.html
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${DOCSDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MTHEMES}
	@${ECHO_MSG} "Installing theme files."
	${MKDIR} ${DATADIR}/themes
	cd ${WRKSRC2} && ${FIND} * | ${CPIO} -dpmu -R ${BINOWN}:${BINGRP} --quiet ${DATADIR}/themes
.endif

.include <bsd.port.mk>
