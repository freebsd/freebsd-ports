PORTNAME=	bitwarden-cli
DISTVERSIONPREFIX=	cli-v
DISTVERSION=	2025.8.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://nodejs.org/dist/v${PKG_NODE_VER}/:node
DISTFILES=	node-v${PKG_NODE_VER}${EXTRACT_SUFX}:node \
		${PREFETCH_FILE}:prefetch

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

FETCH_DEPENDS=	npm:www/npm${NODEJS_SUFFIX}
BUILD_DEPENDS=	npm:www/npm${NODEJS_SUFFIX}
LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
		libicui18n.so:devel/icu \
		libuv.so:devel/libuv \
		libsimdjson.so:devel/simdjson \
		libcares.so:dns/c-ares \
		libngtcp2.so:net/libngtcp2 \
		libnghttp2.so:www/libnghttp2 \
		libnghttp3.so:www/libnghttp3
RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		ca_root_nss>0:security/ca_root_nss
TEST_DEPENDS=	npm:www/npm${NODEJS_SUFFIX}

USES=		gmake localbase:ldflags nodejs:22,build pkgconfig \
		python:build ssl

USE_GITHUB=	yes
GH_ACCOUNT=	bitwarden
GH_PROJECT=	clients

MAKE_ENV+=	PYTHONDONTWRITEBYTECODE=1

# don't strip executable upon install since it causes error
STRIP=		# empty

BUILD_WRKSRC=	${WRKSRC}/apps/cli

PLIST_FILES=	bin/bw \
		share/zsh/site-functions/_bw

PORTDOCS=	CONTRIBUTING.md README.md SECURITY.md

OPTIONS_DEFINE=	DOCS

PREFETCH_FILE=	${PORTNAME}-${DISTVERSION}-node-modules${EXTRACT_SUFX}
PREFETCH_TIMESTAMP=	61171200
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
			--shared-zlib \
			--with-intl=system-icu
NODE_ARCH=	${ARCH:S/aarch64/arm64/:S/amd64/x64/:S/i386/ia32/}

pre-fetch:
	if [ ! -f ${DISTDIR}/${PREFETCH_FILE} ]; then \
		${MKDIR} ${WRKDIR}/node-modules-cache; \
		${CP} -R ${FILESDIR}/packagejsons/* ${WRKDIR}/node-modules-cache; \
		cd ${WRKDIR}/node-modules-cache && \
		${SETENV} HOME=${WRKDIR} \
			npm ci --ignore-scripts --no-progress --no-audit --no-fund; \
		${FIND} ${WRKDIR}/node-modules-cache -type d -exec ${CHMOD} 755 {} ';'; \
		for dir in `${FIND} -s ${WRKDIR}/node-modules-cache -type d -name node_modules -print | \
			${GREP} -ve 'node_modules/.*/node_modules'`; do \
			${MTREE_CMD} -cbnSp $${dir} | ${MTREE_CMD} -C | ${SED} \
				-e 's:time=[0-9.]*:time=${PREFETCH_TIMESTAMP}.000000000:' \
				-e 's:\([gu]id\)=[0-9]*:\1=0:g' \
				-e 's:flags=.*:flags=none:' \
				-e "s|\.|$${dir}|" \
				-e 's|^${WRKDIR}|.|' >> ${WRKDIR}/node-modules-cache.mtree; \
		done; \
		${TAR} -cz --options 'gzip:!timestamp' -f ${DISTDIR}/${PREFETCH_FILE} \
			-C ${WRKDIR} @node-modules-cache.mtree; \
		${RM} -r ${WRKDIR}; \
	fi

post-extract:
	@for dir in `${FIND} -s ${WRKDIR}/node-modules-cache -type d -name node_modules -print | \
		${GREP} -ve 'node_modules/.*/node_modules'`; do \
		${MV} $${dir} `${ECHO_CMD} $${dir} | sed -e 's|${WRKDIR}/node-modules-cache|${WRKSRC}|'`; \
	done

post-patch:
	# apply FreeBSD patches for node
	for p in ${PATCHDIR}/node/patch-*;do \
		${PATCH} -s -p0 -d ${WRKDIR}/node-v${PKG_NODE_VER} < $${p}; \
	done
	# apply node patch from pkg-fetch
	${PATCH} -s -p1 -d ${WRKDIR}/node-v${PKG_NODE_VER} < \
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
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ELECTRON_SKIP_BINARY_DOWNLOAD=1 \
		npm rebuild --nodedir=${WRKDIR}/node-v${PKG_NODE_VER} --verbose

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
