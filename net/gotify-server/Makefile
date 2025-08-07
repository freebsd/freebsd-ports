PORTNAME=	gotify-server
PORTVERSION=	2.6.3
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	https://github.com/mfechner/freebsd-net-gotify-server/raw/refs/heads/main/:yarn_cache
DISTNAME=	server
DISTFILES=	${PORTNAME}-yarn-offline-cache-${DISTVERSION}${EXTRACT_SUFX}:yarn_cache

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Simple server for sending and receiving messages
WWW=		https://github.com/gotify/server

LICENSE=	MIT

BROKEN_i386=	Build does not succeed (timeout in poudriere)

BUILD_DEPENDS=	yarn${NODEJS_SUFFIX}>=1.10.0:www/yarn${NODEJS_SUFFIX} \
		
USES=		go:modules,1.24 nodejs:build
USE_RC_SUBR=	gotify_server
GO_MODULE=	github.com/gotify/server/v2

_BUILD_DATE=	$$(date -u "+%Y-%m-%d-%H%M UTC")
#GO_TARGET=     ./
GO_BUILDFLAGS=	-buildmode=pie -modcacherw \
		-ldflags=" \
		-X 'main.Version=${PORTVERSION}' \
		-X 'main.Commit=${GL_TAGNAME:C/^(........).*/\1/}' \
		-X 'main.BuildDate=${_BUILD_DATE}' \
		-X 'main.Mode=prod'"

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400000
MAKE_ENV+=	 NODE_OPTIONS=--openssl-legacy-provider
.endif

USERS=		gotify
GROUPS=		gotify

PLIST_FILES=	bin/gotify-server

post-patch:
	# setup yarnrc for offline node_modules installatio
	@${ECHO_CMD} 'yarn-offline-mirror "${WRKDIR}/yarn-offline-cache"' >> ${WRKSRC}/ui/.yarnrc
	
pre-build:
	@cd ${WRKSRC}/ui && ${SETENV} ${MAKE_ENV} HOME=${WRKDIR} PUPPETEER_SKIP_CHROMIUM_DOWNLOAD=true yarn install --offline
	@cd ${WRKSRC}/ui && ${SETENV} ${MAKE_ENV} yarn build
	#${RM} -r ${STAGEDIR}${PREFIX}/share/.cache

pre-install:
	@${RM} ${WRKSRC}/.yarnrc

do-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/bin/gotify-server ${STAGEDIR}${PREFIX}/bin/gotify-server
	@${MV} ${WRKSRC}/config.example.yml ${WRKSRC}/config.yml.sample
	@${MKDIR} ${STAGEDIR}${ETCDIR}
.for x in config.yml.sample
	@${CP} ${WRKSRC}/${x} ${STAGEDIR}${ETCDIR}/${x}
.endfor
	@${MKDIR} ${STAGEDIR}/var/db/gotify

post-install:
	@${ECHO} "@sample ${ETCDIR}/config.yml.sample" >> ${TMPPLIST}
	@${ECHO_CMD} "@owner gotify" >> ${TMPPLIST}
	@${ECHO_CMD} "@group gotify" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir /var/db/gotify" >> ${TMPPLIST}
	#@${ECHO_CMD} "@dir /var/db/gotify/certs" >> ${TMPPLIST}

# To update
# 1. comment DISTFILES
# 2. Run 'make makesum'
# 3. Run 'make make-yarn-cache'
# 4. Upload yarn cache
# 5. Uncomment DITSFILES
# 6. Run 'make makesum'

make-yarn-cache: patch
	${RM} -r ${WRKDIR}/yarn-offline-cache
	cd ${WRKSRC}/ui && ${SETENV} ${MAKE_ENV} PUPPETEER_SKIP_CHROMIUM_DOWNLOAD=true yarn --frozen-lockfile --ignore-scripts
	cd ${WRKDIR} && ${TAR} -czf ${PORTNAME}-yarn-offline-cache-${DISTVERSION}${EXTRACT_SUFX} yarn-offline-cache
	@${ECHO_CMD} upload ${PORTNAME}-yarn-offline-cache-${DISTVERSION}${EXTRACT_SUFX}

.include <bsd.port.post.mk>
