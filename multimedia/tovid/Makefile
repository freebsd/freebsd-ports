# New ports collection makefile for:	tovid
# Date created:		Mon Dec 26 20:00:42 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tovid
PORTVERSION=	0.24
PORTREVISION=	7
CATEGORIES=	multimedia python
MASTER_SITES=	http://download.berlios.de/tovid/

MAINTAINER=	lioux@FreeBSD.org
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
		mkisofs:${PORTSDIR}/sysutils/cdrtools \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools
RUN_DEPENDS=	\
		${BUILD_DEPENDS} \
		bash:${PORTSDIR}/shells/bash \
		${PYTHON_SITELIBDIR}/wx-2.6-gtk2-ansi/wx/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython26

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
GNU_CONFIGURE=	yes

MAN1=	idvid.1 makedvd.1 makemenu.1 makeslides.1 makexml.1 postproc.1 \
	tovid-suite.1 tovid.1

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|gawk|${AWK}|' \
		-e 's|md5sum|md5|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT} \
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
	@${REINPLACE_CMD} -E \
		-e 's|/usr/bin/env[[:space:]]+python|${PYTHON_CMD}|' \
		${WRKSRC}/${dir}/*
.endfor
# sh interpreter safeness
	@${REINPLACE_CMD} -E \
		-e 's|`which env`[[:space:]]+sh|${LOCALBASE}/bin/bash|' \
		${WRKSRC}/src/Makefile.in

post-build:
	@cd ${WRKSRC} && ${MAKE}

post-install:
	@cd ${WRKSRC} && ${MAKE} install

.include <bsd.port.mk>
