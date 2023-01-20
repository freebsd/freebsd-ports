PORTNAME=	dendrite
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
CATEGORIES=	net-im

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Matrix protocol homeserver
WWW=		https://github.com/matrix-org/dendrite

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	matrix
PLIST_SUB=	PORTNAME=${PORTNAME}
USE_RC_SUBR=	${PORTNAME}
USERS=		${PORTNAME}
GROUPS=		${USERS}

DENDRITE_BINS=	create-account dendrite-demo-pinecone			\
		dendrite-demo-yggdrasil dendrite-monolith-server	\
		dendrite-polylith-multi dendrite-upgrade-tests		\
		furl generate-config generate-keys resolve-state

.for f in ${DENDRITE_BINS}
GO_TARGET+=	./cmd/$f:${PREFIX}/dendrite/bin/$f
.endfor

USE_GITHUB=	yes
USE_GITLAB=	nodefault
GH_ACCOUNT=	matrix-org
GH_TUPLE=	Arceliar:ironwood:45b4281814c2:arceliar_ironwood/vendor/github.com/Arceliar/ironwood \
		Arceliar:phony:dde1a8dca979:arceliar_phony/vendor/github.com/Arceliar/phony \
		DATA-DOG:go-sqlmock:v1.5.0:data_dog_go_sqlmock/vendor/github.com/DATA-DOG/go-sqlmock \
		HdrHistogram:hdrhistogram-go:v1.1.2:hdrhistogram_hdrhistogram_go/vendor/github.com/HdrHistogram/hdrhistogram-go \
		MFAshby:stdemuxerhook:v1.0.0:mfashby_stdemuxerhook/vendor/github.com/MFAshby/stdemuxerhook \
		Masterminds:semver:v3.1.1:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Microsoft:go-winio:v0.5.2:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		RoaringBitmap:roaring:v1.2.1:roaringbitmap_roaring/vendor/github.com/RoaringBitmap/roaring \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bits-and-blooms:bitset:v1.3.3:bits_and_blooms_bitset/vendor/github.com/bits-and-blooms/bitset \
		blevesearch:bleve:v2.3.4:blevesearch_bleve_v2/vendor/github.com/blevesearch/bleve/v2 \
		blevesearch:bleve_index_api:v1.0.3:blevesearch_bleve_index_api/vendor/github.com/blevesearch/bleve_index_api \
		blevesearch:geo:v0.1.14:blevesearch_geo/vendor/github.com/blevesearch/geo \
		blevesearch:go-porterstemmer:v1.0.3:blevesearch_go_porterstemmer/vendor/github.com/blevesearch/go-porterstemmer \
		blevesearch:gtreap:v0.1.1:blevesearch_gtreap/vendor/github.com/blevesearch/gtreap \
		blevesearch:mmap-go:v1.0.4:blevesearch_mmap_go/vendor/github.com/blevesearch/mmap-go \
		blevesearch:scorch_segment_api:v2.1.2:blevesearch_scorch_segment_api_v2/vendor/github.com/blevesearch/scorch_segment_api/v2 \
		blevesearch:segment:v0.9.0:blevesearch_segment/vendor/github.com/blevesearch/segment \
		blevesearch:snowballstem:v0.9.0:blevesearch_snowballstem/vendor/github.com/blevesearch/snowballstem \
		blevesearch:upsidedown_store_api:v1.0.1:blevesearch_upsidedown_store_api/vendor/github.com/blevesearch/upsidedown_store_api \
		blevesearch:vellum:v1.0.8:blevesearch_vellum/vendor/github.com/blevesearch/vellum \
		blevesearch:zapx:v11.3.5:blevesearch_zapx_v11/vendor/github.com/blevesearch/zapx/v11 \
		blevesearch:zapx:v12.3.5:blevesearch_zapx_v12/vendor/github.com/blevesearch/zapx/v12 \
		blevesearch:zapx:v13.3.5:blevesearch_zapx_v13/vendor/github.com/blevesearch/zapx/v13 \
		blevesearch:zapx:v14.3.5:blevesearch_zapx_v14/vendor/github.com/blevesearch/zapx/v14 \
		blevesearch:zapx:v15.3.5:blevesearch_zapx_v15/vendor/github.com/blevesearch/zapx/v15 \
		cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		codeclysm:extract:v2.2.0:codeclysm_extract/vendor/github.com/codeclysm/extract \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgraph-io:ristretto:v0.1.1:dgraph_io_ristretto/vendor/github.com/dgraph-io/ristretto \
		docker:distribution:v2.8.1:docker_distribution/vendor/github.com/docker/distribution \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.5.0:docker_go_units/vendor/github.com/docker/go-units \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		etcd-io:bbolt:v1.3.6:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		getsentry:sentry-go:v0.14.0:getsentry_sentry_go/vendor/github.com/getsentry/sentry-go \
		go-macaroon:macaroon:v2.1.0:go_macaroon_macaroon/vendor/gopkg.in/macaroon.v2 \
		go-task:slim-sprig:348f09dbbbc0:go_task_slim_sprig/vendor/github.com/go-task/slim-sprig \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:crypto:v0.1.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:c99f073a8326:golang_exp/vendor/golang.org/x/exp \
		golang:geo:740aa86cb551:golang_geo/vendor/github.com/golang/geo \
		golang:glog:v1.0.0:golang_glog/vendor/github.com/golang/glog \
		golang:image:v0.1.0:golang_image/vendor/golang.org/x/image \
		golang:mobile:b36e6246172e:golang_mobile/vendor/golang.org/x/mobile \
		golang:mock:v1.6.0:golang_mock/vendor/github.com/golang/mock \
		golang:mod:v0.6.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.1.0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:v0.1.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.1.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.4.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.1.0:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.2.0:golang_tools/vendor/golang.org/x/tools \
		gologme:log:v1.3.0:gologme_log/vendor/github.com/gologme/log \
		google:go-cmp:v0.5.9:google_go_cmp/vendor/github.com/google/go-cmp \
		google:pprof:94a9f03dee38:google_pprof/vendor/github.com/google/pprof \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.5.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		gotestyourself:gotest.tools:v3.4.0:gotestyourself_gotest_tools/vendor/gotest.tools/v3 \
		h2non:bimg:v1.1.9:h2non_bimg/vendor/gopkg.in/h2non/bimg.v1 \
		h2non:filetype:v1.1.3:h2non_filetype/vendor/github.com/h2non/filetype \
		json-iterator:go:v1.1.12:json_iterator_go/vendor/github.com/json-iterator/go \
		juju:errors:v1.0.0:juju_errors/vendor/github.com/juju/errors \
		kardianos:minwinsvc:v1.0.2:kardianos_minwinsvc/vendor/github.com/kardianos/minwinsvc \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		klauspost:compress:v1.15.11:klauspost_compress/vendor/github.com/klauspost/compress \
		kr:pretty:v0.3.1:kr_pretty/vendor/github.com/kr/pretty \
		lib:pq:v1.10.7:lib_pq/vendor/github.com/lib/pq \
		lucas-clemente:quic-go:v0.30.0:lucas_clemente_quic_go/vendor/github.com/lucas-clemente/quic-go \
		lukechampine:uint128:v1.2.0:lukechampine_uint128/vendor/lukechampine.com/uint128 \
		marten-seemann:qtls-go1-18:v0.1.3:marten_seemann_qtls_go1_18/vendor/github.com/marten-seemann/qtls-go1-18 \
		marten-seemann:qtls-go1-19:v0.1.1:marten_seemann_qtls_go1_19/vendor/github.com/marten-seemann/qtls-go1-19 \
		matrix-org:dugong:66e6b1c67e2e:matrix_org_dugong/vendor/github.com/matrix-org/dugong \
		matrix-org:go-sqlite3-js:28aa791a1c91:matrix_org_go_sqlite3_js/vendor/github.com/matrix-org/go-sqlite3-js \
		matrix-org:gomatrix:ceba4d9f7530:matrix_org_gomatrix/vendor/github.com/matrix-org/gomatrix \
		matrix-org:gomatrixserverlib:d8748f6d5dc8:matrix_org_gomatrixserverlib/vendor/github.com/matrix-org/gomatrixserverlib \
		matrix-org:pinecone:fef26631b847:matrix_org_pinecone/vendor/github.com/matrix-org/pinecone \
		matrix-org:util:55161520e1d4:matrix_org_util/vendor/github.com/matrix-org/util \
		mattn:go-isatty:v0.0.16:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-sqlite3:v1.14.15:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		matttproud:golang_protobuf_extensions:c182affec369:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		minio:highwayhash:v1.0.2:minio_highwayhash/vendor/github.com/minio/highwayhash \
		moby:moby:v20.10.19:moby_moby/vendor/github.com/docker/docker \
		moby:term:39b0c02b01ae:moby_term/vendor/github.com/moby/term \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.2:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		morikuni:aec:v1.0.0:morikuni_aec/vendor/github.com/morikuni/aec \
		mschoch:smat:v0.2.0:mschoch_smat/vendor/github.com/mschoch/smat \
		nats-io:jwt:v2.3.0:nats_io_jwt_v2/vendor/github.com/nats-io/jwt \
		nats-io:nats-server:v2.9.8:nats_io_nats_server_v2/vendor/github.com/nats-io/nats-server/v2 \
		nats-io:nats.go:v1.20.0:nats_io_nats_go/vendor/github.com/nats-io/nats.go \
		nats-io:nkeys:v0.3.0:nats_io_nkeys/vendor/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/github.com/nats-io/nuid \
		neilalexander:utp:54ae7b1cd5f9:neilalexander_utp/vendor/github.com/neilalexander/utp \
		nfnt:resize:83c6a9932646:nfnt_resize/vendor/github.com/nfnt/resize \
		ngrok:sqlmw:97c9c04efc79:ngrok_sqlmw/vendor/github.com/ngrok/sqlmw \
		nhooyr:websocket:v1.8.7:nhooyr_websocket/vendor/nhooyr.io/websocket \
		onsi:ginkgo:v2.3.0:onsi_ginkgo_v2/vendor/github.com/onsi/ginkgo/v2 \
		onsi:gomega:v1.22.1:onsi_gomega/vendor/github.com/onsi/gomega \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:c5a74bcca799:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.13.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.37.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.8.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.28.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		remyoudompheng:bigfft:ef77025ab5aa:remyoudompheng_bigfft/vendor/github.com/remyoudompheng/bigfft \
		sirupsen:logrus:v1.9.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		stretchr:testify:v1.8.1:stretchr_testify/vendor/github.com/stretchr/testify \
		tidwall:gjson:v1.14.3:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.1.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.2.0:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tidwall:sjson:v1.2.5:tidwall_sjson/vendor/github.com/tidwall/sjson \
		uber-go:atomic:v1.10.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber:jaeger-client-go:v2.30.0:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		uber:jaeger-lib:v2.4.1:uber_jaeger_lib/vendor/github.com/uber/jaeger-lib \
		yggdrasil-network:yggdrasil-go:v0.4.6:yggdrasil_network_yggdrasil_go/vendor/github.com/yggdrasil-network/yggdrasil-go

