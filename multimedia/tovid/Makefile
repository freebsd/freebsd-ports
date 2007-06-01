# New ports collection makefile for:	tovid
# Date created:		Mon Dec 26 20:00:42 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tovid
PORTVERSION=	0.30
PORTREVISION=	2
CATEGORIES=	multimedia python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tovid

PATCH_SITES=	http://tovid.sourceforge.net/download/patches/
PATCHFILES=	tovid-0.30.2.patch.gz
PATCH_DIST_STRIP=-p1

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A collection of video disc authoring tools

BUILD_DEPENDS=	\
		sox:${PORTSDIR}/audio/sox \
		composite:${PORTSDIR}/graphics/ImageMagick \
		convert:${PORTSDIR}/graphics/ImageMagick \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		spumux:${PORTSDIR}/multimedia/dvdauthor \
		ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
		mp2enc:${PORTSDIR}/multimedia/mjpegtools \
		mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		mplex:${PORTSDIR}/multimedia/mjpegtools \
		ppmtoy4m:${PORTSDIR}/multimedia/mjpegtools \
		yuvdenoise:${PORTSDIR}/multimedia/mjpegtools \
		yuvfps:${PORTSDIR}/multimedia/mjpegtools \
		mencoder:${PORTSDIR}/multimedia/mplayer \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		tcprobe:${PORTSDIR}/multimedia/transcode \
		tcrequant:${PORTSDIR}/multimedia/transcode \
		vcdxbuild:${PORTSDIR}/multimedia/vcdimager \
		cdrdao:${PORTSDIR}/sysutils/cdrdao \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		txt2tags:${PORTSDIR}/textproc/txt2tags
RUN_DEPENDS=	\
		sox:${PORTSDIR}/audio/sox \
		composite:${PORTSDIR}/graphics/ImageMagick \
		convert:${PORTSDIR}/graphics/ImageMagick \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		spumux:${PORTSDIR}/multimedia/dvdauthor \
		ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
		mp2enc:${PORTSDIR}/multimedia/mjpegtools \
		mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		mplex:${PORTSDIR}/multimedia/mjpegtools \
		ppmtoy4m:${PORTSDIR}/multimedia/mjpegtools \
		yuvdenoise:${PORTSDIR}/multimedia/mjpegtools \
		yuvfps:${PORTSDIR}/multimedia/mjpegtools \
		mencoder:${PORTSDIR}/multimedia/mplayer \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		tcprobe:${PORTSDIR}/multimedia/transcode \
		tcrequant:${PORTSDIR}/multimedia/transcode \
		vcdxbuild:${PORTSDIR}/multimedia/vcdimager \
		cdrdao:${PORTSDIR}/sysutils/cdrdao \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		txt2tags:${PORTSDIR}/textproc/txt2tags \
		bash:${PORTSDIR}/shells/bash

USE_PYTHON=	yes
#USE_PYDISTUTILS=	yes
USE_CDRTOOLS=	yes
USE_WX=		2.6
WX_COMPS=	python
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
NO_BUILD=	yes

CONFIGURE_ARGS=	--mandir=${PREFIX}/man/

MAN1=	idvid.1 makedvd.1 makemenu.1 makeslides.1 makevcd.1 makexml.1 \
	postproc.1 todisc.1 tovid.1 tovid-stats.1

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|gawk|${AWK}|' \
		-e 's|md5sum|md5|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
# md5sum -> md5
# gnu sed -> sed
# linux du -b -> emulation with awk
# du should follow symbolic links
# faster mplayer -dumpaudio
# faster mplayer -dumpvideo
	@${REINPLACE_CMD} -E \
		-e 's|md5sum|md5|' \
		-e 's|sed[[:space:]]+-r|sed -E|' \
		-e "s,du[[:space:]]+-b([^\|]+),ls -ALln \1 | ${AWK} '{print \$$5}'," \
		-e 's|(du[[:space:]]+-c)|\1 -H|' \
		-e 's|(du[[:space:]]+-h)|\1 -H|' \
		-e 's|(-dumpaudio)|-vc dummy -vo null \1|' \
		-e 's|(-dumpvideo)|-ac dummy -ao null \1|' \
		${WRKSRC}/src/*
# bash to sh fixes
	@${REINPLACE_CMD} -E \
		-e 's|\[\[|\[|' \
		-e 's|\]\]|\]|' \
		-e 's|(\[[^]]+=)=|\1|g' \
		-e 's|(\[[^]]+=)=|\1|g' \
		-e 's,(\[[^]]+)\|\|,\1 -o,g' \
		-e 's|(\[[^]]+)&&|\1 -a|g' \
		${WRKSRC}/src/*
# python interpreter safeness
.for dir in libtovid src
	@${FIND} ${WRKSRC}/${dir} -type f | ${XARGS} \
	${REINPLACE_CMD} -E \
		-e 's|/usr/bin/env[[:space:]]+python|${PYTHON_CMD}|'
.endfor

	@${FIND} ${WRKSRC} -name '*.bak' -delete

post-build:
	@cd ${WRKSRC} && ${MAKE}

post-install:
	@cd ${WRKSRC} && ${MAKE} install

.include <bsd.port.mk>
