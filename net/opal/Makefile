# New ports collection makefile for:	openh323
# Date created:		Thu Feb 17 15:00:48 GMT 2000
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	opal
PORTVERSION=	2.2.11
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	VoIP abstraction library

OPTIONS=	FFMPEG	"Support H263 audio/video codec"	on \
		SPEEX	"Use speex installed by audio/speex"	on

LIB_DEPENDS=	pt_r:${PORTSDIR}/devel/pwlib

CONFLICTS=	opal-3.*

# In opal's Makefile the default make's target is optshared
ALL_TARGET=	-j`${SYSCTL} -n hw.ncpu` optshared
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_ARGS=	-j`${SYSCTL} -n hw.ncpu`

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -I${WRKSRC}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

# Be sure to compile position-independent objects for the shared libraries
CFLAGS+=	-fPIC

.if defined(WITHOUT_FFMPEG)
CONFIGURE_ARGS+=--disable-h263avcodec
.else
LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=--enable-h263avcodec=${LOCALBASE}/include/ffmpeg
.endif

.if defined(WITHOUT_SPEEX)
CONFIGURE_ARGS+=--enable-localspeex=no
.else
LIB_DEPENDS+=	speex:${PORTSDIR}/audio/speex
CONFIGURE_ARGS+=--enable-localspeex=yes
.endif

.include <bsd.port.post.mk>
