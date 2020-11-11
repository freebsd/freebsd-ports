# $FreeBSD$

PORTNAME=	datadog
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	7.23.1
CATEGORIES=	sysutils

MAINTAINER=	uros@gruber.si
COMMENT=	Datadog Server and Application monitoring agent

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	various cgo modules fail on non-x86 architectures

BUILD_DEPENDS=	go>=1.15:lang/go \
		cmake>=3.18:devel/cmake \
		go-bindata>0:devel/go-bindata

USES=		go python:3.7+

DATADOG_PREFIX=	${PREFIX}/bin/${PORTNAME}
LOGDIR=		/var/log/${PORTNAME}
RUNDIR=		/var/run/${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	DataDog
GH_PROJECT=	datadog-agent
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GH_SUBDIR=	src/github.com/DataDog/datadog-agent
GH_TAGNAME=	${DISTVERSION}

# For list of modules you can check:
# https://github.com/DataDog/datadog-agent/blob/${DISTVERSION}/Gopkg.toml
GH_TUPLE=	\
		DataDog:agent-payload:v4.44.0:datadog_agent_payload/src/github.com/DataDog/agent-payload \
		DataDog:cast:1ee8c8bd14a3:datadog_cast/src/github.com/spf13/cast \
		DataDog:datadog-go:v3.5.0:datadog_datadog_go/src/github.com/DataDog/datadog-go \
		DataDog:datadog-operator:9c71245c6822:datadog_datadog_operator/src/github.com/DataDog/datadog-operator \
		DataDog:dd-trace-go:v1.23.1:datadog_dd_trace_go/src/gopkg.in/DataDog/dd-trace-go.v1 \
		DataDog:ebpf:7a8f7d072a50:datadog_ebpf/src/github.com/DataDog/ebpf \
		DataDog:gobpf:5f8313cb4d71:datadog_gobpf/src/github.com/iovisor/gobpf \
		DataDog:gohai:e17d616e422a:datadog_gohai/src/github.com/DataDog/gohai \
		DataDog:gopsutil:1b53412ef321:datadog_gopsutil/src/github.com/DataDog/gopsutil \
		DataDog:mmh3:f5b682d8c981:datadog_mmh3/src/github.com/DataDog/mmh3 \
		DataDog:viper:v1.8.0:datadog_viper/src/github.com/spf13/viper \
		DataDog:watermarkpodautoscaler:v0.1.0:datadog_watermarkpodautoscaler/src/github.com/DataDog/watermarkpodautoscaler \
		DataDog:zstd:2bf71ec48360:datadog_zstd/src/github.com/DataDog/zstd \
		Knetic:govaluate:v3.0.0:knetic_govaluate/src/gopkg.in/Knetic/govaluate.v3 \
		Masterminds:goutils:v1.1.0:masterminds_goutils/src/github.com/Masterminds/goutils \
		Masterminds:semver:v1.5.0:masterminds_semver/src/github.com/Masterminds/semver \
		Masterminds:sprig:v2.22.0:masterminds_sprig/src/github.com/Masterminds/sprig \
		Microsoft:go-winio:fc70bd9a86b5:microsoft_go_winio/src/github.com/Microsoft/go-winio \
		Microsoft:hcsshim:v0.8.7:microsoft_hcsshim/src/github.com/Microsoft/hcsshim \
		NYTimes:gziphandler:v1.1.1:nytimes_gziphandler/src/github.com/NYTimes/gziphandler \
		PuerkitoBio:purell:v1.1.1:puerkitobio_purell/src/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/src/github.com/PuerkitoBio/urlesc \
		StackExchange:wmi:e0a55b97c705:stackexchange_wmi/src/github.com/StackExchange/wmi \
		alecthomas:participle:v0.4.4:alecthomas_participle/src/github.com/alecthomas/participle \
		alecthomas:repr:d37bc2a10ba1:alecthomas_repr/src/github.com/alecthomas/repr \
		armon:go-metrics:v0.3.0:armon_go_metrics/src/github.com/armon/go-metrics \
		aws:aws-sdk-go:v1.30.5:aws_aws_sdk_go/src/github.com/aws/aws-sdk-go \
		beevik:ntp:v0.3.0:beevik_ntp/src/github.com/beevik/ntp \
		benesch:cgosymbolizer:bec6fe6e597b:benesch_cgosymbolizer/src/github.com/benesch/cgosymbolizer \
		beorn7:perks:v1.0.1:beorn7_perks/src/github.com/beorn7/perks \
		bhmj:jsonslice:92c3edaad8e2:bhmj_jsonslice/src/github.com/bhmj/jsonslice \
		blabber:go-freebsd-sysctl:dcd5a22:go_freebsd_sysctl/src/github.com/blabber/go-freebsd-sysctl \
		blang:semver:v3.5.1:blang_semver/src/github.com/blang/semver \
		bmizerany:pat:6226ea591a40:bmizerany_pat/src/github.com/bmizerany/pat \
		cenkalti:backoff:v2.2.1:cenkalti_backoff/src/github.com/cenkalti/backoff \
		census-instrumentation:opencensus-go:v0.22.2:census_instrumentation_opencensus_go/src/go.opencensus.io \
		cespare:xxhash:v1.1.0:cespare_xxhash/src/github.com/cespare/xxhash \
		cihub:seelog:d2c6e5aa9fbf:cihub_seelog/src/github.com/cihub/seelog \
		clbanning:mxj:v1.8.4:clbanning_mxj/src/github.com/clbanning/mxj \
		cloudfoundry:bbs:d7bc971db0db:cloudfoundry_bbs/src/code.cloudfoundry.org/bbs \
		cloudfoundry:cfhttp:v2.0.0:cloudfoundry_cfhttp/src/code.cloudfoundry.org/cfhttp/v2 \
		cloudfoundry:garden:061eda450ad9:cloudfoundry_garden/src/code.cloudfoundry.org/garden \
		cloudfoundry:lager:v2.0.0:cloudfoundry_lager/src/code.cloudfoundry.org/lager \
		cloudfoundry:tlsconfig:bbe0f8da39b3:cloudfoundry_tlsconfig/src/code.cloudfoundry.org/tlsconfig \
		containerd:cgroups:b44481373989:containerd_cgroups/src/github.com/containerd/cgroups \
		containerd:containerd:v1.2.13:containerd_containerd/src/github.com/containerd/containerd \
		containerd:continuity:0f16d7a0959c:containerd_continuity/src/github.com/containerd/continuity \
		containerd:fifo:ff969a566b00:containerd_fifo/src/github.com/containerd/fifo \
		containerd:typeurl:v1.0.0:containerd_typeurl/src/github.com/containerd/typeurl \
		coreos:etcd:v3.3.15:coreos_etcd/src/github.com/coreos/etcd \
		coreos:go-semver:v0.3.0:coreos_go_semver/src/github.com/coreos/go-semver \
		coreos:go-systemd:40e2722dffea:coreos_go_systemd/src/github.com/coreos/go-systemd \
		coreos:pkg:399ea9e2e55f:coreos_pkg/src/github.com/coreos/pkg \
		datadog:extendeddaemonset:94ec1f3a5192:datadog_extendeddaemonset/src/github.com/datadog/extendeddaemonset \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/src/github.com/davecgh/go-spew \
		dgraph-io:ristretto:v0.0.3:dgraph_io_ristretto/src/github.com/dgraph-io/ristretto \
		dgryski:go-jump:e1f439676b57:dgryski_go_jump/src/github.com/dgryski/go-jump \
		docker:distribution:0ac367fd6bee:docker_distribution/src/github.com/docker/distribution \
		docker:go-connections:v0.4.0:docker_go_connections/src/github.com/docker/go-connections \
		docker:go-events:e31b211e4f1c:docker_go_events/src/github.com/docker/go-events \
		docker:go-units:v0.4.0:docker_go_units/src/github.com/docker/go-units \
		docker:spdystream:449fdfce4d96:docker_spdystream/src/github.com/docker/spdystream \
		dsnet:compress:v0.0.1:dsnet_compress/src/github.com/dsnet/compress \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/src/github.com/dustin/go-humanize \
		elastic:go-libaudit:v0.4.0:elastic_go_libaudit/src/github.com/elastic/go-libaudit \
		emicklei:go-restful-swagger12:7524189396c6:emicklei_go_restful_swagger12/src/github.com/emicklei/go-restful-swagger12 \
		emicklei:go-restful:v2.9.6:emicklei_go_restful/src/github.com/emicklei/go-restful \
		etcd-io:etcd:3cf2f69b5738:etcd_io_etcd/src/go.etcd.io/etcd \
		evanphx:json-patch:v4.5.0:evanphx_json_patch/src/github.com/evanphx/json-patch \
		fatih:color:v1.9.0:fatih_color/src/github.com/fatih/color \
		florianl:go-conntrack:v0.2.0:florianl_go_conntrack/src/github.com/florianl/go-conntrack \
		florianl:go-tc:v0.1.0:florianl_go_tc/src/github.com/florianl/go-tc \
		freddierice:go-losetup:fc9adea44124:freddierice_go_losetup/src/github.com/freddierice/go-losetup \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/src/github.com/fsnotify/fsnotify \
		ghodss:yaml:25d852aebe32:ghodss_yaml/src/github.com/ghodss/yaml \
		go-inf:inf:v0.9.1:go_inf_inf/src/gopkg.in/inf.v0 \
		go-ini:ini:v1.55.0:go_ini_ini/src/github.com/go-ini/ini \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/src/github.com/go-ole/go-ole \
		go-openapi:jsonpointer:v0.19.3:go_openapi_jsonpointer/src/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.19.2:go_openapi_jsonreference/src/github.com/go-openapi/jsonreference \
		go-openapi:spec:v0.19.8:go_openapi_spec/src/github.com/go-openapi/spec \
		go-openapi:swag:v0.19.5:go_openapi_swag/src/github.com/go-openapi/swag \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/src/gopkg.in/yaml.v2 \
		gobwas:glob:v0.2.3:gobwas_glob/src/github.com/gobwas/glob \
		godbus:dbus:v4.1.0:godbus_dbus/src/github.com/godbus/dbus \
		gogo:googleapis:v1.3.2:gogo_googleapis/src/github.com/gogo/googleapis \
		gogo:protobuf:v1.3.1:gogo_protobuf/src/github.com/gogo/protobuf \
		golang:appengine:v1.6.5:golang_appengine/src/google.golang.org/appengine \
		golang:crypto:75b288015ac9:golang_crypto/src/golang.org/x/crypto \
		golang:glog:23def4e6c14b:golang_glog/src/github.com/golang/glog \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/src/github.com/golang/groupcache \
		golang:mobile:d2bd2a29d028:golang_mobile/src/golang.org/x/mobile \
		golang:net:c89045814202:golang_net/src/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/src/golang.org/x/oauth2 \
		golang:protobuf:v1.3.2:golang_protobuf/src/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/src/github.com/golang/snappy \
		golang:sync:cd5d95a43a6e:golang_sync/src/golang.org/x/sync \
		golang:sys:196b9ba8737a:golang_sys/src/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/src/golang.org/x/text \
		golang:time:555d28b269f0:golang_time/src/golang.org/x/time \
		golang:tools:82bb89366a1e:golang_tools/src/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/src/golang.org/x/xerrors \
		gomodules:jsonpatch:v3.0.1:gomodules_jsonpatch/src/gomodules.xyz/jsonpatch/v3 \
		gomodules:orderedmap:v0.1.0:gomodules_orderedmap/src/gomodules.xyz/orderedmap \
		google:go-cmp:v0.4.0:google_go_cmp/src/github.com/google/go-cmp \
		google:go-genproto:09dca8ec2884:google_go_genproto/src/google.golang.org/genproto \
		google:gofuzz:v1.0.0:google_gofuzz/src/github.com/google/gofuzz \
		google:gopacket:v1.1.17:google_gopacket/src/github.com/google/gopacket \
		google:uuid:v1.1.1:google_uuid/src/github.com/google/uuid \
		googleapis:gnostic:v0.3.1:googleapis_gnostic/src/github.com/googleapis/gnostic \
		gorilla:mux:v1.7.4:gorilla_mux/src/github.com/gorilla/mux \
		grpc-ecosystem:go-grpc-middleware:v1.2.0:grpc_ecosystem_go_grpc_middleware/src/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:v1.2.0:grpc_ecosystem_go_grpc_prometheus/src/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc-ecosystem:grpc-gateway:v1.12.2:grpc_ecosystem_grpc_gateway/src/github.com/grpc-ecosystem/grpc-gateway \
		grpc:grpc-go:v1.26.0:grpc_grpc_go/src/google.golang.org/grpc \
		hashicorp:consul:v1.4.0:hashicorp_consul_api/src/github.com/hashicorp/consul \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/src/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/src/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-hclog:v0.12.0:hashicorp_go_hclog/src/github.com/hashicorp/go-hclog \
		hashicorp:go-immutable-radix:v1.1.0:hashicorp_go_immutable_radix/src/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/src/github.com/hashicorp/go-multierror \
		hashicorp:go-rootcerts:v1.0.2:hashicorp_go_rootcerts/src/github.com/hashicorp/go-rootcerts \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/src/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/src/github.com/hashicorp/hcl \
		hashicorp:serf:v0.8.5:hashicorp_serf/src/github.com/hashicorp/serf \
		hectane:go-acl:da78bae5fc95:hectane_go_acl/src/github.com/hectane/go-acl \
		huandu:xstrings:v1.2.0:huandu_xstrings/src/github.com/huandu/xstrings \
		ianlancetaylor:cgosymbolizer:f5072df9c550:ianlancetaylor_cgosymbolizer/src/github.com/ianlancetaylor/cgosymbolizer \
		imdario:mergo:v0.3.7:imdario_mergo/src/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/src/github.com/inconshreveable/mousetrap \
		itchyny:astgen-go:aaa595cf980e:itchyny_astgen_go/src/github.com/itchyny/astgen-go \
		itchyny:gojq:v0.10.2:itchyny_gojq/src/github.com/itchyny/gojq \
		jmespath:go-jmespath:v0.3.0:jmespath_go_jmespath/src/github.com/jmespath/go-jmespath \
		json-iterator:go:v1.1.9:json_iterator_go/src/github.com/json-iterator/go \
		kardianos:osext:2bc1f35cddc0:kardianos_osext/src/github.com/kardianos/osext \
		konsorten:go-windows-terminal-sequences:v1.0.3:konsorten_go_windows_terminal_sequences/src/github.com/konsorten/go-windows-terminal-sequences \
		kubernetes-incubator:custom-metrics-apiserver:3d9be26a50eb:kubernetes_incubator_custom_metrics_apiserver/src/github.com/kubernetes-incubator/custom-metrics-apiserver \
		kubernetes-sigs:controller-runtime:v0.5.2:kubernetes_sigs_controller_runtime/src/sigs.k8s.io/controller-runtime \
		kubernetes-sigs:structured-merge-diff:6149e4549fca:kubernetes_sigs_structured_merge_diff/src/sigs.k8s.io/structured-merge-diff \
		kubernetes-sigs:yaml:v1.1.0:kubernetes_sigs_yaml/src/sigs.k8s.io/yaml \
		kubernetes:api:35e52d86657a:kubernetes_api/src/k8s.io/api \
		kubernetes:apiextensions-apiserver:5357c4baaf65:kubernetes_apiextensions_apiserver/src/k8s.io/apiextensions-apiserver \
		kubernetes:apimachinery:a2eda9f80ab8:kubernetes_apimachinery/src/k8s.io/apimachinery \
		kubernetes:apiserver:5190913f932d:kubernetes_apiserver/src/k8s.io/apiserver \
		kubernetes:autoscaler:fa95810cfc1e:kubernetes_autoscaler/src/k8s.io/autoscaler/vertical-pod-autoscaler \
		kubernetes:client-go:bec269661e48:kubernetes_client_go/src/k8s.io/client-go \
		kubernetes:cloud-provider:20453efc2458:kubernetes_cloud_provider/src/k8s.io/cloud-provider \
		kubernetes:component-base:039242c015a9:kubernetes_component_base/src/k8s.io/component-base \
		kubernetes:cri-api:608eb1dad4ac:kubernetes_cri_api/src/k8s.io/cri-api \
		kubernetes:klog:4ad0115ba9e4:kubernetes_klog/src/k8s.io/klog \
		kubernetes:kube-openapi:30be4d16710a:kubernetes_kube_openapi/src/k8s.io/kube-openapi \
		kubernetes:kube-state-metrics:dbbe062e36a4:kubernetes_kube_state_metrics/src/k8s.io/kube-state-metrics \
		kubernetes:kubernetes:v1.16.2:kubernetes_kubernetes/src/k8s.io/kubernetes \
		kubernetes:metrics:3b1a734dba6e:kubernetes_metrics/src/k8s.io/metrics \
		kubernetes:utils:94aeca20bf09:kubernetes_utils/src/k8s.io/utils \
		lestrrat-go:strftime:v1.0.1:lestrrat_go_strftime/src/github.com/lestrrat-go/strftime \
		lxn:walk:02935bac0ab8:lxn_walk/src/github.com/lxn/walk \
		lxn:win:2da648fda5b4:lxn_win/src/github.com/lxn/win \
		magiconair:properties:v1.8.1:magiconair_properties/src/github.com/magiconair/properties \
		mailru:easyjson:b2ccc519800e:mailru_easyjson/src/github.com/mailru/easyjson \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/src/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/src/github.com/mattn/go-isatty \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/src/github.com/matttproud/golang_protobuf_extensions \
		mdlayher:netlink:v1.1.0:mdlayher_netlink/src/github.com/mdlayher/netlink \
		mholt:archiver:26cf5bb32d07:mholt_archiver/src/github.com/mholt/archiver \
		miekg:dns:v1.1.31:miekg_dns/src/github.com/miekg/dns \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/src/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/src/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/src/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.0:mitchellh_reflectwalk/src/github.com/mitchellh/reflectwalk \
		moby:sys:mountinfo/v0.1.3:moby_sys_mountinfo/src/github.com/moby/sys \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/src/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/src/github.com/modern-go/reflect2 \
		munnerz:goautoneg:a547fc61f48d:munnerz_goautoneg/src/github.com/munnerz/goautoneg \
		natefinch:lumberjack:v2.0.0:natefinch_lumberjack/src/gopkg.in/natefinch/lumberjack.v2 \
		nwaples:rardecode:v1.1.0:nwaples_rardecode/src/github.com/nwaples/rardecode \
		opencontainers:go-digest:v1.0.0-rc1:opencontainers_go_digest/src/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:opencontainers_image_spec/src/github.com/opencontainers/image-spec \
		opencontainers:runc:6cc515888830:opencontainers_runc/src/github.com/opencontainers/runc \
		opencontainers:runtime-spec:v1.0.2:opencontainers_runtime_spec/src/github.com/opencontainers/runtime-spec \
		openshift:api:32369d4db2ad:openshift_api/src/github.com/openshift/api \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/src/github.com/patrickmn/go-cache \
		pbnjay:strptime:5c05b0d668c9:pbnjay_strptime/src/github.com/pbnjay/strptime \
		pborman:uuid:v1.2.0:pborman_uuid/src/github.com/pborman/uuid \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/src/github.com/pelletier/go-toml \
		philhofer:fwd:v1.0.0:philhofer_fwd/src/github.com/philhofer/fwd \
		pierrec:lz4:v2.5.0:pierrec_lz4/src/github.com/pierrec/lz4 \
		pkg:errors:v0.9.1:pkg_errors/src/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/src/github.com/pmezard/go-difflib \
		prometheus:client_golang:v0.9.2:prometheus_client_golang/src/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/src/github.com/prometheus/client_model \
		prometheus:common:v0.9.1:prometheus_common/src/github.com/prometheus/common \
		prometheus:procfs:v0.0.6:prometheus_procfs/src/github.com/prometheus/procfs \
		robfig:cron:v3.0.0:robfig_cron_v3/src/github.com/robfig/cron/v3 \
		samuel:go-zookeeper:2cc03de413da:samuel_go_zookeeper/src/github.com/samuel/go-zookeeper \
		shirou:gopsutil:d5eecd68:shirou_gopsutil/src/github.com/shirou/gopsutil \
		shirou:w32:bb4de0191aa4:shirou_w32/src/github.com/shirou/w32 \
		shuLhan:go-bindata:v3.4.0:shulhan_go_bindata/src/github.com/shuLhan/go-bindata \
		sirupsen:logrus:v1.6.0:sirupsen_logrus/src/github.com/sirupsen/logrus \
		soniah:gosnmp:v1.26.0:soniah_gosnmp/src/github.com/soniah/gosnmp \
		spf13:afero:v1.2.2:spf13_afero/src/github.com/spf13/afero \
		spf13:cobra:v0.0.5:spf13_cobra/src/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/src/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/src/github.com/spf13/pflag \
		stretchr:objx:v0.2.0:stretchr_objx/src/github.com/stretchr/objx \
		stretchr:testify:v1.5.1:stretchr_testify/src/github.com/stretchr/testify \
		syndtr:gocapability:d98352740cb2:syndtr_gocapability/src/github.com/syndtr/gocapability \
		tedsuo:rata:v1.0.0:tedsuo_rata/src/github.com/tedsuo/rata \
		tinylib:msgp:v1.1.2:tinylib_msgp/src/github.com/tinylib/msgp \
		twmb:murmur3:v1.1.3:twmb_murmur3/src/github.com/twmb/murmur3 \
		uber-go:atomic:v1.6.0:uber_go_atomic/src/go.uber.org/atomic \
		uber-go:multierr:v1.5.0:uber_go_multierr/src/go.uber.org/multierr \
		uber-go:zap:v1.14.1:uber_go_zap/src/go.uber.org/zap \
		ulikunitz:xz:v0.5.7:ulikunitz_xz/src/github.com/ulikunitz/xz \
		urfave:negroni:v1.0.0:urfave_negroni/src/github.com/urfave/negroni \
		vishvananda:netlink:v1.1.0:vishvananda_netlink \
		vishvananda:netns:0a2b9b5464df:vishvananda_netns/src/github.com/vishvananda/netns \
		vito:go-sse:v1.0.0:vito_go_sse/src/github.com/vito/go-sse \
		vmihailenco:msgpack:v4.3.11:vmihailenco_msgpack_v4/src/github.com/vmihailenco/msgpack/v4 \
		vmihailenco:tagparser:v0.1.1:vmihailenco_tagparser/src/github.com/vmihailenco/tagparser \
		zorkian:go-datadog-api:v2.29.0:zorkian_go_datadog_api/src/gopkg.in/zorkian/go-datadog-api.v2

USE_RC_SUBR=	${PORTNAME}-process-agent ${PORTNAME}-trace-agent ${PORTNAME}-agent

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST=	DATADOG_PREFIX=${DATADOG_PREFIX} \
		ETCDIR=${ETCDIR} \
		LOGDIR=${LOGDIR} \
		PORTNAME=${PORTNAME} \
		PYTHON_CMD=${PYTHON_CMD} \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
		RUNDIR=${RUNDIR} \
		USER=${USERS}

PLIST_SUB+=	DATADOG_PREFIX=${DATADOG_PREFIX} \
		ETCDIR=${ETCDIR} \
		GROUP=${GROUPS} \
		LOGDIR=${LOGDIR} \
		PORTNAME=${PORTNAME} \
		RUNDIR=${RUNDIR} \
		USER=${USERS}

OPTIONS_DEFINE=		DOCS APM CONSUL PYTHON EC2 ETCD GCE JMX LOG PROCESS ZK ZLIB
OPTIONS_DEFAULT=	DOCS EC2 GCE LOG PYTHON PROCESS ZLIB

APM_DESC=	Make the APM agent execution available
CONSUL_DESC=	Enable consul as a configuration store
DOCS_DESC=	Install documentation
EC2_DESC=	Enable EC2 hostname detection and metadata collection
ETCD_DESC=	Enable Etcd as a configuration store
GCE_DESC=	Enable GCE hostname detection and metadata collection
JMX_DESC=	Enable the JMX-fetch bridge
LOG_DESC=	Enable the log agent
PROCESS_DESC=	Enable the process agent
PYTHON_DESC=	Embed the Python interpreter
ZK_DESC=	Enable Zookeeper as a configuration store
ZLIB_DESC=	Use zlib

APM_VARS=	agent_build_tags+=apm
CONSUL_VARS=	agent_build_tags+=consul
EC2_VARS=	agent_build_tags+=ec2
ETCD_VARS=	agent_build_tags+=etcd
GCE_VARS=	agent_build_tags+=gce
JMX_VARS=	agent_build_tags+=jmx
LOG_VARS=	agent_build_tags+=log
PROCESS_VARS=	agent_build_tags+=process
PYTHON_VARS=	agent_build_tags+=python
ZK_VARS=	agent_build_tags+=zk
ZLIB_VARS=	agent_build_tags+=zlib

USE_LDCONFIG=	yes

PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

LD_FLAG_STRING=		-s -X '${GO_PKGNAME}/pkg/version.AgentVersion=${DISTVERSION}' -X '${GO_PKGNAME}/pkg/config.DefaultPython=3'

DATADOG_BINARIES=	agent dogstatsd trace-agent process-agent

post-extract:
	@${MKDIR} ${WRKSRC}/vendor/github.com/vishvananda
	@${RLN} ${WRKSRC_mdlayher_netlink} ${WRKSRC}/vendor/github.com/vishvananda/netlink
	@${RM} ${WRKSRC}/go.mod

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/datadog-agent|${ETCDIR}|g' \
		${WRKSRC}/pkg/config/config_template.yaml \
		${WRKSRC}/cmd/agent/common/common_nix.go \
		${WRKSRC}/pkg/config/config_nix.go \
		${WRKSRC}/cmd/system-probe/main_linux.go \
		${WRKSRC}/cmd/process-agent/main.go \
		${WRKSRC}/pkg/config/config.go

	@${REINPLACE_CMD} -e 's|/opt/datadog-agent/run|${RUNDIR}|g' \
		${WRKSRC}/pkg/config/config.go \
		${WRKSRC}/pkg/config/config_nix.go  \
		${WRKSRC}/pkg/config/config_template.yaml

	@${REINPLACE_CMD} -e 's|/opt/datadog-agent/etc|${ETCDIR}|g' \
		${WRKSRC}/pkg/trace/flags/flags_nix.go

pre-build:
# Build rtloader (Previously called six)
	(cd ${WRKSRC}/rtloader && ${SETENV} ${MAKE_ENV} ${BUILD_ENV} \
		cmake -DBUILD_DEMO:BOOL=OFF \
		-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
		-DDISABLE_PYTHON2:BOOL=ON -DDISABLE_PYTHON3:BOOL=OFF && make -C .)

# Generate go source from templates
	${GO_CMD} generate ${WRKSRC}/pkg/status/render.go
	${GO_CMD} generate ${WRKSRC}/cmd/agent/gui/gui.go

do-build:
# Build go binaries
.for bin in ${DATADOG_BINARIES}
	(cd ${WRKSRC}/cmd/${bin}; \
		${SETENV} ${MAKE_ENV} ${BUILD_ENV} GOPATH=${WRKSRC} \
		CGO_CFLAGS="-w -I${WRKSRC}/rtloader/include -I${WRKSRC}/rtloader/common" \
		CGO_LDFLAGS="-L${WRKSRC}/rtloader/rtloader" ${GO_CMD} build -tags \
		'${AGENT_BUILD_TAGS}' -o ${WRKSRC}/cmd/${bin}/${bin} -ldflags "${LD_FLAG_STRING}")
.endfor

post-build:
# Generate config files
	${SETENV} ${MAKE_ENV} ${BUILD_ENV} ${GO_CMD} run ${WRKSRC}/pkg/config/render_config.go agent-py3 \
	${WRKSRC}/pkg/config/config_template.yaml \
	${WRKSRC}/cmd/agent/dist/datadog.yaml

	${SETENV} ${MAKE_ENV} ${BUILD_ENV} ${GO_CMD} run ${WRKSRC}/pkg/config/render_config.go system-probe \
	${WRKSRC}/pkg/config/config_template.yaml \
	${WRKSRC}/cmd/agent/dist/system-probe.yaml

do-install:
	${MKDIR} ${STAGEDIR}${DATADOG_PREFIX}
	${MKDIR} ${STAGEDIR}${ETCDIR}/conf.d
	${MKDIR} ${STAGEDIR}${LOGDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${RUNDIR}

.for doc in README.md CHANGELOG.rst CONTRIBUTING.md LICENSE
	(${INSTALL_MAN} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR})
.endfor

	# Install binaries
	${INSTALL_PROGRAM} ${WRKSRC}/cmd/process-agent/process-agent ${STAGEDIR}${DATADOG_PREFIX}/process-agent
	${INSTALL_PROGRAM} ${WRKSRC}/cmd/trace-agent/trace-agent ${STAGEDIR}${DATADOG_PREFIX}/trace-agent
	${INSTALL_PROGRAM} ${WRKSRC}/cmd/agent/agent	${STAGEDIR}${DATADOG_PREFIX}/agent
	cd ${WRKSRC}/cmd/agent && ${COPYTREE_SHARE} dist ${STAGEDIR}${DATADOG_PREFIX}
	cd ${WRKSRC}/pkg/status && ${COPYTREE_SHARE} templates ${STAGEDIR}${DATADOG_PREFIX}/dist

	# Install rtloader library
	cd ${WRKSRC}/rtloader && make -C . ${INSTALL} DESTDIR=${STAGEDIR}

post-install:
	# Install configuration files
	${INSTALL_DATA} ${WRKSRC}/cmd/agent/dist/datadog.yaml \
		${STAGEDIR}${ETCDIR}/datadog.yaml.example

	# Strip binaries
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdatadog-agent-rtloader.so.0.1.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdatadog-agent-three.so

.include <bsd.port.mk>
