# $FreeBSD$

PORTNAME=	youtube_dl
PORTVERSION=	2012.09.27
CATEGORIES=	www
MASTER_SITES=	GH \
		CRITICAL

EXTRACT_SUFX=	# empty

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	A program for downloading videos from YouTube.com

LICENSE=	GPLv2

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip

USE_PYTHON_RUN=	2.6-2.7
ALL_TARGET=	compile
USE_GITHUB=	yes
GH_ACCOUNT=	rg3
GH_PROJECT=	youtube-dl
GH_COMMIT=	b5de8af

PLIST_FILES=	bin/youtube-dl

OPTIONS=	RTMPDUMP "Use RTMPDUMP to download rtmp video streams" on \
		FFMPEG   "Use ffmpeg (required for audio conversion)"  off

.include <bsd.port.options.mk>

.if defined(WITH_RTMPDUMP)
RUN_DEPENDS+=	rtmpdump:${PORTSDIR}/multimedia/rtmpdump
.endif

.if defined(WITH_FFMPEG)
# allow either multimedia/ffmpeg or multimedia/ffmpeg-devel
. if exists(${LOCALBASE}/include/libavcodec/vda.h)
RUN_DEPENDS+=	ffprobe:${PORTSDIR}/multimedia/ffmpeg-devel
. else
RUN_DEPENDS+=	ffprobe:${PORTSDIR}/multimedia/ffmpeg
. endif
.endif

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/youtube-dl ${PREFIX}/bin/youtube-dl

.if defined(WITH_FFMPEG)
post-install:
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
