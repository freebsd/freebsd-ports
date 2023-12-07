PORTNAME=	datadog-agent
DISTVERSION=	7.24.1
PORTREVISION=	15
CATEGORIES=	sysutils net www

MAINTAINER=	uros@gruber.si
COMMENT=	Datadog Agent: collect metrics and events from your systems and apps
WWW=		https://www.datadoghq.com/

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		SHA256 Checksum mismatch for kubernetes-client-go-bec269661e48_GH0.tar.gz
BROKEN_i386=	fails to build: vendor/github.com/DataDog/gopsutil/process/process_freebsd.go:95:9: cannot use k.Start.Sec * 1000 (value of type int32) as type int64 in return statement

BUILD_DEPENDS=	cmake-core>=3.12:devel/cmake-core \
		go-bindata>0:devel/go-bindata

USES=		go:modules python

USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	datadog
GH_TUPLE=	\
		DataDog:agent-payload:v4.46.0:datadog_agent_payload/vendor/github.com/DataDog/agent-payload \
		DataDog:cast:1ee8c8bd14a3:datadog_cast/vendor/github.com/spf13/cast \
		DataDog:datadog-go:v3.5.0:datadog_datadog_go/vendor/github.com/DataDog/datadog-go \
		DataDog:datadog-operator:9c71245c6822:datadog_datadog_operator/vendor/github.com/DataDog/datadog-operator \
		DataDog:dd-trace-go:v1.23.1:datadog_dd_trace_go/vendor/gopkg.in/DataDog/dd-trace-go.v1 \
		DataDog:ebpf:a91a2d800994:datadog_ebpf/vendor/github.com/DataDog/ebpf \
		DataDog:gobpf:5f8313cb4d71:datadog_gobpf/vendor/github.com/iovisor/gobpf \
		DataDog:gohai:e17d616e422a:datadog_gohai/vendor/github.com/DataDog/gohai \
		DataDog:gopsutil:1b53412ef321:datadog_gopsutil/vendor/github.com/DataDog/gopsutil \
		DataDog:mmh3:f5b682d8c981:datadog_mmh3/vendor/github.com/DataDog/mmh3 \
		DataDog:viper:v1.8.0:datadog_viper/vendor/github.com/spf13/viper \
		DataDog:watermarkpodautoscaler:v0.1.0:datadog_watermarkpodautoscaler/vendor/github.com/DataDog/watermarkpodautoscaler \
		DataDog:zstd:2bf71ec48360:datadog_zstd/vendor/github.com/DataDog/zstd \
		Knetic:govaluate:v3.0.0:knetic_govaluate/vendor/gopkg.in/Knetic/govaluate.v3 \
		Masterminds:goutils:v1.1.0:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v1.5.0:masterminds_semver/vendor/github.com/Masterminds/semver \
		Masterminds:sprig:v2.22.0:masterminds_sprig/vendor/github.com/Masterminds/sprig \
		Microsoft:go-winio:fc70bd9a86b5:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Microsoft:hcsshim:v0.8.7:microsoft_hcsshim/vendor/github.com/Microsoft/hcsshim \
		NYTimes:gziphandler:v1.1.1:nytimes_gziphandler/vendor/github.com/NYTimes/gziphandler \
		PuerkitoBio:purell:v1.1.1:puerkitobio_purell/vendor/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/vendor/github.com/PuerkitoBio/urlesc \
		StackExchange:wmi:e0a55b97c705:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		alecthomas:participle:v0.4.4:alecthomas_participle/vendor/github.com/alecthomas/participle \
		alecthomas:repr:d37bc2a10ba1:alecthomas_repr/vendor/github.com/alecthomas/repr \
		armon:go-metrics:v0.3.0:armon_go_metrics/vendor/github.com/armon/go-metrics \
		avast:retry-go:v2.7.0:avast_retry_go/vendor/github.com/avast/retry-go \
		aws:aws-sdk-go:v1.30.5:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beevik:ntp:v0.3.0:beevik_ntp/vendor/github.com/beevik/ntp \
		benesch:cgosymbolizer:bec6fe6e597b:benesch_cgosymbolizer/vendor/github.com/benesch/cgosymbolizer \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bhmj:jsonslice:92c3edaad8e2:bhmj_jsonslice/vendor/github.com/bhmj/jsonslice \
		blabber:go-freebsd-sysctl:503969f39d8f:blabber_go_freebsd_sysctl/vendor/github.com/blabber/go-freebsd-sysctl \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		bmizerany:pat:6226ea591a40:bmizerany_pat/vendor/github.com/bmizerany/pat \
		cenkalti:backoff:v2.2.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		census-instrumentation:opencensus-go:v0.22.2:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		cihub:seelog:d2c6e5aa9fbf:cihub_seelog/vendor/github.com/cihub/seelog \
		clbanning:mxj:v1.8.4:clbanning_mxj/vendor/github.com/clbanning/mxj \
		cloudfoundry:bbs:d7bc971db0db:cloudfoundry_bbs/vendor/code.cloudfoundry.org/bbs \
		cloudfoundry:cfhttp:v2.0.0:cloudfoundry_cfhttp/vendor/code.cloudfoundry.org/cfhttp/v2 \
		cloudfoundry:garden:061eda450ad9:cloudfoundry_garden/vendor/code.cloudfoundry.org/garden \
		cloudfoundry:lager:v2.0.0:cloudfoundry_lager/vendor/code.cloudfoundry.org/lager \
		cloudfoundry:tlsconfig:bbe0f8da39b3:cloudfoundry_tlsconfig/vendor/code.cloudfoundry.org/tlsconfig \
		cobaugh:osrelease:a93a0a55a249:cobaugh_osrelease/vendor/github.com/cobaugh/osrelease \
		containerd:cgroups:b44481373989:containerd_cgroups/vendor/github.com/containerd/cgroups \
		containerd:containerd:v1.2.13:containerd_containerd/vendor/github.com/containerd/containerd \
		containerd:continuity:0f16d7a0959c:containerd_continuity/vendor/github.com/containerd/continuity \
		containerd:fifo:ff969a566b00:containerd_fifo/vendor/github.com/containerd/fifo \
		containerd:typeurl:v1.0.0:containerd_typeurl/vendor/github.com/containerd/typeurl \
		coreos:etcd:v3.3.15:coreos_etcd/vendor/github.com/coreos/etcd \
		coreos:go-semver:v0.3.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		coreos:go-systemd:40e2722dffea:coreos_go_systemd/vendor/github.com/coreos/go-systemd \
		coreos:pkg:399ea9e2e55f:coreos_pkg/vendor/github.com/coreos/pkg \
		datadog:extendeddaemonset:94ec1f3a5192:datadog_extendeddaemonset/vendor/github.com/datadog/extendeddaemonset \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgraph-io:ristretto:v0.0.3:dgraph_io_ristretto/vendor/github.com/dgraph-io/ristretto \
		dgryski:go-jump:e1f439676b57:dgryski_go_jump/vendor/github.com/dgryski/go-jump \
		docker:distribution:0ac367fd6bee:docker_distribution/vendor/github.com/docker/distribution \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-events:e31b211e4f1c:docker_go_events/vendor/github.com/docker/go-events \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		docker:spdystream:449fdfce4d96:docker_spdystream/vendor/github.com/docker/spdystream \
		dsnet:compress:v0.0.1:dsnet_compress/vendor/github.com/dsnet/compress \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		elastic:go-libaudit:v0.4.0:elastic_go_libaudit/vendor/github.com/elastic/go-libaudit \
		emicklei:go-restful-swagger12:7524189396c6:emicklei_go_restful_swagger12/vendor/github.com/emicklei/go-restful-swagger12 \
		emicklei:go-restful:v2.9.6:emicklei_go_restful/vendor/github.com/emicklei/go-restful \
		etcd-io:etcd:3cf2f69b5738:etcd_io_etcd/vendor/go.etcd.io/etcd \
		evanphx:json-patch:v4.5.0:evanphx_json_patch/vendor/github.com/evanphx/json-patch \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		florianl:go-conntrack:v0.2.0:florianl_go_conntrack/vendor/github.com/florianl/go-conntrack \
		florianl:go-tc:v0.2.0:florianl_go_tc/vendor/github.com/florianl/go-tc \
		freddierice:go-losetup:fc9adea44124:freddierice_go_losetup/vendor/github.com/freddierice/go-losetup \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		ghodss:yaml:25d852aebe32:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ini:ini:v1.55.0:go_ini_ini/vendor/github.com/go-ini/ini \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-openapi:jsonpointer:v0.19.3:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.19.2:go_openapi_jsonreference/vendor/github.com/go-openapi/jsonreference \
		go-openapi:spec:v0.19.8:go_openapi_spec/vendor/github.com/go-openapi/spec \
		go-openapi:swag:v0.19.5:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		godbus:dbus:v4.1.0:godbus_dbus/vendor/github.com/godbus/dbus \
		gogo:googleapis:v1.3.2:gogo_googleapis/vendor/github.com/gogo/googleapis \
		gogo:protobuf:v1.3.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:glog:23def4e6c14b:golang_glog/vendor/github.com/golang/glog \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mobile:d2bd2a29d028:golang_mobile/vendor/golang.org/x/mobile \
		golang:net:c89045814202:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:cd5d95a43a6e:golang_sync/vendor/golang.org/x/sync \
		golang:sys:196b9ba8737a:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		golang:tools:82bb89366a1e:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		gomodules:jsonpatch:v3.0.1:gomodules_jsonpatch/vendor/gomodules.xyz/jsonpatch/v3 \
		gomodules:orderedmap:v0.1.0:gomodules_orderedmap/vendor/gomodules.xyz/orderedmap \
		google:go-cmp:v0.4.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:09dca8ec2884:google_go_genproto/vendor/google.golang.org/genproto \
		google:gofuzz:v1.0.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:gopacket:v1.1.17:google_gopacket/vendor/github.com/google/gopacket \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		googleapis:gnostic:v0.3.1:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		gorilla:mux:v1.7.4:gorilla_mux/vendor/github.com/gorilla/mux \
		grpc-ecosystem:go-grpc-middleware:v1.2.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:v1.2.0:grpc_ecosystem_go_grpc_prometheus/vendor/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc-ecosystem:grpc-gateway:v1.12.2:grpc_ecosystem_grpc_gateway/vendor/github.com/grpc-ecosystem/grpc-gateway \
		grpc:grpc-go:v1.26.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:consul:v1.4.0:hashicorp_consul_api/vendor/github.com/hashicorp/consul \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-hclog:v0.12.0:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-immutable-radix:v1.1.0:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-multierror:v1.1.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-rootcerts:v1.0.2:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:serf:v0.8.5:hashicorp_serf/vendor/github.com/hashicorp/serf \
		hectane:go-acl:da78bae5fc95:hectane_go_acl/vendor/github.com/hectane/go-acl \
		huandu:xstrings:v1.2.0:huandu_xstrings/vendor/github.com/huandu/xstrings \
		ianlancetaylor:cgosymbolizer:f5072df9c550:ianlancetaylor_cgosymbolizer/vendor/github.com/ianlancetaylor/cgosymbolizer \
		imdario:mergo:v0.3.7:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		itchyny:astgen-go:aaa595cf980e:itchyny_astgen_go/vendor/github.com/itchyny/astgen-go \
		itchyny:gojq:v0.10.2:itchyny_gojq/vendor/github.com/itchyny/gojq \
		jmespath:go-jmespath:v0.3.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		json-iterator:go:v1.1.9:json_iterator_go/vendor/github.com/json-iterator/go \
		kardianos:osext:2bc1f35cddc0:kardianos_osext/vendor/github.com/kardianos/osext \
		konsorten:go-windows-terminal-sequences:v1.0.3:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kubernetes-incubator:custom-metrics-apiserver:3d9be26a50eb:kubernetes_incubator_custom_metrics_apiserver/vendor/github.com/kubernetes-incubator/custom-metrics-apiserver \
		kubernetes-sigs:controller-runtime:v0.5.2:kubernetes_sigs_controller_runtime/vendor/sigs.k8s.io/controller-runtime \
		kubernetes-sigs:structured-merge-diff:6149e4549fca:kubernetes_sigs_structured_merge_diff/vendor/sigs.k8s.io/structured-merge-diff \
		kubernetes-sigs:yaml:v1.1.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:35e52d86657a:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apiextensions-apiserver:5357c4baaf65:kubernetes_apiextensions_apiserver/vendor/k8s.io/apiextensions-apiserver \
		kubernetes:apimachinery:a2eda9f80ab8:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:apiserver:5190913f932d:kubernetes_apiserver/vendor/k8s.io/apiserver \
		kubernetes:autoscaler:fa95810cfc1e:kubernetes_autoscaler/vendor/k8s.io/autoscaler/vertical-pod-autoscaler \
		kubernetes:client-go:bec269661e48:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:cloud-provider:20453efc2458:kubernetes_cloud_provider/vendor/k8s.io/cloud-provider \
		kubernetes:component-base:039242c015a9:kubernetes_component_base/vendor/k8s.io/component-base \
		kubernetes:cri-api:608eb1dad4ac:kubernetes_cri_api/vendor/k8s.io/cri-api \
		kubernetes:klog:4ad0115ba9e4:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:kube-openapi:30be4d16710a:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:kube-state-metrics:dbbe062e36a4:kubernetes_kube_state_metrics/vendor/k8s.io/kube-state-metrics \
		kubernetes:kubernetes:v1.16.2:kubernetes_kubernetes/vendor/k8s.io/kubernetes \
		kubernetes:metrics:3b1a734dba6e:kubernetes_metrics/vendor/k8s.io/metrics \
		kubernetes:utils:94aeca20bf09:kubernetes_utils/vendor/k8s.io/utils \
		lestrrat-go:strftime:v1.0.1:lestrrat_go_strftime/vendor/github.com/lestrrat-go/strftime \
		lxn:walk:02935bac0ab8:lxn_walk/vendor/github.com/lxn/walk \
		lxn:win:2da648fda5b4:lxn_win/vendor/github.com/lxn/win \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mailru:easyjson:b2ccc519800e:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mdlayher:netlink:v1.1.0:mdlayher_netlink/vendor/github.com/mdlayher/netlink \
		mholt:archiver:26cf5bb32d07:mholt_archiver/vendor/github.com/mholt/archiver \
		miekg:dns:v1.1.31:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.0:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		moby:moby:v17.12.0-ce:moby_moby/vendor/github.com/docker/docker \
		moby:sys:mountinfo/v0.1.3:moby_sys_mountinfo/vendor/github.com/moby/sys \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		munnerz:goautoneg:a547fc61f48d:munnerz_goautoneg/vendor/github.com/munnerz/goautoneg \
		natefinch:lumberjack:v2.0.0:natefinch_lumberjack/vendor/gopkg.in/natefinch/lumberjack.v2 \
		nwaples:rardecode:v1.1.0:nwaples_rardecode/vendor/github.com/nwaples/rardecode \
		opencontainers:go-digest:v1.0.0-rc1:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runc:6cc515888830:opencontainers_runc/vendor/github.com/opencontainers/runc \
		opencontainers:runtime-spec:v1.0.2:opencontainers_runtime_spec/vendor/github.com/opencontainers/runtime-spec \
		openshift:api:32369d4db2ad:openshift_api/vendor/github.com/openshift/api \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pbnjay:strptime:5c05b0d668c9:pbnjay_strptime/vendor/github.com/pbnjay/strptime \
		pborman:uuid:v1.2.0:pborman_uuid/vendor/github.com/pborman/uuid \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		philhofer:fwd:v1.0.0:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pierrec:lz4:v2.5.0:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v0.9.2:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.9.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.6:prometheus_procfs/vendor/github.com/prometheus/procfs \
		robfig:cron:v3.0.0:robfig_cron_v3/vendor/github.com/robfig/cron/v3 \
		samuel:go-zookeeper:2cc03de413da:samuel_go_zookeeper/vendor/github.com/samuel/go-zookeeper \
		shirou:gopsutil:v2.20.3:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		shirou:w32:bb4de0191aa4:shirou_w32/vendor/github.com/shirou/w32 \
		shuLhan:go-bindata:v3.4.0:shulhan_go_bindata/vendor/github.com/shuLhan/go-bindata \
		sirupsen:logrus:v1.6.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		soniah:gosnmp:v1.26.0:soniah_gosnmp/vendor/github.com/soniah/gosnmp \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cobra:v1.0.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:objx:v0.2.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.5.1:stretchr_testify/vendor/github.com/stretchr/testify \
		syndtr:gocapability:d98352740cb2:syndtr_gocapability/vendor/github.com/syndtr/gocapability \
		tedsuo:rata:v1.0.0:tedsuo_rata/vendor/github.com/tedsuo/rata \
		tinylib:msgp:v1.1.2:tinylib_msgp/vendor/github.com/tinylib/msgp \
		twmb:murmur3:v1.1.3:twmb_murmur3/vendor/github.com/twmb/murmur3 \
		uber-go:atomic:v1.6.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:automaxprocs:v1.2.0:uber_go_automaxprocs/vendor/go.uber.org/automaxprocs \
		uber-go:multierr:v1.5.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.14.1:uber_go_zap/vendor/go.uber.org/zap \
		ulikunitz:xz:v0.5.7:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		urfave:negroni:v1.0.0:urfave_negroni/vendor/github.com/urfave/negroni \
		vishvananda:netlink:v1.1.0:vishvananda_netlink \
		vishvananda:netns:0a2b9b5464df:vishvananda_netns/vendor/github.com/vishvananda/netns \
		vito:go-sse:v1.0.0:vito_go_sse/vendor/github.com/vito/go-sse \
		vmihailenco:msgpack:v4.3.11:vmihailenco_msgpack_v4/vendor/github.com/vmihailenco/msgpack/v4 \
		vmihailenco:tagparser:v0.1.1:vmihailenco_tagparser/vendor/github.com/vmihailenco/tagparser \
		zorkian:go-datadog-api:v2.29.0:zorkian_go_datadog_api/vendor/gopkg.in/zorkian/go-datadog-api.v2

