PORTNAME=	consul
PORTVERSION=	1.11.3
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
# co-maintainer: brd
COMMENT=	Service discovery and configuration made easy

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	hashicorp

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp

GITID=		e319d7ed

# match upstream binary
# BUILDID=	jEUiMg_1RMhlbZeyNYjV/ijwJGvqKqRf1Lp83NMdl/IgvEGfTeWaZiOZl1A74t/280WzJjHc5prHay9fQQr \
# CGO_ENABLED=	0
# GO_BUILDFLAGS=	-ldflags=" \
#		-buildid=${BUILDID} -extldflags=-static

CONSULUITAG=	${DISTVERSIONPREFIX}${PORTVERSION}

GO_BUILDFLAGS=	-ldflags=" \
		-X github.com/hashicorp/consul/version.GitCommit=${GITID} \
		"

USE_RC_SUBR=	consul

PLIST_FILES=	bin/consul

ETCDIR=			${PREFIX}/etc/${PORTNAME}.d
CONSUL_USER?=		consul
CONSUL_GROUP?=		consul
CONSUL_DBDIR?=		/var/db/${PORTNAME}

USERS=		${CONSUL_USER}
GROUPS=		${CONSUL_GROUP}

SUB_LIST=	CONSUL_DBDIR=${CONSUL_DBDIR} \
		GROUP=${CONSUL_GROUP} \
		USER=${CONSUL_USER}

