PORTNAME=	gitlab-pages
PORTVERSION=	1.48.0
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
GL_COMMIT=	f9d008b7e62b92d8843b0cb6a6a3ac46c338e456

# Build with: make gomod-vendor
# 53dd
GH_TUPLE=	\
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		census-instrumentation:opencensus-go:v0.22.2:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		client9:reopen:v1.0.0:client9_reopen/vendor/github.com/client9/reopen \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		getsentry:sentry-go:v0.7.0:getsentry_sentry_go/vendor/github.com/getsentry/sentry-go \
		go-yaml:yaml:a5ece683394c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang-jwt:jwt:v4.0.0:golang_jwt_jwt_v4/vendor/github.com/golang-jwt/jwt/v4 \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:215e87163ea7:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mock:v1.3.1:golang_mock/vendor/github.com/golang/mock \
		golang:net:c7110b5ffcbb:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:665e8c7367d1:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:time:9d24e82272b4:golang_time/vendor/golang.org/x/time \
		google:go-genproto:ca5a22157cba:google_go_genproto/vendor/google.golang.org/genproto \
		google:pprof:d4f498aebedc:google_pprof/vendor/github.com/google/pprof \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.15.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.50.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:handlers:v1.4.2:gorilla_handlers/vendor/github.com/gorilla/handlers \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:securecookie:v1.1.1:gorilla_securecookie/vendor/github.com/gorilla/securecookie \
		gorilla:sessions:v1.2.0:gorilla_sessions/vendor/github.com/gorilla/sessions \
		grpc:grpc-go:v1.24.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		karlseguin:ccache:v2.0.6:karlseguin_ccache_v2/vendor/github.com/karlseguin/ccache/v2 \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		namsral:flag:v1.7.4-pre:namsral_flag/vendor/github.com/namsral/flag \
		oklog:ulid:v2.0.2:oklog_ulid_v2/vendor/github.com/oklog/ulid/v2 \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pires:go-proxyproto:v0.2.0:pires_go_proxyproto/vendor/github.com/pires/go-proxyproto \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.6.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.9.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.11:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.21.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rs:cors:v1.7.0:rs_cors/vendor/github.com/rs/cors \
		sebest:xff:6c115e0ffa35:sebest_xff/vendor/github.com/sebest/xff \
		sirupsen:logrus:v1.7.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		tj:assert:v0.0.3:tj_assert/vendor/github.com/tj/assert \
		tj:go-redirects:5c02ead0bbc5:tj_go_redirects/vendor/github.com/tj/go-redirects

GL_TUPLE=	gitlab-org:go-mimedb:e7aae885685d3b4c73716eae321d8486e914ad74:gitlab_org_go_mimedb/vendor/gitlab.com/gitlab-org/go-mimedb \
		gitlab-org:labkit:949268af2aa8352c644cb1cbc63cf4112972d2c9:gitlab_org_labkit/vendor/gitlab.com/gitlab-org/labkit

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