DATADOG_PREFIX=	${PREFIX}/bin/${PORTNAME}
ETCDIR=		${PREFIX}/etc/datadog
LOGDIR=		/var/log/datadog
RUNDIR=		/var/run/datadog

USERS=	datadog
GROUPS=	${USERS}

SUB_FILES=	pkg-message
SUB_LIST=	RUNDIR=${RUNDIR} \
		LOGDIR=${LOGDIR} \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
		PYTHON_CMD=${PYTHON_CMD} \
		USER=${USERS} \
		PORTNAME=${PORTNAME} \
		DATADOG_PREFIX=${DATADOG_PREFIX}

PLIST_SUB+=	RUNDIR=${RUNDIR} \
		LOGDIR=${LOGDIR} \
		USER=${USERS} \
		GROUP=${GROUPS} \
		PORTNAME=${PORTNAME} \
		DATADOG_PREFIX=${DATADOG_PREFIX}

OPTIONS_DEFINE=	DOCS PYTHON SECRETS JMX ZSTD
OPTIONS_DEFAULT=	PYTHON PROCESS LOG

OPTIONS_GROUP=		AGENTS STORE META
OPTIONS_GROUP_AGENTS=	LOG APM PROCESS DOGSTATSD
OPTIONS_GROUP_STORE=	CONSUL ZK ETCD
OPTIONS_GROUP_META=	EC2 GCE

