PORTNAME=	youtube_dl
PORTVERSION=	2023.03.14
CATEGORIES=	www

# Implicit approval to commit trivial version updates.
MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Program for downloading videos from various services
WWW=		https://yt-dl.org/

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pandoc:textproc/hs-pandoc

USES=		gmake python

USE_GITHUB=	yes
GH_ACCOUNT=	ytdl-org
GH_PROJECT=	youtube-dl
GH_TAGNAME=	6fece0a

MAKE_ARGS=	PYTHON=${PYTHON_CMD}
ALL_TARGET=	youtube-dl
NO_ARCH=	yes

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

.include <bsd.port.mk>
