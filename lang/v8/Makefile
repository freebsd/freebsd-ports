# Created by: siasia
# $FreeBSD$

PORTNAME=	v8
PORTVERSION=	3.18.5
CATEGORIES=	lang
MASTER_SITES=	LOCAL/vanilla

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open source JavaScript engine by Google

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/bin/python:${PORTSDIR}/lang/python

CONFLICTS_INSTALL=	v8-devel-[0-9]*

PORTSCOUT=	limit:^3.18.*

ALL_TARGET=	native
MAKE_ARGS=	library=shared
MAKE_ENV=	CC.host=${CC} CXX.host=${CXX} LINK.host=${CXX} LINK.target=${CXX}
USE_LDCONFIG=	yes
USES=		compiler cpe execinfo gmake python:2 tar:xz

CPE_VENDOR=	google

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-unused-private-field
MAKE_ENV+=	LINK=clang++
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
	${INSTALL_PROGRAM} ${WRKSRC}/out/native/d8 ${STAGEDIR}${PREFIX}/bin/d8
	cd ${WRKSRC}/include/ && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_LIB} ${WRKSRC}/out/native/lib.target/libv8.so ${STAGEDIR}${PREFIX}/lib/libv8.so.1
	${LN} -fs ${PREFIX}/lib/libv8.so.1 ${STAGEDIR}${PREFIX}/lib/libv8.so

.include <bsd.port.post.mk>
