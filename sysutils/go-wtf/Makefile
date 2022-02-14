PORTNAME=	wtf
PORTVERSION=	0.41.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
PKGNAMEPREFIX=	go-

MAINTAINER=	hsw@bitmark.com
COMMENT=	Personal information dashboard for your terminal

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cpe go:modules
MASTER_SITES=	https://bitbucket.org/${GH_ACCOUNT}/${GH_PROJECT}/get/${GH_COMMIT}.tar.gz?dummy=/

CPE_VENDOR=	wtfutil

CONFLICTS=	wtf

USE_GITHUB=	yes
GH_ACCOUNT=	wtfutil
# Note:  docker:engine line renames to docker/docker
#        because docker:docker internal dir is named "moby"
# i.e.
# ORIGINAL: docker:docker:v1.13.1:docker_docker/vendor/github.com/docker/docker
# REPLACE:  docker:engine:v1.13.1:docker_engine/vendor/github.com/docker/docker
GH_TUPLE=	\
		AlecAivazis:survey:v1.7.1:alecaivazis_survey/vendor/gopkg.in/AlecAivazis/survey.v1 \
		Azure:go-autorest:v11.1.2:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		Microsoft:go-winio:v0.4.14:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		PagerDuty:go-pagerduty:f60f4fc45222:pagerduty_go_pagerduty/vendor/github.com/PagerDuty/go-pagerduty \
		PuerkitoBio:goquery:v1.5.1:puerkitobio_goquery/vendor/github.com/PuerkitoBio/goquery \
		StackExchange:wmi:cbe66965904d:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		VictorAvelar:devto-api-go:v1.0.0:victoravelar_devto_api_go/vendor/github.com/VictorAvelar/devto-api-go \
		adlio:trello:v1.8.0:adlio_trello/vendor/github.com/adlio/trello \
		alecthomas:chroma:v0.8.1:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		andybalholm:cascadia:v1.1.0:andybalholm_cascadia/vendor/github.com/andybalholm/cascadia \
		andygrunwald:go-gerrit:5959a9bf9ff8:andygrunwald_go_gerrit/vendor/github.com/andygrunwald/go-gerrit \
		aokoli:goutils:v1.1.0:aokoli_goutils/vendor/github.com/aokoli/goutils \
		apache:thrift:v0.12.0:apache_thrift/vendor/github.com/apache/thrift \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		briandowns:openweathermap:5f41b7c9d92d:briandowns_openweathermap/vendor/github.com/briandowns/openweathermap \
		cenkalti:backoff:v2.2.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		census-ecosystem:opencensus-go-exporter-jaeger:v0.1.0:census_ecosystem_opencensus_go_exporter_jaeger/vendor/contrib.go.opencensus.io/exporter/jaeger \
		census-ecosystem:opencensus-go-exporter-prometheus:v0.1.0:census_ecosystem_opencensus_go_exporter_prometheus/vendor/contrib.go.opencensus.io/exporter/prometheus \
		census-instrumentation:opencensus-go:v0.22.4:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		cloudfoundry:bytefmt:854d396b647c:cloudfoundry_bytefmt/vendor/code.cloudfoundry.org/bytefmt \
		creack:pty:v1.1.11:creack_pty/vendor/github.com/creack/pty \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		digitalocean:godo:v1.52.0:digitalocean_godo/vendor/github.com/digitalocean/godo \
		dlclark:regexp2:v1.2.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		docker:docker-credential-helpers:v0.6.3:docker_docker_credential_helper/vendor/github.com/docker/docker-credential-helpers \
		docker:distribution:v2.7.1:docker_distribution/vendor/github.com/docker/distribution \
		docker:engine:v1.13.1:docker_engine/vendor/github.com/docker/docker \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		eapache:go-resiliency:v1.2.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		fsamin:go-dump:v1.0.9:fsamin_go_dump/vendor/github.com/fsamin/go-dump \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v1.4.0:gdamore_tcell/vendor/github.com/gdamore/tcell \
		go-gorp:gorp:v2.0.0:go_gorp_gorp/vendor/github.com/go-gorp/gorp \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-yaml:yaml:913338de1bd2:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		godbus:dbus:v4.1.0:godbus_dbus/vendor/github.com/godbus/dbus \
		gogo:protobuf:v1.2.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang-jwt:jwt:v3.2.1:golang_jwt_jwt_1/vendor/github.com/dgrijalva/jwt-go \
		golang-jwt:jwt:v3.2.2:golang_jwt_jwt/vendor/github.com/golang-jwt/jwt \
		golang:appengine:v1.6.6:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:948cd5f35899:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:c89045814202:golang_net/vendor/golang.org/x/net \
		golang:oauth2:5d25da1a8d43:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:6e8e738ad208:golang_sync/vendor/golang.org/x/sync \
		golang:sys:528a39cd75f3:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.4:golang_text/vendor/golang.org/x/text \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		google:btree:v1.0.0:google_btree/vendor/github.com/google/btree \
		google:go-cmp:v0.5.2:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:0bd0a958aa1d:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-github:v32.1.0:google_go_github_v32/vendor/github.com/google/go-github/v32 \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:gofuzz:v1.0.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:gnostic:v0.1.0:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.33.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.65.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gophercloud:gophercloud:v0.5.0:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		gorilla:websocket:v1.4.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
		gotestyourself:gotest.tools:v2.2.0:gotestyourself_gotest_tools/vendor/gotest.tools \
		gregjones:httpcache:3befbb6ad0cc:gregjones_httpcache/vendor/github.com/gregjones/httpcache \
		grpc:grpc-go:v1.29.1:grpc_grpc_go_1/vendor/google.golang.org/grpc \
		grpc:grpc-go:v1.31.1:grpc_grpc_go \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-retryablehttp:v0.6.4:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hekmon:cunits:v2.0.1:hekmon_cunits/vendor/github.com/hekmon/cunits \
		hekmon:transmissionrpc:1d589625bacd:hekmon_transmissionrpc/vendor/github.com/hekmon/transmissionrpc \
		huandu:xstrings:v1.2.0:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v0.3.9:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jarcoal:httpmock:3be5f16b70eb:jarcoal_httpmock/vendor/gopkg.in/jarcoal/httpmock.v1 \
		jaytaylor:html2text:3577fbdbcff7:jaytaylor_html2text/vendor/jaytaylor.com/html2text \
		jedib0t:go-pretty:v6.1.0:jedib0t_go_pretty_v6/vendor/github.com/jedib0t/go-pretty/v6 \
		jessevdk:go-flags:v1.4.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		json-iterator:go:v1.1.10:json_iterator_go/vendor/github.com/json-iterator/go \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		konsorten:go-windows-terminal-sequences:v1.0.3:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kothar:asana-go:715318d0343a6b566e23e0da7eb87e5c59c088e8:mikehouston_asana_go/vendor/bitbucket.org/mikehouston/asana-go \
		kubernetes-sigs:yaml:v1.1.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:89a74a8d264d:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:dcb391cde5ca:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v10.0.0:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v0.2.0:kubernetes_klog/vendor/k8s.io/klog \
		lib:pq:v1.2.0:lib_pq/vendor/github.com/lib/pq \
		logrusorgru:aurora:94edacc10f9b:logrusorgru_aurora/vendor/github.com/logrusorgru/aurora \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		maruel:panicparse:v1.3.0:maruel_panicparse/vendor/github.com/maruel/panicparse \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		microsoft:azure-devops-go-api:26902c1d4325:microsoft_azure_devops_go_api_azuredevops/vendor/github.com/microsoft/azure-devops-go-api \
		mitchellh:hashstructure:2bca23e0e452:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mmcdole:gofeed:68ee9054d97b:mmcdole_gofeed/vendor/github.com/mmcdole/gofeed \
		mmcdole:goxpp:0068e33feabf:mmcdole_goxpp/vendor/github.com/mmcdole/goxpp \
		mndrix:tap-go:56cca451570b:mndrix_tap_go/vendor/github.com/mndrix/tap-go \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		nicklaw5:helix:v0.7.0:nicklaw5_helix/vendor/github.com/nicklaw5/helix \
		olebedev:config:364964f3a8e4:olebedev_config/vendor/github.com/olebedev/config \
		olekukonko:tablewriter:v0.0.4:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		onsi:ginkgo:v1.12.0:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:gomega:v1.9.0:onsi_gomega/vendor/github.com/onsi/gomega \
		opencontainers:go-digest:v1.0.0-rc1:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		ovh:cds:39429542624d:ovh_cds/vendor/github.com/ovh/cds \
		ovh:cds:71125b036b25:ovh_cds_interpolate \
		ovh:venom:v0.25.0:ovh_venom/vendor/github.com/ovh/venom \
		pborman:uuid:v1.2.0:pborman_uuid/vendor/github.com/pborman/uuid \
		peterbourgon:diskv:v2.0.1:peterbourgon_diskv/vendor/github.com/peterbourgon/diskv \
		piquette:finance-go:v1.0.0:piquette_finance_go/vendor/github.com/piquette/finance-go \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:profile:v1.5.0:pkg_profile/vendor/github.com/pkg/profile \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.1.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:14fe0d1b01d4:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.6.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		radovskyb:watcher:v1.0.7:radovskyb_watcher/vendor/github.com/radovskyb/watcher \
		rivo:tview:1316ea7a4b35:rivo_tview/vendor/github.com/rivo/tview \
		rivo:uniseg:v0.1.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rs:xid:v1.2.1:rs_xid/vendor/github.com/rs/xid \
		sguiheux:go-coverage:287b082a7197:sguiheux_go_coverage/vendor/github.com/sguiheux/go-coverage \
		shirou:gopsutil:v2.20.9:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		shopspring:decimal:v1.2.0:shopspring_decimal/vendor/github.com/shopspring/decimal \
		shurcooL:githubv4:f27d2ca7f6d5:shurcool_githubv4/vendor/github.com/shurcooL/githubv4 \
		shurcooL:graphql:d48a9a75455f:shurcool_graphql/vendor/github.com/shurcooL/graphql \
		sirupsen:logrus:v1.6.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		smartystreets:assertions:b2de0cb4f26d:smartystreets_assertions/vendor/github.com/smartystreets/assertions \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.6.1:spf13_viper/vendor/github.com/spf13/viper \
		ssor:bom:6386211fdfcf:ssor_bom/vendor/github.com/ssor/bom \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		wtfutil:spotigopher:7d8168fe103a:wtfutil_spotigopher/vendor/github.com/wtfutil/spotigopher \
		wtfutil:todoist:0ec29ceda61a:wtfutil_todoist/vendor/github.com/wtfutil/todoist \
		xanzy:go-gitlab:v0.39.0:xanzy_go_gitlab/vendor/github.com/xanzy/go-gitlab \
		zmb3:spotify:e12fb981aacb:zmb3_spotify/vendor/github.com/zmb3/spotify \
		zorkian:go-datadog-api:v2.30.0:zorkian_go_datadog_api/vendor/github.com/zorkian/go-datadog-api

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/ovh/cds/sdk/interpolate
	@${RLN} ${WRKSRC_ovh_cds_interpolate}/sdk/interpolate ${WRKSRC}/vendor/github.com/ovh/cds/sdk/interpolate
	@${RLN} ${WRKSRC_grpc_grpc_go} ${WRKSRC}/vendor/google.golang.org/grpc

GO_BUILDFLAGS=	-ldflags "-X main.version=${DISTVERSION}"

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${FIND} ${WRKSRC}/_sample_configs -name "*.yml" -exec ${INSTALL_DATA} {} \
	${STAGEDIR}${EXAMPLESDIR}/ \;

.include <bsd.port.mk>
