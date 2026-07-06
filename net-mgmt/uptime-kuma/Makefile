PORTNAME=	uptime-kuma
DISTVERSION=	2.4.0
CATEGORIES=	net-mgmt www
MASTER_SITES=	LOCAL/dch/${PORTNAME}/:npmcache \
		https://github.com/louislam/${PORTNAME}/releases/download/${DISTVERSION}/:dist
DISTFILES=	${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}:npmcache \
		dist.tar.gz:dist
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX} \
		louislam-${PORTNAME}-${DISTVERSION}_GH0.tar.gz

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Self-hosted server monitoring tool
WWW=		https://github.com/louislam/uptime-kuma

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/npm:www/npm \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		esbuild:devel/esbuild
LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

USES=		gmake nodejs:lts,build,run python:build
USE_GITHUB=	yes
GH_ACCOUNT=	louislam
USE_RC_SUBR=	uptimekuma

WWWDIR=		${PREFIX}/www/${PORTNAME}

SUB_LIST+=	GROUPS=${GROUPS} \
		USERS=${USERS}

USERS=		www
GROUPS=		www

PLIST_FILES=	"@dir(${USERS},${GROUPS},750) /var/db/${PORTNAME}" \
		"@dir(${USERS},${GROUPS},750) /var/log/${PORTNAME}" \
		"@dir(${USERS},${GROUPS},750) /var/run/${PORTNAME}"

_NODE_ARCH=		${ARCH:S/aarch64/arm64/:S/amd64/x64/}
_NPM_CACHE=		${WRKDIR}/.npm
_PRUNE_EXTRA_DIRS=	beta kuma-pr release uptime-kuma-push \
			push-examples/typescript-fetch
_PRUNE_NODE_FILES=	-name '*.map' -o -name '*.d.ts' -o -name '*.ts' -o \
			-name '*.cts' -o -name '*.mts' -o -name '*.tsbuildinfo'
_PRUNE_NODE_EXPR=	-name .github -o -name .circleci -o -name __pycache__ \
			-o -name benchmark -o -name benchmarks -o -name \
			coverage -o -name docs -o -name example -o -name \
			examples -o -name test -o -name tests
_PRUNE_NODE_MODULES=	@azure @azure-rest @mapbox/node-pre-gyp @typespec \
			are-we-there-yet cacache gauge make-fetch-happen \
			node-gyp nopt npmlog playwright-core tar

post-extract:
	@${MKDIR} ${_NPM_CACHE}
	${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/dist.tar.gz -C ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e '/monitorTypeList\["real-browser"\]/d' \
		-e '/RealBrowserMonitorType/d' \
		${WRKSRC}/server/uptime-kuma-server.js
	${REINPLACE_CMD} -e '/remoteBrowserSocketHandler/d' \
		-e '/resetChrome/d' \
		-e '/Chrome executable is changed/d' \
		${WRKSRC}/server/server.js
	${REINPLACE_CMD} \
		-e 's#const { testChrome } = require("../monitor-types/real-browser-monitor-type");#const testChrome = async () => { throw new Error("Real browser monitor is not supported on FreeBSD."); };#' \
		${WRKSRC}/server/socket-handlers/general-socket-handler.js
	${REINPLACE_CMD} \
		-e 's#const { testRemoteBrowser } = require("../monitor-types/real-browser-monitor-type");#const testRemoteBrowser = async () => { throw new Error("Real browser monitor is not supported on FreeBSD."); };#' \
		${WRKSRC}/server/socket-handlers/remote-browser-socket-handler.js

do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} HOME=${WRKDIR} npm_config_cache=${_NPM_CACHE} \
		npm_config_offline=true npm_config_python=${PYTHON_CMD} \
		npm_config_nodedir=${LOCALBASE} CFLAGS="-I${LOCALBASE}/include" \
		CXXFLAGS="-I${LOCALBASE}/include" npm ci --ignore-scripts \
		--legacy-peer-deps --no-audit --no-fund --no-progress
# hack out the esbuild version check and let us use whats in ports
	${SED} -i '' \
		'/checkAndPreparePackage()\.then/,$$d' \
		${WRKSRC}/node_modules/esbuild/install.js
	${ECHO_CMD} 'checkAndPreparePackage();' >> ${WRKSRC}/node_modules/esbuild/install.js
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} HOME=${WRKDIR} npm_config_cache=${_NPM_CACHE} \
		npm_config_offline=true npm_config_python=${PYTHON_CMD} \
		npm_config_nodedir=${LOCALBASE} ESBUILD_BINARY_PATH=${LOCALBASE}/bin/esbuild \
		CFLAGS="-I${LOCALBASE}/include" CXXFLAGS="-I${LOCALBASE}/include" \
		npm rebuild --legacy-peer-deps --no-audit --no-fund --no-progress
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} HOME=${WRKDIR} npm_config_cache=${_NPM_CACHE} \
		npm_config_offline=true npm prune --omit=dev --ignore-scripts \
		--legacy-peer-deps --no-audit --no-fund --no-progress

