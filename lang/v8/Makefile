# New ports collection makefile for:   v8
# Date created:        12 November 2010
# Whom:                siasia
#
# $FreeBSD$
#

PORTNAME=	v8
PORTVERSION=	3.12.9
PORTREVISION=	0
CATEGORIES=	lang
MASTER_SITES=	LOCAL/vanilla

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Google\'s open source JavaScript engine

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

USE_GMAKE=	yes
USE_PYTHON=	2.7+
USE_XZ=		yes
USE_LDCONFIG=	yes
ALL_TARGET=	native
OPTIONS=	SNAPSHOT "Enable snapshots" Off

.include <bsd.port.options.mk>

MAKE_ARGS=	library=shared

.if ${CC} == "clang" && ${CXX} == "clang++"
MAKE_ENV+=	LINK=clang++
.else
MAKE_ARGS+=	strictaliasing=off
.endif

.if defined(WITHOUT_SNAPSHOT)
MAKE_ARGS+=	snapshot=off
.else
MAKE_ARGS+=	snapshot=on
.endif

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_LIB} -m 755 ${WRKSRC}/out/native/lib.target/libv8.so ${PREFIX}/lib/libv8.so.1
	${LN} -sf ${PREFIX}/lib/libv8.so.1 ${PREFIX}/lib/libv8.so
	${INSTALL_DATA} ${WRKSRC}/include/v8.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8-debug.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8-preparser.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8-profiler.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8-testing.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8stdint.h ${PREFIX}/include/

.include <bsd.port.post.mk>
