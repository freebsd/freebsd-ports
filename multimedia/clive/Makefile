# New ports collection makefile for:	clive
# Date created:		2007-02-11
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clive
PORTVERSION=	0.4.19
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	multimedia
MASTER_SITES=	http://download.gna.org/clive/0.4/src/ \
		SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Video extraction utility for YouTube and Google Video

# deskutils/ljclive (same executable/manpage/distfile name)
CONFLICTS=	clive-[0-9]*

GNU_CONFIGURE=	yes

USE_BZIP2=	yes
USE_PYTHON=	yes

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	${PORTNAME}.1
.else
CONFIGURE_ARGS=	--with-doc=no
.endif

OPTIONS=	FFMPEG	"Install ffmpeg for re-encoding" off \
		MPLAYER	"Install mplayer as video player" off \
		NEWT	"Use devel/newt instead of bundled module" off \
		SQLITE3 "Install sqlite3 for caching visited URLs" off \
		VLC	"Install vlc as video player" off \
		XCLIP	"Install xclip (read URLs from clipboard)" off
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.pre.mk>

.if defined(WITH_FFMPEG)
RUN_DEPENDS+=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg
.endif

.if defined(WITH_MPLAYER)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if defined(WITH_NEWT)
PLIST_SUB+=	OPTNEWT="@comment "
CONFIGURE_ARGS+=	--with-installed-newt=yes
LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang
RUN_DEPENDS+=	newt${PYTHON_PKGNAMESUFFIX}>=0.51.0_4:${PORTSDIR}/devel/newt
.else
PLIST_SUB+=	OPTNEWT=""
LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${PYTHON_INCLUDEDIR} $${CPPFLAGS}" LDFLAGS="-L${LOCALBASE}/lib $${LDFLAGS} -L${PYTHON_LIBDIR}" SLANG_LIBS="-lncurses -lslang"
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

.include <bsd.port.post.mk>
