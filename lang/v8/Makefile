# Created by: siasia
# $FreeBSD$

PORTNAME=	v8
PORTVERSION=	3.18.5
CATEGORIES=	lang
MASTER_SITES=	LOCAL/vanilla

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Google\'s open source JavaScript engine

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo

CONFLICTS=	v8-3.24.*

USES=		gmake compiler tar:xz
USE_PYTHON=	2
USE_LDCONFIG=	yes
ALL_TARGET=	native
MAKE_ARGS=	library=shared
MAKE_ENV+=	CC.host=${CC} CXX.host=${CXX} LINK.host=${CXX} LINK.target=${CXX}

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
MAKE_ENV+=	LINK=clang++
CFLAGS+=	-Wno-unused-private-field
.if ${COMPILER_VERSION} >= 33
CFLAGS+=	-Wno-nested-anon-types -Wno-unused-function
.if ${COMPILER_VERSION} >= 34
CFLAGS+=	-Wno-unused-const-variable
.endif
.endif
.else
MAKE_ARGS+=	strictaliasing=off
USE_GCC=	any
.endif

ONLY_FOR_ARCHS=	i386 amd64

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/build/common.gypi ${WRKSRC}/tools/gyp/v8.gyp
	@${REINPLACE_CMD} -e '1 s|${SETENV} python|&2|' ${WRKSRC}/build/gyp/gyp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/native/d8 ${STAGEDIR}/${PREFIX}/bin/d8
	${INSTALL_LIB} -m 755 ${WRKSRC}/out/native/lib.target/libv8.so ${STAGEDIR}/${PREFIX}/lib/libv8.so.1
	${LN} -sf ${PREFIX}/lib/libv8.so.1 ${STAGEDIR}/${PREFIX}/lib/libv8.so
	${INSTALL_DATA} ${WRKSRC}/include/v8.h ${STAGEDIR}/${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/v8-debug.h ${STAGEDIR}/${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/v8-preparser.h ${STAGEDIR}/${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/v8-profiler.h ${STAGEDIR}/${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/v8-testing.h ${STAGEDIR}/${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/v8stdint.h ${STAGEDIR}/${PREFIX}/include

.include <bsd.port.post.mk>
