# New ports collection makefile for:	openh323
# Date created:		Thu Feb 17 15:00:48 GMT 2000
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	opal
PORTVERSION=	2.2.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.voxgratia.org/releases/
DISTNAME=	${PORTNAME}-v${PORTVERSION:S/./_/g}-src-
EXTRACT_SUFX=	tar.gz

MAINTAINER=	jbq@caraldi.com
COMMENT=	VoIP abstraction library

LIB_DEPENDS=	pt_r:${PORTSDIR}/devel/pwlib

WRKSRC=		${WRKDIR}/${PORTNAME}_v${PORTVERSION:S/./_/g}

# In opal's Makefile the default make's target is optshared
ALL_TARGET=	optshared
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:259
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -I${WRKSRC}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

# Be sure to compile position-independent objects for the shared libraries
CFLAGS+=	-fPIC

.ifdef (WITH_FFMPEG)
LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=--enable-h263avcodec=${LOCALBASE}/include/ffmpeg
.endif

.ifdef (WITH_SPEEX)
LIB_DEPENDS+=	speex:${PORTSDIR}/audio/speex
BUILD_DEPENDS+=	${LOCALBASE}/include/speex/speex_echo.h:${PORTSDIR}/audio/speex
CONFIGURE_ARGS+=--enable-localspeex=no
.else
CONFIGURE_ARGS+=--enable-localspeex=yes
.endif

.include <bsd.port.post.mk>
