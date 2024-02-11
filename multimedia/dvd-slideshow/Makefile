PORTNAME=	dvd-slideshow
DISTVERSION=	0.8.6-1
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION} \
		SF/${PORTNAME}/${PORTNAME}-themes/${THEMEVERSION}:themes
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
THEMEVERSION=	0.8.4-1

MAINTAINER=	oz@nixil.net
COMMENT=	Script to create slideshow-style DVD with some simple menus
WWW=		https://dvd-slideshow.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	bash:shells/bash \
		mpeg2enc:multimedia/mjpegtools \
		ffmpeg:multimedia/ffmpeg \
		sox:audio/sox \
		dvdauthor:multimedia/dvdauthor \
		jhead:graphics/jhead \
		flvtool2:multimedia/rubygem-flvtool2 \
		${LOCALBASE}/share/fonts/urwfonts-ttf/README:x11-fonts/urwfonts-ttf \
		cdrecord:sysutils/cdrtools

USES=		magick:6,run

NO_BUILD=	yes
DATADIR=	${PREFIX}/share/apps/${PORTNAME}

OPTIONS_DEFINE=	DOCS LAME THEMES TOOLAME VORBIS
OPTIONS_SUB=	yes

THEMES_DESC=	Install optional themes

LAME_RUN_DEPENDS=	lame:audio/lame
THEMES_DISTFILES=	${PORTNAME}-themes-${THEMEVERSION}${EXTRACT_SUFX}:themes
TOOLAME_RUN_DEPENDS=	toolame:audio/toolame
VORBIS_RUN_DEPENDS=	oggdec:audio/vorbis-tools

WRKSRC2=	${WRKDIR}/${PORTNAME}-themes-${THEMEVERSION}

post-patch:
.for f in dvd-slideshow dvd-menu dir2slideshow gallery1-to-slideshow jigl2slideshow
	@${REINPLACE_CMD} -e 's|!/bin/bash|!${PREFIX}/bin/bash|g ; \
		s|/usr/share/fonts/|${LOCALBASE}/share/fonts/|g ; \
		s|seq |seq2 |g' ${WRKSRC}/${f}
	@${REINPLACE_CMD} -e 's|/opt/dvd-slideshow/themes|${DATADIR}/themes|g' \
		${WRKSRC}/${f}
.endfor

do-install:
.for s in dvd-slideshow dvd-menu dir2slideshow gallery1-to-slideshow jigl2slideshow
	${INSTALL_SCRIPT} ${WRKSRC}/${s} ${STAGEDIR}${PREFIX}/bin
.endfor
.for m in dvd-slideshow dvd-menu dir2slideshow gallery1-to-slideshow jigl2slideshow
	${INSTALL_MAN} ${WRKSRC}/man/${m}.1 ${STAGEDIR}${PREFIX}/share/man/man1
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dvd-slideshowrc ${STAGEDIR}${DOCSDIR}
.for d in changelog gallery1-to-slideshow dir2slideshow jigl2slideshow dvd-menu dvd-slideshow
	${INSTALL_DATA} ${WRKSRC}/doc/${d}.html ${STAGEDIR}${DOCSDIR}
.endfor

do-install-THEMES-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/themes
	cd ${WRKSRC2} && ${FIND} . | ${CPIO} -dpmu -R ${BINOWN}:${BINGRP} \
		--quiet ${STAGEDIR}${DATADIR}/themes

.include <bsd.port.mk>
