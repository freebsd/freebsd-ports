PORTNAME=	promscale
DISTVERSION=	0.6.2
PORTREVISION=	3
CATEGORIES=	net-mgmt

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Timescale analytical platform for Prometheus metrics

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	timescale
GH_TUPLE=	Microsoft:go-winio:6eac466e5fa3:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Microsoft:hcsshim:v0.8.15:microsoft_hcsshim/vendor/github.com/Microsoft/hcsshim \
		NYTimes:gziphandler:v1.1.1:nytimes_gziphandler/vendor/github.com/NYTimes/gziphandler \
		alecthomas:units:ff826a37aa15:alecthomas_units/vendor/github.com/alecthomas/units \
		aws:aws-sdk-go:v1.38.35:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		blang:semver:v4.0.0:blang_semver_v4/vendor/github.com/blang/semver \
		cenkalti:backoff:v2.2.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		census-instrumentation:opencensus-go:v0.23.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cilium:ebpf:v0.2.0:cilium_ebpf/vendor/github.com/cilium/ebpf \
		containerd:cgroups:8a68de567b68:containerd_cgroups/vendor/github.com/containerd/cgroups \
		containerd:containerd:v1.5.0-beta.1:containerd_containerd/vendor/github.com/containerd/containerd \
		coreos:go-systemd:v22.1.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		docker:distribution:v2.7.1:docker_distribution/vendor/github.com/docker/distribution \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		edsrzf:mmap-go:v1.0.0:edsrzf_mmap_go/vendor/github.com/edsrzf/mmap-go \
		felixge:fgprof:v0.9.1:felixge_fgprof/vendor/github.com/felixge/fgprof \
		go-kit:kit:v0.10.0:go_kit_kit/vendor/github.com/go-kit/kit \
		go-logfmt:logfmt:v0.5.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		godbus:dbus:v5.0.3:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:0c34fe9e7dc2:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:83fdc39ff7b5:golang_lint/vendor/golang.org/x/lint \
		golang:net:0714010a04ed:golang_net/vendor/golang.org/x/net \
		golang:oauth2:81ed05c6b58c:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.3:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:0981d6026fa6:golang_sys/vendor/golang.org/x/sys \
		golang:term:6a3ed077a48d:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		golang:time:f8bda1e9f3ba:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.1.0:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-genproto:86c259c2b4ab:google_go_genproto/vendor/google.golang.org/genproto \
		google:pprof:3a04a4d88a10:google_pprof/vendor/github.com/google/pprof \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		grpc:grpc-go:v1.37.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:go-hclog:v0.12.2:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-immutable-radix:v1.2.0:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		inhies:go-bytesize:d0aed0d254f8:inhies_go_bytesize/vendor/github.com/inhies/go-bytesize \
		jackc:chunkreader:v2.0.1:jackc_chunkreader_v2/vendor/github.com/jackc/chunkreader/v2 \
		jackc:pgconn:v1.8.1:jackc_pgconn/vendor/github.com/jackc/pgconn \
		jackc:pgerrcode:afa3381909a6:jackc_pgerrcode/vendor/github.com/jackc/pgerrcode \
		jackc:pgio:v1.0.0:jackc_pgio/vendor/github.com/jackc/pgio \
		jackc:pgpassfile:v1.0.0:jackc_pgpassfile/vendor/github.com/jackc/pgpassfile \
		jackc:pgproto3:v2.0.6:jackc_pgproto3_v2/vendor/github.com/jackc/pgproto3/v2 \
		jackc:pgservicefile:2b9c44734f2b:jackc_pgservicefile/vendor/github.com/jackc/pgservicefile \
		jackc:pgtype:v1.4.2:jackc_pgtype/vendor/github.com/jackc/pgtype \
		jackc:pgx:v4.8.0:jackc_pgx_v4/vendor/github.com/jackc/pgx/v4 \
		jackc:puddle:v1.1.1:jackc_puddle/vendor/github.com/jackc/puddle \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		jpillora:backoff:v1.0.0:jpillora_backoff/vendor/github.com/jpillora/backoff \
		julienschmidt:httprouter:v1.3.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:c182affec369:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:colorstring:d06e56a500db:mitchellh_colorstring/vendor/github.com/mitchellh/colorstring \
		moby:moby:v20.10.6:moby_moby/vendor/github.com/docker/docker \
		moby:sys:mount/v0.2.0:moby_sys_mount/vendor/github.com/moby/sys \
		moby:sys:mountinfo/v0.4.0:moby_sys_mountinfo \
		mwitkow:go-conntrack:2f068394615f:mwitkow_go_conntrack/vendor/github.com/mwitkow/go-conntrack \
		oklog:ulid:v1.3.1:oklog_ulid/vendor/github.com/oklog/ulid \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runc:v1.0.0-rc93:opencontainers_runc/vendor/github.com/opencontainers/runc \
		opencontainers:runtime-spec:e6143ca7d51d:opencontainers_runtime_spec/vendor/github.com/opencontainers/runtime-spec \
		opentracing-contrib:go-stdlib:v1.0.0:opentracing_contrib_go_stdlib/vendor/github.com/opentracing-contrib/go-stdlib \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		pbnjay:memory:b12e5d931931:pbnjay_memory/vendor/github.com/pbnjay/memory \
		peterbourgon:ff:v3.0.0:peterbourgon_ff_v3/vendor/github.com/peterbourgon/ff/v3 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.10.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.23.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		prometheus:prometheus:7bc11dcb0664:prometheus_prometheus/vendor/github.com/prometheus/prometheus \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		schollz:progressbar:v3.7.2:schollz_progressbar_v3/vendor/github.com/schollz/progressbar/v3 \
		sergi:go-diff:v1.0.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		shurcooL:vfsgen:0d455de96546:shurcool_vfsgen/vendor/github.com/shurcooL/vfsgen \
		sirupsen:logrus:v1.7.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		testcontainers:testcontainers-go:2bbeb1e04514:testcontainers_testcontainers_go/vendor/github.com/testcontainers/testcontainers-go \
		thanos-io:thanos:v0.20.1:thanos_io_thanos/vendor/github.com/thanos-io/thanos \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:goleak:v1.1.10:uber_go_goleak/vendor/go.uber.org/goleak \
		uber:jaeger-client-go:v2.28.0:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		uber:jaeger-lib:v2.4.1:uber_jaeger_lib/vendor/github.com/uber/jaeger-lib

GO_TARGET=	./cmd/prom-migrator ./cmd/promscale

PLIST_FILES=	bin/prom-migrator \
		bin/promscale

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/moby/sys/mountinfo
	@${RLN} ${WRKSRC_moby_sys_mountinfo}/mountinfo ${WRKSRC}/vendor/github.com/moby/sys/mountinfo

GO_TARGET=	./cmd/promscale ./cmd/prom-migrator

.include <bsd.port.mk>
