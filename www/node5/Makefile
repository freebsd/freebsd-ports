# $FreeBSD$

PORTNAME=	node
PORTVERSION=	5.11.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES=	http://nodejs.org/dist/v${PORTVERSION}/
PKGNAMESUFFIX=	5

MAINTAINER=	bradleythughes@fastmail.fm
COMMENT=	V8 JavaScript for client and server (5.x)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream provides limited support after the release of v6.0.0, see https://nodejs.org/en/blog/release/v6.0.0/#what-about-node-js-v5
EXPIRATION_DATE=	2016-07-01

OPTIONS_DEFINE=	BUNDLED_SSL DOCS
OPTIONS_DEFAULT=BUNDLED_SSL
OPTIONS_SUB=	yes

BUNDLED_SSL_DESC=	Use node's bundled OpenSSL implementation
BUNDLED_SSL_USE_OFF=	OPENSSL=yes
BUNDLED_SSL_VARS_OFF=	WITH_OPENSSL_PORT=yes

USES=		compiler execinfo gmake python:2
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	node-[0-9]* node-devel-[0-9]* node010-[0-9]* node012-[0-9]* iojs-[0-9]* node4-[0-9]*

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
USE_GCC=	yes
.endif

.if empty(PORT_OPTIONS:MBUNDLED_SSL)
CONFIGURE_ARGS+=	--shared-openssl \
			--shared-openssl-includes=${OPENSSLINC} \
			--shared-openssl-libpath=${OPENSSLLIB}
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
		${WRKSRC}/deps/v8/src/d8.gyp \
		${WRKSRC}/node.gyp

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/node

.include <bsd.port.post.mk>
