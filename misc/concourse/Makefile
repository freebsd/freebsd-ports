PORTNAME=	concourse
DISTVERSIONPREFIX=	v
DISTVERSION=	6.7.2
PORTREVISION=	27
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Automation system written in Go
WWW=		https://concourse-ci.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cpe go:modules
USE_GITHUB=	yes

CONFLICTS_INSTALL=	concourse-fly fly # bin/fly

CPE_VENDOR=	pivotal_software

GH_TUPLE=	\
		Azure:go-autorest:5bd9621f41a0:azure_go_autorest_date/vendor/github.com/Azure/go-autorest \
		Azure:go-autorest:autorest/v0.10.1:azure_go_autorest_autorest \
		Azure:go-autorest:e727cfcfc902:azure_go_autorest_adal \
		Azure:go-autorest:logger/v0.1.0:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.5.0:azure_go_autorest_tracing \
		DataDog:datadog-go:v3.2.0:datadog_datadog_go/vendor/github.com/DataDog/datadog-go \
		Masterminds:squirrel:v1.1.0:masterminds_squirrel/vendor/github.com/Masterminds/squirrel \
		Microsoft:go-winio:fc70bd9a86b5:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Microsoft:hcsshim:v0.8.7:microsoft_hcsshim/vendor/github.com/Microsoft/hcsshim \
		NYTimes:gziphandler:v1.1.1:nytimes_gziphandler/vendor/github.com/NYTimes/gziphandler \
		VividCortex:ewma:v1.1.1:vividcortex_ewma/vendor/github.com/VividCortex/ewma \
		apache:thrift:v0.13.0:apache_thrift/vendor/github.com/apache/thrift \
		aryann:difflib:e206f873d14a:aryann_difflib/vendor/github.com/aryann/difflib \
		aws:aws-sdk-go:v1.25.18:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beevik:etree:4cd0dd976db8:beevik_etree/vendor/github.com/beevik/etree \
		beorn7:perks:v1.0.0:beorn7_perks/vendor/github.com/beorn7/perks \
		bgentry:go-netrc:9fd32a8b3d3d:bgentry_go_netrc/vendor/github.com/bgentry/go-netrc \
		bmizerany:pat:6226ea591a40:bmizerany_pat/vendor/github.com/bmizerany/pat \
		caarlos0:env:v3.5.0:caarlos0_env/vendor/github.com/caarlos0/env \
		cenkalti:backoff:v2.1.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		census-instrumentation:opencensus-go:v0.22.2:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		charlievieth:fs:7dc373669fa1:charlievieth_fs/vendor/github.com/charlievieth/fs \
		cloudfoundry-incubator:credhub-cli:e3951663d25c:cloudfoundry_incubator_credhub_cli/vendor/code.cloudfoundry.org/credhub-cli \
		cloudfoundry:clock:02e53af36e6c:cloudfoundry_clock/vendor/code.cloudfoundry.org/clock \
		cloudfoundry:garden:62470dc86365:cloudfoundry_garden/vendor/code.cloudfoundry.org/garden \
		cloudfoundry:go-socks5:54f73bdb8a8e:cloudfoundry_go_socks5/vendor/github.com/cloudfoundry/go-socks5 \
		cloudfoundry:lager:v2.0.0:cloudfoundry_lager/vendor/code.cloudfoundry.org/lager \
		cloudfoundry:localip:b88ad0dea95c:cloudfoundry_localip/vendor/code.cloudfoundry.org/localip \
		cloudfoundry:socks5-proxy:3659db090cb2:cloudfoundry_socks5_proxy/vendor/github.com/cloudfoundry/socks5-proxy \
		cloudfoundry:urljoiner:5cabba6c0a50:cloudfoundry_urljoiner/vendor/code.cloudfoundry.org/urljoiner \
		concourse:baggageclaim:v1.8.0:concourse_baggageclaim/vendor/github.com/concourse/baggageclaim \
		concourse:dex:821b48abfd88:concourse_dex/vendor/github.com/concourse/dex \
		concourse:flag:v1.1.0:concourse_flag/vendor/github.com/concourse/flag \
		concourse:go-archive:v1.0.1:concourse_go_archive/vendor/github.com/concourse/go-archive \
		concourse:retryhttp:v1.0.2:concourse_retryhttp/vendor/github.com/concourse/retryhttp \
		containerd:cgroups:06e718085901:containerd_cgroups/vendor/github.com/containerd/cgroups \
		containerd:containerd:v1.3.2:containerd_containerd/vendor/github.com/containerd/containerd \
		containerd:continuity:1097c8bae83b:containerd_continuity/vendor/github.com/containerd/continuity \
		containerd:fifo:ff969a566b00:containerd_fifo/vendor/github.com/containerd/fifo \
		containerd:go-cni:c154a49e2c75:containerd_go_cni/vendor/github.com/containerd/go-cni \
		containerd:ttrpc:4f1b8fe65a5c:containerd_ttrpc/vendor/github.com/containerd/ttrpc \
		containerd:typeurl:5eb25027c9fd:containerd_typeurl/vendor/github.com/containerd/typeurl \
		containernetworking:cni:v0.7.1:containernetworking_cni/vendor/github.com/containernetworking/cni \
		coreos:go-iptables:v0.4.5:coreos_go_iptables/vendor/github.com/coreos/go-iptables \
		coreos:go-oidc:v2.0.0:coreos_go_oidc/vendor/github.com/coreos/go-oidc \
		cppforlife:go-semi-semantic:576b6af77ae4:cppforlife_go_semi_semantic/vendor/github.com/cppforlife/go-semi-semantic \
		creack:pty:v1.1.9:creack_pty/vendor/github.com/creack/pty \
		cyberark:conjur-api-go:v0.6.0:cyberark_conjur_api_go/vendor/github.com/cyberark/conjur-api-go \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		docker:distribution:0d3efadf0154:docker_distribution/vendor/github.com/docker/distribution \
		docker:go-events:e31b211e4f1c:docker_go_events/vendor/github.com/docker/go-events \
		evanphx:json-patch:v4.5.0:evanphx_json_patch/vendor/github.com/evanphx/json-patch \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		felixge:httpsnoop:v1.0.0:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/gopkg.in/fsnotify.v1 \
		go-asn1-ber:asn1-ber:f715ec2f112d:go_asn1_ber_asn1_ber/vendor/gopkg.in/asn1-ber.v1 \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ldap:ldap:v2.5.1:go_ldap_ldap/vendor/gopkg.in/ldap.v2 \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobuffalo:packr:v1.13.7:gobuffalo_packr/vendor/github.com/gobuffalo/packr \
		gogo:googleapis:v1.3.1:gogo_googleapis/vendor/github.com/gogo/googleapis \
		gogo:protobuf:v1.3.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.1:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:bac4c82f6975:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:611e8accdfc9:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mod:c90efee705ee:golang_mod/vendor/golang.org/x/mod \
		golang:net:7e3656a0809f:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369cfe45:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:cd5d95a43a6e:golang_sync/vendor/golang.org/x/sync \
		golang:sys:6aff5f38e54f:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:9d24e82272b4:golang_time/vendor/golang.org/x/time \
		golang:tools:066e0c02454c:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.4.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:3caeed10a8bf:google_go_genproto/vendor/google.golang.org/genproto \
		google:gofuzz:v1.0.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:jsonapi:5d047c6bc66b:google_jsonapi/vendor/github.com/google/jsonapi \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:gnostic:v0.3.1:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.11.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.47.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gophercloud:gophercloud:v0.10.0:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		gorilla:context:v1.1.1:gorilla_context/vendor/github.com/gorilla/context \
		gorilla:handlers:3a5767ca75ec:gorilla_handlers/vendor/github.com/gorilla/handlers \
		gorilla:mux:v1.6.2:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.4.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.26.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-hclog:v0.9.2:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-multierror:v1.1.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-retryablehttp:v0.6.2:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-rootcerts:v1.0.2:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-sockaddr:v1.0.2:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:go-version:v1.2.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:vault:390e96e22eb2:hashicorp_vault_sdk/vendor/github.com/hashicorp/vault \
		hashicorp:vault:bdd38fca2cff:hashicorp_vault_api \
		hpcloud:tail:v1.0.0:hpcloud_tail/vendor/github.com/hpcloud/tail \
		imdario:mergo:v0.3.6:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:go-update:8152e7eb6ccf:inconshreveable_go_update/vendor/github.com/inconshreveable/go-update \
		influxdata:influxdb1-client:f8cdb5d5f175:influxdata_influxdb1_client/vendor/github.com/influxdata/influxdb1-client \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		jonboulle:clockwork:v0.1.0:jonboulle_clockwork/vendor/github.com/jonboulle/clockwork \
		json-iterator:go:v1.1.7:json_iterator_go/vendor/github.com/json-iterator/go \
		klauspost:compress:v1.9.7:klauspost_compress/vendor/github.com/klauspost/compress \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kr:pty:v1.1.8:kr_pty/vendor/github.com/kr/pty \
		krishicks:yaml-patch:v0.0.10:krishicks_yaml_patch/vendor/github.com/krishicks/yaml-patch \
		kubernetes-sigs:yaml:v1.1.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:40a48860b5ab:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:d7deff9243b1:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v11.0.0:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v0.3.0:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:kube-openapi:30be4d16710a:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:utils:3a4a5477acf8:kubernetes_utils/vendor/k8s.io/utils \
		lann:builder:47ae307949d0:lann_builder/vendor/github.com/lann/builder \
		lann:ps:62de8c46ede0:lann_ps/vendor/github.com/lann/ps \
		lib:pq:v1.3.0:lib_pq/vendor/github.com/lib/pq \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-sqlite3:v1.10.0:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		maxbrunsfeld:counterfeiter:v6.2.3:maxbrunsfeld_counterfeiter_v6/vendor/github.com/maxbrunsfeld/counterfeiter/v6 \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		miekg:dns:v1.1.6:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		nu7hatch:gouuid:179d4d0c4d8d:nu7hatch_gouuid/vendor/github.com/nu7hatch/gouuid \
		onsi:ginkgo:v1.12.0:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:gomega:v1.10.0:onsi_gomega/vendor/github.com/onsi/gomega \
		open-telemetry:opentelemetry-go:v0.2.1:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		opencontainers:go-digest:v1.0.0-rc1:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runc:v0.1.1:opencontainers_runc/vendor/github.com/opencontainers/runc \
		opencontainers:runtime-spec:v1.0.1:opencontainers_runtime_spec/vendor/github.com/opencontainers/runtime-spec \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		peterhellberg:link:v1.0.0:peterhellberg_link/vendor/github.com/peterhellberg/link \
		pierrec:lz4:v2.0.5:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:term:aa71e9d9e942:pkg_term/vendor/github.com/pkg/term \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		pquerna:cachecontrol:1555304b9b35:pquerna_cachecontrol/vendor/github.com/pquerna/cachecontrol \
		prometheus:client_golang:v0.9.3:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:14fe0d1b01d4:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.4.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.5:prometheus_procfs/vendor/github.com/prometheus/procfs \
		racksec:srslog:a4725f04ec91:racksec_srslog/vendor/github.com/racksec/srslog \
		russellhaering:goxmldsig:eaac44c63fe0:russellhaering_goxmldsig/vendor/github.com/russellhaering/goxmldsig \
		ryanuber:go-glob:v1.0.0:ryanuber_go_glob/vendor/github.com/ryanuber/go-glob \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		skratchdot:open-golang:75fb7ed4208c:skratchdot_open_golang/vendor/github.com/skratchdot/open-golang \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		square:certstrap:v1.1.1:square_certstrap/vendor/github.com/square/certstrap \
		square:go-jose:v2.3.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:objx:v0.2.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		syndtr:gocapability:d98352740cb2:syndtr_gocapability/vendor/github.com/syndtr/gocapability \
		tedsuo:ifrit:bea94bb476cc:tedsuo_ifrit/vendor/github.com/tedsuo/ifrit \
		tedsuo:rata:07d200713958:tedsuo_rata/vendor/github.com/tedsuo/rata \
		vbauerster:mpb:3a6acfe12ac6:vbauerster_mpb_v4/vendor/github.com/vbauerster/mpb/v4 \
		vito:go-flags:c7161c3bd74d:vito_go_flags/vendor/github.com/jessevdk/go-flags \
		vito:go-interact:fa338ed9e9ec:vito_go_interact/vendor/github.com/vito/go-interact \
		vito:go-sse:fd69d275caac:vito_go_sse/vendor/github.com/vito/go-sse \
		vito:houdini:v1.1.1:vito_houdini/vendor/github.com/vito/houdini \
		vito:twentythousandtonnesofcrudeoil:3b21ad808fcb:vito_twentythousandtonnesofcrudeoil/vendor/github.com/vito/twentythousandtonnesofcrudeoil

GO_TARGET=	./cmd/concourse \
		./fly

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RLN} ${WRKSRC_azure_go_autorest_autorest}/autorest ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RLN} ${WRKSRC_azure_go_autorest_adal}/autorest/adal ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RM} -r ${WRKSRC}/vendor/github.com/hashicorp/vault/api
	@${RLN} ${WRKSRC_hashicorp_vault_api}/api ${WRKSRC}/vendor/github.com/hashicorp/vault/api

PLIST_FILES=	bin/concourse \
	bin/fly

.include <bsd.port.mk>
