# $FreeBSD$

PORTNAME=	youtube_dl
PORTVERSION=	2013.09.24.2
PORTREVISION=	1
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

PLIST_FILES=	bin/youtube-dl \
		man/man1/youtube-dl.1.gz

WRKSRC=		${WRKDIR}/youtube-dl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRTMPDUMP}
RUN_DEPENDS+=	rtmpdump:${PORTSDIR}/multimedia/rtmpdump
.endif

.if ${PORT_OPTIONS:MBASH}
PLIST_FILES+=	etc/bash_completion.d/youtube-dl.sh
.endif

.if ${PORT_OPTIONS:MFFMPEG}
RUN_DEPENDS+=	ffprobe:${PORTSDIR}/multimedia/ffmpeg
.endif

post-extract:
	@# remove tarball provided version, build our own
	@${RM} -f ${WRKSRC}/youtube-dl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/youtube-dl ${STAGEDIR}${PREFIX}/bin/youtube-dl
	@${INSTALL_DATA} ${WRKSRC}/youtube-dl.1 ${STAGEDIR}${PREFIX}/man/man1
.if ${PORT_OPTIONS:MBASH}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/youtube-dl.bash-completion \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/youtube-dl.sh
.endif

.if ${PORT_OPTIONS:MFFMPEG}
post-install:
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
