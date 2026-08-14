PORTNAME=	code-server
DISTVERSION=	4.132.0
CATEGORIES=	www
MASTER_SITES=	https://github.com/joneum/FreeBSD-CodeServer/releases/download/code-server-${DISTVERSION}/:code_server \
		https://github.com/github/copilot-cli/releases/download/v${COPILOT_CLI_VERSION}/:copilot_cli
DISTFILES=	vscode-node-modules-${VSCODE_VERSION}${EXTRACT_SUFX}:code_server \
		vscode-reh-web-linux-x64-${DISTVERSION}${EXTRACT_SUFX}:code_server
.if !defined(BOOTSTRAP_NODE_MODULES)
DISTFILES+=	code-server-node-modules-${DISTVERSION}${EXTRACT_SUFX}:code_server
.endif
DISTFILES+=	github-copilot-${COPILOT_CLI_VERSION}-linux-x64.tgz:copilot_cli

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Run VS Code on a remote server and access it through a browser
WWW=		https://github.com/coder/code-server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

EXTRACT_DEPENDS=	jq:textproc/jq
BUILD_DEPENDS=	npm-node22>0:www/npm-node22 \
		bash:shells/bash \
		pkgconf:devel/pkgconf \
		rg:textproc/ripgrep \
		tgrep:textproc/tgrep
LIB_DEPENDS=	libinotify.so:devel/libinotify \
		libsecret-1.so:security/libsecret \
		libuv.so:devel/libuv \
		libxkbfile.so:x11/libxkbfile \
		libX11.so:x11/libX11
RUN_DEPENDS=	node:www/node22

# Only a linux-x64 (amd64) vscode-reh-web distfile is provided.
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	only the vscode-reh-web-linux-x64 distfile is provided

USES=		nodejs:22 perl5 pkgconfig python:build ssl

USE_GITHUB=	yes
GH_ACCOUNT=	coder
GH_PROJECT=	code-server
GH_TAGNAME=	v${DISTVERSION}
GH_TUPLE=	microsoft:vscode:${VSCODE_VERSION}:vscode

USE_RC_SUBR=	code-server

SUB_FILES=	code-server-wrapper

OPTIONS_DEFINE=	DOCS
PORTDOCS=	README.md

NO_CCACHE=	yes

VSCODE_VERSION=		1.132.0
# Copilot CLI SDK, only needed so the VS Code extension build passes.
# GitHub Copilot is closed-source and not usable on FreeBSD.
COPILOT_CLI_VERSION=	1.0.73

MAKE_ENV+=	NODE_OPTIONS=--max-old-space-size=6144 \
		ESBUILD_WORKER_THREADS=1

.include "${.CURDIR}/Makefile.vscode"
.include "${.CURDIR}/Makefile.build"
.include "${.CURDIR}/Makefile.install"

.include <bsd.port.mk>
