PORTNAME=	pomerium
DISTVERSIONPREFIX=	v
DISTVERSION=	0.33.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www
# Custom distfiles for packages not on GitHub
MASTER_SITES+=	https://git.sr.ht/~shabbyrobe/gocovmerge/archive/:shabbyrobe \
		https://proxy.golang.org/buf.build/gen/go/bufbuild/protovalidate/protocolbuffers/go/@v/:bufbsr
DISTFILES+=	fa4f82cfbf4d.tar.gz:shabbyrobe \
		v1.36.11-20260415201107-50325440f8f2.1.zip:bufbsr
# The BSR zip must be extracted manually; exclude it from auto-extraction
# to avoid the framework trying to use tar on a zip file.
EXTRACT_ONLY=	${DISTFILES:N*.zip\:bufbsr:C/:.*//}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Identity-aware access proxy
WWW=		https://pomerium.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

EXTRACT_DEPENDS+=	${LOCALBASE}/bin/unzip:archivers/unzip
RUN_DEPENDS=		${LOCALBASE}/libexec/pomerium-envoy:www/pomerium-envoy-custom

USES=		cpe go:modules,1.26
USE_GITHUB=	yes
GH_TUPLE=	Azure:azure-sdk-for-go:f6309d465ff4:azure_azure_sdk_for_go \
		Azure:go-ansiterm:faa5f7b0171c:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		AzureAD:microsoft-authentication-library-for-go:v1.7.0:azuread_microsoft_authentication_library_for_go/vendor/github.com/AzureAD/microsoft-authentication-library-for-go \
		CAFxX:httpcompression:v0.0.9:cafxx_httpcompression/vendor/github.com/CAFxX/httpcompression \
		DataDog:zstd:v1.5.7:datadog_zstd/vendor/github.com/DataDog/zstd \
		FiloSottile:bigmod:v0.0.3:filosottile_bigmod/vendor/filippo.io/bigmod \
		FiloSottile:csrf:v0.2.1:filosottile_csrf/vendor/filippo.io/csrf \
		FiloSottile:keygen:790df0a991a0:filosottile_keygen/vendor/filippo.io/keygen \
		GoogleCloudPlatform:opentelemetry-operations-go:v0.55.0:googlecloudplatform_opentelemetry_operations_go/vendor/github.com/GoogleCloudPlatform/opentelemetry-operations-go \
		GoogleCloudPlatform:opentelemetry-operations-go:detectors/gcp/v1.32.0:googlecloudplatform_opentelemetry_operations_go_gcp \
		Masterminds:semver:v3.5.0:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Microsoft:go-winio:v0.6.2:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		RaduBerinde:axisds:v0.1.0:raduberinde_axisds/vendor/github.com/RaduBerinde/axisds \
		RaduBerinde:btreemap:3d62b7205d54:raduberinde_btreemap/vendor/github.com/RaduBerinde/btreemap \
		VictoriaMetrics:fastcache:v1.13.3:victoriametrics_fastcache/vendor/github.com/VictoriaMetrics/fastcache \
		agnivade:levenshtein:v1.2.1:agnivade_levenshtein/vendor/github.com/agnivade/levenshtein \
		andybalholm:brotli:v1.0.5:andybalholm_brotli/vendor/github.com/andybalholm/brotli \
		antlr4-go:antlr:v4.13.1:antlr4_go_antlr_v4/vendor/github.com/antlr4-go/antlr/v4 \
		apapsch:go-jsonmerge:v2.0.0:apapsch_go_jsonmerge_v2/vendor/github.com/apapsch/go-jsonmerge/v2 \
		armon:go-metrics:v0.4.1:armon_go_metrics/vendor/github.com/armon/go-metrics \
		atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
		aws:aws-sdk-go-v2:v1.41.11:aws_aws_sdk_go_v2/vendor/github.com/aws/aws-sdk-go-v2 \
		aws:smithy-go:v1.27.0:aws_smithy_go/vendor/github.com/aws/smithy-go \
		aymanbagabas:go-osc52:v2.0.1:aymanbagabas_go_osc52_v2/vendor/github.com/aymanbagabas/go-osc52/v2 \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bits-and-blooms:bitset:v1.24.4:bits_and_blooms_bitset/vendor/github.com/bits-and-blooms/bitset \
		bufbuild:protovalidate-go:v1.2.0:bufbuild_protovalidate_go/vendor/buf.build/go/protovalidate \
		caddyserver:certmagic:v0.25.2:caddyserver_certmagic/vendor/github.com/caddyserver/certmagic \
		caddyserver:zerossl:v0.1.5:caddyserver_zerossl/vendor/github.com/caddyserver/zerossl \
		ccoveille:go-safecast:v2.0.1:ccoveille_go_safecast_v2/vendor/github.com/ccoveille/go-safecast/v2 \
		cenkalti:backoff:v4.3.0:cenkalti_backoff_v4/vendor/github.com/cenkalti/backoff/v4 \
		cenkalti:backoff:v5.0.3:cenkalti_backoff_v5/vendor/github.com/cenkalti/backoff/v5 \
		census-ecosystem:opencensus-go-exporter-prometheus:v0.4.2:census_ecosystem_opencensus_go_exporter_prometheus/vendor/contrib.go.opencensus.io/exporter/prometheus \
		census-instrumentation:opencensus-go:v0.24.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.3.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		charmbracelet:bubbles:v2.1.0:charmbracelet_bubbles/vendor/charm.land/bubbles/v2 \
		charmbracelet:bubbletea:v2.0.7:charmbracelet_bubbletea/vendor/charm.land/bubbletea/v2 \
		charmbracelet:colorprofile:v0.4.3:charmbracelet_colorprofile/vendor/github.com/charmbracelet/colorprofile \
		charmbracelet:lipgloss:v2.0.4:charmbracelet_lipgloss/vendor/charm.land/lipgloss/v2 \
		charmbracelet:ultraviolet:948f4557a654:charmbracelet_ultraviolet/vendor/github.com/charmbracelet/ultraviolet \
		charmbracelet:x:ansi/v0.11.7:charmbracelet_x_ansi \
		charmbracelet:x:conpty/v0.2.0:charmbracelet_x_conpty \
		charmbracelet:x:exp/ordered/v0.1.0:charmbracelet_x_exp_ordered \
		charmbracelet:x:term/v0.2.2:charmbracelet_x_term/vendor/github.com/charmbracelet/x \
		charmbracelet:x:termios/v0.1.1:charmbracelet_x_termios \
		charmbracelet:x:b57e5e6d29bb:charmbracelet_x_vt \
		charmbracelet:x:windows/v0.2.2:charmbracelet_x_windows \
		charmbracelet:x:xpty/v0.1.3:charmbracelet_x_xpty \
		clipperhouse:displaywidth:v0.11.0:clipperhouse_displaywidth/vendor/github.com/clipperhouse/displaywidth \
		clipperhouse:uax29:v2.7.0:clipperhouse_uax29_v2/vendor/github.com/clipperhouse/uax29/v2 \
		cloudflare:circl:v1.6.3:cloudflare_circl/vendor/github.com/cloudflare/circl \
		cncf:xds:dba9d589def2:cncf_xds_go \
		cockroachdb:crlib:1264a2edc35b:cockroachdb_crlib/vendor/github.com/cockroachdb/crlib \
		cockroachdb:errors:v1.11.3:cockroachdb_errors/vendor/github.com/cockroachdb/errors \
		cockroachdb:logtags:21c54148d20b:cockroachdb_logtags/vendor/github.com/cockroachdb/logtags \
		cockroachdb:pebble:v2.1.4:cockroachdb_pebble_v2/vendor/github.com/cockroachdb/pebble/v2 \
		cockroachdb:redact:v1.1.5:cockroachdb_redact/vendor/github.com/cockroachdb/redact \
		cockroachdb:swiss:b0f6560f979b:cockroachdb_swiss/vendor/github.com/cockroachdb/swiss \
		cockroachdb:tokenbucket:cc333fc44b06:cockroachdb_tokenbucket/vendor/github.com/cockroachdb/tokenbucket \
		connectrpc:connect-go:v1.20.0:connectrpc_connect_go/vendor/connectrpc.com/connect \
		connectrpc:grpchealth-go:v1.4.0:connectrpc_grpchealth_go/vendor/connectrpc.com/grpchealth \
		connectrpc:grpcreflect-go:v1.3.0:connectrpc_grpcreflect_go/vendor/connectrpc.com/grpcreflect \
		connectrpc:otelconnect-go:v0.9.0:connectrpc_otelconnect_go/vendor/connectrpc.com/otelconnect \
		containerd:errdefs:v0.3.0:containerd_errdefs_pkg/vendor/github.com/containerd/errdefs \
		containerd:errdefs:v1.0.0:containerd_errdefs \
		containerd:log:v0.1.0:containerd_log/vendor/github.com/containerd/log \
		containerd:platforms:v1.0.0-rc.2:containerd_platforms/vendor/github.com/containerd/platforms \
		coreos:go-oidc:v3.18.0:coreos_go_oidc_v3/vendor/github.com/coreos/go-oidc/v3 \
		cpuguy83:dockercfg:v0.3.2:cpuguy83_dockercfg/vendor/github.com/cpuguy83/dockercfg \
		creack:pty:v1.1.24:creack_pty/vendor/github.com/creack/pty \
		dave:jennifer:v1.7.1:dave_jennifer/vendor/github.com/dave/jennifer \
		davecgh:go-spew:d8f796af33cc:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		decred:dcrd:dcrec/secp256k1/v4.4.0:decred_dcrd_v4 \
		distribution:reference:v0.6.0:distribution_reference/vendor/github.com/distribution/reference \
		docker:go-connections:v0.7.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.5.0:docker_go_units/vendor/github.com/docker/go-units \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		ebitengine:purego:v0.10.0:ebitengine_purego/vendor/github.com/ebitengine/purego \
		envoyproxy:go-control-plane:envoy/v1.37.0:envoyproxy_go_control_plane/vendor/github.com/envoyproxy/go-control-plane \
		envoyproxy:protoc-gen-validate:v1.3.3:envoyproxy_protoc_gen_validate/vendor/github.com/envoyproxy/protoc-gen-validate \
		etcd-io:bbolt:v1.4.3:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		ettle:strcase:v0.2.0:ettle_strcase/vendor/github.com/ettle/strcase \
		exaring:otelpgx:v0.10.0:exaring_otelpgx/vendor/github.com/exaring/otelpgx \
		fatih:color:v1.18.0:fatih_color/vendor/github.com/fatih/color \
		felixge:httpsnoop:v1.0.4:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		fsnotify:fsnotify:v1.9.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		fxamacker:cbor:v2.9.2:fxamacker_cbor_v2/vendor/github.com/fxamacker/cbor/v2 \
		gaissmai:bart:v0.26.1:gaissmai_bart/vendor/github.com/gaissmai/bart \
		getsentry:sentry-go:v0.27.0:getsentry_sentry_go/vendor/github.com/getsentry/sentry-go \
		go-chi:chi:v5.3.0:go_chi_chi_v5/vendor/github.com/go-chi/chi/v5 \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/github.com/go-ini/ini \
		go-jose:go-jose:v3.0.5:go_jose_go_jose_v3/vendor/github.com/go-jose/go-jose/v3 \
		go-jose:go-jose:v4.1.4:go_jose_go_jose_v4/vendor/github.com/go-jose/go-jose/v4 \
		go-kit:log:v0.2.1:go_kit_log/vendor/github.com/go-kit/log \
		go-logfmt:logfmt:v0.6.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-logr:logr:v1.4.3:go_logr_logr/vendor/github.com/go-logr/logr \
		go-logr:stdr:v1.2.2:go_logr_stdr/vendor/github.com/go-logr/stdr \
		go-ole:go-ole:v1.3.0:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-viper:mapstructure:v2.5.0:go_viper_mapstructure_v2/vendor/github.com/go-viper/mapstructure/v2 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_v3/vendor/gopkg.in/yaml.v3 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		goccy:go-json:v0.10.5:goccy_go_json/vendor/github.com/goccy/go-json \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang-jwt:jwt:v5.3.1:golang_jwt_jwt_v5/vendor/github.com/golang-jwt/jwt/v5 \
		golang:crypto:v0.53.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:74f9aab9d74a:golang_exp/vendor/golang.org/x/exp \
		golang:freetype:e2365dfdc4a0:golang_freetype/vendor/github.com/golang/freetype \
		golang:groupcache:2c02b8208cf8:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:image:v0.42.0:golang_image/vendor/golang.org/x/image \
		golang:mod:v0.36.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.55.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.36.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:snappy:v1.0.0:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:v0.21.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.46.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.44.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.38.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.15.0:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.45.0:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:7835f813f4da:golang_xerrors/vendor/golang.org/x/xerrors \
		google:btree:v1.1.3:google_btree/vendor/github.com/google/btree \
		google:cel-go:v0.28.1:google_cel_go/vendor/github.com/google/cel-go \
		google:cel-spec:v0.25.2:google_cel_spec/vendor/cel.dev/expr \
		google:go-cmp:v0.7.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:d00831a3d3e7:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-genproto:3dc84a4a5aaa:google_go_genproto_api/vendor/google.golang.org/genproto/googleapis/api \
		google:go-genproto:3dc84a4a5aaa:google_go_genproto_rpc/vendor/google.golang.org/genproto/googleapis/rpc \
		google:go-jsonnet:v0.22.0:google_go_jsonnet/vendor/github.com/google/go-jsonnet \
		google:go-tpm:v0.9.8:google_go_tpm/vendor/github.com/google/go-tpm \
		google:gnostic:e0e09f706281:google_gnostic/vendor/github.com/google/gnostic \
		google:gnostic-models:v0.7.1:google_gnostic_models/vendor/github.com/google/gnostic-models \
		google:go-cloud:v0.46.0:google_go_cloud/vendor/gocloud.dev \
		google:jsonschema-go:v0.4.2:google_jsonschema_go/vendor/github.com/google/jsonschema-go \
		google:s2a-go:v0.1.9:google_s2a_go/vendor/github.com/google/s2a-go \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		google:wire:v0.7.0:google_wire/vendor/github.com/google/wire \
		googleapis:enterprise-certificate-proxy:v0.3.16:googleapis_enterprise_certificate_proxy/vendor/github.com/googleapis/enterprise-certificate-proxy \
		googleapis:gax-go:v2.22.0:googleapis_gax_go_v2 \
		googleapis:google-api-go-client:v0.283.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.123.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		googleapis:google-cloud-go:auth/v0.20.0:googleapis_google_cloud_go_auth \
		googleapis:google-cloud-go:auth/oauth2adapt/v0.2.8:googleapis_google_cloud_go_oauth2adapt \
		googleapis:google-cloud-go:compute/metadata/v0.9.0:googleapis_google_cloud_go_metadata \
		googleapis:google-cloud-go:iam/v1.5.3:googleapis_google_cloud_go_iam \
		googleapis:google-cloud-go:monitoring/v1.24.3:googleapis_google_cloud_go_monitoring \
		googleapis:google-cloud-go:storage/v1.61.3:googleapis_google_cloud_go_storage \
		gorilla:mux:v1.8.1:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:securecookie:v1.1.2:gorilla_securecookie/vendor/github.com/gorilla/securecookie \
		gorilla:websocket:e064f32e3674:gorilla_websocket/vendor/github.com/gorilla/websocket \
		gregjones:httpcache:901d90724c79:gregjones_httpcache/vendor/github.com/gregjones/httpcache \
		grpc-ecosystem:go-grpc-middleware:v2.3.3:grpc_ecosystem_go_grpc_middleware_v2/vendor/github.com/grpc-ecosystem/go-grpc-middleware/v2 \
		grpc-ecosystem:grpc-gateway:v2.28.0:grpc_ecosystem_grpc_gateway_v2/vendor/github.com/grpc-ecosystem/grpc-gateway/v2 \
		grpc:grpc-go:v1.82.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-hclog:v1.6.2:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-immutable-radix:v1.0.0:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-metrics:v0.5.4:hashicorp_go_metrics/vendor/github.com/hashicorp/go-metrics \
		hashicorp:go-msgpack:v2.1.2:hashicorp_go_msgpack_v2/vendor/github.com/hashicorp/go-msgpack/v2 \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-set:v3.0.1:hashicorp_go_set_v3/vendor/github.com/hashicorp/go-set/v3 \
		hashicorp:golang-lru:v0.5.1:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:golang-lru:v2.0.7:hashicorp_golang_lru_v2/vendor/github.com/hashicorp/golang-lru/v2 \
		hashicorp:raft:v1.7.3:hashicorp_raft/vendor/github.com/hashicorp/raft \
		hegeldev:hegel-go:v0.3.3:hegeldev_hegel_go/vendor/hegel.dev/go/hegel \
		imdario:mergo:v1.0.2:imdario_mergo/vendor/dario.cat/mergo \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jackc:pgpassfile:v1.0.0:jackc_pgpassfile/vendor/github.com/jackc/pgpassfile \
		jackc:pgservicefile:5a60cdf6a761:jackc_pgservicefile/vendor/github.com/jackc/pgservicefile \
		jackc:pgx:v5.9.2:jackc_pgx_v5/vendor/github.com/jackc/pgx/v5 \
		jackc:puddle:v2.2.2:jackc_puddle_v2/vendor/github.com/jackc/puddle/v2 \
		johannesboyne:gofakes3:ebf3e50324d3:johannesboyne_gofakes3/vendor/github.com/johannesboyne/gofakes3 \
		jxskiss:base62:v1.1.0:jxskiss_base62/vendor/github.com/jxskiss/base62 \
		klauspost:compress:v1.18.6:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v2.3.0:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
		klauspost:crc32:v1.3.0:klauspost_crc32/vendor/github.com/klauspost/crc32 \
		kr:pretty:v0.3.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		kralicky:go-adaptive-radix-tree:330eb762e74c:kralicky_go_adaptive_radix_tree/vendor/github.com/kralicky/go-adaptive-radix-tree \
		kubernetes-sigs:yaml:v1.6.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kylelemons:godebug:v1.1.0:kylelemons_godebug/vendor/github.com/kylelemons/godebug \
		lestrrat-go:blackmagic:v1.0.4:lestrrat_go_blackmagic/vendor/github.com/lestrrat-go/blackmagic \
		lestrrat-go:dsig-secp256k1:v1.0.0:lestrrat_go_dsig_secp256k1/vendor/github.com/lestrrat-go/dsig-secp256k1 \
		lestrrat-go:dsig:v1.0.0:lestrrat_go_dsig/vendor/github.com/lestrrat-go/dsig \
		lestrrat-go:httpcc:v1.0.1:lestrrat_go_httpcc/vendor/github.com/lestrrat-go/httpcc \
		lestrrat-go:httprc:v3.0.2:lestrrat_go_httprc_v3/vendor/github.com/lestrrat-go/httprc/v3 \
		lestrrat-go:jwx:v3.0.13:lestrrat_go_jwx_v3/vendor/github.com/lestrrat-go/jwx/v3 \
		lestrrat-go:option:v2.0.0:lestrrat_go_option_v2/vendor/github.com/lestrrat-go/option/v2 \
		libdns:libdns:v1.1.1:libdns_libdns/vendor/github.com/libdns/libdns \
		libp2p:go-reuseport:v0.4.0:libp2p_go_reuseport/vendor/github.com/libp2p/go-reuseport \
		lucasb-eyer:go-colorful:v1.4.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		lufia:plan9stats:fba389f38bae:lufia_plan9stats/vendor/github.com/lufia/plan9stats \
		magiconair:properties:v1.8.10:magiconair_properties/vendor/github.com/magiconair/properties \
		martinlindhe:base36:v1.1.1:martinlindhe_base36/vendor/github.com/martinlindhe/base36 \
		mattn:go-colorable:v0.1.14:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.22:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.23:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mholt:acmez:v3.1.6:mholt_acmez_v3/vendor/github.com/mholt/acmez/v3 \
		miekg:dns:v1.1.72:miekg_dns/vendor/github.com/miekg/dns \
		minio:crc64nvme:v1.1.1:minio_crc64nvme/vendor/github.com/minio/crc64nvme \
		minio:md5-simd:v1.1.2:minio_md5_simd/vendor/github.com/minio/md5-simd \
		minio:minio-go:v7.0.99:minio_minio_go/vendor/github.com/minio/minio-go/v7 \
		minio:minlz:87eb42fe8882:minio_minlz/vendor/github.com/minio/minlz \
		mitchellh:hashstructure:v2.0.2:mitchellh_hashstructure_v2/vendor/github.com/mitchellh/hashstructure/v2 \
		moby:docker-image-spec:v1.3.1:moby_docker_image_spec/vendor/github.com/moby/docker-image-spec \
		moby:go-archive:v0.2.0:moby_go_archive/vendor/github.com/moby/go-archive \
		moby:moby:6cbde19f7b9f:moby_moby \
		moby:patternmatcher:v0.6.1:moby_patternmatcher/vendor/github.com/moby/patternmatcher \
		moby:sys:user/v0.4.0:moby_sys_user/vendor/github.com/moby/sys \
		moby:sys:sequential/v0.6.0:moby_sys_sequential \
		moby:sys:userns/v0.1.0:moby_sys_userns \
		moby:term:v0.5.2:moby_term/vendor/github.com/moby/term \
		modelcontextprotocol:go-sdk:v1.5.0:modelcontextprotocol_go_sdk/vendor/github.com/modelcontextprotocol/go-sdk \
		muesli:cancelreader:v0.2.2:muesli_cancelreader/vendor/github.com/muesli/cancelreader \
		muesli:termenv:v0.16.0:muesli_termenv/vendor/github.com/muesli/termenv \
		munnerz:goautoneg:a7dc8b61c822:munnerz_goautoneg/vendor/github.com/munnerz/goautoneg \
		natefinch:atomic:v1.0.1:natefinch_atomic/vendor/github.com/natefinch/atomic \
		oapi-codegen:runtime:v1.3.1:oapi_codegen_runtime/vendor/github.com/oapi-codegen/runtime \
		onsi:ginkgo:v1.16.5:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		open-policy-agent:opa:v1.15.1:open_policy_agent_opa/vendor/github.com/open-policy-agent/opa \
		open-telemetry:opentelemetry-go-contrib:detectors/gcp/v1.43.0:open_telemetry_opentelemetry_go_contrib/vendor/go.opentelemetry.io/contrib \
		open-telemetry:opentelemetry-go-contrib:instrumentation/google.golang.org/grpc/otelgrpc/v0.68.0:open_telemetry_opentelemetry_go_contrib_1 \
		open-telemetry:opentelemetry-go-contrib:instrumentation/net/http/otelhttp/v0.68.0:open_telemetry_opentelemetry_go_contrib_2 \
		open-telemetry:opentelemetry-go-contrib:propagators/autoprop/v0.68.0:open_telemetry_opentelemetry_go_contrib_3 \
		open-telemetry:opentelemetry-go-instrumentation:sdk/v1.2.1:open_telemetry_opentelemetry_go_instrumentation \
		open-telemetry:opentelemetry-go:v1.43.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		open-telemetry:opentelemetry-proto-go:v1.10.0:open_telemetry_opentelemetry_proto_go \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.1.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		oras-project:oras-go:v2.6.0:oras_project_oras_go/vendor/oras.land/oras-go/v2 \
		pelletier:go-toml:v2.2.4:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		peterbourgon:ff:v3.4.0:peterbourgon_ff_v3/vendor/github.com/peterbourgon/ff/v3 \
		philhofer:fwd:v1.2.0:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pierrec:lz4:v4.1.21:pierrec_lz4_v4/vendor/github.com/pierrec/lz4/v4 \
		pires:go-proxyproto:v0.11.0:pires_go_proxyproto/vendor/github.com/pires/go-proxyproto \
		pkg:browser:5ac0b6a4141c:pkg_browser/vendor/github.com/pkg/browser \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		planetscale:vtprotobuf:0393e58bdf10:planetscale_vtprotobuf/vendor/github.com/planetscale/vtprotobuf \
		pmezard:go-difflib:5d4384ee4fb2:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		pomerium:datasource:aec349b682d9:pomerium_datasource/vendor/github.com/pomerium/datasource \
		pomerium:envoy-custom:16ede7a56f2f:pomerium_envoy_custom/vendor/github.com/pomerium/envoy-custom \
		pomerium:protoutil:a733aa3acfed:pomerium_protoutil/vendor/github.com/pomerium/protoutil \
		pomerium:webauthn:07401bebfe9c:pomerium_webauthn/vendor/github.com/pomerium/webauthn \
		power-devops:perfstat:82ca36839d55:power_devops_perfstat/vendor/github.com/power-devops/perfstat \
		prometheus:client_golang:v1.23.2:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.6.2:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.67.5:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:otlptranslator:v1.0.0:prometheus_otlptranslator/vendor/github.com/prometheus/otlptranslator \
		prometheus:procfs:v0.20.1:prometheus_procfs/vendor/github.com/prometheus/procfs \
		prometheus:statsd_exporter:v0.22.7:prometheus_statsd_exporter/vendor/github.com/prometheus/statsd_exporter \
		protocolbuffers:protobuf-go:v1.36.11:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		quic-go:qpack:v0.6.0:quic_go_qpack/vendor/github.com/quic-go/qpack \
		quic-go:quic-go:v0.59.1:quic_go_quic_go/vendor/github.com/quic-go/quic-go \
		rcrowley:go-metrics:65e299d6c5c9:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rogpeppe:go-internal:v1.14.1:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		rs:cors:v1.11.1:rs_cors/vendor/github.com/rs/cors \
		rs:xid:v1.6.0:rs_xid/vendor/github.com/rs/xid \
		rs:zerolog:v1.35.1:rs_zerolog/vendor/github.com/rs/zerolog \
		ryszard:goskiplist:2dfbae5fcf46:ryszard_goskiplist/vendor/github.com/ryszard/goskiplist \
		sagikazarmark:locafero:v0.11.0:sagikazarmark_locafero/vendor/github.com/sagikazarmark/locafero \
		sahilm:fuzzy:v0.1.1:sahilm_fuzzy/vendor/github.com/sahilm/fuzzy \
		segmentio:asm:v1.2.1:segmentio_asm/vendor/github.com/segmentio/asm \
		segmentio:encoding:v0.5.4:segmentio_encoding/vendor/github.com/segmentio/encoding \
		shirou:gopsutil:v3.24.5:shirou_gopsutil_v3/vendor/github.com/shirou/gopsutil/v3 \
		shirou:gopsutil:v4.26.3:shirou_gopsutil_v4/vendor/github.com/shirou/gopsutil/v4 \
		shoenig:go-m1cpu:v0.1.6:shoenig_go_m1cpu/vendor/github.com/shoenig/go-m1cpu \
		shogo82148:go-sfv:v0.3.3:shogo82148_go_sfv/vendor/github.com/shogo82148/go-sfv \
		sirupsen:logrus:v1.9.4:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		sourcegraph:conc:5f936abd7ae8:sourcegraph_conc/vendor/github.com/sourcegraph/conc \
		spf13:afero:v1.15.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.10.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.10.2:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.10:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.21.0:spf13_viper/vendor/github.com/spf13/viper \
		spiffe:go-spiffe:v2.6.0:spiffe_go_spiffe_v2/vendor/github.com/spiffe/go-spiffe/v2 \
		sryoya:protorand:e7440656b2a4:sryoya_protorand/vendor/github.com/sryoya/protorand \
		stretchr:objx:v0.5.3:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.11.1:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.6.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		tchap:go-patricia:v2.3.3:tchap_go_patricia_v2/vendor/github.com/tchap/go-patricia/v2 \
		testcontainers:testcontainers-go:v0.42.0:testcontainers_testcontainers_go/vendor/github.com/testcontainers/testcontainers-go \
		tidwall:gjson:v1.18.0:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.1.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.2.0:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tinylib:msgp:v1.6.1:tinylib_msgp/vendor/github.com/tinylib/msgp \
		tklauser:go-sysconf:v0.3.16:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.11.0:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		tniswong:go.rfcx:07783c52761f:tniswong_go_rfcx/vendor/github.com/tniswong/go.rfcx \
		uber-go:automaxprocs:v1.6.0:uber_go_automaxprocs/vendor/go.uber.org/automaxprocs \
		uber-go:mock:v0.6.0:uber_go_mock/vendor/go.uber.org/mock \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.28.0:uber_go_zap/vendor/go.uber.org/zap \
		uber-go:zap:exp/v0.3.0:uber_go_zap_exp \
		valyala:fastjson:v1.6.7:valyala_fastjson/vendor/github.com/valyala/fastjson \
		vektah:gqlparser:v2.5.33:vektah_gqlparser_v2/vendor/github.com/vektah/gqlparser/v2 \
		volatiletech:null:v9.0.0:volatiletech_null_v9/vendor/github.com/volatiletech/null/v9 \
		weastur:hclog-zerolog:v1.0.0:weastur_hclog_zerolog/vendor/github.com/weastur/hclog-zerolog \
		x448:float16:v0.8.4:x448_float16/vendor/github.com/x448/float16 \
		xeipuuv:gojsonpointer:02993c407bfb:xeipuuv_gojsonpointer/vendor/github.com/xeipuuv/gojsonpointer \
		xeipuuv:gojsonreference:bd5ef7bd5415:xeipuuv_gojsonreference/vendor/github.com/xeipuuv/gojsonreference \
		xo:terminfo:abceb7e1c41e:xo_terminfo/vendor/github.com/xo/terminfo \
		yaml:go-yaml:v2.4.4:yaml_go_yaml_v2/vendor/go.yaml.in/yaml/v2 \
		yaml:go-yaml:v3.0.4:yaml_go_yaml_v3b/vendor/go.yaml.in/yaml/v3 \
		yashtewari:glob-intersection:v0.2.0:yashtewari_glob_intersection/vendor/github.com/yashtewari/glob-intersection \
		yosida95:uritemplate:v3.0.2:yosida95_uritemplate_v3/vendor/github.com/yosida95/uritemplate/v3 \
		yuin:gopher-lua:v1.1.2:yuin_gopher_lua/vendor/github.com/yuin/gopher-lua \
		yusufpapurcu:wmi:v1.2.4:yusufpapurcu_wmi/vendor/github.com/yusufpapurcu/wmi \
		zeebo:assert:v1.3.1:zeebo_assert/vendor/github.com/zeebo/assert \
		zeebo:blake3:v0.2.4:zeebo_blake3/vendor/github.com/zeebo/blake3 \
		zeebo:xxh3:v1.1.0:zeebo_xxh3/vendor/github.com/zeebo/xxh3
USE_RC_SUBR=	${PORTNAME}

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}:${PREFIX}/libexec/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "${STRIP} -w \
		-X github.com/pomerium/pomerium/internal/version.Version=${DISTVERSIONPREFIX}${DISTVERSION} \
		-X github.com/pomerium/pomerium/internal/version.ProjectName=${PORTNAME} \
		-X github.com/pomerium/pomerium/internal/version.ProjectURL=https://pomerium.com"
