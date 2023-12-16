PORTNAME=	bitwarden-cli
DISTVERSIONPREFIX=	cli-v
DISTVERSION=	2023.10.0
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
		libcares.so:dns/c-ares \
		libnghttp2.so:www/libnghttp2
RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		ca_root_nss>0:security/ca_root_nss
TEST_DEPENDS=	npm:www/npm${NODEJS_SUFFIX}

USES=		gmake localbase:ldflags nodejs:18,build pkgconfig \
		python:build ssl

USE_GITHUB=	yes
GH_ACCOUNT=	bitwarden
GH_PROJECT=	clients

MAKE_ENV+=	PYTHONDONTWRITEBYTECODE=1

BUILD_WRKSRC=	${WRKSRC}/apps/cli

PLIST_FILES=	bin/bw \
		share/zsh/site-functions/_bw

PORTDOCS=	CONTRIBUTING.md README.md SECURITY.md

OPTIONS_DEFINE=	DOCS

PREFETCH_FILE=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION}-node-modules${EXTRACT_SUFX}
PREFETCH_TIMESTAMP=	1699354730
PKG_NODE_VER=	18.15.0
PKG_FETCH_VER=	3.5
PKG_NODE_CONFIGURE_ARGS=--openssl-use-def-ca-store \
			--shared-brotli \
			--shared-cares \
			--shared-libuv \
			--shared-nghttp2 \
			--shared-openssl \
			--shared-zlib \
			--with-intl=system-icu
NODE_ARCH=	${ARCH:S/aarch64/arm64/:S/amd64/x64/:S/i386/ia32/}

pre-fetch:
	if [ ! -f ${DISTDIR}/${PREFETCH_FILE} ]; then \
		${MKDIR} ${WRKDIR}/node-modules-cache; \
		${CP} -R ${FILESDIR}/packagejsons/* ${WRKDIR}/node-modules-cache; \
		cd ${WRKDIR}/node-modules-cache && \
		${SETENV} HOME=${WRKDIR} npm install -g --prefix=${WRKDIR} npm@9.9.0 && \
		${SETENV} HOME=${WRKDIR} PATH=${WRKDIR}/bin:${PATH} \
			npm ci --ignore-scripts --no-progress --no-audit --no-fund; \
		${FIND} ${WRKDIR}/node-modules-cache -depth 1 -print | \
			${GREP} -v node_modules | ${XARGS} ${RM} -r; \
		${FIND} ${WRKDIR}/node-modules-cache -type d -exec ${CHMOD} 755 {} ';'; \
		cd ${WRKDIR}/node-modules-cache && \
		${MTREE_CMD} -cbnSp node_modules | ${MTREE_CMD} -C | ${SED} \
			-e 's:time=[0-9.]*:time=${PREFETCH_TIMESTAMP}.000000000:' \
			-e 's:\([gu]id\)=[0-9]*:\1=0:g' \
			-e 's:flags=.*:flags=none:' \
			-e 's:^\.:./node_modules:' > node-modules-cache.mtree; \
		${TAR} -cz --options 'gzip:!timestamp' \
			-f ${DISTDIR}/${PREFETCH_FILE} \
			@node-modules-cache.mtree; \
		${RM} -r ${WRKDIR}; \
	fi

post-extract:
	${MV} ${WRKDIR}/node_modules ${WRKSRC}

post-patch:
	# apply FreeBSD patches for node
	for p in ${.CURDIR:H:H}/www/node${NODEJS_VERSION}/files/patch-*; do \
		${PATCH} -s -p0 -d ${WRKDIR}/node-v${PKG_NODE_VER} < $${p}; \
	done
	# apply node patch from pkg-fetch
	${PATCH} -s -p1 -d ${WRKDIR}/node-v${PKG_NODE_VER} < \
		${WRKSRC}/node_modules/pkg-fetch/patches/node.v${PKG_NODE_VER}.cpp.patch

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm run postinstall
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
		npm run build:prod
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		npx pkg . --targets node${NODEJS_VERSION}-freebsd-${NODE_ARCH} --output ./dist/bw
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		./dist/bw completion --shell zsh > _bw

do-install:
	# don't strip executable since it causes error
	${INSTALL_KLD} ${BUILD_WRKSRC}/dist/bw ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${BUILD_WRKSRC}/_bw \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_bw

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${BUILD_WRKSRC} && ${SETENV} ${TEST_ENV} npm run test

.include <bsd.port.mk>
