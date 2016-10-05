# Created by: Alex Deiter <Alex.Deiter@Gmail.COM>
# $FreeBSD$

PORTNAME=	appkonference
PORTVERSION=	2.7
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-performance Asterisk voice/video conferencing plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_CSTD=	gnu89
USES=		compiler:features gmake
WRKSRC=		${WRKDIR}/${PORTNAME}/konference

PLIST_FILES=	lib/asterisk/modules/app_konference.so

ONLY_FOR_ARCHS=		amd64 armv6 i386 powerpc
ONLY_FOR_ARCHS_REASON=	not yet ported to this architecture

OPTIONS_DEFINE=		OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	ASTERISK13 OPTIMIZED_CFLAGS
OPTIONS_SINGLE=		ASTERISK
OPTIONS_SINGLE_ASTERISK=ASTERISK11 ASTERISK13

ASTERISK_DESC=		Asterisk version
ASTERISK11_DESC=	Asterisk 11.x support
ASTERISK13_DESC=	Asterisk 13.x support

ASTERISK11_BUILD_DEPENDS=	asterisk11>0:net/asterisk11
ASTERISK11_RUN_DEPENDS=	asterisk11>0:net/asterisk11
ASTERISK11_MAKE_ARGS=	ASTERISK_SRC_VERSION=1100

ASTERISK13_BUILD_DEPENDS=	asterisk13>0:net/asterisk13
ASTERISK13_RUN_DEPENDS=	asterisk13>0:net/asterisk13
ASTERISK13_MAKE_ARGS=	ASTERISK_SRC_VERSION=1300

OPTIMIZED_CFLAGS_CFLAGS=	-O3 -ffast-math

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS} && ${CHOSEN_COMPILER_TYPE} == gcc
CFLAGS+=	-funroll-all-loops -fsingle-precision-constant
.endif

.if ${CHOSEN_COMPILER_TYPE} == clang
CFLAGS+=        -fblocks
.endif

.include <bsd.port.post.mk>