CGO_ENABLED=	0

POMERIUMPIDDIR=	/var/run/${PORTNAME}/
POMERIUM_USER?=	www

SUB_FILES+=	extract_freebsd.go
SUB_LIST+=	POMERIUM_USER=${POMERIUM_USER} \
		POMERIUMPIDDIR=${POMERIUMPIDDIR}
PLIST_SUB+=	${SUB_LIST}

# Vendor symlink pairs: "src:dest" relative to ${WRKSRC}/vendor/.
# The post-extract loop creates the parent directory, removes any existing
# destination (idempotent), and installs a symlink.
# go.shabbyrobe.org/gocovmerge (from sourcehut)
VENDOR_SUBMOD_PAIRS+=	${WRKDIR}/gocovmerge-fa4f82cfbf4d:go.shabbyrobe.org/gocovmerge
# charmbracelet/x monorepo submodules
VENDOR_SUBMOD_PAIRS+=	${WRKSRC_charmbracelet_x_ansi}/ansi:github.com/charmbracelet/x/ansi \
			${WRKSRC_charmbracelet_x_conpty}/conpty:github.com/charmbracelet/x/conpty \
			${WRKSRC_charmbracelet_x_exp_ordered}/exp/ordered:github.com/charmbracelet/x/exp/ordered \
			${WRKSRC_charmbracelet_x_termios}/termios:github.com/charmbracelet/x/termios \
			${WRKSRC_charmbracelet_x_vt}/vt:github.com/charmbracelet/x/vt \
			${WRKSRC_charmbracelet_x_vt}/vttest:github.com/charmbracelet/x/vttest \
			${WRKSRC_charmbracelet_x_windows}/windows:github.com/charmbracelet/x/windows \
			${WRKSRC_charmbracelet_x_xpty}/xpty:github.com/charmbracelet/x/xpty
