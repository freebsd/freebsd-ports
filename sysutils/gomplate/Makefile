PORTNAME=	gomplate
DISTVERSIONPREFIX=	v
DISTVERSION=	3.9.0
CATEGORIES=	sysutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Command-line tool for rendering templates before executing binaries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	hairyhenderson
GH_TAG_COMMIT=	d71e73f
GH_TUPLE=	\
		Masterminds:goutils:v1.1.0:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Shopify:ejson:v1.2.2:shopify_ejson/vendor/github.com/Shopify/ejson \
		armon:go-metrics:f0300d1749da:armon_go_metrics/vendor/github.com/armon/go-metrics \
		aws:aws-sdk-go:v1.36.31:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		census-instrumentation:opencensus-go:v0.22.5:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		docker:libkv:458977154600:docker_libkv/vendor/github.com/docker/libkv \
		dustin:gojson:2e71ec9dd5ad:dustin_gojson/vendor/github.com/dustin/gojson \
		emirpasic:gods:v1.12.0:emirpasic_gods/vendor/github.com/emirpasic/gods \
		etcd-io:bbolt:v1.3.5:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		fullsailor:pkcs7:d7302db945fa:fullsailor_pkcs7/vendor/github.com/fullsailor/pkcs7 \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-git:gcfg:v1.5.0:go_git_gcfg/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.0.0:go_git_go_billy_v5/vendor/github.com/go-git/go-billy/v5 \
		go-git:go-git:v5.2.0:go_git_go_git_v5/vendor/github.com/go-git/go-git/v5 \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:496545a6307b:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:eec23a3978ad:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:738671d3881b:golang_lint/vendor/golang.org/x/lint \
		golang:mod:v0.4.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:c7110b5ffcbb:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0b49973bad19:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:22da62e12c0c:golang_sys/vendor/golang.org/x/sys \
		golang:term:2321bbc49cbf:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.4:golang_text/vendor/golang.org/x/text \
		golang:time:3af7569d3a1e:golang_time/vendor/golang.org/x/time \
		golang:tools:a1a1cbeaa516:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cloud:v0.21.0:google_go_cloud/vendor/gocloud.dev \
		google:go-cmp:v0.5.4:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:6486ece9c497:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		google:wire:v0.4.0:google_wire/vendor/github.com/google/wire \
		googleapis:gax-go:v2.0.2:googleapis_gax_go/vendor/github.com/googleapis/gax-go \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2 \
		googleapis:google-api-go-client:v0.36.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:storage/v1.12.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.72.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gosimple:slug:v1.9.0:gosimple_slug/vendor/github.com/gosimple/slug \
		gotestyourself:gotest.tools:v3.0.3:gotestyourself_gotest_tools/vendor/gotest.tools/v3 \
		grpc:grpc-go:v1.34.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hairyhenderson:toml:2a4f3b6160f2:hairyhenderson_toml/vendor/github.com/hairyhenderson/toml \
		hashicorp:consul:v1.8.1:hashicorp_consul_api/vendor/github.com/hashicorp/consul \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-hclog:v0.12.0:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-immutable-radix:v1.0.0:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-multierror:v1.1.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-retryablehttp:v0.5.4:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-rootcerts:v1.0.2:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-sockaddr:v1.0.2:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:golang-lru:v0.5.1:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:serf:v0.9.5:hashicorp_serf/vendor/github.com/hashicorp/serf \
		hashicorp:vault:api/v1.0.4:hashicorp_vault_api/vendor/github.com/hashicorp/vault \
		hashicorp:vault:sdk/v0.1.13:hashicorp_vault_sdk \
		imdario:mergo:v0.3.9:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		johannesboyne:gofakes3:901cf567bf01:johannesboyne_gofakes3/vendor/github.com/johannesboyne/gofakes3 \
		joho:godotenv:v1.3.0:joho_godotenv/vendor/github.com/joho/godotenv \
		jstemmer:go-junit-report:v0.9.1:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		kevinburke:ssh_config:01f96b0aa0cd:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		kr:pretty:v0.2.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		kubernetes:client-go:v11.0.0:kubernetes_client_go/vendor/k8s.io/client-go \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.4.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pierrec:lz4:v2.0.5:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rainycape:unidecode:cb7f23ec59be:rainycape_unidecode/vendor/github.com/rainycape/unidecode \
		rs:zerolog:v1.20.0:rs_zerolog/vendor/github.com/rs/zerolog \
		ryanuber:go-glob:v1.0.0:ryanuber_go_glob/vendor/github.com/ryanuber/go-glob \
		ryszard:goskiplist:2dfbae5fcf46:ryszard_goskiplist/vendor/github.com/ryszard/goskiplist \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		shabbyrobe:gocovmerge:f6ea450bfb63:shabbyrobe_gocovmerge/vendor/github.com/shabbyrobe/gocovmerge \
		spf13:afero:v1.5.1:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cobra:v1.1.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		square:go-jose:v2.3.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		ugorji:go:v1.2.3:ugorji_go_codec/vendor/github.com/ugorji/go \
		xanzy:ssh-agent:v0.2.1:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent \
		zealic:xignore:v0.3.3:zealic_xignore/vendor/github.com/zealic/xignore

GO_TARGET=	./cmd/gomplate
GO_BUILDFLAGS=	-ldflags "\
		-w -s \
		-X github.com/${GH_ACCOUNT}/${PORTNAME}/v3/version.GitCommit=${GH_TAG_COMMIT} \
		-X github.com/${GH_ACCOUNT}/${PORTNAME}/v3/version.Version=${DISTVERSION}"

PLIST_FILES=	bin/gomplate

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RM} -r ${WRKSRC}/vendor/github.com/googleapis/gax-go/v2
	@${RLN} ${WRKSRC_googleapis_gax_go_v2}/v2 ${WRKSRC}/vendor/github.com/googleapis/gax-go/v2
	@${RM} -r ${WRKSRC}/vendor/github.com/hashicorp/vault/sdk
	@${RLN} ${WRKSRC_hashicorp_vault_sdk}/sdk ${WRKSRC}/vendor/github.com/hashicorp/vault/sdk

.include <bsd.port.mk>
