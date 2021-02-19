# $FreeBSD$

PORTNAME=	amfora
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.0
CATEGORIES=	www

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Fancy terminal browser for the Gemini protocol

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	makeworld-the-better-one
GH_TUPLE=	PuerkitoBio:goquery:v1.5.1:puerkitobio_goquery/vendor/github.com/PuerkitoBio/goquery \
		andybalholm:cascadia:v1.1.0:andybalholm_cascadia/vendor/github.com/andybalholm/cascadia \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:19e17097d8fe:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		go-check:check:41f04d3bba15:go_check_check/vendor/gopkg.in/check.v1 \
		go-ini:ini:v1.62.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:eeeca48fe776:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:0c6587e931a9:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:986b41b23924:golang_net/vendor/golang.org/x/net \
		golang:sys:22da62e12c0c:golang_sys/vendor/golang.org/x/sys \
		golang:term:2321bbc49cbf:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.5:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.5.0:google_go_cmp/vendor/github.com/google/go-cmp \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		json-iterator:go:v1.1.10:json_iterator_go/vendor/github.com/json-iterator/go \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		makeworld-the-better-one:go-gemini:v0.11.0:makeworld_the_better_one_go_gemini/vendor/github.com/makeworld-the-better-one/go-gemini \
		makeworld-the-better-one:go-isemoji:v1.1.0:makeworld_the_better_one_go_isemoji/vendor/github.com/makeworld-the-better-one/go-isemoji \
		makeworld-the-better-one:gofeed:c0c6354134fe:makeworld_the_better_one_gofeed/vendor/github.com/mmcdole/gofeed \
		makeworld-the-better-one:progressbar:b036c4d38568:makeworld_the_better_one_progressbar_v3/vendor/github.com/schollz/progressbar/v3 \
		mattn:go-runewidth:v0.0.10:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:colorstring:d06e56a500db:mitchellh_colorstring/vendor/github.com/mitchellh/colorstring \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.3.1:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mmcdole:goxpp:0068e33feabf:mmcdole_goxpp/vendor/github.com/mmcdole/goxpp \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		pelletier:go-toml:v1.8.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rkoesters:xdg:edd15b846f9b:rkoesters_xdg/vendor/github.com/rkoesters/xdg \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.1:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv

USE_GITLAB=	nodefault
GL_TUPLE=	tslocum:cbind:475986e4fda25b9fc3b95ee0b3d286dfa121c816:tslocum_cbind/vendor/gitlab.com/tslocum/cbind \
		tslocum:cview:d776e728ef6d2a9990a5cd86a70b31f0678613e2:tslocum_cview/vendor/gitlab.com/tslocum/cview

_BUILD_VERSION=	${DISTVERSIONFULL}
_BUILD_COMMIT=	71385e9

GO_BUILDFLAGS=	-ldflags "\
 	      	-s -w \
		-X main.version=${_BUILD_VERSION}  \
		-X main.commit=${_BUILD_COMMIT}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	NOTES.md README.md THANKS.md
PORTEXAMPLES=	default-config.toml

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
