PORTNAME=	yt-dlp
DISTVERSION=	2021.05.11
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command-line program for downloading videos from various platforms

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake python shebangfix
SHEBANG_GLOB=	devscripts/*.py

USE_GITHUB=	yes

MAKE_ARGS=	PYTHON=${PYTHON_CMD}

NO_ARCH=	yes

OPTIONS_DEFINE=		FFMPEG MUTAGEN RTMPDUMP SYMLINK
OPTIONS_DEFAULT=	FFMPEG RTMPDUMP
OPTIONS_SUB=	yes

MUTAGEN_DESC=	Thumbnail support via Mutagen
RTMPDUMP_DESC=	Use rtmpdump to download rtmp video streams
SYMLINK_DESC=	Install youtube-dl symbolic link for executable

FFMPEG_RUN_DEPENDS=	ffprobe:multimedia/ffmpeg
MUTAGEN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>0:audio/py-mutagen@${PY_FLAVOR}
RTMPDUMP_RUN_DEPENDS=	rtmpdump:multimedia/rtmpdump
SYMLINK_CONFLICTS=	youtube_dl

post-install-SYMLINK-on:
	@${RLN} ${STAGEDIR}${PREFIX}/bin/yt-dlp ${STAGEDIR}${PREFIX}/bin/youtube-dl

.include <bsd.port.mk>
