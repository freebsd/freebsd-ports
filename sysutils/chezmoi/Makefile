# Created by: Samir Noir <samir@noir.im>

PORTNAME=	chezmoi
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.12
CATEGORIES=	sysutils

MAINTAINER=	samir@noir.im
COMMENT=	Manage your dotfiles across multiple diverse machines, securely

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	twpayne

GH_TUPLE=	Masterminds:goutils:v1.1.1:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v3.1.1:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Masterminds:sprig:v3.2.2:masterminds_sprig_v3/vendor/github.com/Masterminds/sprig/v3 \
		Microsoft:go-winio:v0.5.0:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		alecthomas:chroma:v0.9.1:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		alecthomas:colour:v0.1.0:alecthomas_colour/vendor/github.com/alecthomas/colour \
		alecthomas:repr:bb82daffcca2:alecthomas_repr/vendor/github.com/alecthomas/repr \
		aymerick:douceur:v0.2.0:aymerick_douceur/vendor/github.com/aymerick/douceur \
		bmatcuk:doublestar:v3.0.0:bmatcuk_doublestar_v3/vendor/github.com/bmatcuk/doublestar/v3 \
		charmbracelet:glamour:v0.3.0:charmbracelet_glamour/vendor/github.com/charmbracelet/glamour \
		coreos:go-semver:v0.3.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		danieljoos:wincred:v1.1.0:danieljoos_wincred/vendor/github.com/danieljoos/wincred \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dlclark:regexp2:v1.4.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		emirpasic:gods:v1.12.0:emirpasic_gods/vendor/github.com/emirpasic/gods \
		etcd-io:bbolt:v1.3.5:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-errgo:errgo:v2.1.0:go_errgo_errgo/vendor/gopkg.in/errgo.v2 \
		go-git:gcfg:v1.5.0:go_git_gcfg/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.3.1:go_git_go_billy_v5/vendor/github.com/go-git/go-billy/v5 \
		go-git:go-git:v5.3.0:go_git_go_git_v5/vendor/github.com/go-git/go-git/v5 \
		go-ini:ini:v1.62.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		godbus:dbus:v5.0.4:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:38f3c27a63bf:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:16afe75a6701:golang_net/vendor/golang.org/x/net \
		golang:oauth2:81ed05c6b58c:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:a76c4d0a0096:golang_sys/vendor/golang.org/x/sys \
		golang:term:a79de5458b56:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		google:go-github:v35.2.0:google_go_github_v35/vendor/github.com/google/go-github/v35 \
		google:go-querystring:v1.1.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:renameio:v1.0.1:google_renameio/vendor/github.com/google/renameio \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		gopherjs:gopherjs:fce0ec30dd00:gopherjs_gopherjs/vendor/github.com/gopherjs/gopherjs \
		gorilla:css:v1.0.0:gorilla_css/vendor/github.com/gorilla/css \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		huandu:xstrings:v1.3.2:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v0.3.12:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		kevinburke:ssh_config:v1.1.0:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		magiconair:properties:v1.8.5:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.12:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		microcosm-cc:bluemonday:v1.0.9:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mitchellh:copystructure:v1.2.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.4.1:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.2:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		muesli:combinator:v0.3.0:muesli_combinator/vendor/github.com/muesli/combinator \
		muesli:reflow:v0.2.0:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:termenv:v0.8.1:muesli_termenv/vendor/github.com/muesli/termenv \
		olekukonko:tablewriter:v0.0.5:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		pelletier:go-toml:v1.9.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:diff:20ebb0f2a09e:pkg_diff/vendor/github.com/pkg/diff \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rogpeppe:go-internal:v1.8.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		rs:zerolog:v1.21.0:rs_zerolog/vendor/github.com/rs/zerolog \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		shopspring:decimal:v1.2.0:shopspring_decimal/vendor/github.com/shopspring/decimal \
		smartystreets:assertions:v1.2.0:smartystreets_assertions/vendor/github.com/smartystreets/assertions \
		spf13:afero:v1.6.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.1.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.1:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:objx:v0.3.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		twpayne:go-shell:v0.3.0:twpayne_go_shell/vendor/github.com/twpayne/go-shell \
		twpayne:go-vfs:v2.0.0:twpayne_go_vfs_v2/vendor/github.com/twpayne/go-vfs/v2 \
		twpayne:go-vfsafero:v2.0.0:twpayne_go_vfsafero_v2/vendor/github.com/twpayne/go-vfsafero/v2 \
		twpayne:go-xdg:v4.0.0:twpayne_go_xdg_v4/vendor/github.com/twpayne/go-xdg/v4 \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.7.0:uber_go_multierr/vendor/go.uber.org/multierr \
		xanzy:ssh-agent:v0.3.0:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent \
		yuin:goldmark-emoji:v1.0.1:yuin_goldmark_emoji/vendor/github.com/yuin/goldmark-emoji \
		yuin:goldmark:v1.3.5:yuin_goldmark/vendor/github.com/yuin/goldmark \
		zalando:go-keyring:v0.1.1:zalando_go_keyring/vendor/github.com/zalando/go-keyring \
		DHowett:go-plist:1454fab16a06:go_plist/vendor/howett.net/plist

PLIST_FILES=	bin/chezmoi

OPTIONS_DEFINE=		BASH DOCS FISH ZSH
OPTIONS_DEFAULT=	BASH FISH ZSH

BASH_PLIST_FILES=	etc/bash_completion.d/chezmoi
DOCS_PORTDOCS=		*
FISH_PLIST_FILES=	share/fish/vendor_functions.d/chezmoi.fish
ZSH_PLIST_FILES=	share/zsh/site-functions/_chezmoi

post-extract:
	@${MKDIR} ${WRKSRC}/vendor/github.com/chris-ramon
	@${RLN} ${WRKSRC_aymerick_douceur} ${WRKSRC}/vendor/github.com/chris-ramon/douceur

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completions/chezmoi-completion.bash ${STAGEDIR}${PREFIX}/etc/bash_completion.d/chezmoi

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
	    "! -name docs.go")

post-install-FISH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/vendor_functions.d
	${INSTALL_DATA} ${WRKSRC}/completions/chezmoi.fish ${STAGEDIR}${PREFIX}/share/fish/vendor_functions.d/chezmoi.fish

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/chezmoi.zsh ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_chezmoi

.include <bsd.port.mk>
