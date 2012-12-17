# $FreeBSD$

PORTNAME=	youtube_dl
PORTVERSION=	2012.12.11
CATEGORIES=	www
MASTER_SITES=	https://cloud.github.com/downloads/rg3/youtube-dl/ \
		CRITICAL
DISTNAME=	youtube-dl.${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	A program for downloading videos from YouTube.com

LICENSE=	GPLv2

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip

USE_PYTHON_RUN=	2.6-2.7
ALL_TARGET=	youtube-dl

OPTIONS_DEFINE=	BASH RTMPDUMP FFMPEG
OPTIONS_DEFAULT=RTMPDUMP

BASH_DESC=	Install programmable completions for Bash
RTMPDUMP_DESC=	Use RTMPDUMP to download rtmp video streams

PLIST_FILES=	bin/youtube-dl
MAN1=		youtube-dl.1

WRKSRC=		${WRKDIR}/youtube-dl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRTMPDUMP}
RUN_DEPENDS+=	rtmpdump:${PORTSDIR}/multimedia/rtmpdump
.endif

.if ${PORT_OPTIONS:MBASH}
ALL_TARGET+=	youtube-dl.bash-completion
PLIST_FILES+=	etc/bash_completion.d/youtube-dl.sh
.endif

.if ${PORT_OPTIONS:MFFMPEG}
# allow either multimedia/ffmpeg or multimedia/ffmpeg-devel
. if exists(${LOCALBASE}/include/libavcodec/vda.h)
RUN_DEPENDS+=	ffprobe:${PORTSDIR}/multimedia/ffmpeg-devel
. else
RUN_DEPENDS+=	ffprobe:${PORTSDIR}/multimedia/ffmpeg
. endif
.endif

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/youtube-dl ${PREFIX}/bin/youtube-dl
	@${INSTALL_DATA} ${WRKSRC}/youtube-dl.1 ${PREFIX}/man/man1
.if ${PORT_OPTIONS:MBASH}
	${MKDIR} ${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/youtube-dl.bash-completion \
		${PREFIX}/etc/bash_completion.d/youtube-dl.sh
.endif

.if ${PORT_OPTIONS:MFFMPEG}
post-install:
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
