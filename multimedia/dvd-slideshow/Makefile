# New ports collection makefile for:	dvd-slideshow
# Date created:				2005-02-16
# Whom:					Phil Oleson <oz@nixil.net>
#
# $FreeBSD$
#

PORTNAME=	dvd-slideshow
PORTVERSION=	0.7.5
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	oz@nixil.net
COMMENT=	Script that creates a slideshow-style DVD with some simple menus

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		identify:${PORTSDIR}/graphics/ImageMagick \
		mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
		sox:${PORTSDIR}/audio/sox \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		seq2:${PORTSDIR}/misc/seq2 \
		${X11BASE}/lib/X11/fonts/urwfonts-ttf/README:${PORTSDIR}/x11-fonts/urwfonts-ttf

NO_BUILD=	yes
USE_CDRTOOLS=	yes

OPTIONS=	DVDRWTOOLS "Needed to record/burn DVD" off \
		LAME "Optional support for audio" off \
		VORBISTOOLS "Optional audio support" off

PLIST_FILES=	bin/dvd-slideshow \
		bin/dvd-menu \
		bin/dir2slideshow \
		bin/gallery1-to-slideshow \
		bin/jigl2slideshow

MAN1=		dvd-slideshow.1 \
		dvd-menu.1 \
		dir2slideshow.1 \
		gallery1-to-slideshow.1 \
		jigl2slideshow.1

DOC_FILES=	changelog.html gallery1-to-slideshow.html \
		dir2slideshow.html jigl2slideshow.html \
		dvd-menu.html dvd-slideshow.html
PORTDOCS=	${DOC_FILES} dvd-slideshowrc

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/growisofs)
WITH_DVDRWTOOLS=yes
.endif
.if exists(${LOCALBASE}/bin/lame)
WITH_LAME=yes
.endif
.if exists(${LOCALBASE}/bin/oggdec)
WITH_VORBISTOOLS=yes
.endif

.if defined(WITH_DVDRWTOOLS)
RUN_DEPENDS+=	growisofs:${PORTSDIR}/sysutils/dvd+rw-tools
.endif
.if defined(WITH_LAME)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif
.if defined(WITH_VORBISTOOLS)
RUN_DEPENDS+=	oggdec:${PORTSDIR}/audio/vorbis-tools
.endif

post-patch:
.for FILE in dvd-slideshow dvd-menu dir2slideshow gallery1-to-slideshow jigl2slideshow
	@${REINPLACE_CMD} -e 's|!/bin/bash|!${PREFIX}/bin/bash|g ; \
			      s|/usr/share/fonts/|${X11BASE}/lib/X11/fonts/|g ; \
			      s|seq |seq2 |g' \
				 ${WRKSRC}/${FILE}
.endfor

do-install:
.for FILE in dvd-slideshow dvd-menu dir2slideshow gallery1-to-slideshow jigl2slideshow
	${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${PREFIX}/bin
.endfor
	@${ECHO_MSG} "Installing man files."
.for FILE in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/man/${FILE} ${PREFIX}/man/man1
.endfor
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "Installing doc files."
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/dvd-slideshowrc ${DOCSDIR}
.for FILE in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
