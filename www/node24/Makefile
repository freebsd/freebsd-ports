PORTNAME=	node
PORTVERSION=	${NODEJS_PORTVERSION}
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	https://nodejs.org/dist/v${PORTVERSION}/
PKGNAMESUFFIX=	${PORTVERSION:R:R}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	V8 JavaScript for client and server
WWW=		https://nodejs.org/ \
		https://github.com/nodejs/node

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_SSL=	libressl libressl-devel
BROKEN_SSL_REASON=	Node.js ${PORTVERSION:R:R}.x requires OpenSSL or the BUNDLED_SSL option enabled
ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc64 powerpc64le

BUILD_DEPENDS=	objdump:devel/binutils
LIB_DEPENDS=	libada.so:devel/libada \
		libbrotlidec.so:archivers/brotli \
		libcares.so:dns/c-ares \
		libgtest.so:devel/googletest \
		libhdr_histogram.so:graphics/hdr_histogram \
		libicui18n.so:devel/icu \
		libllhttp.so:www/llhttp \
		libnbytes.so:www/nbytes \
		libnghttp2.so:www/libnghttp2 \
		libnghttp3.so:www/libnghttp3 \
		libngtcp2.so:net/libngtcp2 \
		libsimdjson.so:devel/simdjson \
		libsqlite3.so:databases/sqlite3 \
		libuv.so:devel/libuv \
		libuvwasi.so:devel/uvwasi \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	corepack>=0:www/corepack

USES=		compiler:c++20-lang gmake localbase pkgconfig python:build shebangfix tar:xz

# merve stays bundled: devel/merve links the system libsimdutf, while node
# bundles and exports its own simdutf. rtld binds libsimdutf's internal calls
# to node's copy, the dispatch tables disagree, and CJS export lexing jumps
# to garbage (SIGBUS). Revisit together with --shared-simdutf.
CONFIGURE_ARGS=	--prefix=${PREFIX:S|^${DESTDIR}||} \
		--shared-ada \
		--shared-brotli \
		--shared-cares \
		--shared-gtest \
		--shared-hdr-histogram \
		--shared-http-parser \
		--shared-libuv \
		--shared-nbytes \
		--shared-nghttp2 \
		--shared-nghttp3 \
		--shared-ngtcp2 \
		--shared-simdjson \
		--shared-sqlite \
		--shared-uvwasi \
		--shared-uvwasi-includes=${LOCALBASE}/include \
		--shared-zlib \
		--shared-zstd \
		--with-intl=system-icu \
		--without-corepack \
		--without-npm
HAS_CONFIGURE=	yes
MAKE_ENV=	CC.host="${CCACHE_BIN} ${CC}" \
		CFLAGS.host="${CFLAGS}" \
		CXX.host="${CCACHE_BIN} ${CXX}" \
		CXXFLAGS.host="${CXXFLAGS}" \
		LDFLAGS.host="${LDFLAGS}" \
		LINK.host="${CXX}"
REINPLACE_ARGS=	-i ''

CONFLICTS_INSTALL=	node[0-9][0-9]

SHEBANG_FILES=	deps/v8/third_party/inspector_protocol/*.py \
		deps/v8/tools/*.py \
		tools/*.py \
		tools/inspector_protocol/*.py

OPTIONS_DEFINE=	BUNDLED_SSL DOCS JIT
OPTIONS_DEFAULT=JIT
OPTIONS_SUB=	yes
BUNDLED_SSL_DESC=	Use bundled OpenSSL implementation from node.js
JIT_DESC=		Use Just In Time compiler

BUNDLED_SSL_CONFIGURE_OFF=	--openssl-use-def-ca-store --shared-openssl
BUNDLED_SSL_USES_OFF=	ssl
JIT_CONFIGURE_OFF=	--v8-lite-mode

.include "Makefile.version"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBUNDLED_SSL} && ${ARCH} != amd64
CONFIGURE_ARGS+=--openssl-no-asm
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/tools/v8_gypfiles/v8.gyp
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/deps/ada/
	@${RM} -r ${WRKSRC}/deps/brotli/
	@${RM} -r ${WRKSRC}/deps/cares/
	@${RM} -r ${WRKSRC}/deps/corepack/
	@${RM} -r ${WRKSRC}/deps/googletest/
	@${RM} -r ${WRKSRC}/deps/histogram/
	@${RM} -r ${WRKSRC}/deps/icu-small/
	@${RM} -r ${WRKSRC}/deps/llhttp/
	@${RM} -r ${WRKSRC}/deps/nbytes/
	@${RM} -r ${WRKSRC}/deps/nghttp2/
	@${RM} -r ${WRKSRC}/deps/ngtcp2/
	@${RM} -r ${WRKSRC}/deps/npm/
	@${RM} -r ${WRKSRC}/deps/simdjson/
	@${RM} -r ${WRKSRC}/deps/sqlite/
	@${RM} -r ${WRKSRC}/deps/uv/
	@${RM} -r ${WRKSRC}/deps/uvwasi/
	@${RM} -r ${WRKSRC}/deps/zlib/
	@${RM} -r ${WRKSRC}/deps/zstd/

post-configure:
	# Post-process Makefile and *.mk files created by node-gyp and remove
	# all occurrences of -I${LOCALBASE}/include. C*FLAGS include this
	# before all -I../deps/* for bundled code. This can cause build
	# breakages if the dependency is installed in ${LOCALBASE}. The
	# USES+=localbase above will ensure that we pick up includes for real
	# external dependencies.
	@${FIND} ${WRKSRC}/out -type f -print0 | ${XARGS} -0 ${REINPLACE_CMD} -e 's|-I${LOCALBASE}/include||g'

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/node
# Fail if two simdutf copies end up in one process (node exports its bundled
# simdutf; a DSO linking the system libsimdutf.so, e.g. libmerve, then binds
# to the wrong one and CJS export lexing SIGBUSes). Importing a CommonJS
# module from ESM runs that lexer; stdin avoids a temp file.
	${ECHO_CMD} 'exports.ok = 1' | ${STAGEDIR}${PREFIX}/bin/node --input-type=module -e 'import "/dev/stdin"'

post-install-BUNDLED_SSL-on:
	cd ${STAGEDIR}${PREFIX} && ${FIND} include/node/openssl/ -type f >> ${TMPPLIST}

.include <bsd.port.mk>
