# Created by: Roger Hardiman <roger@freebsd.org>
# $FreeBSD$

PORTNAME=	opal
PORTVERSION=	2.2.11
PORTREVISION=	7
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VoIP abstraction library

OPTIONS_DEFINE=	FFMPEG SPEEX
OPTIONS_DEFAULT=FFMPEG SPEEX
FFMPEG_DESC=	H263 audio/video codec support
SPEEX_DESC=	Use audio/speex instead of bundled version

LIB_DEPENDS=	pt_r:${PORTSDIR}/devel/pwlib

CONFLICTS=	opal-3.*

# In opal's Makefile the default make's target is optshared
ALL_TARGET=	-j`${SYSCTL} -n hw.ncpu` optshared
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_ARGS=	-j`${SYSCTL} -n hw.ncpu`

CPPFLAGS+=	-I${LOCALBASE}/include -I${WRKSRC}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

# Be sure to compile position-independent objects for the shared libraries
CFLAGS+=	-fPIC

.if ${OSVERSION} >= 900000
BROKEN=		does not compile on 9.X
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=--enable-h263avcodec=${LOCALBASE}/include/ffmpeg
.else
CONFIGURE_ARGS+=--disable-h263avcodec
.endif

.if ${PORT_OPTIONS:MSPEEX}
LIB_DEPENDS+=	speex:${PORTSDIR}/audio/speex
CONFIGURE_ARGS+=--enable-localspeex=yes
.else
CONFIGURE_ARGS+=--enable-localspeex=no
.endif


.include <bsd.port.post.mk>
