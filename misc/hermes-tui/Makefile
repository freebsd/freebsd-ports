PORTNAME=	hermes-tui
PORTVERSION=	${HERMES_VERSION}
CATEGORIES=	misc
MASTER_SITES=	LOCAL/olivier

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Terminal UI for the Hermes AI agent
WWW=		https://github.com/NousResearch/hermes-agent

LICENSE=	MIT

# The TUI talks to hermes-agent's tui_gateway, whose protocol moves with
# each release: pin to the same version.
RUN_DEPENDS=	hermes-agent>=${PORTVERSION}<${PORTVERSION}_99:misc/hermes-agent

USES=		nodejs:run

NO_ARCH=	yes
NO_BUILD=	yes

# hermes looks for a prebuilt TUI at hermes_cli/tui_dist/entry.js only;
# without one it tries an npm build inside the read-only install tree.
HERMES_TUIDIR=	${PREFIX}/lib/hermes-agent/hermes_cli/tui_dist

PLIST_FILES=	${HERMES_TUIDIR:S,^${PREFIX}/,,}/entry.js \
		${HERMES_TUIDIR:S,^${PREFIX}/,,}/hermes-build.json \
		${HERMES_TUIDIR:S,^${PREFIX}/,,}/package.json \
		${HERMES_TUIDIR:S,^${PREFIX}/,,}/scripts/clipboard_image.py \
		${HERMES_TUIDIR:S,^${PREFIX}/,,}/scripts/gateway_bootstrap.py

# Upstream ships no prebuilt TUI.  The distfile is the esbuild bundle of
# ui-tui/: pure JS (node builtins only), so NO_ARCH-safe.  Regenerate it on
# every bump from the hermes-agent source tarball (amd64, node 24+, npm 11.17+):
#
#   tar xzf ${DISTDIR}/NousResearch-hermes-agent-${PORTVERSION}-v${PORTVERSION}_GH0.tar.gz
#   cd hermes-agent-${PORTVERSION}
#   npm ci --ignore-scripts --no-audit --no-fund --engine-strict=false -w ui-tui
#   node scripts/build/tui.mjs --source . --out /tmp/tui
#   mkdir /tmp/${DISTNAME}
#   cp -a /tmp/tui/dist/. /tmp/tui/package.json /tmp/${DISTNAME}/
#   cd /tmp && tar --no-acls --no-xattrs --no-fflags --uid=0 --gid=0 \
#       -czf ${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}
#
# then upload to LOCAL/<committer> and make makesum.  The layout (dist/*
# plus package.json, which marks entry.js as an ES module) mirrors upstream's
# plant_surfaces() in scripts/build/agent.py.

do-install:
	${MKDIR} ${STAGEDIR}${HERMES_TUIDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${HERMES_TUIDIR}

.include "${.CURDIR}/../hermes-agent/Makefile.version"
.include <bsd.port.mk>
