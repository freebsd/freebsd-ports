# Created by: Phil Oleson <oz@nixil.net>
# $FreeBSD$

PORTNAME=	dvd-slideshow
PORTVERSION=	0.8.4
DISTVERSIONSUFFIX=	-2
PORTREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}${DISTVERSIONSUFFIX} \
		SF/${PORTNAME}/${PORTNAME}-themes/${THEMEVERSION}-1:themes
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
THEMEVERSION=	0.8.4

MAINTAINER=	oz@nixil.net
COMMENT=	Script to create slideshow-style DVD with some simple menus

RUN_DEPENDS=	bash:shells/bash \
		identify:graphics/ImageMagick \
		mpeg2enc:multimedia/mjpegtools \
		ffmpeg:multimedia/ffmpeg \
		sox:audio/sox \
		dvdauthor:multimedia/dvdauthor \
		jhead:graphics/jhead \
		flvtool2:multimedia/rubygem-flvtool2 \
		${LOCALBASE}/share/fonts/urwfonts-ttf/README:x11-fonts/urwfonts-ttf \
		cdrecord:sysutils/cdrtools

NO_BUILD=	yes
DATADIR=	${PREFIX}/share/apps/${PORTNAME}

OPTIONS_DEFINE=	LAME THEMES TOOLAME VORBIS
THEMES_DESC=	Install optional themes

LAME_RUN_DEPENDS=	lame:audio/lame
VORBIS_RUN_DEPENDS=	oggdec:audio/vorbis-tools
TOOLAME_RUN_DEPENDS=	toolame:audio/toolame

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTHEMES}
DISTFILES+=	${PORTNAME}-themes-${THEMEVERSION}-1${EXTRACT_SUFX}:themes
WRKSRC2=	${WRKDIR}/${PORTNAME}-themes-${THEMEVERSION}-1
PLIST_SUB+=	NOTHEMES=""
.else
PLIST_SUB+=	NOTHEMES="@comment "
.endif

post-patch:
.for f in dvd-slideshow dvd-menu dir2slideshow gallery1-to-slideshow jigl2slideshow
	@${REINPLACE_CMD} -e 's|!/bin/bash|!${PREFIX}/bin/bash|g ; \
		s|/usr/share/fonts/|${LOCALBASE}/share/fonts/|g ; \
		s|seq |seq2 |g' ${WRKSRC}/${f}
.  if ${PORT_OPTIONS:MTHEMES}
	@${REINPLACE_CMD} -e 's|/opt/dvd-slideshow/themes|${DATADIR}/themes|g' \
		${WRKSRC}/${f}
.  endif
.endfor

do-install:
.for s in dvd-slideshow dvd-menu dir2slideshow gallery1-to-slideshow jigl2slideshow
	${INSTALL_SCRIPT} ${WRKSRC}/${s} ${STAGEDIR}${PREFIX}/bin
.endfor
.for m in dvd-slideshow dvd-menu dir2slideshow gallery1-to-slideshow jigl2slideshow
	${INSTALL_MAN} ${WRKSRC}/man/${m}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dvd-slideshowrc ${STAGEDIR}${DOCSDIR}
.for d in changelog gallery1-to-slideshow dir2slideshow jigl2slideshow dvd-menu dvd-slideshow
	${INSTALL_DATA} ${WRKSRC}/doc/${d}.html ${STAGEDIR}${DOCSDIR}
.endfor
.if ${PORT_OPTIONS:MTHEMES}
	@${MKDIR} ${STAGEDIR}${DATADIR}/themes
	cd ${WRKSRC2} && ${FIND} . | ${CPIO} -dpmu -R ${BINOWN}:${BINGRP} \
		--quiet ${STAGEDIR}${DATADIR}/themes
.endif

.include <bsd.port.mk>
