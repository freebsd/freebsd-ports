# $FreeBSD$

PORTNAME=	wtf
PORTVERSION=	0.20.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
PKGNAMEPREFIX=	go-

MAINTAINER=	hsw@bitmark.com
COMMENT=	Personal information dashboard for your terminal

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules

CONFLICTS=	wtf

USE_GITHUB=	yes
GH_ACCOUNT=	wtfutil
GH_TUPLE=	\
		PagerDuty:go-pagerduty:cf1437c7c8d6:pagerduty_go_pagerduty/vendor/github.com/PagerDuty/go-pagerduty \
		PuerkitoBio:goquery:v1.5.0:puerkitobio_goquery/vendor/github.com/PuerkitoBio/goquery \
		StackExchange:wmi:cbe66965904d:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		adlio:trello:v1.0.0:adlio_trello/vendor/github.com/adlio/trello \
		alecthomas:chroma:v0.6.3:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		andybalholm:cascadia:v1.0.0:andybalholm_cascadia/vendor/github.com/andybalholm/cascadia \
		andygrunwald:go-gerrit:64931d233c2d:andygrunwald_go_gerrit/vendor/github.com/andygrunwald/go-gerrit \
		briandowns:openweathermap:5f41b7c9d92d:briandowns_openweathermap/vendor/github.com/briandowns/openweathermap \
		cenkalti:backoff:v2.2.0:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		census-instrumentation:opencensus-go:v0.22.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		darkSasori:todoist:ec6b38b374ab:darksasori_todoist/vendor/github.com/darkSasori/todoist \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dlclark:regexp2:v1.1.6:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v1.1.4:gdamore_tcell/vendor/github.com/gdamore/tcell \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-inf:inf:v0.9.0:go_yaml_yaml/vendor/gopkg.in/inf.v0 \
		godbus:dbus:v5.0.1:godbus_dbus/vendor/github.com/godbus/dbus \
		gogo:protobuf:65acae22fc9d:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.1:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:4def268fd1a4:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:da137c7871d7:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369cfe45:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:6a60838ec25:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:85acf8d2951c:golang_time/vendor/golang.org/x/time \
		google:go-genproto:eb59cef1c072:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-github:v26.0.9:google_go_github/vendor/github.com/google/go-github/v26 \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:gofuzz:v1.0.0:google_gofuzz/vendor/github.com/google/gofuzz \
		googleapis:gnostic:0c5108395e2d:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.7.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.40.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc:grpc-go:v1.21.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:golang-lru:v0.5.1:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hekmon:cunits:v2.0.1:hekmon_cunits/vendor/github.com/hekmon/cunits \
		hekmon:transmissionrpc:1d589625bacd:hekmon_transmissionrpc/vendor/github.com/hekmon/transmissionrpc \
		imdario:mergo:v0.3.5:imdario_mergo//vendor/github.com/imdario/mergo \
		json-iterator:go:v1.1.6:json_iterator_go/vendor/github.com/json-iterator/go \
		jessevdk:go-flags:v1.4.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		kubernetes:api:7cf5895f2711:k8s_io_api/vendor/k8s.io/api \
		kubernetes:apimachinery:6fa4771c83b3:k8s_io_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v12.0.0:k8s_io_client_go/vendor/k8s.io/client-go \
		kubernetes:gengo:0689ccc1d7d6:k8s_io_gengo/vendor/k8s.io/gengo \
		kubernetes:klog:v0.3.1:k8s_io_klog/vendor/k8s.io/klog \
		kubernetes:kube-openapi:b3a7cee44a30:k8s_io_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:utils:c2654d5206da:k8s_io_utils/vendor/k8s.io/utils \
		kubernetes-sigs:yaml:v1.1.0:sigs_k8s_io_yaml/vendor/sigs.k8s.io/yaml \
		logrusorgru:aurora:cea283e61946:logrusorgru_aurora/vendor/github.com/logrusorgru/aurora \
		lucasb-eyer:go-colorful:v1.0.2:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mmcdole:gofeed:0e68beaf6fdf:mmcdole_gofeed/vendor/github.com/mmcdole/gofeed \
		mmcdole:goxpp:0068e33feabf:mmcdole_goxpp/vendor/github.com/mmcdole/goxpp \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect/vendor/github.com/modern-go/reflect2 \
		olebedev:config:364964f3a8e4:olebedev_config/vendor/github.com/olebedev/config \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:profile:v1.3.0:pkg_profile/vendor/github.com/pkg/profile \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		radovskyb:watcher:v1.0.6:radovskyb_watcher/vendor/github.com/radovskyb/watcher \
		rivo:tview:2e907d29e475:rivo_tview/vendor/github.com/rivo/tview \
		rivo:uniseg:v0.1.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		shirou:gopsutil:v2.18.12:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		sticreations:spotigopher:98632f6f94b0:sticreations_spotigopher/vendor/github.com/sticreations/spotigopher \
		stretchr:testify:v1.3.0:stretchr_testify/vendor/github.com/stretchr/testify \
		xanzy:go-gitlab:v0.18.0:xanzy_go_gitlab/vendor/github.com/xanzy/go-gitlab \
		zmb3:spotify:158b1863f5b5:zmb3_spotify/vendor/github.com/zmb3/spotify \
		zorkian:go-datadog-api:v2.21.0:zorkian_go_datadog_api/vendor/github.com/zorkian/go-datadog-api

# this is missing, so use the local copy
#		yfronto:newrelic:7c9c2852e8f9:yfronto_newrelic/vendor/github.com/yfronto/newrelic
post-extract:
	${LN} -s ${PKGNAME}/vendor/github.com/yfronto/newrelic ${WRKDIR}/newrelic-7c9c2852e8f9

do-build:
	@cd ${WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} go 'install' -ldflags "-X main.version=${DISTVERSION}" -v -buildmode=exe -mod=vendor .

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/go/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

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
