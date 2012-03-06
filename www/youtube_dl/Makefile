# New ports collection makefile for:	youtube_dl
# Date created:		2006-08-12
# Whom:			Pankov Pavel <pankov_p@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	youtube_dl
PORTVERSION=	2012.02.27
CATEGORIES=	www
MASTER_SITES=	https://raw.github.com/rg3/youtube-dl/${PORTVERSION}/ \
		CRITICAL
DISTNAME=	youtube-dl
EXTRACT_SUFX=	# empty
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	A program for downloading videos from YouTube.com

LICENSE=	GPLv2

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PYTHON_RUN=	2.5-2.7

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

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}/youtube-dl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/youtube-dl ${PREFIX}/bin/youtube-dl

.if defined(WITH_FFMPEG)
post-install:
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
