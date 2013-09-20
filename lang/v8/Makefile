# Created by: siasia
# $FreeBSD$

PORTNAME=	v8
PORTVERSION=	3.18.5
CATEGORIES=	lang
MASTER_SITES=	LOCAL/vanilla

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Google\'s open source JavaScript engine

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo

USE_GMAKE=	yes
USE_XZ=		yes
USE_PYTHON=	2.6+
USE_LDCONFIG=	yes
ALL_TARGET=	native
MAKE_ARGS=	library=shared

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${CC:T:Mclang} == "clang" || ${CXX:T:Mclang++} == "clang++" || ${OSVERSION} >= 1000024
_CLANG!=	clang --version | ${HEAD} -1 | ${SED} -e 's/.*clang version \([0-9]\)\.\([0-9]\).*/\1\2/'
MAKE_ENV+=	LINK=clang++
CFLAGS+=	-Wno-unused-private-field
.if ${_CLANG} >= 33
CFLAGS+=	-Wno-nested-anon-types -Wno-unused-function
.endif
.else
MAKE_ARGS+=	strictaliasing=off
USE_GCC=	any
.endif

ONLY_FOR_ARCHS=	i386 amd64

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/build/common.gypi ${WRKSRC}/tools/gyp/v8.gyp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/native/d8 ${PREFIX}/bin/d8
	${INSTALL_LIB} -m 755 ${WRKSRC}/out/native/lib.target/libv8.so ${PREFIX}/lib/libv8.so.1
	${LN} -sf ${PREFIX}/lib/libv8.so.1 ${PREFIX}/lib/libv8.so
	${INSTALL_DATA} ${WRKSRC}/include/v8.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8-debug.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8-preparser.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8-profiler.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8-testing.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8stdint.h ${PREFIX}/include/

.include <bsd.port.post.mk>