DOCS_DESC=	Install documentation
PYTHON_DESC=	Embed the Python interpreter
SECRETS_DESC=	Enable secrets support in configuration files
CONSUL_DESC=	Enable consul as a configuration store
ZK_DESC=	Enable Zookeeper as a configuration store
ETCD_DESC=	Enable Etcd as a configuration store
EC2_DESC=	Enable EC2 hostname detection and metadata collection
GCE_DESC=	Enable GCE hostname detection and metadata collection
JMX_DESC=	Enable the JMX-fetch bridge
LOG_DESC=	Enable the log agent
APM_DESC=	Build the APM agent
PROCESS_DESC=	Build the process agent
DOGSTATSD_DESC=	Build the dogstatsd agent
ZSTD_DESC=	Use Zstandard instead of Zlib

PYTHON_VARS=	agent_build_tags+=python
SECRETS_VARS=	agent_build_tags+=secrets
CONSUL_VARS=	agent_build_tags+=consul
ZSTD_VARS=	agent_build_tags+=zstd
ZK_VARS=	agent_build_tags+=zk
ETCD_VARS=	agent_build_tags+=etcd
EC2_VARS=	agent_build_tags+=ec2
GCE_VARS=	agent_build_tags+=gce
JMX_VARS=	agent_build_tags+=jmx
LOG_VARS=	agent_build_tags+=log
APM_VARS=	agent_build_tags+=apm use_rc_subr+=datadog-trace-agent
PROCESS_VARS=	agent_build_tags+=process use_rc_subr+=datadog-process-agent
DOGSTATSD_VARS=	use_rc_subr+=datadog-dogstatsd

