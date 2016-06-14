# $FreeBSD$

PORTNAME=	youtube_dl
PORTVERSION=	2016.06.12
CATEGORIES=	www
MASTER_SITES=	https://yt-dl.org/downloads/${PORTVERSION}/
DISTNAME=	youtube-dl-${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Program for downloading videos from YouTube.com

LICENSE=	UNLICENSE
LICENSE_NAME=	The Unlicense
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	zip:archivers/zip

ALL_TARGET=	youtube-dl
MAKE_ARGS=	PYTHON=${PYTHON_CMD}
USES=		python
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/youtube-dl

OPTIONS_DEFINE=	BASH FISH RTMPDUMP FFMPEG ZSH
OPTIONS_DEFAULT=BASH FISH RTMPDUMP ZSH
OPTIONS_SUB=	yes
FISH_DESC=	Install programmable completions for Fish
RTMPDUMP_DESC=	Use RTMPDUMP to download rtmp video streams

PLIST_FILES=	bin/youtube-dl \
		man/man1/youtube-dl.1.gz \
		%%BASH%%etc/bash_completion.d/youtube-dl.sh \
		%%FISH%%share/fish/completions/youtube-dl.fish \
		%%ZSH%%share/zsh/site-functions/_youtube-dl

FFMPEG_RUN_DEPENDS=	${LOCALBASE}/bin/ffprobe:multimedia/ffmpeg
RTMPDUMP_RUN_DEPENDS=	${LOCALBASE}/bin/rtmpdump:multimedia/rtmpdump

post-extract:
	@# remove tarball provided version, build our own
	@${RM} -f ${WRKSRC}/youtube-dl

post-patch:
	@${REINPLACE_CMD} -e 's|python devscripts/|${PYTHON_CMD} devscripts/|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
