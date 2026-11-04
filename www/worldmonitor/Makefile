PORTNAME=	worldmonitor
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.7
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Real-time global intelligence dashboard
WWW=		https://github.com/koala73/worldmonitor

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	the build kit contains prebuilt amd64 binaries

RUN_DEPENDS=	${LOCALBASE}/bin/redis-server:databases/redis \
		${LOCALBASE}/bin/curl:ftp/curl

USES=		cpe nodejs:24,build,run
CPE_VENDOR=	koala73
USE_GITHUB=	yes
GH_ACCOUNT=	koala73
USE_RC_SUBR=	worldmonitor worldmonitor_redis_rest worldmonitor_relay worldmonitor_seed
SUB_FILES=	pkg-message worldmonitor-seed

MASTER_SITES+=	https://github.com/joneum/FreeBSD-WorldMonitor/releases/download/${DISTVERSION}/:buildkit
DISTFILES+=	${PORTNAME}-buildkit-${DISTVERSION}.tar.xz:buildkit
DISTFILES+=	${PORTNAME}-redis-rest-${DISTVERSION}.tar.xz:buildkit
DISTFILES+=	${PORTNAME}-seed-${DISTVERSION}.tar.xz:buildkit

MAKE_ENV+=	HOME=${WRKDIR}

.if defined(WORLDMONITOR_CLERK_PUBLISHABLE_KEY)
MAKE_ENV+=	VITE_CLERK_PUBLISHABLE_KEY=${WORLDMONITOR_CLERK_PUBLISHABLE_KEY}
.endif

post-extract:
	${MV} ${WRKDIR}/node_modules ${WRKSRC}/node_modules
	${MV} ${WRKDIR}/pro-test/node_modules ${WRKSRC}/pro-test/node_modules

pre-build:
	cd ${WRKSRC} && ${LOCALBASE}/bin/node ${FILESDIR}/extract-eval-scripts.mjs scripts/seed-military-bases.mjs > docker/military-eval-scripts.json

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/node scripts/generate-inventory-facts.mjs
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/node docker/build-handlers.mjs
	cd ${WRKSRC}/pro-test && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/node node_modules/vite/bin/vite.js build
	cd ${WRKSRC}/pro-test && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/node prerender.mjs
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/node node_modules/@typescript/native/bin/tsc
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/node node_modules/vite/bin/vite.js build

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/shared
	cd ${WRKSRC}/dist && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/dist
	${RM} ${STAGEDIR}${WWWDIR}/dist/.well-known/mcp-registry-auth ${STAGEDIR}${WWWDIR}/dist/.well-known/openai-apps-challenge
	cd ${WRKSRC} && ${COPYTREE_SHARE} "api data" ${STAGEDIR}${WWWDIR}
	${FIND} ${STAGEDIR}${WWWDIR}/api \( -name "*.ts" -o -name "*.test.*" \) -delete
	${INSTALL_DATA} ${WRKSRC}/shared/llm-health-providers.js ${STAGEDIR}${WWWDIR}/shared
	${INSTALL_DATA} ${WRKSRC}/src-tauri/sidecar/local-api-server.mjs ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/src-tauri/sidecar/package.json ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/docker/validate-session-secret.mjs ${STAGEDIR}${WWWDIR}
	cd ${WRKDIR}/runtime-node_modules && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/node_modules
	@${MKDIR} ${STAGEDIR}${WWWDIR}/redis-rest
	${INSTALL_DATA} ${WRKSRC}/docker/redis-rest-proxy.mjs ${STAGEDIR}${WWWDIR}/redis-rest
	${INSTALL_DATA} ${WRKSRC}/docker/military-eval-scripts.json ${STAGEDIR}${WWWDIR}/redis-rest
	cd ${WRKDIR}/redis-rest-node_modules && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/redis-rest/node_modules
	@${MKDIR} ${STAGEDIR}${WWWDIR}/seed/api ${STAGEDIR}${WWWDIR}/seed/server
	cd ${WRKSRC} && ${COPYTREE_SHARE} "scripts shared data" ${STAGEDIR}${WWWDIR}/seed
	cd ${WRKSRC} && ${COPYTREE_SHARE} server/_shared ${STAGEDIR}${WWWDIR}/seed
	${FIND} ${STAGEDIR}${WWWDIR}/seed/scripts \( -name "*.test.*" -o -name ais-relay-test-preload.cjs -o -name generate-sandbox-fixtures.mjs \) -delete
	${RM} -r ${STAGEDIR}${WWWDIR}/seed/scripts/fixtures
	cd ${WRKSRC}/api && ${INSTALL_DATA} _seed-envelope.js _upstash-json.js ${STAGEDIR}${WWWDIR}/seed/api
	cd ${WRKDIR}/seed-node_modules && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/seed/node_modules
	${INSTALL_SCRIPT} ${WRKDIR}/worldmonitor-seed ${STAGEDIR}${WWWDIR}/seed
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}/var/db/worldmonitor
	${INSTALL_DATA} ${FILESDIR}/worldmonitor.env.sample ${STAGEDIR}${PREFIX}/etc
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/worldmonitor.newsyslog.conf ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/worldmonitor.conf
	${SED} -n '/^  server {/,/^  }$$/p' ${WRKSRC}/docker/nginx.conf | ${SED} \
		-e 's|\$${LOCAL_API_PORT}|46123|g' \
		-e 's|\$${LOCAL_API_TOKEN}|change-me-token|g' \
		-e 's|root [^;]*;|root ${WWWDIR}/dist;|' \
		> ${STAGEDIR}${EXAMPLESDIR}/nginx-server.conf

.include <bsd.port.mk>
