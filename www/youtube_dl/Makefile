# $FreeBSD$

PORTNAME=	youtube_dl
PORTVERSION=	2015.01.25
CATEGORIES=	www
MASTER_SITES=	https://yt-dl.org/downloads/${PORTVERSION}/
DISTNAME=	youtube-dl-${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Program for downloading videos from YouTube.com

LICENSE=	UNLICENSE
LICENSE_NAME=	The Unlicense
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip

ALL_TARGET=	youtube-dl
MAKE_ARGS=	PYTHON=${PYTHON_CMD}
USES=		python:run
NO_ARCH=	yes

OPTIONS_DEFINE=	BASH FISH RTMPDUMP FFMPEG ZSH
OPTIONS_DEFAULT=RTMPDUMP

FISH_DESC=	Install programmable completions for Fish
RTMPDUMP_DESC=	Use RTMPDUMP to download rtmp video streams

PLIST_FILES=	bin/youtube-dl \
		man/man1/youtube-dl.1.gz

WRKSRC=		${WRKDIR}/youtube-dl

BASH_PLIST_FILES=	etc/bash_completion.d/youtube-dl.sh
FISH_PLIST_FILES=	share/fish/completions/youtube-dl.fish
ZSH_PLIST_FILES=	share/zsh/site-functions/_youtube-dl
FFMPEG_RUN_DEPENDS=	${LOCALBASE}/bin/ffprobe:${PORTSDIR}/multimedia/ffmpeg
RTMPDUMP_RUN_DEPENDS=	${LOCALBASE}/bin/rtmpdump:${PORTSDIR}/multimedia/rtmpdump

.include <bsd.port.options.mk>

post-extract:
	@# remove tarball provided version, build our own
	@${RM} -f ${WRKSRC}/youtube-dl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/youtube-dl ${STAGEDIR}${PREFIX}/bin/youtube-dl
	${INSTALL_DATA} ${WRKSRC}/youtube-dl.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MBASH}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/youtube-dl.bash-completion \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/youtube-dl.sh
.endif
.if ${PORT_OPTIONS:MFISH}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/youtube-dl.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/
.endif
.if ${PORT_OPTIONS:MZSH}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/youtube-dl.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_youtube-dl
.endif

.include <bsd.port.mk>
