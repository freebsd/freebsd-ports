PORTNAME=	immich-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.4
CATEGORIES=	www
MASTER_SITES=	https://github.com/joneum/FreeBSD-Immich/releases/download/v${DISTVERSION}/:buildkit
DISTFILES=	immich-freebsd-buildkit-${DISTVERSION}${EXTRACT_SUFX}:buildkit
EXTRACT_ONLY=	${DISTFILES:N*\:npm:C/:[^:]*$//}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Command line interface for Immich
WWW=		https://immich.app/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64le
ONLY_FOR_ARCHS_REASON=	the TypeScript compiler ships no FreeBSD/i386 binary

BUILD_DEPENDS=	${LOCALBASE}/bin/npm:www/npm-node22

USES=		cpe nodejs:22,build,run
CPE_VENDOR=	futo
CPE_PRODUCT=	immich

USE_GITHUB=	yes
GH_ACCOUNT=	immich-app
GH_PROJECT=	immich

# Shares the buildkit distfile with www/immich, see the comment there on
# how it is made.
BUILDKIT=	${WRKDIR}/immich-freebsd-buildkit-${DISTVERSION}
PNPM=		${WRKDIR}/pnpm-prefix/bin/pnpm
PNPM_VERSION=	11.22.0

MAKE_ENV=	CI=1 \
		COREPACK_ENABLE_STRICT=0 \
		HOME=${WRKDIR}

SUB_FILES=	immich
SUB_LIST=	NODE=${LOCALBASE}/bin/node

NO_ARCH=	yes

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64le
WASM_RD=	rolldown@1.2.5/node_modules/@rolldown/binding-wasm32-wasi
WASM_NPM=	@rolldown/binding-wasm32-wasi/-/binding-wasm32-wasi-1.2.5.tgz ${WASM_RD} \
		@emnapi/core/-/core-2.0.0-alpha.4.tgz ${WASM_RD}/node_modules/@emnapi/core \
		@emnapi/runtime/-/runtime-2.0.0-alpha.4.tgz ${WASM_RD}/node_modules/@emnapi/runtime \
		@emnapi/wasi-threads/-/wasi-threads-2.0.1.tgz ${WASM_RD}/node_modules/@emnapi/wasi-threads \
		@napi-rs/wasm-runtime/-/wasm-runtime-1.2.5.tgz ${WASM_RD}/node_modules/@napi-rs/wasm-runtime \
		@tybys/wasm-util/-/wasm-util-0.10.4.tgz ${WASM_RD}/node_modules/@tybys/wasm-util \
		tslib/-/tslib-2.8.1.tgz ${WASM_RD}/node_modules/tslib
MASTER_SITES+=	https://registry.npmjs.org/:npm
DISTFILES+=	${WASM_NPM:M*.tgz:S/$/:npm/}
TSC_SHIM=	${WRKSRC}/node_modules/.pnpm/typescript@7.0.2/node_modules/@typescript/typescript-freebsd-ppc64
.endif

pre-build:
	cd ${WRKDIR} && ${SETENV} ${MAKE_ENV} PATH=${PATH} \
		${LOCALBASE}/bin/npm install -g --prefix ${WRKDIR}/pnpm-prefix \
		${BUILDKIT}/pnpm-${PNPM_VERSION}.tgz

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PNPM} install --offline --frozen-lockfile --ignore-scripts \
		--store-dir ${BUILDKIT}/pnpm-store
.if ${ARCH} == powerpc64le
.for f d in ${WASM_NPM}
	@${RM} -r ${WRKSRC}/node_modules/.pnpm/${d}
	@${MKDIR} ${WRKSRC}/node_modules/.pnpm/${d}
	@${TAR} -xf ${DISTDIR}/${f} -C ${WRKSRC}/node_modules/.pnpm/${d} \
		--strip-components 1
.endfor
	@${MKDIR} ${TSC_SHIM}/lib
	@${ECHO_CMD} '{"name":"@typescript/typescript-freebsd-ppc64"}' > \
		${TSC_SHIM}/package.json
	@${PRINTF} '#!/bin/sh\nexec ${LOCALBASE}/bin/node %s "$$@"\n' \
		${WRKSRC}/node_modules/.pnpm/typescript@6.0.3/node_modules/typescript/bin/tsc \
		> ${TSC_SHIM}/lib/tsc
	@${CHMOD} +x ${TSC_SHIM}/lib/tsc
.endif
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PNPM} --filter @immich/sdk --filter @immich/cli build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PNPM} --store-dir ${BUILDKIT}/pnpm-store --filter @immich/cli \
		--prod --no-optional deploy ${WRKDIR}/cli-pruned

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKDIR}/cli-pruned && ${PAX} -rw . ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/immich ${STAGEDIR}${PREFIX}/bin/immich

.include <bsd.port.mk>
