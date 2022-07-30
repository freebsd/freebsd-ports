PORTNAME=	node
DISTVERSIONPREFIX=	v
DISTVERSION=	14.20.0
CATEGORIES=	www
MASTER_SITES=	http://nodejs.org/dist/v${DISTVERSION}/
PKGNAMESUFFIX=	14

MAINTAINER=	bhughes@FreeBSD.org
COMMENT=	V8 JavaScript for client and server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc64 powerpc64le

BUILD_DEPENDS+=	brotli>=1.0.9,1:archivers/brotli \
		c-ares>=1.17.2:dns/c-ares \
		libnghttp2>=1.42.0:www/libnghttp2 \
		libuv>=1.42.0:devel/libuv \
		objdump:devel/binutils
LIB_DEPENDS+=	libbrotlidec.so:archivers/brotli \
		libcares.so:dns/c-ares \
		libnghttp2.so:www/libnghttp2 \
		libuv.so:devel/libuv

USES=		compiler:c++11-lib gmake localbase pkgconfig \
		python:2.7-3.10,build shebangfix
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

MAKE_ENV+=	CC.host=${CC} \
		CFLAGS.host="${CFLAGS}" \
		CXX.host=${CXX} \
		CXXFLAGS.host="${CXXFLAGS}" \
		LDFLAGS.host="${LDFLAGS}" \
		LINK.host=${CXX}
TEST_ARGS=	-i
TEST_TARGET=	test-only

CONFLICTS_INSTALL=	node node10 node16

PREFIX_RELDEST=	${PREFIX:S,^${DESTDIR},,}
REINPLACE_ARGS=	-i ''

OPTIONS_DEFINE=		BUNDLED_SSL COREPACK DOCS DTRACE NLS
OPTIONS_DEFAULT=	COREPACK DTRACE
OPTIONS_DEFAULT+=	${OPTIONS_DEFAULT_${OPSYS}_${OSREL:R}}

.if !exists(/usr/sbin/dtrace)
OPTIONS_EXCLUDE+=	DTRACE
.endif

OPTIONS_EXCLUDE_aarch64=	DTRACE
# dt_modtext:/usr/src/cddl/contrib/opensolaris/lib/libdtrace/common/dt_link.c(820): arm not implemented
OPTIONS_EXCLUDE_armv6=	DTRACE
OPTIONS_EXCLUDE_armv7=	DTRACE
OPTIONS_EXCLUDE_powerpc64=	DTRACE
OPTIONS_EXCLUDE_powerpc64le=	DTRACE

OPTIONS_SUB=	yes

BUNDLED_SSL_DESC=	Use bundled OpenSSL implementation from node.js
COREPACK_DESC=		Build and install corepack package manager

BUNDLED_SSL_RUN_DEPENDS_OFF=	ca_root_nss>=0:security/ca_root_nss
BUNDLED_SSL_USES_OFF=		ssl
BUNDLED_SSL_CONFIGURE_OFF=	--openssl-use-def-ca-store \
				--shared-openssl

COREPACK_CONFIGURE_OFF=	--without-corepack
DTRACE_CONFIGURE_ON=	--with-dtrace

NLS_BUILD_DEPENDS=	icu>=69.1:devel/icu
NLS_LIB_DEPENDS=	libicui18n.so:devel/icu
NLS_CONFIGURE_ON=	--with-intl=system-icu

.include <bsd.port.options.mk>

.if (defined(PPC_ABI) && ${PPC_ABI} == ELFv2) || ${ARCH} == powerpc64le
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-common.gypi
.endif

.if ${ARCH} == armv6 || ${ARCH} == armv7
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-tools_v8__gypfiles_v8.gyp
.endif

.if ${PORT_OPTIONS:MBUNDLED_SSL} && ${ARCH} != amd64
CONFIGURE_ARGS+=	--openssl-no-asm
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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/node

.include <bsd.port.mk>