post-build:
	${ECHO_CMD} "module.exports = require('./binding/napi-v6-freebsd-${_NODE_ARCH}/node_sqlite3.node');" \
		> ${WRKSRC}/node_modules/@louislam/sqlite3/lib/sqlite3-binding.js
	${REINPLACE_CMD} -e '/"test-e2e":/d' \
		-e '/"test-e2e-ui":/d' \
		-e '/"playwright-codegen":/d' \
		-e '/"playwright-show-report":/d' \
		-e '/"playwright-core":/d' \
		-e '/"@playwright\/test":/d' \
		${WRKSRC}/package.json
	${REINPLACE_CMD} \
		-e 's#var _identity = require("@azure/identity");#var _identity = {};#' \
		-e 's#var _coreAuth = require("@azure/core-auth");#var _coreAuth = { isTokenCredential: function() { return false; } };#' \
		-e '/@azure\/identity/d' \
		-e "/type !== 'default'.*azure-active-directory-default/s#^.*#      if (type !== 'default' \&\& type !== 'ntlm') {#" \
		-e "/must one of/s#^.*#        throw new TypeError('Only default and ntlm SQL Server authentication are supported in the FreeBSD port.');#" \
		${WRKSRC}/node_modules/tedious/lib/connection.js
	${REINPLACE_CMD} -e '/"@azure\//d' \
		${WRKSRC}/node_modules/tedious/package.json
	${REINPLACE_CMD} -e '/"azure",/d' \
		${WRKSRC}/node_modules/mssql/package.json

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
.for d in server db extra dist dist-frontend
	if [ -d ${WRKSRC}/${d} ]; then \
		(cd ${WRKSRC} && \
		${COPYTREE_SHARE} ${d} ${STAGEDIR}${WWWDIR}); \
		fi
.endfor
	${MKDIR} ${STAGEDIR}${WWWDIR}/src
	${INSTALL_DATA} ${WRKSRC}/src/util.js \
		${STAGEDIR}${WWWDIR}/src
	${INSTALL_DATA} ${WRKSRC}/package.json \
		${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} node_modules ${STAGEDIR}${WWWDIR})
	${RM} -r ${STAGEDIR}${WWWDIR}/node_modules/@esbuild
	${RM} -r ${STAGEDIR}${WWWDIR}/node_modules/@rollup
	${RM} -r ${STAGEDIR}${WWWDIR}/node_modules/@louislam/sqlite3/build-tmp-napi-v6
	${RM} ${STAGEDIR}${WWWDIR}/node_modules/@louislam/node-addon-api/node_api.Makefile
	${RM} ${STAGEDIR}${WWWDIR}/node_modules/@louislam/node-addon-api/nothing.target.mk
	${RM} -r ${STAGEDIR}${WWWDIR}/node_modules/cpu-features/build/Release/.deps
	${RM} -r ${STAGEDIR}${WWWDIR}/node_modules/cpu-features/build/Release/obj.target
	${RM} ${STAGEDIR}${WWWDIR}/node_modules/cpu-features/build/Release/cpu_features.a
	${RM} ${STAGEDIR}${WWWDIR}/node_modules/cpu-features/build/Makefile
	${RM} ${STAGEDIR}${WWWDIR}/node_modules/cpu-features/build/binding.Makefile
	${RM} ${STAGEDIR}${WWWDIR}/node_modules/cpu-features/build/config.gypi
	${RM} ${STAGEDIR}${WWWDIR}/node_modules/cpu-features/build/cpufeatures.target.mk
	${RM} -r ${STAGEDIR}${WWWDIR}/node_modules/cpu-features/build/deps
	${RM} -r ${STAGEDIR}${WWWDIR}/node_modules/ssh2/lib/protocol/crypto/build/Release/.deps
	${RM} -r ${STAGEDIR}${WWWDIR}/node_modules/ssh2/lib/protocol/crypto/build/Release/obj.target
	${RM} ${STAGEDIR}${WWWDIR}/node_modules/ssh2/lib/protocol/crypto/build/Makefile
	${RM} ${STAGEDIR}${WWWDIR}/node_modules/ssh2/lib/protocol/crypto/build/binding.Makefile
	${RM} ${STAGEDIR}${WWWDIR}/node_modules/ssh2/lib/protocol/crypto/build/config.gypi
	${RM} ${STAGEDIR}${WWWDIR}/node_modules/ssh2/lib/protocol/crypto/build/sshcrypto.target.mk
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/log/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/run/${PORTNAME}

