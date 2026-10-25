PORTNAME=	claude-code
DISTVERSION=	2.1.310
CATEGORIES=	misc # machine-learning
# The linux-x64 package is fetched regardless of our own architecture,
# because we extract the actual NodeJS code from it anyway.
MASTER_SITES=	https://registry.npmjs.org/@anthropic-ai/claude-code-linux-x64/-/
DISTFILES=	claude-code-linux-x64-${DISTVERSION}.tgz

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Agentic coding tool from Anthropic that lives in your terminal
WWW=		https://github.com/anthropics/claude-code

# The package is Anthropic's proprietary CLI plus one GPLv3 file: clawgod's
# Bun.ant shim, fetched below. They are separate files that happen to be
# installed side by side, not a combined work, hence LICENSE_COMB=multi.
LICENSE=	Proprietary GPLv3
LICENSE_COMB=	multi
LICENSE_NAME_Proprietary=	Anthropic Proprietary License
LICENSE_FILE_Proprietary=	${FILESDIR}/LICENSE
LICENSE_FILE_GPLv3=		${CLAWGOD_WRKSRC}/LICENSE
LICENSE_PERMS_Proprietary=	dist-mirror pkg-mirror auto-accept

# post-extract runs unhare to unpack the JS out of the Bun binary, so the
# dependency has to be satisfied by the extract phase rather than the build one.
EXTRACT_DEPENDS=${LOCALBASE}/bin/unhare:archivers/unhare
RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash \
		${LOCALBASE}/bin/rg:textproc/ripgrep

USES=		nodejs:run npm:npm,build

# Since 2.1.271 the Ink renderer builds its cell grid through
# Bun.ant.CellSegmenter, an Anthropic-private Bun API that exists only inside
# the binary we unpack -- not in Bun proper, and certainly not in node. The
# renderer checks for it and throws before the first frame, so every release
# from 2.1.269 on would otherwise be unrunnable here.
#
# clawgod reimplemented that one API in plain JavaScript, for its own users
# running the extracted bundle on stock Bun. Only that single file is taken:
# it depends on nothing outside Intl.Segmenter, touches no network or disk,
# and the rest of that project -- which patches entitlement, telemetry and
# safety code -- is deliberately left alone.
#
# The pin is a commit, not a branch: this shim tracks a reverse-engineered
# contract and has been revised once already. When a claude-code release
# breaks the renderer again, move the pin to whichever commit answers it.
CLAWGOD_COMMIT=	f9d2dcde3d2977f9015c9a7002b427b8453e8536
CLAWGOD_WRKSRC=	${WRKDIR}/clawgod-${CLAWGOD_COMMIT}
CLAWGOD_SHIM=	${CLAWGOD_WRKSRC}/src/shared/bun-ant-shim.cjs

USE_GITHUB=	nodefault
GH_TUPLE=	0Chencc:clawgod:${CLAWGOD_COMMIT}:clawgod

WRKSRC=		${WRKDIR}/package
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=		USE_CURL_USER_AGENT
OPTIONS_DEFAULT=	USE_CURL_USER_AGENT
USE_CURL_USER_AGENT_DESC=	Use curl User-Agent for web fetching to bypass bot-blocking filters (e.g. Anubis)

# The User-Agent the option installs.  It is a constant on purpose: probing a
# curl at build time would make the package depend on a tool it never runs,
# and would stamp the builder's curl version into a NO_ARCH package.  Only the
# "curl/" prefix does the work; what follows it is never parsed by anyone.
CURL_USER_AGENT=	curl/8.22.0 (pdp11-unknown-dos)

PACKAGE_NAME=		@anthropic-ai/claude-code

# Where the extracted JS lives after post-extract. The unpacking and the
# Bun-to-Node rewrite are in scripts/post-extract, which bsd.port.mk picks up
# automatically; SCRIPTS_ENV already carries WRKDIR, WRKSRC and PREFIX.
EXTRACTED_JS=		${WRKDIR}/extracted-js
APPDIR=			${PREFIX}/lib/node_modules/${PACKAGE_NAME}
SCRIPTS_ENV+=		EXTRACTED_JS=${EXTRACTED_JS} APPDIR=${APPDIR}

# npm USES extracts node_modules alongside the extracted JS so COPYTREE picks them up
NPM_EXTRACT_WRKSRC=	${EXTRACTED_JS}

SUB_FILES=	claude