OPTIONS_SUB=	yes

PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

ALL_TARGET=		./cmd/agent
APM_ALL_TARGET=		./cmd/trace-agent
PROCESS_ALL_TARGET=	./cmd/process-agent
DOGSTATSD_ALL_TARGET=	./cmd/dogstatsd
GO_TARGET=	${ALL_TARGET}
NO_CCACHE=		yes

USE_RC_SUBR=	${PORTNAME}

CGO_CFLAGS=	-w -I. -I${WRKSRC}/rtloader/include -I${WRKSRC}/rtloader/common
CGO_LDFLAGS=	-L${WRKSRC}/rtloader/rtloader
GO_BUILDFLAGS=	-tags '${AGENT_BUILD_TAGS}' \
    -ldflags="-s -X 'github.com/DataDog/${GH_PROJECT}/pkg/version.AgentVersion=${DISTVERSION}' -X 'github.com/DataDog/${GH_PROJECT}/pkg/config.DefaultPython=3'"

post-patch:
	@${REINPLACE_CMD} 's|/etc/datadog-agent|${ETCDIR}|g' \
		${WRKSRC}/pkg/config/config_template.yaml \
		${WRKSRC}/cmd/agent/common/common_nix.go \
		${WRKSRC}/pkg/config/config_nix.go \
		${WRKSRC}/cmd/system-probe/main_linux.go \
		${WRKSRC}/cmd/process-agent/main.go \
		${WRKSRC}/pkg/config/config.go

	@${REINPLACE_CMD} 's|/opt/datadog-agent/run|${RUNDIR}|g' \
		${WRKSRC}/pkg/config/config.go \
		${WRKSRC}/pkg/config/config_nix.go  \
		${WRKSRC}/pkg/config/config_template.yaml

	@${REINPLACE_CMD} 's|/opt/datadog-agent/etc|${ETCDIR}|g' \
		${WRKSRC}/pkg/trace/flags/flags_nix.go

	@${REINPLACE_CMD} 's|/opt/datadog-agent/embedded/bin|${DATADOG_PREFIX}|g' \
		${WRKSRC}/cmd/agent/dist/conf.d/process_agent.yaml.default \
		${WRKSRC}/cmd/agent/dist/conf.d/apm.yaml.default

	@${REINPLACE_CMD} -e 's|/opt/datadog-agent/bin/agent|${DATADOG_PREFIX}|g' \
		${WRKSRC}/pkg/trace/config/config_nix.go \
		${WRKSRC}/pkg/process/config/config_nix.go

