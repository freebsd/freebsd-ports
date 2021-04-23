PORTNAME=	gitlab-pages
PORTVERSION=	1.38.0
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
GL_COMMIT=	2d16a14c3b1096fbaf0b4c36ea66b8b8b97ade63

# Build with: make gomod-vendor
# 133dd
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Djarvur:go-err113:af658d038157:djarvur_go_err113/vendor/github.com/Djarvur/go-err113 \
		OpenPeeDeeP:depguard:v1.0.1:openpeedeep_depguard/vendor/github.com/OpenPeeDeeP/depguard \
		andybalholm:brotli:v1.0.1:andybalholm_brotli/vendor/github.com/andybalholm/brotli \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bombsimon:wsl:v3.0.0:bombsimon_wsl_v3/vendor/github.com/bombsimon/wsl/v3 \
		cenkalti:backoff:v4.0.2:cenkalti_backoff_v4/vendor/github.com/cenkalti/backoff/v4 \
		census-instrumentation:opencensus-go:v0.22.2:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		client9:reopen:v1.0.0:client9_reopen/vendor/github.com/client9/reopen \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dominikh:go-tools:v0.0.1-2020.1.3:dominikh_go_tools/vendor/honnef.co/go/tools \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		getsentry:sentry-go:v0.7.0:getsentry_sentry_go/vendor/github.com/getsentry/sentry-go \
		go-critic:go-critic:v0.4.1:go_critic_go_critic/vendor/github.com/go-critic/go-critic \
		go-ini:ini:v1.51.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-lintpack:lintpack:v0.5.2:go_lintpack_lintpack/vendor/github.com/go-lintpack/lintpack \
		go-toolsmith:astcast:v1.0.0:go_toolsmith_astcast/vendor/github.com/go-toolsmith/astcast \
		go-toolsmith:astcopy:v1.0.0:go_toolsmith_astcopy/vendor/github.com/go-toolsmith/astcopy \
		go-toolsmith:astequal:v1.0.0:go_toolsmith_astequal/vendor/github.com/go-toolsmith/astequal \
		go-toolsmith:astfmt:v1.0.0:go_toolsmith_astfmt/vendor/github.com/go-toolsmith/astfmt \
		go-toolsmith:astp:v1.0.0:go_toolsmith_astp/vendor/github.com/go-toolsmith/astp \
		go-toolsmith:strparse:v1.0.0:go_toolsmith_strparse/vendor/github.com/go-toolsmith/strparse \
		go-toolsmith:typep:v1.0.0:go_toolsmith_typep/vendor/github.com/go-toolsmith/typep \
		go-yaml:yaml:a5ece683394c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		gofrs:flock:5135e617513b:gofrs_flock/vendor/github.com/gofrs/flock \
		gogo:protobuf:v1.2.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:215e87163ea7:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mock:v1.3.1:golang_mock/vendor/github.com/golang/mock \
		golang:mod:v0.3.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:c7110b5ffcbb:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:b64e53b001e4:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.1.0:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		golangci:check:cfe4005ccda2:golangci_check/vendor/github.com/golangci/check \
		golangci:dupl:3e9179ac440a:golangci_dupl/vendor/github.com/golangci/dupl \
		golangci:errcheck:ef45e06d44b6:golangci_errcheck/vendor/github.com/golangci/errcheck \
		golangci:go-misc:927a3d87b613:golangci_go_misc/vendor/github.com/golangci/go-misc \
		golangci:goconst:041c5f2b40f3:golangci_goconst/vendor/github.com/golangci/goconst \
		golangci:gocyclo:2becd97e67ee:golangci_gocyclo/vendor/github.com/golangci/gocyclo \
		golangci:gofmt:244bba706f1a:golangci_gofmt/vendor/github.com/golangci/gofmt \
		golangci:golangci-lint:v1.27.0:golangci_golangci_lint/vendor/github.com/golangci/golangci-lint \
		golangci:ineffassign:42439a7714cc:golangci_ineffassign/vendor/github.com/golangci/ineffassign \
		golangci:lint-1:297bf364a8e0:golangci_lint_1/vendor/github.com/golangci/lint-1 \
		golangci:maligned:b1d89398deca:golangci_maligned/vendor/github.com/golangci/maligned \
		golangci:misspell:950f5d19e770:golangci_misspell/vendor/github.com/golangci/misspell \
		golangci:prealloc:215b22d4de21:golangci_prealloc/vendor/github.com/golangci/prealloc \
		golangci:revgrep:d9c87f5ffaf0:golangci_revgrep/vendor/github.com/golangci/revgrep \
		golangci:unconvert:28b1c447d1f4:golangci_unconvert/vendor/github.com/golangci/unconvert \
		google:go-genproto:ca5a22157cba:google_go_genproto/vendor/google.golang.org/genproto \
		google:pprof:d4f498aebedc:google_pprof/vendor/github.com/google/pprof \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.15.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.50.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:context:v1.1.1:gorilla_context/vendor/github.com/gorilla/context \
		gorilla:handlers:v1.4.2:gorilla_handlers/vendor/github.com/gorilla/handlers \
		gorilla:securecookie:v1.1.1:gorilla_securecookie/vendor/github.com/gorilla/securecookie \
		gorilla:sessions:v1.2.0:gorilla_sessions/vendor/github.com/gorilla/sessions \
		gostaticanalysis:analysisutil:4088753ea4d3:gostaticanalysis_analysisutil/vendor/github.com/gostaticanalysis/analysisutil \
		grpc:grpc-go:v1.24.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jingyugao:rowserrcheck:72ab7603b68a:jingyugao_rowserrcheck/vendor/github.com/jingyugao/rowserrcheck \
		jirfag:go-printf-func-name:45db9963cdd3:jirfag_go_printf_func_name/vendor/github.com/jirfag/go-printf-func-name \
		jstemmer:go-junit-report:v0.9.1:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		kardianos:osext:2bc1f35cddc0:kardianos_osext/vendor/github.com/kardianos/osext \
		karlseguin:ccache:v2.0.6:karlseguin_ccache_v2/vendor/github.com/karlseguin/ccache/v2 \
		karrick:godirwalk:v1.10.12:karrick_godirwalk/vendor/github.com/karrick/godirwalk \
		kisielk:gotool:v1.0.0:kisielk_gotool/vendor/github.com/kisielk/gotool \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		maratori:testpackage:v1.0.1:maratori_testpackage/vendor/github.com/maratori/testpackage \
		matoous:godox:5d6d842e92eb:matoous_godox/vendor/github.com/matoous/godox \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.9:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mvdan:interfacer:c20040233aed:mvdan_interfacer/vendor/mvdan.cc/interfacer \
		mvdan:lint:adc824a0674b:mvdan_lint/vendor/mvdan.cc/lint \
		mvdan:unparam:d51796306d8f:mvdan_unparam/vendor/mvdan.cc/unparam \
		nakabonne:nestif:v0.3.0:nakabonne_nestif/vendor/github.com/nakabonne/nestif \
		namsral:flag:v1.7.4-pre:namsral_flag/vendor/github.com/namsral/flag \
		nbutton23:zxcvbn-go:ae427f1e4c1d:nbutton23_zxcvbn_go/vendor/github.com/nbutton23/zxcvbn-go \
		oklog:ulid:v2.0.2:oklog_ulid_v2/vendor/github.com/oklog/ulid/v2 \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pires:go-proxyproto:v0.2.0:pires_go_proxyproto/vendor/github.com/pires/go-proxyproto \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.6.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.9.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.11:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.21.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rs:cors:v1.7.0:rs_cors/vendor/github.com/rs/cors \
		ryancurrah:gomodguard:v1.0.4:ryancurrah_gomodguard/vendor/github.com/ryancurrah/gomodguard \
		sebest:xff:6c115e0ffa35:sebest_xff/vendor/github.com/sebest/xff \
		securego:gosec:v2.3.0:securego_gosec_v2/vendor/github.com/securego/gosec/v2 \
		sirupsen:logrus:v1.7.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		sourcegraph:go-diff:v0.5.1:sourcegraph_go_diff/vendor/github.com/sourcegraph/go-diff \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.6.1:spf13_viper/vendor/github.com/spf13/viper \
		sqs:pbtypes:d3ebe8f20ae4:sqs_pbtypes/vendor/sourcegraph.com/sqs/pbtypes \
		stretchr:objx:v0.2.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		tdakkota:asciicheck:d7f85be797a2:tdakkota_asciicheck/vendor/github.com/tdakkota/asciicheck \
		tetafro:godot:v0.3.7:tetafro_godot/vendor/github.com/tetafro/godot \
		timakin:bodyclose:f7f2e9bca95e:timakin_bodyclose/vendor/github.com/timakin/bodyclose \
		tj:go-redirects:5c02ead0bbc5:tj_go_redirects/vendor/github.com/tj/go-redirects \
		tomasen:realip:f0c99a92ddce:tomasen_realip/vendor/github.com/tomasen/realip \
		tommy-muehle:go-mnd:e6f9a994e8fa:tommy_muehle_go_mnd/vendor/github.com/tommy-muehle/go-mnd \
		ultraware:funlen:v0.0.2:ultraware_funlen/vendor/github.com/ultraware/funlen \
		ultraware:whitespace:v0.0.4:ultraware_whitespace/vendor/github.com/ultraware/whitespace \
		uudashr:gocognit:v1.0.1:uudashr_gocognit/vendor/github.com/uudashr/gocognit \
		wadey:gocovmerge:b5bfa59ec0ad:wadey_gocovmerge/vendor/github.com/wadey/gocovmerge

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
