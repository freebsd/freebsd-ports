# New ports collection makefile for:	dvd-slideshow
# Date created:				2005-02-16
# Whom:					Phil Oleson <oz@nixil.net>
#
# $FreeBSD$
#

PORTNAME=	dvd-slideshow
PORTVERSION=	0.7.1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	oz@nixil.net
COMMENT=	Script that creates a slideshow-style DVD with some simple menus

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		identify:${PORTSDIR}/graphics/ImageMagick \
		mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
		sox:${PORTSDIR}/audio/sox \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		mkisofs:${PORTSDIR}/sysutils/cdrtools

NO_BUILD=	yes
USE_REINPLACE=	yes

OPTIONS=	DVDRWTOOLS "Needed to record/burn DVD" off \
		LAME "Optional support for audio" off \
		VORBISTOOLS "Optional audio support" off

PLIST_FILES=	bin/dvd-slideshow \
		bin/dvd-menu \
		bin/dir2slideshow \
		bin/gallery2slideshow \
		bin/jigl2slideshow

MAN1=		dvd-slideshow.1 \
		dvd-menu.1 \
		dir2slideshow.1 \
		gallery2slideshow.1 \
		jigl2slideshow.1

.if !defined(NOPORTDOCS)
DOC_FILES=	README.html changelog.html gallery2slideshow.html \
		dir2slideshow.html jigl2slideshow.html \
		dvd-menu.html dvd-slideshow.html
PLIST_FILES+=   ${DOC_FILES:S,^,%%DOCSDIR%%/,}
PLIST_FILES+=	%%DOCSDIR%%/dvd-slideshowrc
PLIST_DIRS+=    %%DOCSDIR%%
.endif

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

pre-patch:
.for FILE in dvd-slideshow dvd-menu dir2slideshow gallery2slideshow jigl2slideshow
	@${REINPLACE_CMD} -e 's|!/bin/bash|!${PREFIX}/bin/bash|g' ${WRKSRC}/${FILE}
.endfor

do-build:
#	nada. NO_BUILD does not work if no OPTION is selected. see PR 78436

do-install:
.for FILE in dvd-slideshow dvd-menu dir2slideshow gallery2slideshow jigl2slideshow
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
