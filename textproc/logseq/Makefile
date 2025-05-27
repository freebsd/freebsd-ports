PORTNAME=	logseq
PORTVERSION=	0.10.13
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/logseq/logseq/releases/download/${PORTVERSION}/ \
		LOCAL/arrowd/:node_modules
DISTFILES=	Logseq-linux-x64-${PORTVERSION}${EXTRACT_SUFX} \
		logseq/rsapi-${RSAPI_HASH}.freebsd-x64.node${EXTRACT_SUFX}:node_modules \
		logseq/better-sqlite-${BETTER_SQLITE_VERSION}.node${EXTRACT_SUFX}:node_modules

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Open-source platform for knowledge management and collaboration
WWW=		https://logseq.com

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	git:devel/git

USES=		desktop-file-utils electronfix:34 shared-mime-info zip

ELECTRONFIX_MAIN_EXECUTABLE=	Logseq
SUB_FILES=	Logseq
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/Logseq-linux-x64

RSAPI_HASH=	0162b98aaec78aa991cdbca2e070816c6acd189a
# Taken from https://github.com/search?q=repo%3Alogseq%2Flogseq%20better-sqlite&type=code
BETTER_SQLITE_VERSION=	11.10.0
ELECTRON_VERSION=	34.5.6

post-patch:
	${RM} ${WRKSRC}/resources/app/node_modules/@logseq/rsapi-linux-x64-gnu/package.json.orig

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/Logseq ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${PATCHDIR}/Logseq.desktop ${STAGEDIR}${DESKTOPDIR}/Logseq.desktop
	${INSTALL_DATA} ${WRKSRC}/resources/app/icon.png ${STAGEDIR}${PREFIX}/share/pixmaps/Logseq.png
	${FIND} ${STAGEDIR}${DATADIR} -type d -empty -delete
	${MV} ${STAGEDIR}${DATADIR}/resources/app/node_modules/@logseq/rsapi-linux-x64-gnu \
		${STAGEDIR}${DATADIR}/resources/app/node_modules/@logseq/rsapi-freebsd-x64
	${RM} ${STAGEDIR}${DATADIR}/resources/app/node_modules/@logseq/rsapi-freebsd-x64/rsapi.linux-x64-gnu.node
	${INSTALL_PROGRAM} ${WRKDIR}/rsapi.freebsd-x64.node ${STAGEDIR}${DATADIR}/resources/app/node_modules/@logseq/rsapi-freebsd-x64
	${RM} -r ${STAGEDIR}${DATADIR}/resources/app/node_modules/better-sqlite3/bin
	${RM} -r ${STAGEDIR}${DATADIR}/resources/app/node_modules/better-sqlite3/build/Release
	${INSTALL_PROGRAM} ${WRKDIR}/better_sqlite3.node ${STAGEDIR}${DATADIR}/resources/app/node_modules/better-sqlite3/build
	${RM} -r ${STAGEDIR}${DATADIR}/resources/app/node_modules/dugite/git

repackage-node-modules:
	pkg info curl git yarn npm zip > /dev/null
	${MKDIR} /tmp/logseq/
	curl https://sh.rustup.rs -sSf --output ${WRKDIR}/rustup.sh
	${SETENV} HOME=${WRKDIR}/home \
		sh ${WRKDIR}/rustup.sh -y --profile minimal --default-toolchain stable

	git clone https://github.com/logseq/rsapi.git ${WRKDIR}/rsapi-git
	cd ${WRKDIR}/rsapi-git && git checkout ${RSAPI_HASH}
	cd ${WRKDIR}/rsapi-git && ${SETENV} HOME=${WRKDIR}/home PATH=${PATH}:${WRKDIR}/home/.cargo/bin \
		yarn install --immutable --mode=skip-build
	cd ${WRKDIR}/rsapi-git && ${SETENV} HOME=${WRKDIR}/home PATH=${PATH}:${WRKDIR}/home/.cargo/bin \
		yarn build
	${STRIP_CMD} ${WRKDIR}/rsapi-git/packages/rsapi/rsapi.freebsd-x64.node
	cd ${WRKDIR}/rsapi-git/packages/rsapi && zip /tmp/logseq/rsapi-${RSAPI_HASH}.freebsd-x64.node.zip rsapi.freebsd-x64.node

	git clone https://github.com/WiseLibs/better-sqlite3.git ${WRKDIR}/better-sqlite
	cd ${WRKDIR}/better-sqlite && git checkout v${BETTER_SQLITE_VERSION}
	${SED} -i.bak -e 's|node-gyp rebuild|node-gyp rebuild --arch=x64 --dist-url=https://electronjs.org/headers --target=${ELECTRON_VERSION}|g' \
		${WRKDIR}/better-sqlite/package.json
	cd ${WRKDIR}/better-sqlite && ${SETENV} HOME=${WRKDIR}/home \
		npm install --ignore-scripts
	cd ${WRKDIR}/better-sqlite && ${SETENV} HOME=${WRKDIR}/home \
		npm run build-release
	${STRIP_CMD} ${WRKDIR}/better-sqlite/build/Release/better_sqlite3.node
	cd ${WRKDIR}/better-sqlite/build/Release && zip /tmp/logseq/better-sqlite-${BETTER_SQLITE_VERSION}.node.zip better_sqlite3.node

	@cd /tmp \
		&& sha256 logseq/rsapi-${RSAPI_HASH}.freebsd-x64.node.zip \
		&& ${ECHO_CMD} -n "SIZE (logseq/rsapi-${RSAPI_HASH}.freebsd-x64.node.zip) = " \
		&& ${STAT} -f %z /tmp/logseq/rsapi-${RSAPI_HASH}.freebsd-x64.node.zip \
		&& sha256 logseq/better-sqlite-${BETTER_SQLITE_VERSION}.node.zip \
		&& ${ECHO_CMD} -n "SIZE (logseq/better-sqlite-${BETTER_SQLITE_VERSION}.node.zip) = " \
		&& ${STAT} -f %z /tmp/logseq/better-sqlite-${BETTER_SQLITE_VERSION}.node.zip
	@${ECHO_CMD}

.include <bsd.port.mk>
