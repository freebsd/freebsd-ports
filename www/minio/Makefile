# $FreeBSD$

PORTNAME=	minio
PORTVERSION=	${GH_TAGNAME:S/RELEASE.//:S/Z//:S/T/-/:S/-/./g}
CATEGORIES=	www
DIST_SUBDIR=	minio

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Amazon S3 compatible object storage server

LICENSE=	APACHE20

USES=		compiler go:modules

USE_GITHUB=	yes
GHTAG=		RELEASE.2021-03-12T00-00-47Z
COMMIT_ID=	feafccf0072a9b5fbddc33553890ff56cb2f83b6

GH_TUPLE=	${PORTNAME}:${PORTNAME}:${GHTAG}:DEFAULT \
		Azure:azure-pipeline-go:v0.2.2:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-storage-blob-go:v0.10.0:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		Azure:go-autorest:8f84370b53ea:azure_go_autorest_adal/vendor/github.com/Azure/go-autorest \
		Azure:go-ntlmssp:66371956d46c:azure_go_ntlmssp/vendor/github.com/Azure/go-ntlmssp \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Shopify:sarama:v1.27.2:shopify_sarama/vendor/github.com/Shopify/sarama \
		StackExchange:wmi:cbe66965904d:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		alecthomas:participle:v0.2.1:alecthomas_participle/vendor/github.com/alecthomas/participle \
		apache:thrift:v0.13.0:apache_thrift/vendor/git.apache.org/thrift.git \
		bcicen:jstream:v1.0.1:bcicen_jstream/vendor/github.com/bcicen/jstream \
		beevik:ntp:v0.3.0:beevik_ntp/vendor/github.com/beevik/ntp \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		census-instrumentation:opencensus-go:v0.22.5:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cheggaaa:pb:v1.0.29:cheggaaa_pb/vendor/github.com/cheggaaa/pb \
		colinmarc:hdfs:v2.2.0:colinmarc_hdfs_v2/vendor/github.com/colinmarc/hdfs/v2 \
		coredns:coredns:v1.4.0:coredns_coredns/vendor/github.com/coredns/coredns \
		coreos:go-semver:v0.2.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		coreos:go-systemd:39ca1b05acc7:coreos_go_systemd/vendor/github.com/coreos/go-systemd \
		coreos:pkg:3ac0863d7acf:coreos_pkg/vendor/github.com/coreos/pkg \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dchest:siphash:v1.2.1:dchest_siphash/vendor/github.com/dchest/siphash \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		djherbis:atime:v1.0.0:djherbis_atime/vendor/github.com/djherbis/atime \
		dominikh:go-tools:v0.0.1-2019.2.3:dominikh_go_tools/vendor/honnef.co/go/tools \
		dswarbrick:smart:909a45200d6d:dswarbrick_smart/vendor/github.com/dswarbrick/smart \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		eapache:go-resiliency:v1.2.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:776d5712da21:eapache_go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:eapache_queue/vendor/github.com/eapache/queue \
		eclipse:paho.mqtt.golang:v1.3.0:eclipse_paho_mqtt_golang/vendor/github.com/eclipse/paho.mqtt.golang \
		etcd-io:etcd:8a03d2e9614b:etcd_io_etcd/vendor/go.etcd.io/etcd \
		fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		fatih:structs:v1.1.0:fatih_structs/vendor/github.com/fatih/structs \
		felixge:httpsnoop:v1.0.1:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		go-asn1-ber:asn1-ber:v1.5.1:go_asn1_ber_asn1_ber/vendor/github.com/go-asn1-ber/asn1-ber \
		go-ini:ini:v1.57.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-ldap:ldap:v3.2.4:go_ldap_ldap_v3/vendor/github.com/go-ldap/ldap \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.3.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.4.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:c8d3bf9c5392:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:869f871628b6:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:16217165b5de:golang_lint/vendor/golang.org/x/lint \
		golang:mod:v0.3.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:986b41b23924:golang_net/vendor/golang.org/x/net \
		golang:oauth2:e64efc72b421:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:b64e53b001e4:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.1.0:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		gomodule:redigo:v1.8.3:gomodule_redigo/vendor/github.com/gomodule/redigo \
		google:go-genproto:24fa4b261c55:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.4:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.5.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.39.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:handlers:v1.5.1:gorilla_handlers/vendor/github.com/gorilla/handlers \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.26.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-retryablehttp:v0.5.4:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-rootcerts:v1.0.1:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-sockaddr:v1.0.2:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:go-uuid:v1.0.2:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:vault:api/v1.0.4:hashicorp_vault_api/vendor/github.com/hashicorp/vault \
		hashicorp:vault:sdk/v0.1.13:hashicorp_vault_sdk \
		jcmturner:aescts:v1.0.1:jcmturner_aescts/vendor/gopkg.in/jcmturner/aescts.v1 \
		jcmturner:aescts:v2.0.0:jcmturner_aescts_v2/vendor/github.com/jcmturner/aescts \
		jcmturner:dnsutils:v1.0.1:jcmturner_dnsutils/vendor/gopkg.in/jcmturner/dnsutils.v1 \
		jcmturner:dnsutils:v2.0.0:jcmturner_dnsutils_v2/vendor/github.com/jcmturner/dnsutils \
		jcmturner:gofork:v1.0.0:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:goidentity:v6.0.1:jcmturner_goidentity_v6/vendor/github.com/jcmturner/goidentity \
		jcmturner:gokrb5:v7.5.0:jcmturner_gokrb5/vendor/gopkg.in/jcmturner/gokrb5.v7 \
		jcmturner:gokrb5:v8.4.2:jcmturner_gokrb5_v8/vendor/github.com/jcmturner/gokrb5 \
		jcmturner:rpc:v1.1.0:jcmturner_rpc/vendor/gopkg.in/jcmturner/rpc.v1 \
		jcmturner:rpc:v2.0.3:jcmturner_rpc_v2/vendor/github.com/jcmturner/rpc \
		josharian:intern:v1.0.0:josharian_intern/vendor/github.com/josharian/intern \
		json-iterator:go:v1.1.10:json_iterator_go/vendor/github.com/json-iterator/go \
		klauspost:compress:v1.11.12:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v1.3.1:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
		klauspost:cpuid:v2.0.4:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
		klauspost:pgzip:v1.2.5:klauspost_pgzip/vendor/github.com/klauspost/pgzip \
		klauspost:readahead:v1.3.1:klauspost_readahead/vendor/github.com/klauspost/readahead \
		klauspost:reedsolomon:v1.9.11:klauspost_reedsolomon/vendor/github.com/klauspost/reedsolomon \
		lib:pq:v1.8.0:lib_pq/vendor/github.com/lib/pq \
		mailru:easyjson:v0.7.6:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-ieproxy:v0.0.1:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.35:miekg_dns/vendor/github.com/miekg/dns \
		minio:cli:v1.22.0:minio_cli/vendor/github.com/minio/cli \
		minio:highwayhash:v1.0.1:minio_highwayhash/vendor/github.com/minio/highwayhash \
		minio:md5-simd:v1.1.1:minio_md5_simd/vendor/github.com/minio/md5-simd \
		minio:minio-go:6ae69c73ce78:minio_minio_go_v7/vendor/github.com/minio/minio-go/v7 \
		minio:selfupdate:v0.3.1:minio_selfupdate/vendor/github.com/minio/selfupdate \
		minio:sha256-simd:v1.0.0:minio_sha256_simd/vendor/github.com/minio/sha256-simd \
		minio:simdjson-go:v0.2.1:minio_simdjson_go/vendor/github.com/minio/simdjson-go \
		minio:sio:v0.2.1:minio_sio/vendor/github.com/minio/sio \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		montanaflynn:stats:v0.5.0:montanaflynn_stats/vendor/github.com/montanaflynn/stats \
		nats-io:jwt:v1.1.0:nats_io_jwt/vendor/github.com/nats-io/jwt \
		nats-io:nats-server:v2.1.9:nats_io_nats_server_v2/vendor/github.com/nats-io/nats-server/v2 \
		nats-io:nats-streaming-server:v0.19.0:nats_io_nats_streaming_server/vendor/github.com/nats-io/nats-streaming-server \
		nats-io:nats.go:v1.10.0:nats_io_nats_go/vendor/github.com/nats-io/nats.go \
		nats-io:nkeys:v0.2.0:nats_io_nkeys/vendor/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/github.com/nats-io/nuid \
		nats-io:stan.go:v0.7.0:nats_io_stan_go/vendor/github.com/nats-io/stan.go \
		ncw:directio:v1.0.5:ncw_directio/vendor/github.com/ncw/directio \
		nsqio:go-nsq:v1.0.8:nsqio_go_nsq/vendor/github.com/nsqio/go-nsq \
		olivere:elastic:v7.0.22:olivere_elastic_v7/vendor/github.com/olivere/elastic/v7 \
		philhofer:fwd:v1.1.1:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pierrec:lz4:v2.5.2:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		prometheus:client_golang:v1.8.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.14.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.2.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rcrowley:go-metrics:10cdbea86bc0:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		rjeczalik:notify:v0.9.2:rjeczalik_notify/vendor/github.com/rjeczalik/notify \
		rs:cors:v1.7.0:rs_cors/vendor/github.com/rs/cors \
		rs:xid:v1.2.1:rs_xid/vendor/github.com/rs/xid \
		ryanuber:go-glob:v1.0.0:ryanuber_go_glob/vendor/github.com/ryanuber/go-glob \
		secure-io:sio-go:v0.3.1:secure_io_sio_go/vendor/github.com/secure-io/sio-go \
		shirou:gopsutil:v3.21.1:shirou_gopsutil_v3/vendor/github.com/shirou/gopsutil \
		spaolacci:murmur3:v1.1.0:spaolacci_murmur3/vendor/github.com/spaolacci/murmur3 \
		square:go-jose:v2.3.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		streadway:amqp:v1.0.0:streadway_amqp/vendor/github.com/streadway/amqp \
		tidwall:gjson:v1.6.7:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.0.3:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.0.2:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tidwall:sjson:v1.0.4:tidwall_sjson/vendor/github.com/tidwall/sjson \
		tinylib:msgp:v1.1.3:tinylib_msgp/vendor/github.com/tinylib/msgp \
		ttacon:chalk:22c06c80ed31:ttacon_chalk/vendor/github.com/ttacon/chalk \
		uber-go:atomic:v1.5.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.3.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:tools:2cfd321de3ee:uber_go_tools/vendor/go.uber.org/tools \
		uber-go:zap:v1.13.0:uber_go_zap/vendor/go.uber.org/zap \
		valyala:tcplisten:ceec8f93295a:valyala_tcplisten/vendor/github.com/valyala/tcplisten \
		willf:bitset:v1.1.11:willf_bitset/vendor/github.com/willf/bitset \
		willf:bloom:v2.0.3:willf_bloom/vendor/github.com/willf/bloom \
		xdg:scram:7eeb5667e42c:xdg_scram/vendor/github.com/xdg/scram \
		xdg:stringprep:v1.0.0:xdg_stringprep/vendor/github.com/xdg/stringprep

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/hashicorp/vault/sdk
	@${RLN} ${WRKSRC_hashicorp_vault_sdk}/sdk ${WRKSRC}/vendor/github.com/hashicorp/vault/sdk

GO_BUILDFLAGS=	-ldflags=' \
		-X github.com/minio/minio/cmd.Version=${GH_TAGNAME:C/RELEASE\.//:C|(..)-(..)-(..)Z|\1:\2:\3Z|} \
		-X github.com/minio/minio/cmd.ReleaseTag=${GH_TAGNAME} \
		-X github.com/minio/minio/cmd.CommitID=${COMMIT_ID} \
		-X github.com/minio/minio/cmd.ShortCommitID=${COMMIT_ID:C|(............).*|\1|} \
		-X github.com/minio/minio/cmd.GOPATH=${WRKSRC} -s -w'

PLIST_FILES=	bin/${PORTNAME}
USE_RC_SUBR=	${PORTNAME}

MINIO_USER?=	${PORTNAME}
MINIO_GROUP?=	${PORTNAME}
MINIO_DBDIR?=	/var/db/${PORTNAME}

USERS=		${MINIO_USER}
GROUPS=		${MINIO_GROUP}

SUB_LIST=	DBDIR=${MINIO_DBDIR} \
		GROUP="${GROUPS}" \
		USER="${USERS}"

.include <bsd.port.mk>
