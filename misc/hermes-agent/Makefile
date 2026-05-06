PORTNAME=	hermes-agent
PORTVERSION=	0.12.0
CATEGORIES=	misc python
MASTER_SITES+=	LOCAL/olivier:webcache
DISTFILES+=	${PORTNAME}-web-offline-cache-${PORTVERSION}${EXTRACT_SUFX}:webcache

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	AI agent with built-in learning loop
WWW=		https://github.com/NousResearch/hermes-agent

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	npm:www/npm
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anthropic>=0.39.0:misc/py-anthropic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}croniter>=6.0.0:sysutils/py-croniter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}edge-tts>=7.2.7:audio/py-edge-tts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}exa-py>=2.9.0:www/py-exa-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fal-client>=0.13.1:misc/py-fal-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi>=0.104.0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fire>=0.7.0:devel/py-fire@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}firecrawl-py>=4.16.0:www/py-firecrawl-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.5:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openai>=2.21.0:misc/py-openai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parallel-web>=0.4.2:www/py-parallel-web@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>=3.0.52:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.12.5:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.12.0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>0:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=1.2.1:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0.2:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.33.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=14.3.3:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}socksio>0:net/py-socksio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=9.1.4:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0.24.0:www/py-uvicorn@${PY_FLAVOR}

USES=		python:3.11+,run shebangfix nodejs:lts,build
USE_GITHUB=	yes
GH_ACCOUNT=	NousResearch
GH_PROJECT=	hermes-agent
GH_TAGNAME=	v2026.4.30

USE_RC_SUBR=	hermes_dashboard hermes_gateway

SUB_FILES=	pkg-message

NO_ARCH=	yes

# Hermes is an application, not a Python library.  Upstream's Dockerfile,
# Nix flake, and Homebrew formula all install it into a private directory
# (/opt/hermes, the Nix store, libexec/ respectively) rather than into
# site-packages, because the project ships top-level packages with generic
# names (tools, agent, gateway, plugins, ...) and bare modules (cli.py,
# utils.py, ...) that would collide with other Python packages.  We follow
# the same convention: install the source tree under HERMES_LIBDIR and
# create thin wrapper scripts in ${PREFIX}/bin that inject HERMES_LIBDIR
# into sys.path before calling each entry point.
HERMES_LIBDIR=	${PREFIX}/lib/${PORTNAME}

PLIST_SUB+=	HERMES_LIBDIR=${HERMES_LIBDIR:S,^${PREFIX}/,,}

# Web dashboard SPA (Vite/React) — upstream's release tarball does NOT ship
# a prebuilt web_dist/, only the source under web/.  We bring our own npm
# offline mirror as a second distfile (LOCAL/<committer>:webcache) and run
# `npm ci --offline && npm run build` in do-build to produce
# hermes_cli/web_dist/, which the dashboard serves at runtime
# (web_server.py defaults to ${HERMES_LIBDIR}/hermes_cli/web_dist).
#
# How to (re)generate hermes-agent-web-offline-cache-${PORTVERSION}.tar.gz
# on every PORTVERSION bump (run on a connected host with npm 10+ installed):
#
#   1. Extract the upstream source tarball:
#        tar xzf ${DISTDIR}/NousResearch-hermes-agent-${PORTVERSION}-${GH_TAGNAME}_GH0.tar.gz
#        cd hermes-agent-*/web
#   2. Populate a fresh npm cache from web/package-lock.json:
#        rm -rf /tmp/hermes-cache && mkdir -p /tmp/hermes-cache
#        HOME=/tmp npm_config_cache=/tmp/hermes-cache \
#            npm ci --no-audit --no-fund --prefer-offline
#   3. Strip non-deterministic bits (logs, last-checked stamps):
#        rm -rf /tmp/hermes-cache/_logs /tmp/hermes-cache/_update-notifier-last-checked
#   4. Repackage with a top-level dir whose name matches the distfile:
#        mv /tmp/hermes-cache /tmp/${PORTNAME}-web-offline-cache-${PORTVERSION}
#        cd /tmp && tar --no-acls --no-xattrs --no-fflags --uid=0 --gid=0 \
#            -czf ${PORTNAME}-web-offline-cache-${PORTVERSION}.tar.gz \
#            ${PORTNAME}-web-offline-cache-${PORTVERSION}
#   5. Upload to LOCAL/<committer>'s distcache directory and drop a copy
#      into ${DISTDIR} so `make makesum` picks it up locally.
#   6. cd ${.CURDIR} && make makesum
#
# `npm ci --offline` in do-build refuses any registry call, so a missing
# entry in the mirror fails fast instead of silently going to the network.
# npm reads cacache content from ${npm_config_cache}/_cacache.  Point
# npm_config_cache at the *parent* of the _cacache/ tree we shipped — if
# you point it at _cacache/ directly, npm appends _cacache/ a second time
# and silently sees an empty cache (Index entries: 0), then fails every
# install with ENOTCACHED.
WEB_CACHE_DIR=	${WRKDIR}/${PORTNAME}-web-offline-cache-${PORTVERSION}
WEB_NPM_ENV=	HOME=${WRKDIR} \
		npm_config_cache=${WEB_CACHE_DIR} \
		npm_config_update_notifier=false \
		npm_config_audit=false \
		npm_config_fund=false

