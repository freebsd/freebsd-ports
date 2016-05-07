# Created by: Alex Deiter <Alex.Deiter@Gmail.COM>
# $FreeBSD$

PORTNAME=	appkonference
PORTVERSION=	2.7
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-performance Asterisk voice/video conferencing plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	asterisk:net/asterisk
RUN_DEPENDS=	asterisk:net/asterisk


USE_CSTD=	gnu89
USES=		compiler:features gmake
WRKSRC=		${WRKDIR}/${PORTNAME}/konference

PLIST_FILES=	lib/asterisk/modules/app_konference.so

ONLY_FOR_ARCHS=		amd64 arm i386 ia64
ONLY_FOR_ARCHS_REASON=	not yet ported to this architecture

OPTIONS_DEFINE=		OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

OPTIMIZED_CFLAGS_CFLAGS=	-O3 -ffast-math

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS} && ${CHOSEN_COMPILER_TYPE} == gcc
CFLAGS+=	-funroll-all-loops -fsingle-precision-constant
.endif

.include <bsd.port.post.mk>
