# Created by: siasia
# $FreeBSD$

PORTNAME=	v8
PORTVERSION=	3.27.7
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	LOCAL/vanilla
PKGNAMESUFFIX=	-devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open source JavaScript engine by Google

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/bin/python:${PORTSDIR}/lang/python
LIB_DEPENDS=	libicui18n.so:${PORTSDIR}/devel/icu

CONFLICTS_INSTALL=	v8-[0-9]*

ALL_TARGET=	native
MAKE_ARGS=	library=shared use_system_icu=on
MAKE_ENV=	CC.host=${CC} CXX.host=${CXX} LINK.host=${CXX} LINK.target=${CXX}
USE_LDCONFIG=	yes
USE_PYTHON=	2
USES=		compiler execinfo gmake shebangfix tar:xz

SHEBANG_FILES=	${WRKSRC}/build/gyp/gyp
bash_CMD=	${SH}

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
MAKE_ENV+=	LINK=clang++ AR=/usr/bin/ar
MAKE_ARGS+=	clang=on
CFLAGS+=	-Wno-unused-private-field -Wno-unused-variable
.if ${COMPILER_VERSION} >= 33
CFLAGS+=	-Wno-nested-anon-types -Wno-unused-function
.endif
.if ${COMPILER_VERSION} >= 34
CFLAGS+=	-Wno-unused-const-variable
.endif
.else
MAKE_ARGS+=	strictaliasing=off
USE_GCC=	any
.endif

ONLY_FOR_ARCHS=	i386 amd64

post-patch:
	@${REINPLACE_CMD} -e '/^exec python / s| python | ${PYTHON_CMD} |' ${WRKSRC}/build/gyp/gyp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/native/d8 ${STAGEDIR}${PREFIX}/bin/d8
	cd ${WRKSRC}/include/ && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_LIB} ${WRKSRC}/out/native/lib.target/libv8.so ${STAGEDIR}${PREFIX}/lib/libv8.so.1
	${LN} -fs ${PREFIX}/lib/libv8.so.1 ${STAGEDIR}${PREFIX}/lib/libv8.so

.include <bsd.port.post.mk>
