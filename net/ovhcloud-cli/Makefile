PORTNAME=		ovhcloud-cli
DISTVERSIONPREFIX=	v
DISTVERSION=		0.16.0
PORTREVISION=	1
CATEGORIES=		net devel

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Command Line Interface to manage your OVHcloud services
WWW=		https://github.com/ovh/ovhcloud-cli

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	ovh

GO_TARGET=	./cmd/ovhcloud
GO_BUILDFLAGS=	-ldflags "-s -w -extldflags -static -X github.com/ovh/ovhcloud-cli/internal/version.Version=v${PORTVERSION}"

PLIST_FILES=	bin/ovhcloud

GH_TUPLE=	\
		NimbleMarkets:ntcharts:v0.5.1:nimblemarkets_ntcharts/vendor/github.com/NimbleMarkets/ntcharts \
		PaesslerAG:gval:v1.2.4:paesslerag_gval/vendor/github.com/PaesslerAG/gval \
		PaesslerAG:jsonpath:v0.1.1:paesslerag_jsonpath/vendor/github.com/PaesslerAG/jsonpath \
		alecthomas:chroma:v2.27.0:alecthomas_chroma_v2/vendor/github.com/alecthomas/chroma/v2 \
		amstuta:fx:99b16761e78b:amstuta_fx/vendor/github.com/amstuta/fx \
		atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
		aymanbagabas:go-osc52:v2.0.1:aymanbagabas_go_osc52_v2/vendor/github.com/aymanbagabas/go-osc52/v2 \
		aymerick:douceur:v0.2.0:aymerick_douceur/vendor/github.com/aymerick/douceur \
		charmbracelet:bubbles:v1.0.0:charmbracelet_bubbles/vendor/github.com/charmbracelet/bubbles \
		charmbracelet:bubbletea:v1.3.10:charmbracelet_bubbletea/vendor/github.com/charmbracelet/bubbletea \
		charmbracelet:colorprofile:v0.4.3:charmbracelet_colorprofile/vendor/github.com/charmbracelet/colorprofile \
		charmbracelet:glamour:v1.0.0:charmbracelet_glamour/vendor/github.com/charmbracelet/glamour \
		charmbracelet:lipgloss:76690c660834:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		charmbracelet:x:53e2afe73ae5:charmbracelet_x_slice \
		charmbracelet:x:ansi/v0.11.8:charmbracelet_x_ansi \
		charmbracelet:x:cellbuf/v0.0.15:charmbracelet_x_cellbuf \
		charmbracelet:x:term/v0.2.2:charmbracelet_x_term/vendor/github.com/charmbracelet/x \
		clipperhouse:displaywidth:v0.11.0:clipperhouse_displaywidth/vendor/github.com/clipperhouse/displaywidth \
		clipperhouse:uax29:v2.7.0:clipperhouse_uax29_v2/vendor/github.com/clipperhouse/uax29/v2 \
		cloudfoundry:bytefmt:v0.90.0:cloudfoundry_bytefmt/vendor/code.cloudfoundry.org/bytefmt \
		cpuguy83:go-md2man:v2.0.7:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		dlclark:regexp2:v2.8.0:dlclark_regexp2_v2/vendor/github.com/dlclark/regexp2/v2 \
		erikgeiser:coninput:1c3628e74d0f:erikgeiser_coninput/vendor/github.com/erikgeiser/coninput \
		getkin:kin-openapi:v0.149.0:getkin_kin_openapi/vendor/github.com/getkin/kin-openapi \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-ini:ini:v1.67.3:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-openapi:jsonpointer:v1.0.1:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:exp:85c1c2202aba:golang_exp/vendor/golang.org/x/exp \
		golang:net:v0.59.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.37.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:sync:v0.23.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.48.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.46.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.42.0:golang_text/vendor/golang.org/x/text \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:css:v1.0.1:gorilla_css/vendor/github.com/gorilla/css \
		imdario:mergo:v1.0.2:imdario_mergo/vendor/dario.cat/mergo \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jarcoal:httpmock:v1.4.2:jarcoal_httpmock/vendor/github.com/jarcoal/httpmock \
		kr:pretty:v0.3.0:kr_pretty/vendor/github.com/kr/pretty \
		lrstanley:bubblezone:v1.0.0:lrstanley_bubblezone/vendor/github.com/lrstanley/bubblezone \
		lucasb-eyer:go-colorful:v1.4.1:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.24:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-localereader:v0.0.1:mattn_go_localereader/vendor/github.com/mattn/go-localereader \
		mattn:go-runewidth:v0.0.30:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-shellwords:v1.0.15:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords \
		maxatome:go-testdeep:v1.16.0:maxatome_go_testdeep/vendor/github.com/maxatome/go-testdeep \
		maxatome:tdhttpmock:v1.0.0:maxatome_tdhttpmock/vendor/github.com/maxatome/tdhttpmock \
		microcosm-cc:bluemonday:v1.0.27:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		muesli:ansi:276c6243b2f6:muesli_ansi/vendor/github.com/muesli/ansi \
		muesli:cancelreader:v0.2.2:muesli_cancelreader/vendor/github.com/muesli/cancelreader \
		muesli:reflow:v0.3.0:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:termenv:v0.16.0:muesli_termenv/vendor/github.com/muesli/termenv \
		oasdiff:yaml3:v0.0.14:oasdiff_yaml3/vendor/github.com/oasdiff/yaml3 \
		oasdiff:yaml:v0.1.1:oasdiff_yaml/vendor/github.com/oasdiff/yaml \
		ovh:go-ovh:v1.9.0:ovh_go_ovh/vendor/github.com/ovh/go-ovh \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		sahilm:fuzzy:v0.1.3:sahilm_fuzzy/vendor/github.com/sahilm/fuzzy \
		santhosh-tekuri:jsonschema:v6.0.3:santhosh_tekuri_jsonschema_v6/vendor/github.com/santhosh-tekuri/jsonschema/v6 \
		shopspring:decimal:v1.4.0:shopspring_decimal/vendor/github.com/shopspring/decimal \
		spf13:cobra:v1.10.2:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.10:spf13_pflag/vendor/github.com/spf13/pflag \
		xo:terminfo:v1.2.0:xo_terminfo/vendor/github.com/xo/terminfo \
		yaml:go-yaml:v3.0.5:yaml_go_yaml/vendor/go.yaml.in/yaml/v3 \
		yuin:goldmark-emoji:v1.0.6:yuin_goldmark_emoji/vendor/github.com/yuin/goldmark-emoji \
		yuin:goldmark:v1.8.6:yuin_goldmark/vendor/github.com/yuin/goldmark

post-extract:
	@${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/ansi
	@${RLN} ${WRKSRC_charmbracelet_x_ansi}/ansi ${WRKSRC}/vendor/github.com/charmbracelet/x/ansi
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/cellbuf
	@${RLN} ${WRKSRC_charmbracelet_x_cellbuf}/cellbuf ${WRKSRC}/vendor/github.com/charmbracelet/x/cellbuf
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/exp/slice
	@${RLN} ${WRKSRC_charmbracelet_x_slice}/exp/slice ${WRKSRC}/vendor/github.com/charmbracelet/x/exp/slice

.include <bsd.port.mk>