# Python packages and bare modules that constitute the runtime app.
HERMES_PKGS=	acp_adapter agent cron gateway hermes_cli plugins tools tui_gateway
HERMES_MODS=	batch_runner.py cli.py hermes_constants.py hermes_logging.py \
		hermes_state.py hermes_time.py model_tools.py rl_cli.py \
		run_agent.py toolset_distributions.py toolsets.py \
		trajectory_compressor.py utils.py

SHEBANG_FILES=	${HERMES_MODS}

PORTDOCS=	README.md SECURITY.md CONTRIBUTING.md AGENTS.md
OPTIONS_DEFINE=	DOCS

PLIST_FILES=	"@(,,0755) bin/hermes" \
		"@(,,0755) bin/hermes-agent" \
		"@(,,0755) bin/hermes-acp"

# Build the web dashboard SPA from the offline npm mirror.  npm reads its
# package cache from npm_config_cache; --offline forbids any network call
# so a missing dep fails fast instead of silently going to the registry.
# The vite config writes the bundle to ../hermes_cli/web_dist (relative to
# web/), which is then picked up by do-install below.
do-build:
	cd ${WRKSRC}/web && \
		${SETENV} ${WEB_NPM_ENV} \
		npm ci --offline --no-audit --no-fund
	cd ${WRKSRC}/web && \
		${SETENV} ${WEB_NPM_ENV} \
		npm run build

do-install:
	${MKDIR} ${STAGEDIR}${HERMES_LIBDIR}
.for d in ${HERMES_PKGS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${HERMES_LIBDIR} \
		"! -name __pycache__ ! -name *.pyc"
.endfor
.for f in ${HERMES_MODS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${HERMES_LIBDIR}
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${SED} -e 's|%%HERMES_LIBDIR%%|${HERMES_LIBDIR}|g' \
		-e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|g' \
		-e 's|%%ENTRY_MODULE%%|hermes_cli.main|g' \
		-e 's|%%ENTRY_FUNC%%|main|g' \
		${FILESDIR}/wrapper.in > ${STAGEDIR}${PREFIX}/bin/hermes
	${SED} -e 's|%%HERMES_LIBDIR%%|${HERMES_LIBDIR}|g' \
		-e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|g' \
		-e 's|%%ENTRY_MODULE%%|run_agent|g' \
		-e 's|%%ENTRY_FUNC%%|main|g' \
		${FILESDIR}/wrapper.in > ${STAGEDIR}${PREFIX}/bin/hermes-agent
	${SED} -e 's|%%HERMES_LIBDIR%%|${HERMES_LIBDIR}|g' \
		-e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|g' \
		-e 's|%%ENTRY_MODULE%%|acp_adapter.entry|g' \
		-e 's|%%ENTRY_FUNC%%|main|g' \
		${FILESDIR}/wrapper.in > ${STAGEDIR}${PREFIX}/bin/hermes-acp
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} skills ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} optional-skills ${STAGEDIR}${DATADIR}

# Walk the staged HERMES_LIBDIR and DATADIR trees and append every file
# (and every directory we created) to the plist.  This avoids hand-
# maintaining a 500-line pkg-plist for skill templates that change every
# release.
post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${HERMES_LIBDIR:S,^${PREFIX}/,,} ${DATADIR:S,^${PREFIX}/,,} \
			-type f >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${HERMES_LIBDIR:S,^${PREFIX}/,,} ${DATADIR:S,^${PREFIX}/,,} \
			-type d -mindepth 1 | ${SORT} -r | \
			${SED} 's|^|@dir |' >> ${TMPPLIST}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
