# Created by: Alexander Panyushkin <vsityz@gmail.com>
# $FreeBSD$

PORTNAME=	hans
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	SF/hanstunnel/source

MAINTAINER=	vsityz@gmail.com
COMMENT=	Hans makes it possible to tunnel IPv4 through ICMP

LICENSE=	GPLv3

OPTIONS_DEFINE=	CLANG

CLANG_DESC=	Build with Clang instead of GCC

OPTIONS_DEFAULT=	CLANG

PLIST_FILES=	bin/hans

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLANG}
.if ${OSVERSION} >= 900033 && exists(/usr/bin/clang)
CC=		clang
CXX=		clang++
.else
BUILD_DEPENDS+=	clang33:${PORTSDIR}/lang/clang33
CC=		clang33
CXX=		clang++33
.endif
.else
USE_GCC=4.2+
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hans ${STAGEDIR}${LOCALBASE}/bin

.include <bsd.port.mk>
