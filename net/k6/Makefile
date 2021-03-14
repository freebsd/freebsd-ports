# $FreeBSD$

PORTNAME=	k6
DISTVERSIONPREFIX=	v
DISTVERSION=	0.31.0
CATEGORIES=	net

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Modern load testing tool, using Go and Javascript

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	loadimpact
GH_TUPLE=	Azure:go-ntlmssp:4a21cbd618b4:azure_go_ntlmssp/vendor/github.com/Azure/go-ntlmssp \
		DataDog:datadog-go:e67964b4021a:datadog_datadog_go/vendor/github.com/DataDog/datadog-go \
		GeertJohan:go.rice:c02ca9a983da:geertjohan_go_rice/vendor/github.com/GeertJohan/go.rice \
		PuerkitoBio:goquery:v1.3.0:puerkitobio_goquery/vendor/github.com/PuerkitoBio/goquery \
		Shopify:sarama:v1.16.0:shopify_sarama/vendor/github.com/Shopify/sarama \
		Shopify:toxiproxy:v2.1.4:shopify_toxiproxy/vendor/github.com/Shopify/toxiproxy \
		Soontao:goHttpDigestClient:6d28bb1415c5:soontao_gohttpdigestclient/vendor/github.com/Soontao/goHttpDigestClient \
		andybalholm:brotli:71eb68cc467c:andybalholm_brotli/vendor/github.com/andybalholm/brotli \
		andybalholm:cascadia:v1.0.0:andybalholm_cascadia/vendor/github.com/andybalholm/cascadia \
		daaku:go.zipexe:a5fe2436ffcb:daaku_go_zipexe/vendor/github.com/daaku/go.zipexe \
		davecgh:go-spew:v1.1.0:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dlclark:regexp2:a2a8dda75c91:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dop251:goja:60bc6ebb9fc1:dop251_goja/vendor/github.com/dop251/goja \
		dustin:go-humanize:bb3d318650d4:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		eapache:go-resiliency:v1.1.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:bb955e01b934:eapache_go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:eapache_queue/vendor/github.com/eapache/queue \
		fatih:color:v1.5.0:fatih_color/vendor/github.com/fatih/color \
		gedex:inflector:16278e9db813:gedex_inflector/vendor/github.com/gedex/inflector \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		gin-contrib:sse:22d885f9ecc7:gin_contrib_sse/vendor/github.com/gin-contrib/sse \
		gin-gonic:gin:d459835d2b07:gin_gonic_gin/vendor/github.com/gin-gonic/gin \
		go-playground:assert:v1.2.1:go_playground_assert/vendor/gopkg.in/go-playground/assert.v1 \
		go-playground:validator:v8.18.2:go_playground_validator/vendor/gopkg.in/go-playground/validator.v8 \
		go-sourcemap:sourcemap:v2.1.3:go_sourcemap_sourcemap/vendor/github.com/go-sourcemap/sourcemap \
		go-yaml:yaml:v2.1.1:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:gddo:af0f2af80721:golang_gddo/vendor/github.com/golang/gddo \
		golang:net:a5fa9d4b7c91:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:553a64147049:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:fdedc70b468f:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		golang:time:6dc17368e09b:golang_time/vendor/golang.org/x/time \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.1:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:9bfcb5116336:google_go_genproto/vendor/google.golang.org/genproto \
		gorilla:context:1ea25387ff6f:gorilla_context/vendor/github.com/gorilla/context \
		gorilla:mux:v1.6.1:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.31.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		guregu:null:v2.1.2:guregu_null/vendor/gopkg.in/guregu/null.v2 \
		guregu:null:v3.3.0:guregu_null_1/vendor/gopkg.in/guregu/null.v3 \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		influxdata:influxdb1-client:8ff2fc3824fc:influxdata_influxdb1_client/vendor/github.com/influxdata/influxdb1-client \
		jhump:protoreflect:v1.7.0:jhump_protoreflect/vendor/github.com/jhump/protoreflect \
		josharian:intern:v1.0.0:josharian_intern/vendor/github.com/josharian/intern \
		julienschmidt:httprouter:d18983907793:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
		kardianos:osext:ae77be60afb1:kardianos_osext/vendor/github.com/kardianos/osext \
		kelseyhightower:envconfig:v1.4.0:kelseyhightower_envconfig/vendor/github.com/kelseyhightower/envconfig \
		klauspost:compress:v1.7.2:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v1.3.1:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
		konsorten:go-windows-terminal-sequences:v1.0.3:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kubernetes:helm:v2.9.0:kubernetes_helm/vendor/github.com/kubernetes/helm \
		labstack:echo:v3.2.6:labstack_echo/vendor/github.com/labstack/echo \
		labstack:gommon:57409ada9da0:labstack_gommon/vendor/github.com/labstack/gommon \
		mailru:easyjson:8ab5ff9cd8e4:mailru_easyjson/vendor/github.com/mailru/easyjson \
		manyminds:api2go:95be7bd0455e:manyminds_api2go/vendor/github.com/manyminds/api2go \
		mattn:go-colorable:v0.0.9:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.4:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mccutchen:go-httpbin:c5cb2f4802fa:mccutchen_go_httpbin/vendor/github.com/mccutchen/go-httpbin \
		mitchellh:mapstructure:00c29f56e238:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		nu7hatch:gouuid:179d4d0c4d8d:nu7hatch_gouuid/vendor/github.com/nu7hatch/gouuid \
		onsi:ginkgo:v1.14.0:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		oxtoacart:bpool:4e1c5567d7c2:oxtoacart_bpool/vendor/github.com/oxtoacart/bpool \
		pierrec:lz4:2fcda4cb7018:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pierrec:xxHash:v0.1.1:pierrec_xxhash/vendor/github.com/pierrec/xxHash \
		pkg:errors:v0.8.0:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.24.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rcrowley:go-metrics:e2704e165165:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		serenize:snaker:a683aaf2d516:serenize_snaker/vendor/github.com/serenize/snaker \
		sirupsen:logrus:v1.6.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.1.1:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cobra:a114f312e075:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.1:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.2.1:stretchr_testify/vendor/github.com/stretchr/testify \
		tidwall:gjson:v1.6.1:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.0.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.0.2:tidwall_pretty/vendor/github.com/tidwall/pretty \
		ugorji:go:9831f2c3ac10:ugorji_go/vendor/github.com/ugorji/go \
		urfave:negroni:22c5532ea862:urfave_negroni/vendor/github.com/urfave/negroni \
		valyala:bytebufferpool:v1.0.0:valyala_bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		valyala:fasttemplate:dcecefd839c4:valyala_fasttemplate/vendor/github.com/valyala/fasttemplate \
		zyedidia:highlight:201131ce5cf5:zyedidia_highlight/vendor/github.com/zyedidia/highlight

_BUILD_DATE=	$$(date -u +"%FT%T%z")
_BUILD_HASH=	f0169c0

GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X github.com/${GH_ACCOUNT}/${PORTNAME}/lib/consts.VersionDetails=${_BUILD_DATE}/${_BUILD_HASH}"

PLIST_FILES=	bin/${PORTNAME}
_DOCS=		release\ notes/\${DISTVERSIONFULL}.md CODE_OF_CONDUCT.md \
		CONTRIBUTING.md README.md SUPPORT.md
PORTDOCS=	${_DOCS:T}

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${_DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