GH_TUPLE=	\
		swills:consului:${CONSULUITAG}:consului \
		Azure:azure-sdk-for-go:v44.0.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-autorest:8ac76a649a39:azure_go_autorest_cli \
		Azure:go-autorest:9210cb7ab0b1:azure_go_autorest_auth \
		Azure:go-autorest:autorest/v0.11.0:azure_go_autorest_autorest \
		Azure:go-autorest:b3a0b30a7423:azure_go_autorest_date \
		Azure:go-autorest:fe6b9117e507:azure_go_autorest_adal \
		Azure:go-autorest:logger/v0.2.0:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.6.0:azure_go_autorest_tracing \
		Azure:go-autorest:v14.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		DataDog:datadog-go:v3.2.0:datadog_datadog_go/vendor/github.com/DataDog/datadog-go \
		Microsoft:go-winio:v0.4.3:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		NYTimes:gziphandler:v1.0.1:nytimes_gziphandler/vendor/github.com/NYTimes/gziphandler \
		StackExchange:wmi:v1.2.1:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		armon:circbuf:bbbad097214e:armon_circbuf/vendor/github.com/armon/circbuf \
		armon:go-metrics:v0.3.10:armon_go_metrics/vendor/github.com/armon/go-metrics \
		armon:go-radix:v1.0.0:armon_go_radix/vendor/github.com/armon/go-radix \
		aws:aws-sdk-go:v1.25.41:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bgentry:speakeasy:v0.1.0:bgentry_speakeasy/vendor/github.com/bgentry/speakeasy \
		boltdb:bolt:v1.3.1:boltdb_bolt/vendor/github.com/boltdb/bolt \
		census-instrumentation:opencensus-go:v0.22.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		census-instrumentation:opencensus-proto:v0.2.1:census_instrumentation_opencensus_proto/vendor/github.com/census-instrumentation/opencensus-proto \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		circonus-labs:circonus-gometrics:v2.3.1:circonus_labs_circonus_gometrics/vendor/github.com/circonus-labs/circonus-gometrics \
		circonus-labs:circonusllhist:v0.1.3:circonus_labs_circonusllhist/vendor/github.com/circonus-labs/circonusllhist \
		cncf:udpa:5f7e5dd04533:cncf_udpa_go/vendor/github.com/cncf/udpa \
		coredns:coredns:v1.1.2:coredns_coredns/vendor/github.com/coredns/coredns \
		coreos:go-oidc:v2.1.0:coreos_go_oidc/vendor/github.com/coreos/go-oidc \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		denverdino:aliyungo:d3308649c661:denverdino_aliyungo/vendor/github.com/denverdino/aliyungo \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		digitalocean:godo:v1.10.0:digitalocean_godo/vendor/github.com/digitalocean/godo \
		dimchansky:utfbom:v1.1.0:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		docker:go-connections:v0.3.0:docker_go_connections/vendor/github.com/docker/go-connections \
		elazarl:go-bindata-assetfs:e1a2a7ec64b0:elazarl_go_bindata_assetfs/vendor/github.com/elazarl/go-bindata-assetfs \
		envoyproxy:go-control-plane:v0.9.5:envoyproxy_go_control_plane/vendor/github.com/envoyproxy/go-control-plane \
		envoyproxy:protoc-gen-validate:v0.1.0:envoyproxy_protoc_gen_validate/vendor/github.com/envoyproxy/protoc-gen-validate \
		etcd-io:bbolt:v1.3.5:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ole:go-ole:v1.2.6:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-resty:resty:v1.12.0:go_resty_resty/vendor/gopkg.in/resty.v1 \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:c07d793c2f9a:golang_crypto/vendor/golang.org/x/crypto \
		golang:lint:16217165b5de:golang_lint/vendor/golang.org/x/lint \
		golang:net:491a49abca63:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369cfe45:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.5:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:97ac67df715c:golang_sys/vendor/golang.org/x/sys \
		golang:term:7de9c90e9dd1:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		golang:time:3af7569d3a1e:golang_time/vendor/golang.org/x/time \
		golang:tools:113979e3529a:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:btree:v1.0.0:google_btree/vendor/github.com/google/btree \
		google:go-cmp:v0.5.6:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:24fa4b261c55:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:gofuzz:v1.2.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:pprof:01bbb1931b22:google_pprof/vendor/github.com/google/pprof \
		google:tcpproxy:dfa16c61dad2:google_tcpproxy/vendor/github.com/google/tcpproxy \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:gnostic:v0.2.0:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.9.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.38.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gophercloud:gophercloud:v0.1.0:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		gotestyourself:gotest.tools:v3.0.3:gotestyourself_gotest_tools/vendor/gotest.tools/v3 \
		grpc:grpc-go:v1.25.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:consul:v1.11.0:hashicorp_consul_api/github.com/hashicorp/consul/api \
		hashicorp:consul:v0.8.0:hashicorp_consul_sdk/github.com/hashicorp/consul/sdk \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-bexpr:v0.1.2:hashicorp_go_bexpr/vendor/github.com/hashicorp/go-bexpr \
		hashicorp:go-checkpoint:v0.5.0:hashicorp_go_checkpoint/vendor/github.com/hashicorp/go-checkpoint \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-connlimit:v0.3.0:hashicorp_go_connlimit/vendor/github.com/hashicorp/go-connlimit \
		hashicorp:go-discover:c573d69da192:hashicorp_go_discover/vendor/github.com/hashicorp/go-discover \
		hashicorp:go-hclog:v0.14.1:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-immutable-radix:v1.3.0:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-memdb:v1.3.1:hashicorp_go_memdb/vendor/github.com/hashicorp/go-memdb \
		hashicorp:go-msgpack:v0.5.5:hashicorp_go_msgpack/vendor/github.com/hashicorp/go-msgpack \
		hashicorp:go-multierror:v1.1.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-raftchunking:v0.6.1:hashicorp_go_raftchunking/vendor/github.com/hashicorp/go-raftchunking \
		hashicorp:go-retryablehttp:v0.6.7:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-rootcerts:v1.0.2:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-sockaddr:v1.0.2:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:go-syslog:v1.0.0:hashicorp_go_syslog/vendor/github.com/hashicorp/go-syslog \
		hashicorp:go-uuid:v1.0.2:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:go-version:v1.2.1:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:hil:a18a1cd20038:hashicorp_hil/vendor/github.com/hashicorp/hil \
		hashicorp:mdns:v1.0.4:hashicorp_mdns/vendor/github.com/hashicorp/mdns \
		hashicorp:memberlist:v0.3.1:hashicorp_memberlist/vendor/github.com/hashicorp/memberlist \
		hashicorp:net-rpc-msgpackrpc:a14192a58a69:hashicorp_net_rpc_msgpackrpc/vendor/github.com/hashicorp/net-rpc-msgpackrpc \
		hashicorp:raft-autopilot:v0.1.5:hashicorp_raft_autopilot/vendor/github.com/hashicorp/raft-autopilot \
		hashicorp:raft-boltdb:v2.2.0:hashicorp_raft_boltdb_v2/vendor/github.com/hashicorp/raft-boltdb \
		hashicorp:raft:v1.3.3:hashicorp_raft/vendor/github.com/hashicorp/raft \
		hashicorp:serf:v0.9.7:hashicorp_serf/vendor/github.com/hashicorp/serf \
		hashicorp:vault:e0cfd64bc267:hashicorp_vault_sdk/vendor/github.com/hashicorp/vault \
		hashicorp:vault:f687267c8086:hashicorp_vault_api \
		hashicorp:vic:bbfe86ec9443:hashicorp_vic/vendor/github.com/hashicorp/vic \
		hashicorp:yamux:26ff87cf9493:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		imdario:mergo:v0.3.6:imdario_mergo/vendor/github.com/imdario/mergo \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		joyent:triton-go:6801d15b779f:joyent_triton_go/vendor/github.com/joyent/triton-go \
		json-iterator:go:v1.1.9:json_iterator_go/vendor/github.com/json-iterator/go \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kr:text:v0.1.0:kr_text/vendor/github.com/kr/text \
		kubernetes-sigs:structured-merge-diff:v3.0.0:kubernetes_sigs_structured_merge_diff/vendor/sigs.k8s.io/structured-merge-diff/v3 \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.18.2:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:v0.18.2:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v0.18.2:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v1.0.0:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:utils:a9aa75ae1b89:kubernetes_utils/vendor/k8s.io/utils \
		linode:linodego:v0.7.1:linode_linodego/vendor/github.com/linode/linodego \
		lufia:plan9stats:39d0f177ccd0:lufia_plan9stats/vendor/github.com/lufia/plan9stats \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.41:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:cli:v1.1.0:mitchellh_cli/vendor/github.com/mitchellh/cli \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-testing-interface:v1.14.0:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:hashstructure:2bca23e0e452:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		mitchellh:mapstructure:8ebf2d61a8b4:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:pointerstructure:v1.0.0:mitchellh_pointerstructure/vendor/github.com/mitchellh/pointerstructure \
		mitchellh:reflectwalk:v1.0.1:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		nicolai86:scaleway-sdk:798f60e20bb2:nicolai86_scaleway_sdk/vendor/github.com/nicolai86/scaleway-sdk \
		packethost:packngo:b9cb5096f54c:packethost_packngo/vendor/github.com/packethost/packngo \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pierrec:lz4:v2.5.2:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		posener:complete:v1.2.3:posener_complete/vendor/github.com/posener/complete \
		pquerna:cachecontrol:1555304b9b35:pquerna_cachecontrol/vendor/github.com/pquerna/cachecontrol \
		prometheus:client_golang:v1.4.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.9.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.8:prometheus_procfs/vendor/github.com/prometheus/procfs \
		rboyer:safeio:v0.2.1:rboyer_safeio/vendor/github.com/rboyer/safeio \
		renier:xmlrpc:ce4a1a486c03:renier_xmlrpc/vendor/github.com/renier/xmlrpc \
		ryanuber:columnize:v2.1.0:ryanuber_columnize/vendor/github.com/ryanuber/columnize \
		ryanuber:go-glob:v1.0.0:ryanuber_go_glob/vendor/github.com/ryanuber/go-glob \
		sean-:seed:e2103e2c3529:sean__seed/vendor/github.com/sean-/seed \
		shirou:gopsutil:v3.21.10:shirou_gopsutil_v3/vendor/github.com/shirou/gopsutil \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		softlayer:softlayer-go:260589d94c7d:softlayer_softlayer_go/vendor/github.com/softlayer/softlayer-go \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		square:go-jose:v2.5.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:objx:v0.1.1:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tencentcloud:tencentcloud-sdk-go:v1.0.162:tencentcloud_tencentcloud_sdk_go/vendor/github.com/tencentcloud/tencentcloud-sdk-go \
		tklauser:go-sysconf:v0.3.9:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.3.0:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		tv42:httpunix:b75d8614f926:tv42_httpunix/vendor/github.com/tv42/httpunix \
		uber-go:goleak:v1.1.10:uber_go_goleak/vendor/go.uber.org/goleak \
		vmware:govmomi:v0.18.0:vmware_govmomi/vendor/github.com/vmware/govmomi

post-extract:
	${MKDIR} ${WRKSRC}/vendor/github.com/${GH_ACCOUNT}/${PORTNAME}
	${LN} -s ${WRKSRC}/api ${WRKSRC}/vendor/github.com/${GH_ACCOUNT}/${PORTNAME}/api
	${LN} -s ${WRKSRC}/sdk ${WRKSRC}/vendor/github.com/${GH_ACCOUNT}/${PORTNAME}/sdk
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
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RM} -r ${WRKSRC}/vendor/github.com/hashicorp/vault/api
	@${RLN} ${WRKSRC_hashicorp_vault_api}/api ${WRKSRC}/vendor/github.com/hashicorp/vault/api

post-patch:
	@${CP} ${WRKDIR}/consului-${PORTVERSION}/agent/uiserver/bindata_assetfs.go \
		${WRKDIR}/consul-${PORTVERSION}/agent/uiserver/bindata_assetfs.go

.include <bsd.port.mk>
