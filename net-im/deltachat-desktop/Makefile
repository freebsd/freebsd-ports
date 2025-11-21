PORTNAME=	deltachat-desktop
DISTVERSIONPREFIX=	v
DISTVERSION=	2.25.3
PORTREVISION=	0
CATEGORIES=	net-im
MASTER_SITES+=	LOCAL/feld:npmcache
DISTFILES+=	${PORTNAME}-${DISTVERSIONPREFIX}2.25.1-node-deps.tgz:npmcache

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Cross-platform decentralized encrypted messaging service
WWW=		https://delta.chat/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ELECTRON_VER=	37

# Important to keep the RPC server core in sync with the Desktop release
RUN_DEPENDS=	deltachat-rpc-server>=2.25<2.26:net/deltachat-rpc-server
BUILD_DEPENDS=	electron${ELECTRON_VER}:devel/electron${ELECTRON_VER} \
		npm:www/npm${NODEJS_SUFFIX}
USES=		desktop-file-utils nodejs:22,build pkgconfig

# Possible to support more arches, but need their binary
# esbuilds included in the npmcache
ONLY_FOR_ARCHS=	amd64

SUB_FILES+=	deltachat-desktop.sh deltachat.desktop
SUB_LIST+=	ELECTRON_VER=${ELECTRON_VER}

USE_GITHUB=	yes
GH_ACCOUNT=	deltachat
GH_PROJECT=	deltachat-desktop

MAKE_ENV+=	ELECTRON_SKIP_BINARY_DOWNLOAD=1 \
		ELECTRON_OVERRIDE_DIST_PATH=${LOCALBASE}/share/electron${ELECTRON_VER} \
		PATH=${PATH}:${WRKSRC}/node_modules/.bin/ \
		VERSION_INFO_GIT_REF=${GH_TAGNAME}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/packages/target-electron/src/deltachat/controller.ts
	# Have to mv, it won't build with symlinks
	@${MV} ${WRKDIR}/node_modules ${WRKSRC}/node_modules
	@${MV} ${WRKDIR}/packages/target-electron/node_modules ${WRKSRC}/packages/target-electron/node_modules
	@${MV} ${WRKDIR}/packages/frontend/node_modules ${WRKSRC}/packages/frontend/node_modules
	@${MV} ${WRKDIR}/packages/runtime/node_modules ${WRKSRC}/packages/runtime/node_modules
	@${MV} ${WRKDIR}/packages/shared/node_modules ${WRKSRC}/packages/shared/node_modules

do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} pnpm -w --filter=@deltachat-desktop/target-electron build

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && node bin/writeFlatDependencies.js packages/target-electron ${STAGEDIR}${DATADIR}/node_modules
	cd ${WRKSRC}/node_modules/.pnpm/@deltachat+stdio-rpc-server@*/node_modules/@deltachat/ && \
		${COPYTREE_SHARE} stdio-rpc-server/ ${STAGEDIR}${DATADIR}/node_modules/@deltachat/
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
