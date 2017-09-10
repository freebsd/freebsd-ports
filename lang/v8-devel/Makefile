# Created by: siasia
# $FreeBSD$

PORTNAME=	v8
PORTVERSION=	3.27.7
PORTREVISION=	10
CATEGORIES=	lang
MASTER_SITES=	LOCAL/vanilla
PKGNAMESUFFIX=	-devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open source JavaScript engine by Google

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libicui18n.so:devel/icu

CONFLICTS_INSTALL=	v8-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64

ALL_TARGET=	native
MAKE_ARGS=	library=shared use_system_icu=on
MAKE_ENV=	CC.host=${CC} CXX.host=${CXX} LINK.host=${CXX} LINK.target=${CXX}
USE_LDCONFIG=	yes
USES=		compiler cpe execinfo gmake python:2 shebangfix tar:xz

CPE_VENDOR=	google

SHEBANG_FILES=	build/gyp/gyp
bash_CMD=	${SH}

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CXXFLAGS+=	-Wno-nested-anon-types -Wno-unused-function -Wno-unused-private-field -Wno-unused-variable
MAKE_ARGS+=	clang=on
MAKE_ENV+=	LINK=clang++ AR=/usr/bin/ar
.if ${COMPILER_VERSION} >= 34
CXXFLAGS+=	-Wno-unused-const-variable
.if ${COMPILER_VERSION} >= 35
CXXFLAGS+=	-Wno-tautological-undefined-compare
.endif
.endif
.else
MAKE_ARGS+=	strictaliasing=off
USE_GCC=	any
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|test/cctest/cctest.gyp||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/test\/cctest\/cctest.gyp/d' ${WRKSRC}/build/all.gyp
	@${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|' ${WRKSRC}/build/shim_headers.gypi ${WRKSRC}/build/gyp/gyp ${WRKSRC}/tools/gyp/v8.gyp
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/build/toolchain.gypi ${WRKSRC}/tools/gyp/v8.gyp
	@${REINPLACE_CMD} -e 's, | MAP_NORESERVE,,' ${WRKSRC}/src/platform-freebsd.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/native/d8 ${STAGEDIR}${PREFIX}/bin/d8
	cd ${WRKSRC}/include/ && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_LIB} ${WRKSRC}/out/native/lib.target/libv8.so ${STAGEDIR}${PREFIX}/lib/libv8.so.1
	${LN} -fs ${PREFIX}/lib/libv8.so.1 ${STAGEDIR}${PREFIX}/lib/libv8.so

.include <bsd.port.post.mk>
