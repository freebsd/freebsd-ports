# Created by: Jin-Sih Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	node
PORTVERSION=	0.12.14
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES=	http://nodejs.org/dist/v${PORTVERSION}/
PKGNAMESUFFIX=	012

MAINTAINER=	bradleythughes@fastmail.fm
COMMENT=	V8 JavaScript for client and server
DEPRECATED=	Upstream has placed 0.12.x in maintenance mode, see https://github.com/nodejs/LTS#lts_schedule
EXPIRATION_DATE=	2017-04-01

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler execinfo gmake python:2
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	node-[0-9]* node-devel-[0-9]* node010-[0-9]* iojs-[0-9]* node4-[0-9]* node5-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
CONFIGURE_ARGS=	--prefix=${PREFIX_RELDEST} --without-npm --shared-zlib
PREFIX_RELDEST=	${PREFIX:S,^${DESTDIR},,}
REINPLACE_ARGS=	-i ''
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

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/deps/v8/tools/gyp/v8.gyp
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|${PYTHON_CMD}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|'python',|'${PYTHON_CMD}',|" \
		${WRKSRC}/deps/v8/build/shim_headers.gypi \
		${WRKSRC}/deps/v8/tools/gyp/v8.gyp \
		${WRKSRC}/deps/v8/src/d8.gyp

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/node

.include <bsd.port.post.mk>
