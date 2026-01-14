PORTNAME=	bitwarden-cli
DISTVERSIONPREFIX=	cli-v
DISTVERSION=	2025.12.1
CATEGORIES=	security
MASTER_SITES=	https://nodejs.org/dist/v${PKG_NODE_VER}/:node
DISTFILES=	node-v${PKG_NODE_VER}${EXTRACT_SUFX}:node

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Bitwarden client command-line interface
WWW=		https://bitwarden.com

LICENSE=	BITWARDEN GPLv3
LICENSE_COMB=	multi
LICENSE_NAME_BITWARDEN=	BITWARDEN LICENSE AGREEMENT
LICENSE_FILE_BITWARDEN=	${WRKSRC}/LICENSE_BITWARDEN.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE_GPL.txt
LICENSE_PERMS_BITWARDEN=none

ONLY_FOR_ARCHS=	aarch64 amd64

LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
		libzstd.so:archivers/zstd \
		libicui18n.so:devel/icu \
		libuv.so:devel/libuv \
		libsimdjson.so:devel/simdjson \
		libcares.so:dns/c-ares \
		libngtcp2.so:net/libngtcp2 \
		libnghttp2.so:www/libnghttp2 \
		libnghttp3.so:www/libnghttp3
RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		ca_root_nss>0:security/ca_root_nss

USES=		electron:env gmake localbase:ldflags nodejs:22,build \
		pkgconfig python:build sqlite ssl

USE_GITHUB=	yes
GH_ACCOUNT=	bitwarden
GH_PROJECT=	clients

MAKE_ENV+=	PYTHONDONTWRITEBYTECODE=1

# don't strip executable upon install since it causes error
STRIP=		# empty
BINARY_ALIAS=	python=${PYTHON_CMD}

BUILD_WRKSRC=	${WRKSRC}/apps/cli

PLIST_FILES=	bin/bw \
		share/zsh/site-functions/_bw

PORTDOCS=	CONTRIBUTING.md README.md SECURITY.md

OPTIONS_DEFINE=	DOCS

USE_ELECTRON=	npm:npm prefetch extract
PKG_NODE_VER=	22.15.1
PKG_FETCH_VER=	3.5
PKG_NODE_CONFIGURE_ARGS=--openssl-use-def-ca-store \
			--shared-brotli \
			--shared-cares \
			--shared-libuv \
			--shared-nghttp2 \
			--shared-nghttp3 \
			--shared-openssl \
			--shared-ngtcp2 \
			--shared-simdjson \
			--shared-sqlite \
			--shared-zlib \
			--shared-zstd \
			--with-intl=system-icu
NODE_ARCH=	${ARCH:S/aarch64/arm64/:S/amd64/x64/:S/i386/ia32/}

post-patch:
	# apply FreeBSD patches for node
	@${BSDMAKE} PATCHDIR=${PATCHDIR}/node \
		WRKSRC=${WRKDIR}/node-v${PKG_NODE_VER} do-patch
	# apply node patch from pkg-fetch
	@${PATCH} -s -p1 -d ${WRKDIR}/node-v${PKG_NODE_VER} < \
		${WRKSRC}/node_modules/@yao-pkg/pkg-fetch/patches/node.v${PKG_NODE_VER}.cpp.patch

pre-build:
	# build patched node for pkg
	cd ${WRKDIR}/node-v${PKG_NODE_VER} && \
		${SETENV} ${CONFIGURE_ENV} CC=${CC} CXX=${CXX} ./configure ${PKG_NODE_CONFIGURE_ARGS} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} -j ${MAKE_JOBS_NUMBER}
	${MKDIR} ${WRKDIR}/.pkg-cache/v${PKG_FETCH_VER}
	${MV} ${WRKDIR}/node-v${PKG_NODE_VER}/out/Release/node \
		${WRKDIR}/.pkg-cache/v${PKG_FETCH_VER}/built-v${PKG_NODE_VER}-freebsd-${NODE_ARCH}
	${STRIP_CMD} ${WRKDIR}/.pkg-cache/v${PKG_FETCH_VER}/built-v${PKG_NODE_VER}-freebsd-${NODE_ARCH}
	# rebuild node modules against patched node
	@for subdir in `${FIND} ${WRKSRC} -type f -name binding.gyp -exec ${DIRNAME} {} ';' 2>/dev/null`; do \
		${ECHO_MSG} "===>   Rebuilding native modules in $${subdir}"; \
		cd $${subdir} && \
		${SETENV} ${MAKE_ENV} \
			npm_config_runtime=node \
			npm_config_target=${PKG_NODE_VER} \
			npm_config_nodedir=${WRKDIR}/node-v${PKG_NODE_VER} \
			node-gyp rebuild; \
	done

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		npm run build:bit:prod
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		npx pkg . --targets node${NODEJS_VERSION}-freebsd-${NODE_ARCH} --output ./dist/bw
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		./dist/bw completion --shell zsh > _bw

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/dist/bw ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${BUILD_WRKSRC}/_bw \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_bw

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${BUILD_WRKSRC} && ${SETENV} ${TEST_ENV} npm run test

.include <bsd.port.mk>
