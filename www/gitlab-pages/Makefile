PORTNAME=	gitlab-pages
PORTVERSION=	1.49.0
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
GL_COMMIT=	f8512edbec4ec83b426c8ca2dda467de424685e4

# Build with: make gomod-vendor
# 56dd
GH_TUPLE=	\
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		census-instrumentation:opencensus-go:v0.23.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		client9:reopen:v1.0.0:client9_reopen/vendor/github.com/client9/reopen \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		getsentry:sentry-go:v0.11.0:getsentry_sentry_go/vendor/github.com/getsentry/sentry-go \
		go-yaml:yaml:a5ece683394c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang-jwt:jwt:v4.1.0:golang_jwt_jwt_v4/vendor/github.com/golang-jwt/jwt/v4 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mock:v1.6.0:golang_mock/vendor/github.com/golang/mock \
		golang:net:7fd8e65b6420:golang_net/vendor/golang.org/x/net \
		golang:oauth2:6f1e6394065a:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:e5e7981a1069:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		google:go-cmp:v0.5.6:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:db860fec028c:google_go_genproto/vendor/google.golang.org/genproto \
		google:pprof:f964ff605595:google_pprof/vendor/github.com/google/pprof \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.54.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.1.0:googleapis_google_cloud_go_profiler/vendor/cloud.google.com/go/profiler \
		googleapis:google-cloud-go:v0.92.2:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:handlers:v1.4.2:gorilla_handlers/vendor/github.com/gorilla/handlers \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:securecookie:v1.1.1:gorilla_securecookie/vendor/github.com/gorilla/securecookie \
		gorilla:sessions:v1.2.0:gorilla_sessions/vendor/github.com/gorilla/sessions \
		grpc:grpc-go:v1.40.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		karlseguin:ccache:v2.0.6:karlseguin_ccache_v2/vendor/github.com/karlseguin/ccache/v2 \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		namsral:flag:v1.7.4-pre:namsral_flag/vendor/github.com/namsral/flag \
		oklog:ulid:v2.0.2:oklog_ulid_v2/vendor/github.com/oklog/ulid/v2 \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pires:go-proxyproto:v0.2.0:pires_go_proxyproto/vendor/github.com/pires/go-proxyproto \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.11.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.26.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rs:cors:v1.7.0:rs_cors/vendor/github.com/rs/cors \
		sebest:xff:671bd2870b3a:sebest_xff/vendor/github.com/sebest/xff \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tj:assert:v0.0.3:tj_assert/vendor/github.com/tj/assert \
		tj:go-redirects:5c02ead0bbc5:tj_go_redirects/vendor/github.com/tj/go-redirects

GL_TUPLE=	gitlab-org:go-mimedb:e7aae885685d3b4c73716eae321d8486e914ad74:gitlab_org_go_mimedb/vendor/gitlab.com/gitlab-org/go-mimedb \
		gitlab-org:golang-archive-zip:84007c99e03b62ee4dc62a94048d6e59552299d7:gitlab_org_golang_archive_zip/vendor/gitlab.com/gitlab-org/golang-archive-zip \
		gitlab-org:labkit:10e2b43819e0ff8fcfd8be65262fecd03ab5cfbd:gitlab_org_labkit/vendor/gitlab.com/gitlab-org/labkit

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
