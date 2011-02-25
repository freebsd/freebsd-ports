# New ports collection makefile for:	clive
# Date created:		2007-02-11
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clive
PORTVERSION=	1.0.2
PORTREVISION=	1
#PORTEPOCH=	0
CATEGORIES=	multimedia
MASTER_SITES=	http://download.gna.org/clive/1.0.x/ \
		SF/${PORTNAME}/${PORTNAME}-1.x/${PORTVERSION}

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Video extraction utility for YouTube, GoogleVideo, and others

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urlgrabber>=3.1.0_1:${PORTSDIR}/www/py-urlgrabber

# deskutils/ljclive (same executable/manpage/distfile name)
CONFLICTS=	clive-[0-9]*

GNU_CONFIGURE=	yes

USE_BZIP2=	yes
# not compatible with 3.0
USE_PYTHON=	2.5-2.7

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	${PORTNAME}.1 ${PORTNAME}-passwd.1
.else
CONFIGURE_ARGS=	--with-doc=no
.endif

OPTIONS=	FEEDPARSER	"Enable feed parsing" off \
		FFMPEG	"Install ffmpeg for re-encoding" off \
		MPLAYER	"Install mplayer as video player" off \
		NEWT	"Install devel/newt (support for a simple GUI)" off \
		PYCRYPTO	"Install pycrypto to encrypt login password" off \
		SQLITE3 "Install sqlite3 for caching visited URLs" off \
		VLC	"Install vlc as video player" off \
		XCLIP	"Install xclip (read URLs from clipboard)" off \
		XINE	"Install xine as video player" off
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.pre.mk>

.if defined(WITH_FEEDPARSER)
RUN_DEPENDS+=	${PKGNAMEPREFIX}feedparser>=4.1_2:${PORTSDIR}/textproc/py-feedparser
.endif

.if defined(WITH_FFMPEG)
RUN_DEPENDS+=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg
.endif

.if defined(WITH_MPLAYER)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if defined(WITH_NEWT)
RUN_DEPENDS+=	newt${PYTHON_PKGNAMESUFFIX}>=0.51.0_4:${PORTSDIR}/devel/newt
.endif

.if defined(WITH_PYCRYPTO)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pycrypto>=2.0.1_1:${PORTSDIR}/security/py-pycrypto
.endif

.if defined(WITH_SQLITE3)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlite3>=2.5.2_1:${PORTSDIR}/databases/py-sqlite3
.endif

.if defined(WITH_VLC)
RUN_DEPENDS+=	vlc:${PORTSDIR}/multimedia/vlc
.endif

.if defined(WITH_XCLIP)
RUN_DEPENDS+=	xclip:${PORTSDIR}/x11/xclip
.endif

.if defined(WITH_XINE)
RUN_DEPENDS+=	xine:${PORTSDIR}/multimedia/xine
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin/env python|${PYTHON_CMD}|g' \
	${WRKSRC}/src/scripts/clive ${WRKSRC}/src/scripts/clive-passwd

.include <bsd.port.post.mk>