# The plist is generated from the staged tree below, so pruning has to
# happen before TMPPLIST is appended. Native artefacts are treated
# differently from JS helpers: keep and strip FreeBSD ELF modules, but
# delete Linux, Mach-O, PE, and other non-FreeBSD binaries. Do not
# blindly remove JS platform dispatchers; some packages, e.g.
# @louislam/ping, statically require Linux/macOS/Windows helpers even
# when running on FreeBSD. Yes.
#
# Pruning:
#
# Files/modules                         Saving        Functionality lost
# ------------------------------------  --------------  -----------------------
# package-lock/.package-lock files      1.2MB/3 files None at runtime
# node_modules/*.map                    42MB/6.7k     Source-level debugging
# node_modules TS decl/source files     27MB/7.9k     None if JS dist exists
# README*/CHANGELOG*                    4.9MB/700     Bundled package docs
# extra dev/release/test helper scripts <100KB        Only those helpers
# node-gyp/npm fetch/build stack        2.9MB/375     Patched sqlite loader
# Playwright                            6.9MB/291     Real browser monitor
# Azure auth/key-vault deps             10MB/1.8k     AAD auth/AKV encryption
#
# Possible further pruning savings, if people don't use these:
# SQL Server                            4MB/500       SQL Server monitor
# MongoDB                               2.7MB/315     MongoDB monitor
# Redis                                 3.4MB/2.3k    Redis monitor
# Oracle                                1.2MB/113     Oracle DB monitor
# Nostr                                 7.6MB/827     Nostr notifications
post-install:
.for d in ${_PRUNE_EXTRA_DIRS}
	${RM} -r ${STAGEDIR}${WWWDIR}/extra/${d}
.endfor
	${RM} ${STAGEDIR}${WWWDIR}/extra/remove-playwright-test-data.js
.for d in ${_PRUNE_NODE_MODULES}
	${RM} -r ${STAGEDIR}${WWWDIR}/node_modules/${d}
.endfor
	${RM} ${STAGEDIR}${WWWDIR}/node_modules/tedious/lib/always-encrypted/keystore-provider-azure-key-vault.js
	${FIND} -s ${STAGEDIR}${WWWDIR}/node_modules -type d \( ${_PRUNE_NODE_EXPR} \
		\) -prune -exec ${RM} -r {} +
	${FIND} -s ${STAGEDIR}${WWWDIR} -type f \( ${_PRUNE_NODE_FILES} \) \
		-delete
	${FIND} -s -L ${STAGEDIR}${WWWDIR}/node_modules/.bin -type l -exec \
		${RM} {} +
	${FIND} -s ${STAGEDIR}${WWWDIR} -type f \( -name '*.orig' -o -name '*.bak' \
		-o -name '.gitignore' -o -name 'package-lock.json' -o -name \
		'.package-lock.json' \) -delete
	${RM} ${STAGEDIR}${WWWDIR}/server/monitor-types/real-browser-monitor-type.js
	${RM} -r ${STAGEDIR}${WWWDIR}/node_modules/oracledb/build
	${FIND} -s ${STAGEDIR}${WWWDIR} -type f \
		\( -name '*.node' -o -name '*.bare' -o -name '*.so' \
		-o -name '*.dylib' -o -name '*.dll' -o -name '*.exe' \) -exec \
		${SH} -c 'for f do \
			case "$$(${FILE} -b "$$f")" in \
				*ELF*FreeBSD*) ${STRIP_CMD} "$$f";; \
				*ELF*|*Mach-O*|*PE32*) ${RM} "$$f";; \
			esac; \
			done' sh {} +
	${FIND} -s ${STAGEDIR}${WWWDIR} -depth -type d -empty -delete
	${FIND} -s \
		${STAGEDIR}${WWWDIR} \
		-not \
		-type \
		d | \
		${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' \
		>> \
		${TMPPLIST}

# generate npm cache tarball for offline builds.
_tarball: _fetch-src _npm-populate _npm-cache _upload-npm-cache

_NPM_CACHE_SRC_URL=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/archive/${DISTVERSION}${EXTRACT_SUFX}
_NPM_CACHE_TARBALL=	${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}

_fetch-src:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	${FETCH_CMD} -o ${WRKDIR}/src${EXTRACT_SUFX} ${_NPM_CACHE_SRC_URL}
	${TAR} xf ${WRKDIR}/src${EXTRACT_SUFX} -C ${WRKDIR}

_npm-populate:
	(cd ${WRKSRC} && \
		${SETENV} HOME=${WRKDIR} npm_config_cache=${_NPM_CACHE} \
		npm ci --legacy-peer-deps --no-audit --no-fund)

_npm-cache:
	(cd ${WRKDIR} && \
		${TAR} czf ${_NPM_CACHE_TARBALL} .npm)

_upload-npm-cache:
	rsync -Phv --chmod=F0644 ${WRKDIR}/${_NPM_CACHE_TARBALL} freefall.freebsd.org:public_distfiles/${PORTNAME}/

.include <bsd.port.mk>
