# $FreeBSD$

PORTNAME=	cloudquery
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	net

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Transform cloud infrastructure into queryable SQL tables

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

GH_TUPLE=	\
		Azure:go-ansiterm:d6e3b3328b78:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		Microsoft:go-winio:v0.4.14:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Nvveen:Gotty:cd527374f1e5:nvveen_gotty/vendor/github.com/Nvveen/Gotty \
		aws:aws-lambda-go:v1.22.0:aws_aws_lambda_go/vendor/github.com/aws/aws-lambda-go \
		cenkalti:backoff:v3.2.2:cenkalti_backoff_v3/vendor/github.com/cenkalti/backoff/v3 \
		containerd:continuity:180525291bb7:containerd_continuity/vendor/github.com/containerd/continuity \
		creasty:defaults:v1.5.1:creasty_defaults/vendor/github.com/creasty/defaults \
		denisenkom:go-mssqldb:06a60b6afbbc:denisenkom_go_mssqldb/vendor/github.com/denisenkom/go-mssqldb \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-gorm:gorm:v1.20.9:go_gorm_gorm/vendor/gorm.io/gorm \
		go-gorm:mysql:v1.0.2:go_gorm_mysql/vendor/gorm.io/driver/mysql \
		go-gorm:postgres:v1.0.2:go_gorm_postgres/vendor/gorm.io/driver/postgres \
		go-gorm:sqlite:v1.1.3:go_gorm_sqlite/vendor/gorm.io/driver/sqlite \
		go-gorm:sqlserver:v1.0.4:go_gorm_sqlserver/vendor/gorm.io/driver/sqlserver \
		go-ini:ini:v1.51.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-yaml:yaml:eeeca48fe776:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang-sql:civil:cb61b32ac6fe:golang_sql_civil/vendor/github.com/golang-sql/civil \
		golang:crypto:9e8e0b390897:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:5f4716e94777:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:112230192c58:golang_sync/vendor/golang.org/x/sync \
		golang:sys:22da62e12c0c:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.5:golang_text/vendor/golang.org/x/text \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-genproto:cf70463f6119:google_go_genproto/vendor/google.golang.org/genproto \
		grpc:grpc-go:v1.35.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:go-hclog:v0.14.1:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-plugin:v1.4.0:hashicorp_go_plugin/vendor/github.com/hashicorp/go-plugin \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:yamux:3520598351bb:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		iancoleman:strcase:v0.1.2:iancoleman_strcase/vendor/github.com/iancoleman/strcase \
		imdario:mergo:v0.3.11:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jackc:chunkreader:v2.0.1:jackc_chunkreader_v2/vendor/github.com/jackc/chunkreader/v2 \
		jackc:pgconn:v1.7.0:jackc_pgconn/vendor/github.com/jackc/pgconn \
		jackc:pgio:v1.0.0:jackc_pgio/vendor/github.com/jackc/pgio \
		jackc:pgpassfile:v1.0.0:jackc_pgpassfile/vendor/github.com/jackc/pgpassfile \
		jackc:pgproto3:v2.0.5:jackc_pgproto3_v2/vendor/github.com/jackc/pgproto3/v2 \
		jackc:pgservicefile:2b9c44734f2b:jackc_pgservicefile/vendor/github.com/jackc/pgservicefile \
		jackc:pgtype:v1.5.0:jackc_pgtype/vendor/github.com/jackc/pgtype \
		jackc:pgx:v4.9.0:jackc_pgx_v4/vendor/github.com/jackc/pgx/v4 \
		jinzhu:inflection:v1.0.0:jinzhu_inflection/vendor/github.com/jinzhu/inflection \
		jinzhu:now:v1.1.1:jinzhu_now/vendor/github.com/jinzhu/now \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.7:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-sqlite3:v1.14.3:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		mitchellh:go-testing-interface:v1.0.0:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		moby:term:df9cb8a40635:moby_term/vendor/github.com/moby/term \
		natefinch:lumberjack:v2.0.0:natefinch_lumberjack/vendor/gopkg.in/natefinch/lumberjack.v2 \
		neo4j:neo4j-go-driver:003230e3e54b:neo4j_neo4j_go_driver_v4/vendor/github.com/neo4j/neo4j-go-driver/v4 \
		oklog:run:v1.0.0:oklog_run/vendor/github.com/oklog/run \
		olekukonko:tablewriter:v0.0.4:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runc:v1.0.0-rc9:opencontainers_runc/vendor/github.com/opencontainers/runc \
		ory:dockertest:v3.6.3:ory_dockertest_v3/vendor/github.com/ory/dockertest/v3 \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rs:zerolog:v1.20.0:rs_zerolog/vendor/github.com/rs/zerolog \
		shopspring:decimal:v1.2.0:shopspring_decimal/vendor/github.com/shopspring/decimal \
		sirupsen:logrus:v1.7.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.1.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.1:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

