PORTNAME=		ovhcloud-cli
DISTVERSIONPREFIX=	v
DISTVERSION=		0.4.0
CATEGORIES=		net devel

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Command Line Interface to manage your OVHcloud services
WWW=		https://github.com/ovh/ovhcloud-li

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	ovh

GH_TUPLE=	\
		PaesslerAG:gval:v1.2.4:paesslerag_gval/vendor/github.com/PaesslerAG/gval \
		PaesslerAG:jsonpath:v0.1.1:paesslerag_jsonpath/vendor/github.com/PaesslerAG/jsonpath \
		alecthomas:chroma:v2.14.0:alecthomas_chroma_v2/vendor/github.com/alecthomas/chroma/v2 \
		amstuta:fx:99b16761e78b:amstuta_fx/vendor/github.com/amstuta/fx \
		atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
		aymanbagabas:go-osc52:v2.0.1:aymanbagabas_go_osc52_v2/vendor/github.com/aymanbagabas/go-osc52/v2 \
		aymerick:douceur:v0.2.0:aymerick_douceur/vendor/github.com/aymerick/douceur \
		charmbracelet:bubbles:v0.20.0:charmbracelet_bubbles/vendor/github.com/charmbracelet/bubbles \
		charmbracelet:bubbletea:v1.3.4:charmbracelet_bubbletea/vendor/github.com/charmbracelet/bubbletea \
		charmbracelet:colorprofile:f60798e515dc:charmbracelet_colorprofile/vendor/github.com/charmbracelet/colorprofile \
		charmbracelet:glamour:v0.9.1:charmbracelet_glamour/vendor/github.com/charmbracelet/glamour \
		charmbracelet:lipgloss:v1.1.0:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		charmbracelet:x:2c3ea96c31dd:charmbracelet_x_cellbuf \
		charmbracelet:x:ansi/v0.8.0:charmbracelet_x_ansi/vendor/github.com/charmbracelet/x \
		charmbracelet:x:term/v0.2.1:charmbracelet_x_term \
		cpuguy83:go-md2man:v2.0.6:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dlclark:regexp2:v1.11.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		erikgeiser:coninput:1c3628e74d0f:erikgeiser_coninput/vendor/github.com/erikgeiser/coninput \
		getkin:kin-openapi:v0.132.0:getkin_kin_openapi/vendor/github.com/getkin/kin-openapi \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-openapi:jsonpointer:v0.21.0:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:swag:v0.23.0:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		golang:exp:5c715a9e8561:golang_exp/vendor/golang.org/x/exp \
		golang:net:v0.42.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.30.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:sync:v0.16.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.34.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.33.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.27.0:golang_text/vendor/golang.org/x/text \
		gorilla:css:v1.0.1:gorilla_css/vendor/github.com/gorilla/css \
		imdario:mergo:v1.0.2:imdario_mergo/vendor/dario.cat/mergo \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jarcoal:httpmock:v1.4.1:jarcoal_httpmock/vendor/github.com/jarcoal/httpmock \
		josharian:intern:v1.0.0:josharian_intern/vendor/github.com/josharian/intern \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mailru:easyjson:v0.7.7:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-localereader:v0.0.1:mattn_go_localereader/vendor/github.com/mattn/go-localereader \
		mattn:go-runewidth:v0.0.16:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-shellwords:v1.0.12:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords \
		maxatome:go-testdeep:v1.14.0:maxatome_go_testdeep/vendor/github.com/maxatome/go-testdeep \
		maxatome:tdhttpmock:v1.0.0:maxatome_tdhttpmock/vendor/github.com/maxatome/tdhttpmock \
		microcosm-cc:bluemonday:v1.0.27:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mohae:deepcopy:c48cc78d4826:mohae_deepcopy/vendor/github.com/mohae/deepcopy \
		muesli:ansi:276c6243b2f6:muesli_ansi/vendor/github.com/muesli/ansi \
		muesli:cancelreader:v0.2.2:muesli_cancelreader/vendor/github.com/muesli/cancelreader \
		muesli:reflow:v0.3.0:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:termenv:v0.16.0:muesli_termenv/vendor/github.com/muesli/termenv \
		oasdiff:yaml3:d2182401db90:oasdiff_yaml3/vendor/github.com/oasdiff/yaml3 \
		oasdiff:yaml:f31be36b4037:oasdiff_yaml/vendor/github.com/oasdiff/yaml \
		ovh:go-ovh:v1.9.0:ovh_go_ovh/vendor/github.com/ovh/go-ovh \
		perimeterx:marshmallow:v1.1.5:perimeterx_marshmallow/vendor/github.com/perimeterx/marshmallow \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		sahilm:fuzzy:v0.1.1:sahilm_fuzzy/vendor/github.com/sahilm/fuzzy \
		shopspring:decimal:v1.3.1:shopspring_decimal/vendor/github.com/shopspring/decimal \
		spf13:cobra:v1.10.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.9:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.10.0:stretchr_testify/vendor/github.com/stretchr/testify \
		xo:terminfo:abceb7e1c41e:xo_terminfo/vendor/github.com/xo/terminfo \
		yuin:goldmark-emoji:v1.0.5:yuin_goldmark_emoji/vendor/github.com/yuin/goldmark-emoji \
		yuin:goldmark:v1.7.8:yuin_goldmark/vendor/github.com/yuin/goldmark

GO_TARGET=	./cmd/ovhcloud
GO_BUILDFLAGS=	-ldflags "-s -w -extldflags -static -X github.com/ovh/ovhcloud-cli/internal/version.Version=v${PORTVERSION}"

PLIST_FILES=	bin/ovhcloud

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/cellbuf
	@${RLN} ${WRKSRC_charmbracelet_x_cellbuf}/cellbuf ${WRKSRC}/vendor/github.com/charmbracelet/x/cellbuf
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/term
	@${RLN} ${WRKSRC_charmbracelet_x_term}/term ${WRKSRC}/vendor/github.com/charmbracelet/x/term
	@${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor/

.include <bsd.port.mk>
