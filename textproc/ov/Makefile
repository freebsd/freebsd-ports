PORTNAME=	ov
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	textproc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Feature rich terminal pager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	noborus
GH_TUPLE=	atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		dgraph-io:ristretto:v0.0.3:dgraph_io_ristretto/vendor/github.com/dgraph-io/ristretto \
		frankban:quicktest:v1.8.1:frankban_quicktest/vendor/github.com/frankban/quicktest \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v2.1.0:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		go-ini:ini:v1.62.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:5e06dd20ab57:golang_sys/vendor/golang.org/x/sys \
		golang:term:de623e64d2a6:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		klauspost:compress:v1.11.13:klauspost_compress/vendor/github.com/klauspost/compress \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		magiconair:properties:v1.8.5:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-runewidth:v0.0.10:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:mapstructure:v1.4.1:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v1.8.1:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pierrec:lz4:v2.6.0:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		spf13:afero:v1.6.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.1.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.1:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:testify:v1.5.1:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		ulikunitz:xz:v0.5.10:ulikunitz_xz/vendor/github.com/ulikunitz/xz
USE_GITLAB=	nodefault
GL_TUPLE=	tslocum:cbind:475986e4fda25b9fc3b95ee0b3d286dfa121c816:tslocum_cbind/vendor/gitlab.com/tslocum/cbind

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md
PORTEXAMPLES=	${PORTNAME}-less.yaml ${PORTNAME}.yaml

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