pre-build:
# Build rtloader (Previously called six)
	(cd ${WRKSRC}/rtloader && \
		${SETENV} ${MAKE_ENV} ${BUILD_ENV} ${LOCALBASE}/bin/cmake \
		-DBUILD_DEMO:BOOL=OFF -DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
		-DDISABLE_PYTHON2:BOOL=ON -DDISABLE_PYTHON3:BOOL=OFF && \
		${MAKE_CMD} -C .)

# Generate go source from templates
	${SETENV} ${MAKE_ENV} ${GO_ENV} GOCACHE=${TMPDIR} GO111MODULE=off GOFLAGS="-mod=vendor" ${GO_CMD} generate ${WRKSRC}/pkg/status/render.go
	${SETENV} ${MAKE_ENV} ${GO_ENV} GOCACHE=${TMPDIR} GO111MODULE=off GOFLAGS="-mod=vendor" ${GO_CMD} generate ${WRKSRC}/cmd/agent/gui/gui.go

post-build:
# Generate config files
	${SETENV} ${MAKE_ENV} ${GO_ENV} GOCACHE=${TMPDIR} ${GO_CMD} run ${WRKSRC}/pkg/config/render_config.go agent-py3 \
		${WRKSRC}/pkg/config/config_template.yaml \
		${WRKSRC}/cmd/agent/dist/datadog.yaml

	${SETENV} ${MAKE_ENV} ${GO_ENV} GOCACHE=${TMPDIR} ${GO_CMD} run ${WRKSRC}/pkg/config/render_config.go system-probe \
		${WRKSRC}/pkg/config/config_template.yaml \
		${WRKSRC}/cmd/agent/dist/system-probe.yaml

	${SETENV} ${MAKE_ENV} ${GO_ENV} GOCACHE=${TMPDIR} ${GO_CMD} run ${WRKSRC}/pkg/config/render_config.go dogstatsd \
		${WRKSRC}/pkg/config/config_template.yaml \
		${WRKSRC}/cmd/agent/dist/dogstatsd.yaml

