# $FreeBSD$

PORTNAME=	dive
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for exploring each layer in a docker image

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	wagoodman
GH_TUPLE=	\
		Microsoft:go-winio:v0.4.11:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		docker:cli:8ddde26af67f:docker_cli/vendor/github.com/docker/cli \
		docker:distribution:93e082742a009850ac46962150b2f652a822c5ff:docker_distribution/vendor/github.com/docker/distribution \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.3.3:docker_go_units/vendor/github.com/docker/go-units \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-yaml:yaml:v2.2.1:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.1.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:crypto:3d3f9f413869:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:adae6a3d119a:golang_net/vendor/golang.org/x/net \
		golang:sys:93218def8b18:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		google:uuid:v1.1.0:google_uuid/vendor/github.com/google/uuid \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jroimartin:gocui:v0.4.0:jroimartin_gocui/vendor/github.com/jroimartin/gocui \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		logrusorgru:aurora:a7b3b318ed4e:logrusorgru_aurora/vendor/github.com/logrusorgru/aurora \
		lunixbochs:vtclean:2d01aacdc34a:lunixbochs_vtclean/vendor/github.com/lunixbochs/vtclean \
		magiconair:properties:v1.8.0:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-colorable:v0.0.9:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.4:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.3:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:go-homedir:v1.0.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.0.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		moby:moby:0b7cb16dde4a20d024c7be59801d63bcfd18611b:moby_moby/vendor/github.com/docker/docker \
		nsf:termbox-go:60ab7e3d12ed:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		opencontainers:go-digest:v1.0.0-rc1:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		phayes:permbits:59f2482cd460:phayes_permbits/vendor/github.com/phayes/permbits \
		pkg:errors:v0.8.0:pkg_errors/vendor/github.com/pkg/errors \
		sergi:go-diff:v1.0.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		sirupsen:logrus:v1.2.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.2.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v0.0.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.2:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.2.1:spf13_viper/vendor/github.com/spf13/viper \
		wagoodman:keybinding:6a824da6df05:wagoodman_keybinding/vendor/github.com/wagoodman/keybinding

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
