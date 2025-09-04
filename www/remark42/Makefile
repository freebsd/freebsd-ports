PORTNAME=	remark42
DISTVERSIONPREFIX=	v
DISTVERSION=	1.14.0
PORTREVISION=	8
CATEGORIES=	www
MASTER_SITES=	LOCAL/delphij:npmcache
DISTFILES=	${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}:npmcache

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Privacy-focused lightweight commenting engine
WWW=		https://remark42.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS+=	npm-node20>0:www/npm-node20

USES=		cpe go:modules tar:xz

GO_BUILDFLAGS=	-ldflags "-s -w -X main.revision=${DISTVERSION}"
GO_TARGET=	app:${PREFIX}/libexec/${PORTNAME}
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}/backend
LD_FLAG_X_PREFIX=	-X ${GO_PKGNAME}/version

MAKE_ENV+=	npm_config_offline=true

USE_RC_SUBR=	${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	umputun

PLIST_FILES=	libexec/${PORTNAME}

GH_TUPLE=	\
		Depado:bfchroma:v2.0.0:depado_bfchroma_v2/vendor/github.com/Depado/bfchroma/v2 \
		PuerkitoBio:goquery:v1.9.2:puerkitobio_goquery/vendor/github.com/PuerkitoBio/goquery \
		ajg:form:v1.5.1:ajg_form/vendor/github.com/ajg/form \
		alecthomas:chroma:v2.13.0:alecthomas_chroma_v2/vendor/github.com/alecthomas/chroma/v2 \
		andybalholm:cascadia:v1.3.2:andybalholm_cascadia/vendor/github.com/andybalholm/cascadia \
		aymerick:douceur:v0.2.0:aymerick_douceur/vendor/github.com/aymerick/douceur \
		cespare:xxhash:v2.2.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dghubble:oauth1:v0.7.3:dghubble_oauth1/vendor/github.com/dghubble/oauth1 \
		dgryski:go-rendezvous:9f7001d12a5f:dgryski_go_rendezvous/vendor/github.com/dgryski/go-rendezvous \
		didip:tollbooth:v7.0.2:didip_tollbooth_v7/vendor/github.com/didip/tollbooth/v7 \
		didip:tollbooth_chi:d662a7f6928f:didip_tollbooth_chi/vendor/github.com/didip/tollbooth_chi \
		dlclark:regexp2:v1.11.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		etcd-io:bbolt:v1.3.10:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		go-chi:chi:v5.1.0:go_chi_chi_v5/vendor/github.com/go-chi/chi/v5 \
		go-chi:cors:v1.2.1:go_chi_cors/vendor/github.com/go-chi/cors \
		go-chi:render:v1.0.3:go_chi_render/vendor/github.com/go-chi/render \
		go-oauth2:oauth2:v4.5.2:go_oauth2_oauth2_v4/vendor/github.com/go-oauth2/oauth2/v4 \
		go-pkgz:auth:v1.24.2:go_pkgz_auth/vendor/github.com/go-pkgz/auth \
		go-pkgz:email:v0.5.0:go_pkgz_email/vendor/github.com/go-pkgz/email \
		go-pkgz:expirable-cache:v3.0.0:go_pkgz_expirable_cache_v3/vendor/github.com/go-pkgz/expirable-cache \
		go-pkgz:jrpc:v0.3.0:go_pkgz_jrpc/vendor/github.com/go-pkgz/jrpc \
		go-pkgz:lcw:v2.0.0:go_pkgz_lcw_v2/vendor/github.com/go-pkgz/lcw \
		go-pkgz:lgr:v0.11.1:go_pkgz_lgr/vendor/github.com/go-pkgz/lgr \
		go-pkgz:notify:v1.1.1:go_pkgz_notify/vendor/github.com/go-pkgz/notify \
		go-pkgz:repeater:v1.1.3:go_pkgz_repeater/vendor/github.com/go-pkgz/repeater \
		go-pkgz:rest:v1.19.0:go_pkgz_rest/vendor/github.com/go-pkgz/rest \
		go-pkgz:syncs:v1.3.2:go_pkgz_syncs/vendor/github.com/go-pkgz/syncs \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang-jwt:jwt:v3.2.2:golang_jwt_jwt/vendor/github.com/golang-jwt/jwt \
		golang:crypto:v0.25.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:image:v0.18.0:golang_image/vendor/golang.org/x/image \
		golang:net:v0.27.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.21.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:v0.7.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.22.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.16.0:golang_text/vendor/golang.org/x/text \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:google-cloud-go:v0.5.0:googleapis_google_cloud_go/vendor/cloud.google.com/go/compute/metadata \
		gorilla:css:v1.0.1:gorilla_css/vendor/github.com/gorilla/css \
		gorilla:feeds:v1.2.0:gorilla_feeds/vendor/github.com/gorilla/feeds \
		gorilla:websocket:v1.5.3:gorilla_websocket/vendor/github.com/gorilla/websocket \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:golang-lru:v2.0.7:hashicorp_golang_lru_v2/vendor/github.com/hashicorp/golang-lru/v2 \
		jessevdk:go-flags:v1.6.1:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		klauspost:compress:v1.17.9:klauspost_compress/vendor/github.com/klauspost/compress \
		kyokomi:emoji:v2.2.13:kyokomi_emoji_v2/vendor/github.com/kyokomi/emoji/v2 \
		microcosm-cc:bluemonday:v1.0.27:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mongodb:mongo-go-driver:v1.16.0:mongodb_mongo_go_driver/vendor/go.mongodb.org/mongo-driver \
		montanaflynn:stats:v0.7.1:montanaflynn_stats/vendor/github.com/montanaflynn/stats \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		redis:go-redis:v9.4.0:redis_go_redis_v9/vendor/github.com/redis/go-redis/v9 \
		rrivera:identicon:d5ba35832c0d:rrivera_identicon/vendor/github.com/rrivera/identicon \
		rs:xid:v1.5.0:rs_xid/vendor/github.com/rs/xid \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		skip2:go-qrcode:da1b6568686e:skip2_go_qrcode/vendor/github.com/skip2/go-qrcode \
		slack-go:slack:v0.12.5:slack_go_slack/vendor/github.com/slack-go/slack \
		stretchr:testify:v1.9.0:stretchr_testify/vendor/github.com/stretchr/testify \
		uber-go:goleak:v1.3.0:uber_go_goleak/vendor/go.uber.org/goleak \
		xdg-go:pbkdf2:v1.0.0:xdg_go_pbkdf2/vendor/github.com/xdg-go/pbkdf2 \
		xdg-go:scram:v1.1.2:xdg_go_scram/vendor/github.com/xdg-go/scram \
		xdg-go:stringprep:v1.0.4:xdg_go_stringprep/vendor/github.com/xdg-go/stringprep \
		youmark:pkcs8:a2c0da244d78:youmark_pkcs8/vendor/github.com/youmark/pkcs8

REMARK_PIDDIR=	/var/run/${PORTNAME}/
REMARK_USER?=	www
REMARK_DATADIR?=/var/db/${PORTNAME}

REMARK_URL?=	http://127.0.0.1:8080

USE_RC_SUBR=	remark

SUB_LIST+=	REMARK_PIDDIR=${REMARK_PIDDIR} \
		REMARK_USER=${REMARK_USER} \
		REMARK_DATADIR=${REMARK_DATADIR}

# (for maintainer) helper target to generate node_modules tarball
make-npm-cache: extract
	@cd ${WRKDIR} && ${RM} -r .npm
	@cd ${WRKSRC}/frontend/apps/${PORTNAME} \
		&& ${SETENV} HOME=${WRKDIR} npm install --force
	@cd ${WRKDIR} \
		&& ${TAR} -cJf ${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX} .npm \
			${PORTNAME}-${DISTVERSION}/frontend/apps/remark42/package-lock.json \
		&& ${ECHO} "Please upload the file ${WRKDIR}/${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}"

pre-build:
	cd ${WRKSRC}/frontend/apps/${PORTNAME} && ${SETENV} HOME=${WRKDIR} npm install --force --legacy-peer-deps
	cd ${WRKSRC}/frontend/apps/${PORTNAME} && ${SETENV} HOME=${WRKDIR} npm run build
	${RM} -r ${WRKSRC}/backend/app/cmd/web/
	${MV} ${WRKSRC}/frontend/apps/remark42/public ${WRKSRC}/backend/app/cmd/web
	${FIND} ${WRKSRC}/backend/app/cmd/web -type f \( -name '*.html' -or -name '*.js' -or -name '*.mjs' \) \
		-print -exec ${REINPLACE_CMD} -e "s|{% REMARK_URL %}|${REMARK_URL}|g" {} +

do-build:
	cd ${WRKSRC}/backend && ${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} build ${GO_BUILDFLAGS} \
		-o ${GO_WRKDIR_BIN}/${PORTNAME} ./app

.include <bsd.port.mk>
