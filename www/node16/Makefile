PORTNAME=	node
DISTVERSIONPREFIX=	v
DISTVERSION=	16.20.1
PORTREVISION?=	3
CATEGORIES=	www
MASTER_SITES=	https://nodejs.org/dist/v${DISTVERSION}/
PKGNAMESUFFIX=	16

MAINTAINER=	otis@FreeBSD.org
COMMENT=	V8 JavaScript for client and server
WWW=		https://nodejs.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream EOL reaches on 2023-09-11
EXPIRATION_DATE=	2023-09-30

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc64 powerpc64le

BUILD_DEPENDS+=	brotli>=1.0.9,1:archivers/brotli \
		c-ares>=1.17.2:dns/c-ares \
		libnghttp2>=1.45.1:www/libnghttp2 \
		libuv>=1.42.0:devel/libuv \
		objdump:devel/binutils
LIB_DEPENDS+=	libbrotlidec.so:archivers/brotli \
		libcares.so:dns/c-ares \
		libnghttp2.so:www/libnghttp2 \
		libuv.so:devel/libuv

USES=		compiler:c++11-lib gmake localbase pkgconfig python:build \
		shebangfix

BROKEN_SSL=	libressl libressl-devel
BROKEN_SSL_REASON=	node.js ${PORTVERSION:R:R}.x LTS requires OpenSSL 1.1.x or the BUNDLED_SSL option enabled

SHEBANG_FILES=	deps/v8/third_party/inspector_protocol/*.py deps/v8/tools/*.py \
		tools/*.py tools/inspector_protocol/*.py

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX_RELDEST} \
		--shared-brotli \
		--shared-cares \
		--shared-libuv \
		--shared-nghttp2 \
		--shared-zlib \
		--without-npm
CONFIGURE_ENV+=	CC_host="${CCACHE_BIN} ${CC}" \
		CFLAGS_host="${CFLAGS}" \
		CXX_host="${CCACHE_BIN} ${CXX}" \
		CXXFLAGS_host="${CXXFLAGS}" \
		LINK_host=${CXX} \
		LDFLAGS_host="${LDFLAGS}"
MAKE_ARGS+=	CC.host="${CCACHE_BIN} ${CC}" \
		CFLAGS.host="${CFLAGS}" \
		CXX.host="${CCACHE_BIN} ${CXX}" \
		CXXFLAGS.host="${CXXFLAGS}" \
		LINK.host=${CXX} \
		LDFLAGS.host="${LDFLAGS}"

CONFLICTS_INSTALL=	node[0-9][0-9]

REINPLACE_ARGS=	-i ''
PORTSCOUT=	limit:^16\.

OPTIONS_DEFINE=		BUNDLED_SSL COREPACK DOCS NLS
OPTIONS_DEFAULT=	COREPACK

OPTIONS_SUB=	yes

BUNDLED_SSL_DESC=	Use node.js's bundled OpenSSL implementation
COREPACK_DESC=		Build and install corepack package manager

BUNDLED_SSL_RUN_DEPENDS_OFF=	ca_root_nss>=0:security/ca_root_nss
BUNDLED_SSL_USES_OFF=		ssl
BUNDLED_SSL_CONFIGURE_OFF=	--openssl-use-def-ca-store \
				--shared-openssl

COREPACK_CONFIGURE_OFF=	--without-corepack

NLS_BUILD_DEPENDS=	icu>=69.1:devel/icu
NLS_LIB_DEPENDS=	libicui18n.so:devel/icu
NLS_CONFIGURE_ON=	--with-intl=system-icu

PREFIX_RELDEST=	${PREFIX:S,^${DESTDIR},,}

.include <bsd.port.pre.mk>

.if (defined(PPC_ABI) && ${PPC_ABI} == ELFv2) || ${ARCH} == powerpc64le
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-common.gypi
.endif

.if ${ARCH} == armv6 || ${ARCH} == armv7
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-tools_v8__gypfiles_v8.gyp
.endif

.if ${PORT_OPTIONS:MBUNDLED_SSL} && ${ARCH} != amd64
CONFIGURE_ARGS+=	--openssl-no-asm
.endif

.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 160
CXXFLAGS+=	-Wno-error=enum-constexpr-conversion
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/tools/v8_gypfiles/v8.gyp

post-configure:
# Post-process Makefile and *.mk files created by node-gyp and remove
# all occurrences of -I${LOCALBASE}/include. C*FLAGS include this
# before all -I../deps/* for bundled code. This can cause build
# breakages if the dependency is installed in ${LOCALBASE}. The
# USES+=localbase # above will ensure that we pick up includes for real
# external dependencies.
	${FIND} ${WRKSRC}/out -type f -print0 \
		| ${XARGS} -0 ${REINPLACE_CMD} -e "s|-I${LOCALBASE}/include||g"

post-install:
	${RM} -rf ${STAGEDIR}${PREFIX}/share/systemtap
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/node

.include <bsd.port.post.mk>