do-install:
	${MKDIR} \
		${STAGEDIR}${DATADOG_PREFIX} \
		${STAGEDIR}${ETCDIR}/conf.d \
		${STAGEDIR}${LOGDIR} \
		${STAGEDIR}${DOCSDIR} \
		${STAGEDIR}${RUNDIR}

.for doc in README.md CHANGELOG.rst CONTRIBUTING.md LICENSE
	(${INSTALL_MAN} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR})
.endfor

	# Install dist config
.for conf in cpu.d file_handle.d go_expvar.d io.d jmx.d load.d memory.d ntp.d tcp_queue_length.d uptime.d
	(cd ${WRKSRC}/cmd/agent/dist/conf.d && ${COPYTREE_SHARE} ${conf} ${STAGEDIR}${ETCDIR}/conf.d)
.endfor

	cd ${WRKSRC}/cmd/agent/dist/conf.d && \
		${CP} apm.yaml.default process_agent.yaml.default ${STAGEDIR}${ETCDIR}/conf.d

	# Install rtloader library
	${MAKE_CMD} -C ${WRKSRC}/rtloader ${INSTALL} DESTDIR=${STAGEDIR}

	${INSTALL_PROGRAM} ${WRKDIR}/bin/agent ${STAGEDIR}${DATADOG_PREFIX}/agent

do-install-APM-on:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/trace-agent ${STAGEDIR}${DATADOG_PREFIX}/trace-agent

do-install-PROCESS-on:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/process-agent ${STAGEDIR}${DATADOG_PREFIX}/process-agent

do-install-DOGSTATSD-on:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/dogstatsd ${STAGEDIR}${DATADOG_PREFIX}/dogstatsd

post-install:
	# Install configuration files
	${INSTALL_DATA} ${WRKSRC}/cmd/agent/dist/datadog.yaml \
		${STAGEDIR}${ETCDIR}/datadog.yaml.sample

	${INSTALL_DATA} ${WRKSRC}/cmd/agent/dist/system-probe.yaml \
		${STAGEDIR}${ETCDIR}/system-probe.yaml.sample

	${INSTALL_DATA} ${WRKSRC}/cmd/agent/dist/system-probe.yaml \
		${STAGEDIR}${ETCDIR}/dogstatsd.yaml.sample

	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*so*

.include <bsd.port.mk>
