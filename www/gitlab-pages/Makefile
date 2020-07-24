# $FreeBSD$

PORTNAME=	gitlab-pages
PORTVERSION=	1.21.0
CATEGORIES=	www

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Official GitLab Pages daemon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go:modules

USE_GITLAB=	yes
USE_GITHUB=	nodefault

GL_ACCOUNT=	gitlab-org
# Find the here: https://gitlab.com/gitlab-org/gitlab-pages/tags
GL_COMMIT=	e1310e9432b9cdf8ac33304e4385e0564c2f023d

# Build with: make gomod-vendor
# 55dd
GH_TUPLE=	\
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		census-instrumentation:opencensus-go:v0.22.2:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		client9:reopen:v1.0.0:client9_reopen/vendor/github.com/client9/reopen \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		fzipp:gocyclo:6acd4345c835:fzipp_gocyclo/vendor/github.com/fzipp/gocyclo \
		getsentry:sentry-go:v0.5.1:getsentry_sentry_go/vendor/github.com/getsentry/sentry-go \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:87dc89f01550:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:215e87163ea7:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:fdd1cda4f05f:golang_lint/vendor/golang.org/x/lint \
		golang:mock:v1.3.1:golang_mock/vendor/github.com/golang/mock \
		golang:mod:v0.2.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:0de0cce0169b:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:1957bb5e6d1f:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:tools:ed308ab3e770:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-genproto:ca5a22157cba:google_go_genproto/vendor/google.golang.org/genproto \
		google:pprof:d4f498aebedc:google_pprof/vendor/github.com/google/pprof \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.15.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.50.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:context:v1.1.1:gorilla_context/vendor/github.com/gorilla/context \
		gorilla:handlers:v1.4.2:gorilla_handlers/vendor/github.com/gorilla/handlers \
		gorilla:securecookie:v1.1.1:gorilla_securecookie/vendor/github.com/gorilla/securecookie \
		gorilla:sessions:v1.2.0:gorilla_sessions/vendor/github.com/gorilla/sessions \
		grpc:grpc-go:v1.24.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		kardianos:osext:2bc1f35cddc0:kardianos_osext/vendor/github.com/kardianos/osext \
		karrick:godirwalk:v1.10.12:karrick_godirwalk/vendor/github.com/karrick/godirwalk \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		namsral:flag:v1.7.4-pre:namsral_flag/vendor/github.com/namsral/flag \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.6.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.9.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.11:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.21.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rs:cors:v1.7.0:rs_cors/vendor/github.com/rs/cors \
		sebest:xff:6c115e0ffa35:sebest_xff/vendor/github.com/sebest/xff \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		stretchr:objx:v0.2.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.5.1:stretchr_testify/vendor/github.com/stretchr/testify \
		tomasen:realip:f0c99a92ddce:tomasen_realip/vendor/github.com/tomasen/realip \
		wadey:gocovmerge:b5bfa59ec0ad:wadey_gocovmerge/vendor/github.com/wadey/gocovmerge

GL_TUPLE=	gitlab-org:labkit:96e583c57891010df9b5b65d62bbae04e76c341e:gitlab_org_labkit/vendor/gitlab.com/gitlab-org/labkit \
		lupine:go-mimedb:e8af1d65987739a7ab277dedd9772c7398154ff3:lupine_go_mimedb/vendor/gitlab.com/lupine/go-mimedb

GO_BUILDFLAGS=	-ldflags="-X main.VERSION=${PORTVERSION} -X main.REVISION=${GITHASH}"
GO_PKGNAME=	gitlab.com/gitlab-org/gitlab-pages

PLIST_FILES=	bin/gitlab-pages

USE_RC_SUBR=	gitlab_pages

USERS=		gitlab-pages
GROUPS=		gitlab-pages

GO_BUILDFLAGS+=	--ldflags="-X main.VERSION=${PORTVERSION} -X main.REVISION=${GITHASH}"

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/gitlab-pages ${STAGEDIR}${PREFIX}/bin/gitlab-pages

.include <bsd.port.mk>
