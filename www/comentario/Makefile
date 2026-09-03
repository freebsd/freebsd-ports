PORTNAME=	comentario
DISTVERSIONPREFIX=	v
DISTVERSION=	3.18.0
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Self-hosted comment engine for websites
WWW=		https://comentario.app/ \
		https://gitlab.com/comentario/comentario

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Frontend build dependencies include amd64-only native modules

BUILD_DEPENDS=	openapi-generator:devel/openapi-generator \
		swagger:devel/goswagger

USES=		go:1.26+,modules nodejs:24,build npm:yarn4
USE_GITLAB=	yes

USE_RC_SUBR=	comentario

GO_MOD_DIST=	gitlab
GO_MODULE=	gitlab.com/comentario/comentario
GO_BUILDFLAGS+=	-ldflags="-s -w -X main.version=${DISTVERSION} -X main.date=${_BUILD_DATE}"

NPM_CACHE_SETUP_CMD=	${SH} -c \
			"${NPM_CMDNAME} config set nodeLinker node-modules; ${NPM_CMDNAME} config set enableGlobalCache false; ${NPM_CMDNAME} config set cacheFolder './${NPM_MODULE_CACHE}'"
NPM_PREFETCH_ARCHS=	amd64

_BUILD_DATE=	$$(date -ur $$(${AWK} '/^TIMESTAMP/ {print $$3}' ${DISTINFO_FILE}) '+%FT%TZ')
_SWAG_MOD=	github.com/go-openapi/swag@v0.23.0

SUB_FILES=	pkg-message
SUB_LIST=	COMENTARIO_DBDIR=/var/db/${PORTNAME} \
		COMENTARIO_GROUP=${GROUPS} \
		COMENTARIO_USER=${USERS}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_FILES=	"@dir(${USERS},${GROUPS},0700) /var/db/${PORTNAME}" \
		"@sample(root,${GROUPS},0640) ${ETCDIR_REL}/secrets.yaml.sample" \
		"@sample ${ETCDIR_REL}/comentario.conf.sample" \
		bin/${PORTNAME}
PORTDATA=	*

# go.mk's "go mod tidy" runs before swagger-generated sources exist and
# rewrites go.mod.  Restore the distfile copies before generate/vendor.
# Generated restapi still imports the unsplit github.com/go-openapi/swag
# module, which is not in upstream go.mod.
_RESTORE_GOMOD=	${CP} ${DISTDIR}/${DIST_SUBDIR}/go.mod ${WRKSRC}/go.mod && \
		${TAR} -xOf ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}.tar.bz2 \
		${DISTNAME}/go.sum > ${WRKSRC}/go.sum

post-fetch:
	@${ECHO_MSG} "===> Fetching ${_SWAG_MOD}"
	@${RM} -r ${WRKDIR}/.swagfetch
	@${MKDIR} ${WRKDIR}/.swagfetch
	@cd ${WRKDIR}/.swagfetch && ${SETENVI} ${WRK_ENV} ${GO_ENV} \
		GOPROXY=${GO_GOPROXY} ${GO_CMD} mod init tmp
	@cd ${WRKDIR}/.swagfetch && ${SETENVI} ${WRK_ENV} \
		${HTTP_PROXY:DHTTP_PROXY=${HTTP_PROXY:Q}} \
		${http_proxy:Dhttp_proxy=${http_proxy:Q}} \
		${HTTPS_PROXY:DHTTPS_PROXY=${HTTPS_PROXY:Q}} \
		${https_proxy:Dhttps_proxy=${https_proxy:Q}} \
		${NO_PROXY:DNO_PROXY=${NO_PROXY:Q}} \
		${no_proxy:Dno_proxy=${no_proxy:Q}} \
		${GO_ENV} \
		GOPROXY=${GO_GOPROXY} \
		${GO_CMD} get ${_SWAG_MOD}

pre-build:
	@${ECHO_MSG} "===>  Generating frontend API client"
	@${RM} -r ${WRKSRC}/frontend/generated-api
	@openapi-generator generate \
		--additional-properties=ngVersion=22.1.0 \
		-i ${WRKSRC}/resources/swagger/swagger.yml \
		-g typescript-angular \
		-o ${WRKSRC}/frontend/generated-api
	@${ECHO_MSG} "===>  Building frontend"
	@${RM} -r ${WRKSRC}/frontend/.angular ${WRKSRC}/.angular
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} HOME=${WRKDIR} \
		${NPM_CMDNAME} workspace comentario-frontend run build:prod
	@${ECHO_MSG} "===>  Building embed widget"
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} HOME=${WRKDIR} \
		${NPM_CMDNAME} workspace comentario-embed run build:prod
	@${ECHO_MSG} "===>  Generating backend API"
	@${_RESTORE_GOMOD}
	@cd ${GO_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off \
		GOSUMDB=off GOFLAGS="-mod=mod -modcacherw" ${GO_CMD} generate
	@cd ${GO_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} \
		GOPATH=${WRKDIR}/.gopath GOPROXY=${GO_MODCACHE} GOSUMDB=off \
		GOFLAGS="-mod=mod -modcacherw" \
		${GO_CMD} get ${_SWAG_MOD}
	@cd ${GO_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} \
		GOPATH=${WRKDIR}/.gopath GOPROXY=${GO_MODCACHE} GOSUMDB=off \
		${GO_CMD} mod vendor

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR} \
		${STAGEDIR}${ETCDIR} \
		${STAGEDIR}/var/db/${PORTNAME}
	(cd ${WRKSRC}/build/frontend && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${SED} -e 's|^PORT=80$$|PORT=8080|' \
		-e 's|^STATIC_PATH=/usr/lib/comentario/frontend|STATIC_PATH=${DATADIR}|' \
		-e 's|^SECRETS_FILE=/etc/comentario/secrets.yaml|SECRETS_FILE=${ETCDIR}/secrets.yaml|' \
		${WRKSRC}/resources/etc/comentario/comentario.conf \
		> ${WRKDIR}/comentario.conf.sample
	${SED} -e 's|/var/lib/comentario/comentario.sqlite3|/var/db/${PORTNAME}/comentario.sqlite3|' \
		${WRKSRC}/resources/etc/comentario/secrets.yaml \
		> ${WRKDIR}/secrets.yaml.sample
	${INSTALL_DATA} ${WRKDIR}/comentario.conf.sample \
		${WRKDIR}/secrets.yaml.sample ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
