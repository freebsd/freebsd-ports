PORTNAME=	browsh
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.3
CATEGORIES=	www
MASTER_SITES=	https://github.com/browsh-org/browsh/releases/download/${DISTVERSIONFULL}/:xpi
DISTFILES=	${PORTNAME}-${DISTVERSION}.xpi:xpi

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Text-based browser supporting HTML5, CSS3, JS, video and WebGL
WWW=		https://www.brow.sh/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/../LICENSE

RUN_DEPENDS=	firefox>63:www/firefox

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	NYTimes:gziphandler:v1.1.1:nytimes_gziphandler/vendor/github.com/NYTimes/gziphandler \
		fsnotify:fsnotify:v1.7.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v1.4.0:gdamore_tcell/vendor/github.com/gdamore/tcell \
		go-errors:errors:v1.5.1:go_errors_errors/vendor/github.com/go-errors/errors \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:exp:f3f8817b8deb:golang_exp/vendor/golang.org/x/exp \
		golang:net:v0.19.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.15.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.6.0:google_go_cmp/vendor/github.com/google/go-cmp \
		gorilla:websocket:v1.5.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		magiconair:properties:v1.8.7:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-runewidth:v0.0.15:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		nxadm:tail:v1.4.11:nxadm_tail/vendor/github.com/nxadm/tail \
		onsi:ginkgo:v1.16.5:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:gomega:v1.30.0:onsi_gomega/vendor/github.com/onsi/gomega \
		pelletier:go-toml:v2.1.0:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		rivo:uniseg:v0.4.4:rivo_uniseg/vendor/github.com/rivo/uniseg \
		sagikazarmark:locafero:v0.4.0:sagikazarmark_locafero/vendor/github.com/sagikazarmark/locafero \
		sagikazarmark:slog-shim:v0.1.0:sagikazarmark_slog_shim/vendor/github.com/sagikazarmark/slog-shim \
		shibukawa:configdir:e180dbdc8da0:shibukawa_configdir/vendor/github.com/shibukawa/configdir \
		sourcegraph:conc:v0.3.0:sourcegraph_conc/vendor/github.com/sourcegraph/conc \
		spf13:afero:v1.11.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.6.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.18.1:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.6.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr \
		ulule:limiter:v2.2.2:ulule_limiter/vendor/github.com/ulule/limiter
# Use GH_TUPLE+= for browsh-org:browsh:${DISTVERSIONFULL}:browsh so that we can
# use `make gomod-vendor | portedit -i merge Makefile` during updates.
GH_TUPLE+=	browsh-org:browsh:${DISTVERSIONFULL}:browsh
GO_TARGET=	./cmd/browsh

WRKSRC=		${WRKSRC_browsh}
WRKSRC_SUBDIR=	interfacer

PLIST_FILES=	bin/browsh

post-extract:
	${CP} ${_DISTDIR}/${PORTNAME}-${DISTVERSION}.xpi \
		${WRKSRC}/src/browsh/browsh.xpi

.include <bsd.port.mk>