find-new-version:
	@TAB=$$(printf '\t'); \
	new_ver=$$(fetch -q -o - https://downloads.claude.ai/claude-code-releases/latest); \
	current_ver=$$(make -V DISTVERSION); \
	if [ "$$new_ver" != "$$current_ver" ]; then \
		${SED} -i '' "s/^DISTVERSION=.*/DISTVERSION=$${TAB}$$new_ver/" ${.CURDIR}/Makefile; \
		echo "=> New version available: $$current_ver -> $$new_ver"; \
	else \
		echo "=> No new version available (current: $$current_ver)"; \
	fi

do-install:
	# Install extracted JS tree into node_modules
	@cd ${EXTRACTED_JS}/root && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}
	# The npm dependencies go below our own directory, where node finds them
	# by walking up from the entry point, rather than into the shared
	# lib/node_modules. That directory is not ours: www/node26 owns npm and
	# corepack there, other ports keep scoped trees of their own, and
	# dropping generic names like semver, yaml and strip-ansi beside them
	# both risks a pkg conflict and lets an unrelated port resolve our copy
	# by accident -- misc/claude-science did exactly that, and only stopped
	# when it moved out.
	@cd ${EXTRACTED_JS}/node_modules && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/node_modules
	# npm adds .bin shims for dependencies that also ship a CLI (semver, yaml).
	# They are not on PATH here and the polyfill only needs the libraries.
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/node_modules/.bin
	# undici ships the source of its documentation website -- 48 markdown files
	# under docs/docs/ -- which no runtime path reads. The other dependencies
	# ship a README and a licence, and those stay; this is a different thing.
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/node_modules/undici/docs
	# Add ESM type declaration so Node.js treats the .js files as ES modules
	@${ECHO_CMD} '{"type":"module"}' > \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/package.json
	# Install Bun API polyfill (provides Bun-specific APIs like Bun.stringWidth for Bun-compiled code)
	${INSTALL_DATA} ${FILESDIR}/bun-polyfill.cjs \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/bun-polyfill.cjs
	# Install the Bun.ant shim beside it; bun-polyfill.cjs requires it by
	# relative path once the Bun global exists.
	${INSTALL_DATA} ${CLAWGOD_SHIM} \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/bun-ant-shim.cjs
	# Install the fix for directory links in path completion, which the
	# completers require by relative path (see scripts/post-extract).
	${INSTALL_DATA} ${FILESDIR}/follow-dir-links.cjs \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/follow-dir-links.cjs
	# Install wrapper script
	${INSTALL_SCRIPT} ${WRKDIR}/claude ${STAGEDIR}${PREFIX}/bin/claude

post-install:
	# Append content-hashed files dynamically so the plist stays version-agnostic.
	# Upstream renames these on every release as their contents change:
	#   code chunks  - _N.js (2.1.246-2.1.247) or chunk-*.js (other releases)
	#   skills, docs - <name>-<8 char hash>.md / .txt, and since 2.1.251 the
	#                  zstd-compressed .md.zst / .txt.zst that upstream is
	#                  migrating them to (both spellings ship side by side)
	#   helper ESM   - <name>-<8 char hash>.mjs, since 2.1.268. The .mjs files
	#                  with stable names (bin, cli, wrapper) stay in pkg-plist.
	#   helper Python - <name>-<8 char hash>.py, since 2.1.282, so far only in
	#                  the zstd spelling; both are matched, as for the docs.
	# Everything else upstream ships has a stable name and stays in pkg-plist,
	# where check-plist can still catch additions and removals.
	cd ${STAGEDIR}${PREFIX} && \
		${FIND} -s lib/node_modules/${PACKAGE_NAME} \
		\( -name '_*.js' -o -name 'chunk-*.js' \
		-o -name '*-????????.md' -o -name '*-????????.txt' \
		-o -name '*-????????.md.zst' -o -name '*-????????.txt.zst' \
		-o -name '*-????????.mjs' \
		-o -name '*-????????.py' -o -name '*-????????.py.zst' \) \
		>> ${TMPPLIST}

post-install-USE_CURL_USER_AGENT-on:
	# Patch the module that returns the Claude-User agent string to use curl's
	# User-Agent instead, so web fetches bypass bot-blocking filters (e.g. Anubis).
	# The function name and file differ across versions, so we search all JS files.
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME} -name '*.js' \
		-exec ${GREP} -l 'Claude-User' {} \; | \
		${XARGS} ${REINPLACE_CMD} \
		-e 's|return`Claude-User [^`]*`}|return"${CURL_USER_AGENT}"}|g'
	# REINPLACE_CMD leaves .bak copies behind; they are not packaged but would
	# otherwise litter the stage directory.
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME} \
		-name '*.bak' -delete

.include <bsd.port.mk>
