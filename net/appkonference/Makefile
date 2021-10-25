# Created by: Alex Deiter <Alex.Deiter@Gmail.COM>

PORTNAME=	appkonference
PORTVERSION=	2.8
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-performance Asterisk voice/video conferencing plugin

DEPRECATED=	Outdated, depends on unsupported version of net/asterisk
EXPIRATION_DATE=2021-12-31

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		does not build with net/asterisk1{6,8}

ONLY_FOR_ARCHS=		amd64 armv6 armv7 i386 powerpc powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	not yet ported to this architecture

USES=		compiler:features gmake
USE_CSTD=	gnu89
WRKSRC=		${WRKDIR}/${PORTNAME}/konference
MAKE_ARGS=	ASTERISK_SRC_VERSION=1300
# Fix build with clang11
CFLAGS+=	-fcommon

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
