PORTNAME=	step-cli
DISTVERSIONPREFIX=v
DISTVERSION=	0.18.1
CATEGORIES=	security

MAINTAINER=	mw@wipp.bayern
COMMENT=	Smallstep step-ca command line client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	smallstep
GH_PROJECT=	cli

GH_TUPLE=	\
		AndreasBriese:bbloom:46b345b51c96:andreasbriese_bbloom/vendor/github.com/AndreasBriese/bbloom \
		Azure:azure-sdk-for-go:v58.0.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-autorest:446f41b7d65b:azure_go_autorest_validation \
		Azure:go-autorest:55c0c4ebc34d:azure_go_autorest_cli \
		Azure:go-autorest:76c7860e9b60:azure_go_autorest_auth \
		Azure:go-autorest:autorest/v0.11.17:azure_go_autorest_autorest \
		Azure:go-autorest:b3a0b30a7423:azure_go_autorest_date \
		Azure:go-autorest:def88ef859fb:azure_go_autorest_adal \
		Azure:go-autorest:logger/v0.2.0:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.6.0:azure_go_autorest_tracing \
		Azure:go-autorest:v14.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		FiloSottile:edwards25519:v1.0.0-rc.1:filosottile_edwards25519/vendor/filippo.io/edwards25519 \
		Masterminds:goutils:v1.1.1:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v3.1.1:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Masterminds:sprig:v3.2.2:masterminds_sprig_v3/vendor/github.com/Masterminds/sprig/v3 \
		Microsoft:go-winio:v0.4.14:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		ThomasRooney:gexpect:5482f0350944:thomasrooney_gexpect/vendor/github.com/ThomasRooney/gexpect \
		asaskevich:govalidator:f9ffefc3facf:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bgentry:speakeasy:v0.1.0:bgentry_speakeasy/vendor/github.com/bgentry/speakeasy \
		boombuler:barcode:v1.0.1:boombuler_barcode/vendor/github.com/boombuler/barcode \
		census-instrumentation:opencensus-go:v0.23.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		census-instrumentation:opencensus-proto:v0.3.0:census_instrumentation_opencensus_proto/vendor/github.com/census-instrumentation/opencensus-proto \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cheggaaa:pb:v1.0.28:cheggaaa_pb/vendor/gopkg.in/cheggaaa/pb.v1 \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		cncf:udpa:04548b0d99d4:cncf_udpa_go/vendor/github.com/cncf/udpa \
		cncf:xds:cb28da3451f1:cncf_xds_go/vendor/github.com/cncf/xds \
		coreos:go-semver:v0.3.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		coreos:go-systemd:v22.3.2:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		corpix:uarand:v0.1.1:corpix_uarand/vendor/github.com/corpix/uarand \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		creack:pty:v1.1.11:creack_pty/vendor/github.com/creack/pty \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgraph-io:badger:v1.6.2:dgraph_io_badger/vendor/github.com/dgraph-io/badger \
		dgraph-io:badger:v2.2007.4:dgraph_io_badger_v2/vendor/github.com/dgraph-io/badger/v2 \
		dgraph-io:ristretto:41ebdbffecfd:dgraph_io_ristretto/vendor/github.com/dgraph-io/ristretto \
		dgryski:go-farm:a6ae2369ad13:dgryski_go_farm/vendor/github.com/dgryski/go-farm \
		dimchansky:utfbom:v1.1.1:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		envoyproxy:go-control-plane:cf90f659a021:envoyproxy_go_control_plane/vendor/github.com/envoyproxy/go-control-plane \
		envoyproxy:protoc-gen-validate:v0.3.0-java:envoyproxy_protoc_gen_validate/vendor/github.com/envoyproxy/protoc-gen-validate \
		etcd-io:bbolt:v1.3.6:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		etcd-io:etcd:8139dd3:etcd_io_etcd_2/vendor/go.etcd.io/etcd/client/v2 \
		etcd-io:etcd:v3.5.0:etcd_io_etcd/vendor/go.etcd.io/etcd/api/v3 \
		etcd-io:etcd:v3.5.0:etcd_io_etcd_10/vendor/go.etcd.io/etcd/v3 \
		etcd-io:etcd:v3.5.0:etcd_io_etcd_1/vendor/go.etcd.io/etcd/client/pkg/v3 \
		etcd-io:etcd:v3.5.0:etcd_io_etcd_3/vendor/go.etcd.io/etcd/client/v3 \
		etcd-io:etcd:v3.5.0:etcd_io_etcd_4/vendor/go.etcd.io/etcd/etcdctl/v3 \
		etcd-io:etcd:v3.5.0:etcd_io_etcd_5/vendor/go.etcd.io/etcd/etcdutl/v3 \
		etcd-io:etcd:v3.5.0:etcd_io_etcd_6/vendor/go.etcd.io/etcd/pkg/v3 \
		etcd-io:etcd:v3.5.0:etcd_io_etcd_7/vendor/go.etcd.io/etcd/raft/v3 \
		etcd-io:etcd:v3.5.0:etcd_io_etcd_8/vendor/go.etcd.io/etcd/server/v3 \
		etcd-io:etcd:v3.5.0:etcd_io_etcd_9/vendor/go.etcd.io/etcd/tests/v3 \
		form3tech-oss:jwt-go:v3.2.3:form3tech_oss_jwt_go/vendor/github.com/form3tech-oss/jwt-go \
		fullstorydev:grpcurl:v1.8.1:fullstorydev_grpcurl/vendor/github.com/fullstorydev/grpcurl \
		go-chi:chi:v4.0.2:go_chi_chi/vendor/github.com/go-chi/chi \
		go-kit:kit:v0.10.0:go_kit_kit/vendor/github.com/go-kit/kit \
		go-logfmt:logfmt:v0.5.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-sql-driver:mysql:v1.6.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:e495a2d5b3d3:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mock:v1.6.0:golang_mock/vendor/github.com/golang/mock \
		golang:mod:v0.4.2:golang_mod/vendor/golang.org/x/mod \
		golang:net:0dd24b26b47d:golang_net/vendor/golang.org/x/net \
		golang:oauth2:f6687ab2804c:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.3:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:da31bd327af9:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		golang:text:5bd84dd9b33b:golang_text/vendor/golang.org/x/text \
		golang:time:f8bda1e9f3ba:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.1.7:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:btree:v1.0.1:google_btree/vendor/github.com/google/btree \
		google:certificate-transparency-go:a50f74f4ce95:google_certificate_transparency_go/vendor/github.com/google/certificate-transparency-go \
		google:go-cmp:v0.5.6:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:00ab72f36ad5:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.48.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.83.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc-ecosystem:go-grpc-middleware:v1.3.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:v1.2.0:grpc_ecosystem_go_grpc_prometheus/vendor/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc-ecosystem:grpc-gateway:v1.16.0:grpc_ecosystem_grpc_gateway/vendor/github.com/grpc-ecosystem/grpc-gateway \
		grpc:grpc-go:v1.43.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		huandu:xstrings:v1.3.2:huandu_xstrings/vendor/github.com/huandu/xstrings \
		icrowley:fake:4178557ae428:icrowley_fake/vendor/github.com/icrowley/fake \
		imdario:mergo:v0.3.12:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jhump:protoreflect:v1.8.2:jhump_protoreflect/vendor/github.com/jhump/protoreflect \
		jonboulle:clockwork:v0.2.2:jonboulle_clockwork/vendor/github.com/jonboulle/clockwork \
		json-iterator:go:v1.1.11:json_iterator_go/vendor/github.com/json-iterator/go \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		klauspost:compress:v1.12.3:klauspost_compress/vendor/github.com/klauspost/compress \
		kr:pty:v1.1.8:kr_pty/vendor/github.com/kr/pty \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		manifoldco:promptui:v0.9.0:manifoldco_promptui/vendor/github.com/manifoldco/promptui \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.13:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mgutz:ansi:d51e80ef957d:mgutz_ansi/vendor/github.com/mgutz/ansi \
		micromdm:scep:v2.1.0:micromdm_scep_v2/vendor/github.com/micromdm/scep/v2 \
		mitchellh:copystructure:v1.2.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:reflectwalk:v1.0.2:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		mozilla-services:pkcs7:33d05740a352:mozilla_services_pkcs7/vendor/go.mozilla.org/pkcs7 \
		natefinch:lumberjack:v2.0.0:natefinch_lumberjack/vendor/gopkg.in/natefinch/lumberjack.v2 \
		newrelic:go-agent:v2.15.0:newrelic_go_agent/vendor/github.com/newrelic/go-agent \
		olekukonko:tablewriter:v0.0.5:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		open-telemetry:opentelemetry-go-contrib:v0.20.0:open_telemetry_opentelemetry_go_contrib/vendor/go.opentelemetry.io/contrib \
		open-telemetry:opentelemetry-go:v0.20.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		open-telemetry:opentelemetry-proto-go:v0.7.0:open_telemetry_opentelemetry_proto_go/vendor/go.opentelemetry.io/proto/otlp \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		pquerna:otp:v1.0.0:pquerna_otp/vendor/github.com/pquerna/otp \
		prometheus:client_golang:v1.11.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.32.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.7.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rs:xid:v1.2.1:rs_xid/vendor/github.com/rs/xid \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		samfoo:ansi:b6bd2ded7189:samfoo_ansi/vendor/github.com/samfoo/ansi \
		shopspring:decimal:v1.2.0:shopspring_decimal/vendor/github.com/shopspring/decimal \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		slackhq:nebula:v1.5.2:slackhq_nebula/vendor/github.com/slackhq/nebula \
		smallstep:assert:82e2b9b3b262:smallstep_assert/vendor/github.com/smallstep/assert \
		smallstep:certificates:v0.18.1:smallstep_certificates/vendor/github.com/smallstep/certificates \
		smallstep:certinfo:v1.6.0:smallstep_certinfo/vendor/github.com/smallstep/certinfo \
		smallstep:cli-utils:v0.7.2:smallstep_cli_utils/vendor/go.step.sm/cli-utils \
		smallstep:crypto:v0.15.0:smallstep_crypto/vendor/go.step.sm/crypto \
		smallstep:linkedca:v0.9.2:smallstep_linkedca/vendor/go.step.sm/linkedca \
		smallstep:nosql:v0.3.9:smallstep_nosql/vendor/github.com/smallstep/nosql \
		smallstep:truststore:v0.10.1:smallstep_truststore/vendor/github.com/smallstep/truststore \
		smallstep:zcrypto:66c2600f6e71:smallstep_zcrypto/vendor/github.com/smallstep/zcrypto \
		smallstep:zlint:d84eaafe274f:smallstep_zlint/vendor/github.com/smallstep/zlint \
		soheilhy:cmux:v0.1.5:soheilhy_cmux/vendor/github.com/soheilhy/cmux \
		spf13:cast:v1.4.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.1.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		square:go-jose:v2.6.0:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tmc:grpc-websocket-proxy:e5319fda7802:tmc_grpc_websocket_proxy/vendor/github.com/tmc/grpc-websocket-proxy \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.6.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.17.0:uber_go_zap/vendor/go.uber.org/zap \
		urfave:cli:v1.22.5:urfave_cli/vendor/github.com/urfave/cli \
		weppos:publicsuffix-go:v0.4.0:weppos_publicsuffix_go/vendor/github.com/weppos/publicsuffix-go \
		xiang90:probing:43a291ad63a2:xiang90_probing/vendor/github.com/xiang90/probing \
		sslmate:go-pkcs12:57fc603b7f52:group_name/vendor/software.sslmate.com/src/go-pkcs12

