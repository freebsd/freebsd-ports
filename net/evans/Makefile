# $FreeBSD$

PORTNAME=	evans
DISTVERSION=	0.9.0
CATEGORIES=	net

MAINTAINER=	vulcan@wired.sh
COMMENT=	More expressive universal gRPC client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	ktr0731
GH_TUPLE=	chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		desertbit:timer:c41aec40b27f:desertbit_timer/vendor/github.com/desertbit/timer \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-ini:ini:v1.51.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.3.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:net:ff2c4b7c35a0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:cd5d95a43a6e:golang_sync/vendor/golang.org/x/sync \
		golang:sys:593003d681fa:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:tools:e1da425f72fd:golang_tools/vendor/golang.org/x/tools \
		google:go-cmp:v0.4.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:c45acf45369a:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-github:v17.0.0:google_go_github/vendor/github.com/google/go-github \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.29.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-version:v1.2.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		improbable-eng:grpc-web:v0.12.0:improbable_eng_grpc_web/vendor/github.com/improbable-eng/grpc-web \
		inconshreveable:go-update:8152e7eb6ccf:inconshreveable_go_update/vendor/github.com/inconshreveable/go-update \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jhump:protoreflect:10815c273d3f:jhump_protoreflect/vendor/github.com/jhump/protoreflect \
		juju:ansiterm:720a0952cc2a:juju_ansiterm/vendor/github.com/juju/ansiterm \
		k0kubun:pp:v3.0.1:k0kubun_pp/vendor/github.com/k0kubun/pp \
		ktr0731:dept:v0.1.3:ktr0731_dept/vendor/github.com/ktr0731/dept \
		ktr0731:go-multierror:b7773ae21874:ktr0731_go_multierror/vendor/github.com/ktr0731/go-multierror \
		ktr0731:go-prompt:7894cc3f2925:ktr0731_go_prompt/vendor/github.com/ktr0731/go-prompt \
		ktr0731:go-shellstring:v0.1.3:ktr0731_go_shellstring/vendor/github.com/ktr0731/go-shellstring \
		ktr0731:go-updater:v0.1.5:ktr0731_go_updater/vendor/github.com/ktr0731/go-updater \
		ktr0731:grpc-test:v0.1.7:ktr0731_grpc_test/vendor/github.com/ktr0731/grpc-test \
		ktr0731:grpc-web-go-client:v0.2.7:ktr0731_grpc_web_go_client/vendor/github.com/ktr0731/grpc-web-go-client \
		lunixbochs:vtclean:v1.0.0:lunixbochs_vtclean/vendor/github.com/lunixbochs/vtclean \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		manifoldco:promptui:v0.7.0:manifoldco_promptui/vendor/github.com/manifoldco/promptui \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-pipeline:32d779b32768:mattn_go_pipeline/vendor/github.com/mattn/go-pipeline \
		mattn:go-runewidth:v0.0.8:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-tty:523744f04859:mattn_go_tty/vendor/github.com/mattn/go-tty \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		olekukonko:tablewriter:v0.0.4:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		pelletier:go-toml:v1.7.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		phayes:freeport:95f893ade6f2:phayes_freeport/vendor/github.com/phayes/freeport \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:term:aa71e9d9e942:pkg_term/vendor/github.com/pkg/term \
		rakyll:statik:v0.1.7:rakyll_statik/vendor/github.com/rakyll/statik \
		rs:cors:v1.7.0:rs_cors/vendor/github.com/rs/cors \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v0.0.7:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.6.3:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		tj:go-spin:v1.1.0:tj_go_spin/vendor/github.com/tj/go-spin \
		uber-go:atomic:v1.6.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:goleak:v0.10.0:uber_go_goleak/vendor/go.uber.org/goleak \
		zchee:go-xdgbasedir:v1.0.3:zchee_go_xdgbasedir/vendor/github.com/zchee/go-xdgbasedir \
		protocolbuffers:protobuf-go:v1.21.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
