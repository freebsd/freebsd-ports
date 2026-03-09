PORTNAME=	fmd-server
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.0
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	mm@FreeBSD.org
COMMENT=	FMD web server to locate and control your devices
WWW=		https://fmd-foss.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules nodejs:build
USE_GITLAB=	yes
USE_GITHUB=	nodefault
GL_ACCOUNT=	fmd-foss
GO_MODULE=	gitlab.com/fmd-foss/fmd-server

NO_PACKAGE=	downloads nodejs modules during web interface build

USE_RC_SUBR=	${PORTNAME}

CONFIGURE_ENV=	COREPACK_ENABLE_DOWNLOAD_PROMPT=0

PLIST_FILES=	"@sample ${ETCDIR}/config.yml.sample" \
		bin/${PORTNAME}

GH_TUPLE=	\
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.3.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fsnotify:fsnotify:v1.9.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		glebarez:go-sqlite:v1.22.0:glebarez_go_sqlite/vendor/github.com/glebarez/go-sqlite \
		glebarez:sqlite:v1.11.0:glebarez_sqlite/vendor/github.com/glebarez/sqlite \
		go-gorm:gorm:v1.31.1:go_gorm_gorm/vendor/gorm.io/gorm \
		go-viper:mapstructure:v2.5.0:go_viper_mapstructure_v2/vendor/github.com/go-viper/mapstructure/v2 \
		golang:exp:716be5621a96:golang_exp/vendor/golang.org/x/exp \
		golang:sys:v0.40.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.33.0:golang_text/vendor/golang.org/x/text \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jinzhu:inflection:v1.0.0:jinzhu_inflection/vendor/github.com/jinzhu/inflection \
		jinzhu:now:v1.1.5:jinzhu_now/vendor/github.com/jinzhu/now \
		mattn:go-colorable:v0.1.14:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		munnerz:goautoneg:a7dc8b61c822:munnerz_goautoneg/vendor/github.com/munnerz/goautoneg \
		ncruces:go-strftime:v1.0.0:ncruces_go_strftime/vendor/github.com/ncruces/go-strftime \
		pelletier:go-toml:v2.2.4:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		prometheus:client_golang:v1.23.2:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.6.2:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.67.5:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.19.2:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.36.11:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		remyoudompheng:bigfft:24d4a6f8daec:remyoudompheng_bigfft/vendor/github.com/remyoudompheng/bigfft \
		rogpeppe:go-internal:v1.12.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		rs:zerolog:v1.34.0:rs_zerolog/vendor/github.com/rs/zerolog \
		sagikazarmark:locafero:v0.12.0:sagikazarmark_locafero/vendor/github.com/sagikazarmark/locafero \
		spf13:afero:v1.15.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.10.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.10.2:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.10:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.21.0:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.6.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		yaml:go-yaml:v2.4.3:yaml_go_yaml/vendor/go.yaml.in/yaml/v2 \
		yaml:go-yaml:v3.0.4:yaml_go_yaml_1/vendor/go.yaml.in/yaml/v3

GL_TUPLE=	\
		cznic:libc:6e4a801525dcb3e1f9c6a9e560ae30fed5752945:cznic_libc/vendor/modernc.org/libc \
		cznic:mathutil:28129eec384c30a304561c3c8779e4bb29cbff12:cznic_mathutil/vendor/modernc.org/mathutil \
		cznic:memory:0a6f7544739330ad95572cc272626a60176f2faf:cznic_memory/vendor/modernc.org/memory \
		cznic:sqlite:bb6a17d8df4bb5fe2c530d512ca14e8ddfeffc47:cznic_sqlite/vendor/modernc.org/sqlite

post-configure:
		@${MKDIR} ${WRKDIR}/.bin
		@cd ${WRKSRC}/web && \
			${SETENV} ${CONFIGURE_ENV} corepack enable --install-directory ${WRKDIR}/.bin && \
			${SETENV} ${CONFIGURE_ENV} pnpm install

pre-build:
		@cd ${WRKSRC}/web && \
			${SETENV} ${MAKE_ENV} corepack enable --install-directory ${WRKDIR}/.bin && \
			${SETENV} ${MAKE_ENV} pnpm build

post-install:
	        @${MKDIR} ${STAGEDIR}${ETCDIR}
		${INSTALL_DATA} ${WRKSRC}/config.example.yml ${STAGEDIR}${ETCDIR}/config.yml.sample

.include <bsd.port.mk>
