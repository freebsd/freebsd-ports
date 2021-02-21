# $FreeBSD$

PORTNAME=	youtube_dlc
DISTVERSION=	2021.02.19
CATEGORIES=	www

# Implicit approval to commit trivial version updates.
MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Program for downloading videos from various streaming services

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake python shebangfix
SHEBANG_GLOB=	devscripts/*.py
USE_GITHUB=	yes
GH_ACCOUNT=	pukkandan
GH_PROJECT=	yt-dlp

MAKE_ARGS=	PYTHON=${PYTHON_CMD}
NO_ARCH=	yes

OPTIONS_DEFINE=		FFMPEG MANPAGES RTMPDUMP SYMLINK
OPTIONS_DEFAULT=	FFMPEG RTMPDUMP
OPTIONS_SUB=	yes

RTMPDUMP_DESC=	Use rtmpdump to download rtmp video streams
SYMLINK_DESC=	Install youtube-dl symbolic link for executable

FFMPEG_RUN_DEPENDS=	ffprobe:multimedia/ffmpeg
MANPAGES_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc
RTMPDUMP_RUN_DEPENDS=	rtmpdump:multimedia/rtmpdump
SYMLINK_CONFLICTS=	youtube_dl

post-patch-MANPAGES-on:
	@${PATCH} -d ${WRKSRC} -p0 < ${PATCHDIR}/extrapatch-manpages

post-install-SYMLINK-on:
	@${RLN} ${STAGEDIR}${PREFIX}/bin/youtube-dlc ${STAGEDIR}${PREFIX}/bin/youtube-dl

.include <bsd.port.mk>