GL_TUPLE=	https://gitlab.howett.net:go:plist:591f970eefbbeb04d7b37f334a0c4c3256e32876:go_plist/vendor/howett.net/plist

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RLN} ${WRKSRC_azure_go_autorest_autorest}/autorest ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RLN} ${WRKSRC_azure_go_autorest_adal}/autorest/adal ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/auth
	@${RLN} ${WRKSRC_azure_go_autorest_auth}/autorest/azure/auth ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/auth
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/cli
	@${RLN} ${WRKSRC_azure_go_autorest_cli}/autorest/azure/cli ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/cli
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RLN} ${WRKSRC_azure_go_autorest_date}/autorest/date ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/validation
	@${RLN} ${WRKSRC_azure_go_autorest_validation}/autorest/validation ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/validation
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing

SHEBANG_FILES=	autocomplete/bash_autocomplete

GO_TARGET=	./cmd/step
GO_BUILDFLAGS=	-ldflags "-w -X main.Version=${PORTVERSION}"

PLIST_FILES=	bin/step \
		etc/bash_completion.d/step-completion.bash \
		share/zsh/site-functions/_step

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${CP} ${WRKSRC}/autocomplete/bash_autocomplete ${STAGEDIR}${PREFIX}/etc/bash_completion.d/step-completion.bash
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${CP} ${WRKSRC}/autocomplete/zsh_autocomplete ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_step

.include <bsd.port.mk>
