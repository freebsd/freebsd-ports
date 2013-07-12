# $FreeBSD$

PORTNAME=	youtube_dl
PORTVERSION=	2013.07.12
CATEGORIES=	www
MASTER_SITES=	http://youtube-dl.org/downloads/${PORTVERSION}/ \
		http://ftp.de.netbsd.org/pub/unix/Linux/MIRROR.gentoo/distfiles/
DISTNAME=	youtube-dl-${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	A program for downloading videos from YouTube.com

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

PLIST_FILES=	bin/youtube-dl
MAN1=		youtube-dl.1

WRKSRC=		${WRKDIR}/youtube-dl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRTMPDUMP}
RUN_DEPENDS+=	rtmpdump:${PORTSDIR}/multimedia/rtmpdump
.endif

.if ${PORT_OPTIONS:MBASH}
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

post-extract:
	@# remove tarball provided version, build our own
	@${RM} -f ${WRKSRC}/youtube-dl

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
