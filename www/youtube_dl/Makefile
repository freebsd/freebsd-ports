# $FreeBSD$

PORTNAME=	youtube_dl
PORTVERSION=	2021.03.02
CATEGORIES=	www
MASTER_SITES=	https://yt-dl.org/downloads/${PORTVERSION}/
DISTNAME=	youtube-dl-${PORTVERSION}

# Implicit approval to commit trivial version updates.
MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Program for downloading videos from various services

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake python

MAKE_ARGS=	PYTHON=${PYTHON_CMD}
ALL_TARGET=	youtube-dl
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/youtube-dl

PLIST_FILES=	bin/youtube-dl \
		etc/bash_completion.d/youtube-dl.sh \
		man/man1/youtube-dl.1.gz \
		share/fish/vendor_completions.d/youtube-dl.fish \
		share/zsh/site-functions/_youtube-dl

OPTIONS_DEFINE=		FFMPEG RTMPDUMP
OPTIONS_DEFAULT=	RTMPDUMP

RTMPDUMP_DESC=	Use rtmpdump to download rtmp video streams

FFMPEG_RUN_DEPENDS=	ffprobe:multimedia/ffmpeg
RTMPDUMP_RUN_DEPENDS=	rtmpdump:multimedia/rtmpdump

post-extract:
# remove tarball provided version, build our own
	@${RM} ${WRKSRC}/youtube-dl

.include <bsd.port.mk>
