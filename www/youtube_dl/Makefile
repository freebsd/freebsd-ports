# $FreeBSD$

PORTNAME=	youtube_dl
PORTVERSION=	2013.11.06
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

USE_PYTHON_RUN=	2.6-2.7
ALL_TARGET=	youtube-dl

OPTIONS_DEFINE=	BASH RTMPDUMP FFMPEG
OPTIONS_DEFAULT=RTMPDUMP

BASH_DESC=	Install programmable completions for Bash
RTMPDUMP_DESC=	Use RTMPDUMP to download rtmp video streams

PLIST_FILES=	bin/youtube-dl \
		man/man1/youtube-dl.1.gz

WRKSRC=		${WRKDIR}/youtube-dl

BASH_PLIST_FILES=	etc/bash_completion.d/youtube-dl.sh
FFMPEG_RUN_DEPENDS=	${LOCALBASE}/bin/ffprobe:${PORTSDIR}/multimedia/ffmpeg
RTMPDUMP_RUN_DEPENDS=	${LOCALBASE}/bin/rtmpdump:${PORTSDIR}/multimedia/rtmpdump

.include <bsd.port.options.mk>

post-extract:
	@# remove tarball provided version, build our own
	@${RM} -f ${WRKSRC}/youtube-dl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/youtube-dl ${STAGEDIR}${PREFIX}/bin/youtube-dl
	${INSTALL_DATA} ${WRKSRC}/youtube-dl.1 ${STAGEDIR}${PREFIX}/man/man1/
.if ${PORT_OPTIONS:MBASH}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/youtube-dl.bash-completion \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/youtube-dl.sh
.endif

.include <bsd.port.mk>
