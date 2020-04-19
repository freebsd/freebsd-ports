# $FreeBSD$

PORTNAME=	evans
DISTVERSION=	0.8.5
CATEGORIES=	net

MAINTAINER=	vulcan@wired.sh
COMMENT=	More expressive universal gRPC client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	ktr0731
GH_TUPLE=	alecthomas:gometalinter:v3.0.0:alecthomas_gometalinter/vendor/github.com/alecthomas/gometalinter \
		alecthomas:kingpin:df19058c872c:alecthomas_kingpin/vendor/gopkg.in/alecthomas/kingpin.v3-unstable \
		alecthomas:units:f65c72e2690d:alecthomas_units/vendor/github.com/alecthomas/units \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		client9:misspell:v0.3.4:client9_misspell/vendor/github.com/client9/misspell \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-yaml:yaml:v2.2.3:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:lint:16217165b5de:golang_lint/vendor/golang.org/x/lint \
		golang:lint:c67002cb31c3:golang_lint_1/vendor/github.com/golang/lint \
		golang:net:c5a3c61f89f3:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:cd5d95a43a6e:golang_sync/vendor/golang.org/x/sync \
		golang:sys:c990c680b611:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:tools:7c411dea38b0:golang_tools/vendor/golang.org/x/tools \
		google:go-cmp:v0.3.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:20e1ac93f88c:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-github:v17.0.0:google_go_github/vendor/github.com/google/go-github \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:shlex:c34317bd91bf:google_shlex/vendor/github.com/google/shlex \
		gordonklaus:ineffassign:ed7b1b5ee0f8:gordonklaus_ineffassign/vendor/github.com/gordonklaus/ineffassign \
		gorilla:websocket:v1.4.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.24.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-version:v1.2.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		improbable-eng:grpc-web:v0.9.1:improbable_eng_grpc_web/vendor/github.com/improbable-eng/grpc-web \
		inconshreveable:go-update:8152e7eb6ccf:inconshreveable_go_update/vendor/github.com/inconshreveable/go-update \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jhump:protoreflect:10815c273d3f:jhump_protoreflect/vendor/github.com/jhump/protoreflect \
		juju:ansiterm:720a0952cc2a:juju_ansiterm/vendor/github.com/juju/ansiterm \
		k0kubun:pp:v3.0.1:k0kubun_pp/vendor/github.com/k0kubun/pp \
		ktr0731:dept:v0.1.1:ktr0731_dept/vendor/github.com/ktr0731/dept \
		ktr0731:go-multierror:b7773ae21874:ktr0731_go_multierror/vendor/github.com/ktr0731/go-multierror \
		ktr0731:go-prompt:7894cc3f2925:ktr0731_go_prompt/vendor/github.com/ktr0731/go-prompt \
		ktr0731:go-shellstring:v0.1.0:ktr0731_go_shellstring/vendor/github.com/ktr0731/go-shellstring \
		ktr0731:go-updater:v0.1.5:ktr0731_go_updater/vendor/github.com/ktr0731/go-updater \
		ktr0731:grpc-test:v0.1.2:ktr0731_grpc_test/vendor/github.com/ktr0731/grpc-test \
		ktr0731:grpc-web-go-client:c24452752d52:ktr0731_grpc_web_go_client/vendor/github.com/ktr0731/grpc-web-go-client \
		lunixbochs:vtclean:v1.0.0:lunixbochs_vtclean/vendor/github.com/lunixbochs/vtclean \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		manifoldco:promptui:v0.3.2:manifoldco_promptui/vendor/github.com/manifoldco/promptui \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.9:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-pipeline:32d779b32768:mattn_go_pipeline/vendor/github.com/mattn/go-pipeline \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-tty:523744f04859:mattn_go_tty/vendor/github.com/mattn/go-tty \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		nicksnyder:go-i18n:25e77afbf581:nicksnyder_go_i18n/vendor/github.com/nicksnyder/go-i18n \
		nicksnyder:go-i18n:v2.0.2:nicksnyder_go_i18n_1/vendor/github.com/nicksnyder/go-i18n/v2 \
		olekukonko:tablewriter:v0.0.1:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		pelletier:go-toml:v1.4.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		phayes:freeport:95f893ade6f2:phayes_freeport/vendor/github.com/phayes/freeport \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:term:aa71e9d9e942:pkg_term/vendor/github.com/pkg/term \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rakyll:statik:v0.1.6:rakyll_statik/vendor/github.com/rakyll/statik \
		rs:cors:v1.6.0:rs_cors/vendor/github.com/rs/cors \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.4.0:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tj:go-spin:v1.1.0:tj_go_spin/vendor/github.com/tj/go-spin \
		tsenart:deadcode:210d2dc333e9:tsenart_deadcode/vendor/github.com/tsenart/deadcode \
		uber-go:goleak:v0.10.0:uber_go_goleak/vendor/go.uber.org/goleak \
		zchee:go-xdgbasedir:v1.0.3:zchee_go_xdgbasedir/vendor/github.com/zchee/go-xdgbasedir

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
