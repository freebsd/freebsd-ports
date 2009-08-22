# New ports collection makefile for:	dvd-slideshow
# Date created:				2005-02-16
# Whom:					Phil Oleson <oz@nixil.net>
#
# $FreeBSD$
#

PORTNAME=	dvd-slideshow
PORTVERSION=	0.8.2
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}-2
DISTFILES=	${PORTNAME}-${PORTVERSION}-2${EXTRACT_SUFX}
THEMEVERSION=	0.8.0

MAINTAINER=	oz@nixil.net
COMMENT=	Script that creates a slideshow-style DVD with some simple menus

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		identify:${PORTSDIR}/graphics/ImageMagick \
		mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
		sox:${PORTSDIR}/audio/sox \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		jhead:${PORTSDIR}/graphics/jhead \
		flvtool2:${PORTSDIR}/multimedia/ruby-flvtool2 \
		${LOCALBASE}/lib/X11/fonts/urwfonts-ttf/README:${PORTSDIR}/x11-fonts/urwfonts-ttf

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-2

NO_BUILD=	yes
USE_CDRTOOLS=	yes
DATADIR=	${PREFIX}/share/apps/${PORTNAME}

OPTIONS=	LAME "Optional mp3 audio support" off \
		THEMES "Optional themes" off \
		TOOLAME "Faster Optional mp3 audio support" off \
		VORBISTOOLS "Optional ogg vorbis audio support" off

MAN1=		dvd-slideshow.1 \
		dvd-menu.1 \
		dir2slideshow.1 \
		gallery1-to-slideshow.1 \
		jigl2slideshow.1

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/lame)
WITH_LAME=yes
.endif
.if exists(${LOCALBASE}/bin/oggdec)
WITH_VORBISTOOLS=yes
.endif
.if exists(${LOCALBASE}/bin/toolame)
WITH_TOOLAME=yes
.endif

.if defined(WITH_LAME)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif
.if defined(WITH_VORBISTOOLS)
RUN_DEPENDS+=	oggdec:${PORTSDIR}/audio/vorbis-tools
.endif
.if defined(WITH_TOOLAME)
RUN_DEPENDS+=	toolame:${PORTSDIR}/audio/toolame
.endif
.if defined(WITH_THEMES)
DISTFILES+=	${PORTNAME}-themes-${THEMEVERSION}-1${EXTRACT_SUFX}
WRKSRC2=	${WRKDIR}/${PORTNAME}-themes-${THEMEVERSION}-1
PLIST_SUB+=	NOTHEMES=""
.else
PLIST_SUB+=	NOTHEMES="@comment "
.endif
.if defined(NOPORTDOCS)
PLIST_SUB+=	NOPORTDOCS="@comment "
.else
PLIST_SUB+=	NOPORTDOCS=""
.endif

post-patch:
.for FILE in dvd-slideshow dvd-menu dir2slideshow gallery1-to-slideshow jigl2slideshow
	@${REINPLACE_CMD} -e 's|!/bin/bash|!${PREFIX}/bin/bash|g ; \
			      s|/usr/share/fonts/|${LOCALBASE}/lib/X11/fonts/|g ; \
			      s|seq |seq2 |g' \
				 ${WRKSRC}/${FILE}
.ifdef(WITH_THEMES)
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
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "Installing doc files."
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dvd-slideshowrc ${DOCSDIR}
.for FILE in changelog.html gallery1-to-slideshow.html dir2slideshow.html jigl2slideshow.html dvd-menu.html dvd-slideshow.html
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${DOCSDIR}
.endfor
.endif
.ifdef(WITH_THEMES)
	@${ECHO_MSG} "Installing theme files."
	${MKDIR} ${DATADIR}/themes
	cd ${WRKSRC2} && ${FIND} * | ${CPIO} -dpmu -R ${BINOWN}:${BINGRP} --quiet ${DATADIR}/themes
.endif

.include <bsd.port.post.mk>