# cncf/xds - module in go/ subdir
VENDOR_SUBMOD_PAIRS+=	${WRKSRC_cncf_xds_go}/go:github.com/cncf/xds/go
# googleapis/gax-go - v2 module in v2/ subdir
VENDOR_SUBMOD_PAIRS+=	${WRKSRC_googleapis_gax_go_v2}/v2:github.com/googleapis/gax-go/v2
# decred/dcrd - secp256k1 module in dcrec/secp256k1/ subdir
VENDOR_SUBMOD_PAIRS+=	${WRKSRC_decred_dcrd_v4}/dcrec/secp256k1:github.com/decred/dcrd/dcrec/secp256k1/v4
# containerd/errdefs v1.0.0 (replaces pkg/errdefs base)
VENDOR_SUBMOD_PAIRS+=	${WRKSRC_containerd_errdefs}:github.com/containerd/errdefs
# GoogleCloudPlatform/opentelemetry-operations-go detectors/gcp
VENDOR_SUBMOD_PAIRS+=	${WRKSRC_googlecloudplatform_opentelemetry_operations_go_gcp}/detectors/gcp:github.com/GoogleCloudPlatform/opentelemetry-operations-go/detectors/gcp
# google-cloud-go submodules
VENDOR_SUBMOD_PAIRS+=	${WRKSRC_googleapis_google_cloud_go_auth}/auth:cloud.google.com/go/auth \
			${WRKSRC_googleapis_google_cloud_go_oauth2adapt}/auth/oauth2adapt:cloud.google.com/go/auth/oauth2adapt \
			${WRKSRC_googleapis_google_cloud_go_metadata}/compute/metadata:cloud.google.com/go/compute/metadata \
			${WRKSRC_googleapis_google_cloud_go_iam}/iam:cloud.google.com/go/iam \
			${WRKSRC_googleapis_google_cloud_go_monitoring}/monitoring:cloud.google.com/go/monitoring \
			${WRKSRC_googleapis_google_cloud_go_storage}/storage:cloud.google.com/go/storage
