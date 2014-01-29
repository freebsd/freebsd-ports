# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clive
PORTVERSION=	1.0.2
PORTREVISION=	2
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
USE_PYTHON=	2

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	${PORTNAME}.1 ${PORTNAME}-passwd.1
.else
CONFIGURE_ARGS=	--with-doc=no
.endif

OPTIONS_DEFINE=	FEEDPARSER FFMPEG MPLAYER NEWT PYCRYPTO SQLITE3 VLC XCLIP XINE
FEEDPARSER_DESC=	Feed parsing support
FFMPEG_DESC=	ffmpeg for re-encoding
MPLAYER_DESC=	mplayer as video player
NEWT_DESC=	simple GUI support
PYCRYPTO_DESC=	Encrypted login password support
VLC_DESC=	vlc as video player
XCLIP_DESC=	xclip (read URLs from clipboard)
XINE_DESC=	xine as video player

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFEEDPARSER}
RUN_DEPENDS+=	${PKGNAMEPREFIX}feedparser>=4.1_2:${PORTSDIR}/textproc/py-feedparser
.endif

.if ${PORT_OPTIONS:MFFMPEG}
RUN_DEPENDS+=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg
.endif

.if ${PORT_OPTIONS:MMPLAYER}
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if ${PORT_OPTIONS:MNEWT}
RUN_DEPENDS+=	newt${PYTHON_PKGNAMESUFFIX}>=0.51.0_4:${PORTSDIR}/devel/newt
.endif

.if ${PORT_OPTIONS:MPYCRYPTO}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pycrypto>=2.0.1_1:${PORTSDIR}/security/py-pycrypto
.endif

.if ${PORT_OPTIONS:MSQLITE3}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlite3>=2.5.2_1:${PORTSDIR}/databases/py-sqlite3
.endif

.if ${PORT_OPTIONS:MVLC}
RUN_DEPENDS+=	vlc:${PORTSDIR}/multimedia/vlc
.endif

.if ${PORT_OPTIONS:MXCLIP}
RUN_DEPENDS+=	xclip:${PORTSDIR}/x11/xclip
.endif

.if ${PORT_OPTIONS:MXINE}
RUN_DEPENDS+=	xine:${PORTSDIR}/multimedia/xine
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin/env python|${PYTHON_CMD}|g' \
	${WRKSRC}/src/scripts/clive ${WRKSRC}/src/scripts/clive-passwd

.include <bsd.port.mk>
