PORTNAME=	deltachat-desktop
DISTVERSIONPREFIX=	v
DISTVERSION=	2.43.0
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Cross-platform decentralized encrypted messaging service
WWW=		https://delta.chat/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

# Important to keep the RPC server core in sync with the Desktop release
RUN_DEPENDS=	deltachat-rpc-server>=2.43<2.44:net/deltachat-rpc-server
USES=		electron:40,build,run desktop-file-utils nodejs:22,build pkgconfig

USE_ELECTRON=	npm:pnpm prefetch extract
NPM_VER=	9.6.0

# Possible to support more arches, but need their binary
# esbuilds included in the npmcache
ONLY_FOR_ARCHS=	amd64

SUB_FILES+=	deltachat-desktop.sh deltachat.desktop
SUB_LIST+=	ELECTRON_VER=${ELECTRON_VER_MAJOR}

USE_GITHUB=	yes
GH_ACCOUNT=	deltachat
GH_PROJECT=	deltachat-desktop

MAKE_ENV+=	ELECTRON_SKIP_BINARY_DOWNLOAD=1 \
		VERSION_INFO_GIT_REF=${GH_TAGNAME}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/packages/target-electron/src/deltachat/controller.ts

do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${NPM_CMDNAME} -w --filter=@deltachat-desktop/target-electron build

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && node bin/writeFlatDependencies.js packages/target-electron ${STAGEDIR}${DATADIR}/node_modules

	# Shell for-loop to find first matching module at runtime
	# Sometimes there are multiple copies of this module and we just need one
	for mod in ${WRKSRC}/node_modules/.pnpm/@deltachat+stdio-rpc-server@*; do \
		STDIO_RPC_SERVER_MODULE="$$mod"; \
		break; \
	done && \
	cd $$STDIO_RPC_SERVER_MODULE/node_modules/ && \
		${COPYTREE_SHARE} @deltachat ${STAGEDIR}${DATADIR}/node_modules/

	cd ${WRKSRC}/packages/target-electron && \
		${INSTALL} package.json ${STAGEDIR}${DATADIR}/ && \
		${INSTALL} index.js ${STAGEDIR}${DATADIR}/ && \
		${COPYTREE_SHARE} bundle_out ${STAGEDIR}${DATADIR}/ && \
		${COPYTREE_SHARE} html-dist ${STAGEDIR}${DATADIR}/
	cd ${WRKSRC} && ${COPYTREE_SHARE} _locales ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/deltachat-desktop.sh ${STAGEDIR}${PREFIX}/bin/deltachat-desktop
	${INSTALL} ${WRKDIR}/deltachat.desktop ${STAGEDIR}${PREFIX}/share/applications/deltachat.desktop
	${MKDIR} ${STAGEDIR}${DATADIR}/icons
	${INSTALL} ${FILESDIR}/delta-v7-pathed.svg ${STAGEDIR}${DATADIR}/icons/deltachat.svg

.include <bsd.port.post.mk>
