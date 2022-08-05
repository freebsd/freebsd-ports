PORTNAME=	termshark
PORTVERSION=	2.4.0
DISTVERSIONPREFIX=v
CATEGORIES=	net
MASTER_SITES=	https://salsa.debian.org/vasudev/gospake2/-/archive/${GOSPAKE2_HASH}/:gospake2 \
		https://salsa.debian.org/vasudev/ed25519group/-/archive/${ED25519_HASH}/:ed25519
DISTFILES=	gospake2-${GOSPAKE2_HASH}.tar.gz:gospake2 \
		ed25519group-${ED25519_HASH}.tar.gz:ed25519

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Terminal UI for tshark, inspired by Wireshark

LICENSE=	MIT

USES=		go:modules

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=

X11_RUN_DEPENDS_OFF=	tshark>0:net/tshark
X11_RUN_DEPENDS=	wireshark>0:net/wireshark

GOSPAKE2_HASH=	10ebaf42f42fe21f53cad42fe6f5efa9a528da4e
ED25519_HASH=	3aff6cc605d469a7d618240e4a5cee3e1a861b43

USE_GITHUB=	yes
USE_GITLAB=	nodefault

GH_ACCOUNT=	gcla
GH_TUPLE=	\
		adam-hanna:arrayOperations:v0.2.6:adam_hanna_arrayoperations/vendor/github.com/adam-hanna/arrayOperations \
		antchfx:xmlquery:v1.3.3:antchfx_xmlquery/vendor/github.com/antchfx/xmlquery \
		antchfx:xpath:v1.1.11:antchfx_xpath/vendor/github.com/antchfx/xpath \
		araddon:dateparse:0eec95c9db7e:araddon_dateparse/vendor/github.com/araddon/dateparse \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		creack:pty:v1.1.15:creack_pty/vendor/github.com/creack/pty \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		flytam:filenamify:v1.1.0:flytam_filenamify/vendor/github.com/flytam/filenamify \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify_1/vendor/gopkg.in/fsnotify/fsnotify.v1 \
		fsnotify:fsnotify:v1.5.4:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gcla:deep:v1.0.2:gcla_deep/vendor/github.com/gcla/deep \
		gcla:gowid:v1.4.0:gcla_gowid/vendor/github.com/gcla/gowid \
		gcla:tail:650e90873359:gcla_tail/vendor/github.com/gcla/tail \
		gcla:term:3e6af2ebff27:gcla_term/vendor/github.com/gcla/term \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v2.5.0:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		go-ini:ini:v1.66.4:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.0:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		golang:crypto:7b82a4e95df4:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:2e3eb7b945c2:golang_net/vendor/golang.org/x/net \
		golang:sys:bc2c85ada10a:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		jessevdk:go-flags:v1.4.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		klauspost:compress:v1.11.13:klauspost_compress/vendor/github.com/klauspost/compress \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		magiconair:properties:v1.8.6:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mreiferson:go-snappystream:v0.2.3:mreiferson_go_snappystream/vendor/github.com/mreiferson/go-snappystream \
		nhooyr:websocket:v1.8.6:nhooyr_websocket/vendor/nhooyr.io/websocket \
		pelletier:go-toml:v1.9.5:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pelletier:go-toml:v2.0.1:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		psanford:wormhole-william:049df45b8d5a:psanford_wormhole_william/vendor/github.com/psanford/wormhole-william \
		rakyll:statik:v0.1.7:rakyll_statik/vendor/github.com/rakyll/statik \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		shibukawa:configdir:e180dbdc8da0:shibukawa_configdir/vendor/github.com/shibukawa/configdir \
		sirupsen:logrus:v1.7.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.8.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.5.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.12.0:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:testify:v1.7.1:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.3.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		tevino:abool:v1.2.0:tevino_abool/vendor/github.com/tevino/abool

GL_TUPLE=	jonas.jasas:condchan:36637ad2b5bc273b9310b309418ede63697b8ab9:jonas_jasas_condchan/vendor/gitlab.com/jonas.jasas/condchan

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${MKDIR} ${WRKSRC}/vendor/github.com/go-test
	@${RLN} ${WRKSRC_gcla_deep} ${WRKSRC}/vendor/github.com/go-test/deep
	@${MKDIR} ${WRKSRC}/vendor/gopkg.in
	@${RLN} ${WRKSRC_fsnotify_fsnotify} ${WRKSRC}/vendor/gopkg.in/fsnotify.v1
	@${MKDIR} ${WRKSRC}/vendor/gopkg.in/fsnotify
	@${RLN} ${WRKSRC_fsnotify_fsnotify} ${WRKSRC}/vendor/gopkg.in/fsnotify/fsnotify.v1
	@${MKDIR} ${WRKSRC}/vendor/salsa.debian.org/vasudev
	@${MV} ${WRKDIR}/gospake2-${GOSPAKE2_HASH} ${WRKSRC}/vendor/salsa.debian.org/vasudev/gospake2
	@${MV} ${WRKDIR}/ed25519group-${ED25519_HASH} ${WRKSRC}/vendor/salsa.debian.org/vasudev/ed25519group

.include <bsd.port.mk>
