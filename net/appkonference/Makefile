# Created by: Alex Deiter <Alex.Deiter@Gmail.COM>
# $FreeBSD$

PORTNAME=	appkonference
PORTVERSION=	2.7
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-performance Asterisk voice/video conferencing plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		amd64 armv6 armv7 i386 powerpc
ONLY_FOR_ARCHS_REASON=	not yet ported to this architecture

BUILD_DEPENDS=	asterisk:net/asterisk13
RUN_DEPENDS=	asterisk:net/asterisk13

USES=		compiler:features gmake
USE_CSTD=	gnu89
WRKSRC=		${WRKDIR}/${PORTNAME}/konference
MAKE_ARGS=	ASTERISK_SRC_VERSION=1300

PLIST_FILES=	lib/asterisk/modules/app_konference.so

OPTIONS_DEFINE=		OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

OPTIMIZED_CFLAGS_CFLAGS=	-O3 -ffast-math

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS} && ${CHOSEN_COMPILER_TYPE} == gcc
CFLAGS+=	-funroll-all-loops -fsingle-precision-constant
.endif

.if ${CHOSEN_COMPILER_TYPE} == clang
CFLAGS+=        -fblocks
.endif

.include <bsd.port.post.mk>
