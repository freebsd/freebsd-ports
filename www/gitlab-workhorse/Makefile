# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	gitlab-workhorse
PORTVERSION?=	8.63.2
PORTREVISION?=	0
CATEGORIES=	www

MAINTAINER?=	mfechner@FreeBSD.org
COMMENT?=	Smart reverse proxy for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	git>=2.16.2:devel/git
RUN_DEPENDS=	p5-Image-ExifTool>=0:graphics/p5-Image-ExifTool

USES=		gmake go:modules,no_targets
MAKE_ENV=	GOFLAGS="${GO_BUILDFLAGS}"

USE_GITLAB=	yes
GL_ACCOUNT?=	gitlab-org
# Find the commit hash here: https://gitlab.com/gitlab-org/gitlab-workhorse/tags
GL_COMMIT?=	d6a98839b0a1c98eea332e203a1632f8302b21e9

# for go dependencies
USE_GITHUB=	nodefault
# generated with: make gomod-vendor
# 93dd
GH_TUPLE=	\
		Azure:azure-pipeline-go:v0.2.3:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-storage-blob-go:6df5d9af221d:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		Azure:go-autorest:autorest/v0.11.12:azure_go_autorest_autorest \
		Azure:go-autorest:b3a0b30a7423:azure_go_autorest_date \
		Azure:go-autorest:b8bf08c40b80:azure_go_autorest_adal \
		Azure:go-autorest:logger/v0.2.0:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.6.0:azure_go_autorest_tracing \
		Azure:go-autorest:v14.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		DataDog:dd-trace-go:v1.7.0:datadog_dd_trace_go/vendor/gopkg.in/DataDog/dd-trace-go.v1 \
		FZambia:sentinel:v1.0.0:fzambia_sentinel/vendor/github.com/FZambia/sentinel \
		alecthomas:chroma:v0.7.3:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		aws:aws-sdk-go:v1.36.1:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		census-instrumentation:opencensus-go:v0.22.5:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		client9:reopen:v1.0.0:client9_reopen/vendor/github.com/client9/reopen \
		HdrHistogram:hdrhistogram-go:3a0bb77429bd:codahale_hdrhistogram_go/vendor/github.com/codahale/hdrhistogram \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		disintegration:imaging:v1.6.2:disintegration_imaging/vendor/github.com/disintegration/imaging \
		dlclark:regexp2:v1.2.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dominikh:go-tools:v0.0.1-2020.1.5:dominikh_go_tools/vendor/honnef.co/go/tools \
		form3tech-oss:jwt-go:v3.2.2:form3tech_oss_jwt_go/vendor/github.com/form3tech-oss/jwt-go \
		getsentry:sentry-go:v0.7.0:getsentry_sentry_go/vendor/github.com/getsentry/sentry-go \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		gogo:protobuf:v1.2.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:be400aefbc4c:golang_crypto/vendor/golang.org/x/crypto \
		golang:gddo:af0f2af80721:golang_gddo/vendor/github.com/golang/gddo \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:image:e7c1f5e7dbb8:golang_image/vendor/golang.org/x/image \
		golang:lint:738671d3881b:golang_lint/vendor/golang.org/x/lint \
		golang:mod:v0.4.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:6772e930b67b:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0b49973bad19:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:789bb1bd4061:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.5:golang_text/vendor/golang.org/x/text \
		golang:tools:a1a1cbeaa516:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		gomodule:redigo:v2.0.0:gomodule_redigo/vendor/github.com/gomodule/redigo \
		google:go-cloud:5094f54ed8bb:google_go_cloud/vendor/gocloud.dev \
		google:go-cmp:v0.5.4:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:22ae2b108f89:google_go_genproto/vendor/google.golang.org/genproto \
		google:pprof:3e6fc7fc9c4c:google_pprof/vendor/github.com/google/pprof \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		google:wire:v0.4.0:google_wire/vendor/github.com/google/wire \
		googleapis:gax-go:v2.0.2:googleapis_gax_go/vendor/github.com/googleapis/gax-go \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2 \
		googleapis:google-api-go-client:v0.36.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.72.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gopherjs:gopherjs:0766667cb4d1:gopherjs_gopherjs/vendor/github.com/gopherjs/gopherjs \
		gorilla:websocket:v1.4.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc-ecosystem:go-grpc-middleware:v1.2.2:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:v1.2.0:grpc_ecosystem_go_grpc_prometheus/vendor/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc:grpc-go:v1.34.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		johannesboyne:gofakes3:02d71f533bec:johannesboyne_gofakes3/vendor/github.com/johannesboyne/gofakes3 \
		jpillora:backoff:v1.0.0:jpillora_backoff/vendor/github.com/jpillora/backoff \
		jtolds:gls:v4.20.0:jtolds_gls/vendor/github.com/jtolds/gls \
		lightstep:lightstep-tracer-common:bc2310a04743:lightstep_lightstep_tracer_common_gogo/vendor/github.com/lightstep/lightstep-tracer-common \
		lightstep:lightstep-tracer-go:v0.18.1:lightstep_lightstep_tracer_go/vendor/github.com/lightstep/lightstep-tracer-go \
		mattn:go-ieproxy:v0.0.1:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:reflectwalk:v1.0.0:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		oklog:ulid:v2.0.2:oklog_ulid_v2/vendor/github.com/oklog/ulid/v2 \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		philhofer:fwd:v1.0.0:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.8.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.14.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.2.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rafaeljusto:redigomock:257e089e14a1:rafaeljusto_redigomock/vendor/github.com/rafaeljusto/redigomock \
		ryszard:goskiplist:2dfbae5fcf46:ryszard_goskiplist/vendor/github.com/ryszard/goskiplist \
		sebest:xff:6c115e0ffa35:sebest_xff/vendor/github.com/sebest/xff \
		shabbyrobe:gocovmerge:3e036491d500:shabbyrobe_gocovmerge/vendor/github.com/shabbyrobe/gocovmerge \
		sirupsen:logrus:v1.7.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		smartystreets:assertions:b2de0cb4f26d:smartystreets_assertions/vendor/github.com/smartystreets/assertions \
		smartystreets:goconvey:v1.6.4:smartystreets_goconvey/vendor/github.com/smartystreets/goconvey \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		tinylib:msgp:v1.0.2:tinylib_msgp/vendor/github.com/tinylib/msgp \
		uber:jaeger-client-go:v2.15.0:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		uber:jaeger-lib:v1.5.0:uber_jaeger_lib/vendor/github.com/uber/jaeger-lib

GL_TUPLE=	gitlab-org:gitaly:3f5e218def93024f3aafe590c22cd1b29f744105:gitlab_org_gitaly/vendor/gitlab.com/gitlab-org/gitaly \
		gitlab-org:labkit:f2d7fb209ecad2eaddb5fb9c4ab03eb8eaa82811:gitlab_org_labkit/vendor/gitlab.com/gitlab-org/labkit

PLIST_FILES=	bin/gitlab-resize-image \
		bin/gitlab-workhorse \
		bin/gitlab-zip-cat \
		bin/gitlab-zip-metadata
PLIST_DIRS=	${WWWDIR}

# 13dd
post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RLN} ${WRKSRC_azure_go_autorest_autorest}/autorest ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RLN} ${WRKSRC_azure_go_autorest_adal}/autorest/adal ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RLN} ${WRKSRC_azure_go_autorest_date}/autorest/date ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RM} -r ${WRKSRC}/vendor/github.com/googleapis/gax-go/v2
	@${RLN} ${WRKSRC_googleapis_gax_go_v2}/v2 ${WRKSRC}/vendor/github.com/googleapis/gax-go/v2

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}

.include <bsd.port.mk>
