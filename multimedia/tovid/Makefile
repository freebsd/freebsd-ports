# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tovid
PORTVERSION=	0.30
PORTREVISION=	11
CATEGORIES=	multimedia python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

PATCH_SITES=	http://tovid.sourceforge.net/download/patches/
PATCHFILES=	tovid-0.30.2.patch.gz
PATCH_DIST_STRIP=-p1

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A collection of video disc authoring tools

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2013-11-19

BUILD_DEPENDS=	txt2tags:${PORTSDIR}/textproc/txt2tags
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		mplex:${PORTSDIR}/multimedia/mjpegtools \
		ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
		composite:${PORTSDIR}/graphics/ImageMagick \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		vcdxbuild:${PORTSDIR}/multimedia/vcdimager \
		cdrdao:${PORTSDIR}/sysutils/cdrdao \
		tcprobe:${PORTSDIR}/multimedia/transcode \
		cdrecord:${PORTSDIR}/sysutils/cdrtools \
		sox:${PORTSDIR}/audio/sox \
		normalize:${PORTSDIR}/audio/normalize \
		bash:${PORTSDIR}/shells/bash \
		${PYTHON_SITELIBDIR}/cairo/__init__.py:${PORTSDIR}/graphics/py-cairo

USES=		pkgconfig
USE_WX=		2.6
WX_COMPS=	python
NO_BUILD=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes

MAN1=		idvid.1 makedvd.1 makemenu.1 makeslides.1 makevcd.1 makexml.1 \
		postproc.1 pymakexml.1 todisc.1 tovid-stats.1 tovid.1

NO_STAGE=	yes
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

.include <bsd.port.mk>