# moby/sys submodules
VENDOR_SUBMOD_PAIRS+=	${WRKSRC_moby_sys_sequential}/sequential:github.com/moby/sys/sequential \
			${WRKSRC_moby_sys_userns}/userns:github.com/moby/sys/userns
# moby/moby api and client submodules
VENDOR_SUBMOD_PAIRS+=	${WRKSRC_moby_moby}/api:github.com/moby/moby/api \
			${WRKSRC_moby_moby}/client:github.com/moby/moby/client
# opentelemetry-go-contrib submodules
VENDOR_SUBMOD_PAIRS+=	${WRKSRC_open_telemetry_opentelemetry_go_contrib_1}/instrumentation/google.golang.org/grpc/otelgrpc:go.opentelemetry.io/contrib/instrumentation/google.golang.org/grpc/otelgrpc \
			${WRKSRC_open_telemetry_opentelemetry_go_contrib_2}/instrumentation/net/http/otelhttp:go.opentelemetry.io/contrib/instrumentation/net/http/otelhttp \
			${WRKSRC_open_telemetry_opentelemetry_go_contrib_3}/propagators/autoprop:go.opentelemetry.io/contrib/propagators/autoprop
# opentelemetry-go-instrumentation sdk submodule
VENDOR_SUBMOD_PAIRS+=	${WRKSRC_open_telemetry_opentelemetry_go_instrumentation}/sdk:go.opentelemetry.io/auto/sdk
# opentelemetry-proto-go otlp submodule
VENDOR_SUBMOD_PAIRS+=	${WRKSRC_open_telemetry_opentelemetry_proto_go}/otlp:go.opentelemetry.io/proto/otlp
# uber-go/zap/exp submodule
VENDOR_SUBMOD_PAIRS+=	${WRKSRC_uber_go_zap_exp}/exp:go.uber.org/zap/exp
# Azure SDK submodules
VENDOR_SUBMOD_PAIRS+=	${WRKSRC_azure_azure_sdk_for_go}/sdk/azcore:github.com/Azure/azure-sdk-for-go/sdk/azcore \
			${WRKSRC_azure_azure_sdk_for_go}/sdk/azidentity:github.com/Azure/azure-sdk-for-go/sdk/azidentity \
			${WRKSRC_azure_azure_sdk_for_go}/sdk/internal:github.com/Azure/azure-sdk-for-go/sdk/internal \
			${WRKSRC_azure_azure_sdk_for_go}/sdk/storage/azblob:github.com/Azure/azure-sdk-for-go/sdk/storage/azblob
