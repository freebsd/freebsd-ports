# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	termshark
PORTVERSION=	2.1.1
DISTVERSIONPREFIX=v
CATEGORIES=	net

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Terminal UI for tshark, inspired by Wireshark

LICENSE=	MIT

USES=		go:modules

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=

X11_RUN_DEPENDS_OFF=	tshark>0:net/tshark
X11_RUN_DEPENDS=	wireshark>0:net/wireshark

USE_GITHUB=	yes

GH_ACCOUNT=	gcla
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		adam-hanna:arrayOperations:v0.2.5:adam_hanna_arrayoperations/vendor/github.com/adam-hanna/arrayOperations \
		antchfx:xmlquery:v1.0.0:antchfx_xmlquery/vendor/github.com/antchfx/xmlquery \
		antchfx:xpath:v1.0.0:antchfx_xpath/vendor/github.com/antchfx/xpath \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gcla:deep:v1.0.2:gcla_deep/vendor/github.com/gcla/deep \
		gcla:gowid:45eed270dfd5:gcla_gowid/vendor/github.com/gcla/gowid \
		gcla:tail:650e90873359:gcla_tail/vendor/github.com/gcla/tail \
		gcla:tcell:b90e69b9dbe0:gcla_tcell_1/vendor/github.com/gdamore/tcell \
		gcla:term:31cba2f9f402:gcla_term_1/vendor/github.com/pkg/term \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		go-check:check:788fd7840127:go_check_check/vendor/gopkg.in/check.v1 \
		go-test:deep:v1.0.2:go_test_deep \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:net:3b0461eec859:golang_net/vendor/golang.org/x/net \
		golang:sys:b09406accb47:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		hashicorp:golang-lru:v0.5.3:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		jessevdk:go-flags:v1.4.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kr:pretty:v0.1.0:kr_pretty/vendor/github.com/kr/pretty \
		lucasb-eyer:go-colorful:v1.0.3:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		magiconair:properties:v1.8.0:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-isatty:v0.0.9:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.7:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mreiferson:go-snappystream:v0.2.3:mreiferson_go_snappystream/vendor/github.com/mreiferson/go-snappystream \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		shibukawa:configdir:e180dbdc8da0:shibukawa_configdir/vendor/github.com/shibukawa/configdir \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.3.2:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tevino:abool:9b9efcf221b5:tevino_abool/vendor/github.com/tevino/abool

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${MKDIR} ${WRKSRC}/vendor/github.com/go-test
	@${RLN} ${WRKSRC_gcla_deep} ${WRKSRC}/vendor/github.com/go-test/deep
	@${MKDIR} ${WRKSRC}/vendor/gopkg.in
	@${RLN} ${WRKSRC_fsnotify_fsnotify} ${WRKSRC}/vendor/gopkg.in/fsnotify.v1
	@${MKDIR} ${WRKSRC}/vendor/gopkg.in/fsnotify
	@${RLN} ${WRKSRC_fsnotify_fsnotify} ${WRKSRC}/vendor/gopkg.in/fsnotify/fsnotify.v1

.include <bsd.port.mk>
