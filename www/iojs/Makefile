# Created by: Jin-Sih Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	iojs
PORTVERSION=	2.3.3
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	linpct@gmail.com
COMMENT=	V8 JavaScript for client and server

LICENSE=	MIT

USES=		execinfo gmake python:2
USE_GITHUB=	yes
GH_ACCOUNT=	nodejs
GH_PROJECT=	io.js
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFLICTS=	node-0.[02-9][0-9]* node-devel-0.[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
CONFIGURE_ARGS=	--prefix=${PREFIX_RELDEST} --without-npm --shared-zlib
PREFIX_RELDEST=	${PREFIX:S,^${DESTDIR},,}
REINPLACE_ARGS=	-i ''
MAKE_ENV+=	CC.host=${CC} CXX.host=${CXX} LINK.host=${CXX} LINK.target=${CXX}

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 900033 && exists(/usr/bin/clang)
CC=		clang
CXX=		clang++
GYP_DEFINES+=	clang=1
.else
USE_GCC?=	yes
GYP_DEFINES+=	gcc_version=${CXX:S/g++//}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/deps/v8/tools/gyp/v8.gyp
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|${PYTHON_CMD}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|python -c|${PYTHON_CMD} -c|" \
		${WRKSRC}/deps/v8/build/toolchain.gypi
	@${REINPLACE_CMD} -e "s|'python',|'${PYTHON_CMD}',|" \
		${WRKSRC}/tools/icu/icu-generic.gyp \
		${WRKSRC}/deps/v8/build/shim_headers.gypi \
		${WRKSRC}/deps/v8/tools/gyp/v8.gyp \
		${WRKSRC}/deps/v8/src/d8.gyp

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/iojs

.include <bsd.port.mk>
