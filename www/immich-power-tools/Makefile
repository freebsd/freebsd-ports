PORTNAME=	immich-power-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	0.25.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://github.com/joneum/FreeBSD-Immich/releases/download/ipt-v${DISTVERSION}/:buildkit
DISTFILES=	immich-power-tools-freebsd-buildkit-${DISTVERSION}${EXTRACT_SUFX}:buildkit \
		immich-power-tools-mk-buildkit.sh:buildkit

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Tools for organizing and cleaning up an Immich library
WWW=		https://github.com/immich-power-tools/immich-power-tools

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	lang/bun is available for these architectures only

BUILD_DEPENDS=	bun:lang/bun

USES=		gmake nodejs:22,build,run python:build

USE_GITHUB=	yes
GH_ACCOUNT=	immich-power-tools

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		immich-power-tools-freebsd-buildkit-${DISTVERSION}${EXTRACT_SUFX}

USE_RC_SUBR=	immich_power_tools

USERS=		immich
GROUPS=		immich

DBDIR=		/var/db/${PORTNAME}

MAKE_ENV=	BUN_INSTALL_CACHE_DIR=${WRKDIR}/bun-cache \
		CI=1 \
		HOME=${WRKDIR} \
		PYTHON=${PYTHON_CMD} \
		npm_config_nodedir=${LOCALBASE}

_BUN=		${LOCALBASE}/bin/bun
_STANDALONE=	${WRKSRC}/.next/standalone/${WRKSRC:T}

SUB_FILES=	immich-power-tools immich-power-tools.env immich_power_tools \
		pkg-message
SUB_LIST=	DBDIR=${DBDIR} \
		NODE=${LOCALBASE}/bin/node

pre-build:
	${CP} ${WRKDIR}/bun.lock ${WRKSRC}/bun.lock
	${RM} ${WRKSRC}/bun.lockb

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${_BUN} install --offline --frozen-lockfile
	cd ${WRKSRC}/node_modules/better-sqlite3 && ${SETENV} ${MAKE_ENV} \
		${WRKSRC}/node_modules/.bin/node-gyp rebuild --release --nodedir=${LOCALBASE}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} VERSION=${DISTVERSION} \
		NEXT_TEST_WASM_DIR=${WRKSRC}/node_modules/@next/swc-wasm-nodejs \
		${_BUN} run build
	${MKDIR} ${_STANDALONE}/node_modules/better-sqlite3/build/Release \
		${_STANDALONE}/.next ${_STANDALONE}/public
	${CP} ${WRKSRC}/node_modules/better-sqlite3/build/Release/better_sqlite3.node \
		${_STANDALONE}/node_modules/better-sqlite3/build/Release
	cd ${WRKSRC}/.next && ${PAX} -rw static ${_STANDALONE}/.next
	cd ${WRKSRC}/public && ${PAX} -rw . ${_STANDALONE}/public
	cd ${WRKSRC}/src/db && ${PAX} -rw migrations ${_STANDALONE}/src/db

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${_STANDALONE} && ${PAX} -rw . ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/newsyslog-immich_power_tools.conf \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/immich_power_tools.conf
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.env \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.env.sample
	@${MKDIR} ${STAGEDIR}${DBDIR}

post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${WWWDIR_REL}/.next/server ${WWWDIR_REL}/.next/static \
		-type f | ${SORT} >> ${TMPPLIST}

.include <bsd.port.mk>
