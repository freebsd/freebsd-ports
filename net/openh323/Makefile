# New ports collection makefile for:	openh323
# Date created:		Thu Feb 17 15:00:48 GMT 2000
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	openh323
PORTVERSION=	1.19.0.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-v${PORTVERSION:S/./_/g}-src
EXTRACT_SUFX=	-tar.gz
DIST_SUBDIR=	openh323

MAINTAINER=	steve@energistic.com
COMMENT=	A H323 Video Conferencing library

LIB_DEPENDS=	pt_r.1:${PORTSDIR}/devel/pwlib

WRKSRC=		${WRKDIR}/${PORTNAME}_v${PORTVERSION:S/./_/g}

USE_BISON=	build
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

ALL_TARGET=	optshared
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -I${WRKSRC}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" BUILDTIME="YES"
MAKE_ENV=	BUILDTIME="YES"

.include <bsd.port.pre.mk>

.ifdef (WITH_FFMPEG)
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=	--enable-rfc2190avcodec=${LOCALBASE}/include/ffmpeg
.endif

.ifdef (WITH_SPEEX)
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
CONFIGURE_ARGS+=	--enable-localspeex=no
.else
CONFIGURE_ARGS+=	--enable-localspeex=yes
.endif

.if (${ARCH} == "amd64") || (${ARCH} == "ia64") || (${ARCH} == "sparc64")
CFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