# Local replace modules: go -mod=vendor expects replaced code in vendor/
VENDOR_SUBMOD_PAIRS+=	${WRKSRC}/pkg/grpc/config:github.com/pomerium/pomerium/pkg/grpc/config \
			${WRKSRC}/pkg/grpc/databroker:github.com/pomerium/pomerium/pkg/grpc/databroker

post-extract:
	@${MKDIR} ${WRKSRC}/vendor
# Remove go.work* to prevent workspace mode; strip tool(), ignore(),
# and tool-only require entries from go.mod so -mod=vendor succeeds.
	@${RM} -f ${WRKSRC}/go.work ${WRKSRC}/go.work.sum
	@${SED} -i '' '/^tool (/,/^)/d;/^ignore (/,/^)/d' ${WRKSRC}/go.mod
# Install our modules.txt first (needed by the awk step below and by Go).
	${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor/modules.txt
# Remove require entries for tool-only deps (present in upstream go.mod
# but absent from our vendored modules.txt).
	@${AWK} 'FNR==NR{if(/^# /){sub(/^# /,""); sub(/ .*/,""); keep[$$0]=1} next} \
		/^require \(/{inreq=1} \
		inreq && /^\)/{inreq=0} \
		inreq && /^\t/{mod=$$1; if(!(mod in keep)){next}} \
		{print}' ${WRKSRC}/vendor/modules.txt ${WRKSRC}/go.mod > ${WRKSRC}/go.mod.tmp
	@${MV} ${WRKSRC}/go.mod.tmp ${WRKSRC}/go.mod
# buf.build/gen/go BSR module (from Go proxy zip; not auto-extracted)
	@${LOCALBASE}/bin/unzip -qo ${DISTDIR}/v1.36.11-20260415201107-50325440f8f2.1.zip \
		-d ${WRKSRC}/vendor
	@${MV} "${WRKSRC}/vendor/buf.build/gen/go/bufbuild/protovalidate/protocolbuffers/go@v1.36.11-20260415201107-50325440f8f2.1" \
		"${WRKSRC}/vendor/buf.build/gen/go/bufbuild/protovalidate/protocolbuffers/go"
	@for pair in ${VENDOR_SUBMOD_PAIRS}; do \
	    src=$${pair%%:*}; dst=$${pair#*:}; \
	    ${MKDIR} ${WRKSRC}/vendor/$$(dirname $$dst); \
	    ${RM} -rf ${WRKSRC}/vendor/$$dst; \
	    ${RLN} $$src ${WRKSRC}/vendor/$$dst; \
	done

post-patch:
	${CP} ${FILESDIR}/envoy_freebsd.go ${WRKSRC}/pkg/envoy/
	${CP} ${FILESDIR}/pipe_freebsd.go ${WRKSRC}/pkg/ipc/

post-configure:
	${MV} ${WRKDIR}/extract_freebsd.go ${WRKSRC}/pkg/envoy/

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${POMERIUMPIDDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/config/config.example.yaml \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}/config.yaml.sample

# Maintenance target: regenerate files/modules.txt.
# Requires network access.  Run after updating DISTVERSION or GH_TUPLE.
# go mod vendor produces a complete vendor/modules.txt that covers both the
# modules in the tarball and those added via GH_TUPLE symlinks.
generate-modules-txt:
	@${ECHO_MSG} "Regenerating files/modules.txt (requires network access) ..."
	@${RM} -rf ${WRKDIR}/pomerium-modules-gen
	@${MKDIR} ${WRKDIR}/pomerium-modules-gen
	cd ${WRKDIR}/pomerium-modules-gen && \
		git clone --depth 1 -b ${DISTVERSIONPREFIX}${DISTVERSION} \
			https://github.com/${GH_ACCOUNT}/${GH_PROJECT}.git . && \
		${SED} -i '' '/^tool (/,/^)/d;/^ignore (/,/^)/d' go.mod && \
		GOWORK=off ${GO_CMD} mod tidy && \
		GOWORK=off ${GO_CMD} mod vendor && \
		${CP} vendor/modules.txt ${FILESDIR}/modules.txt
	@${ECHO_MSG} "Done.  Commit the updated files/modules.txt."

.include <bsd.port.mk>