GL_TUPLE=	\
		cznic:cc:03159e8e41eec8d08c1e502bfc46868b9a03aa57:cznic_cc/vendor/modernc.org/cc/v3 \
		cznic:ccgo:261537637ce8941f62642fdcc5bf35f770328f26:cznic_ccgo/vendor/modernc.org/ccgo/v3 \
		cznic:libc:fb68bf378cdc24605253253d3e57488f10694dba:cznic_libc/vendor/modernc.org/libc \
		cznic:mathutil:b13e5b5643328f15fd2fcedc85f647f0d8f9180f:cznic_mathutil/vendor/modernc.org/mathutil \
		cznic:memory:75976e411b2d8e904972fb8d6e26b6160202c8ac:cznic_memory/vendor/modernc.org/memory \
		cznic:opt:6b647abadf922391a4527f3a4fa1817eff08b7cd:cznic_opt/vendor/modernc.org/opt \
		cznic:sqlite:e35b2ec9f0ca45816257314f9d0f24544901a247:cznic_sqlite/vendor/modernc.org/sqlite \
		cznic:strutil:bba0c72b66bb9ced2dfd2ee521b7f16b2cbb39fa:cznic_strutil/vendor/modernc.org/strutil \
		cznic:token:a1b392cca155ddafa8e1e45905db0dfe27cd4714:cznic_token/vendor/modernc.org/token

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dendrite-sample.monolith.yaml ${STAGEDIR}${ETCDIR}/${PORTNAME}.yaml.sample
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
