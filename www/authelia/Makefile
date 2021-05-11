PORTNAME=	authelia
DISTVERSIONPREFIX=	v
DISTVERSION=	4.29.2
CATEGORIES=	www
MASTER_SITES=	https://github.com/authelia/authelia/releases/download/v${DISTVERSION}/:public_html
DISTFILES=	authelia-${DISTVERSIONFULL}-public_html${EXTRACT_SUFX}:public_html # html root directory needs to be built in a special way

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Single sign-on multi-factor portal for web apps

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_TUPLE=	\
		Azure:go-ntlmssp:66371956d46c:azure_go_ntlmssp/vendor/github.com/Azure/go-ntlmssp \
		DATA-DOG:go-sqlmock:v1.5.0:data_dog_go_sqlmock/vendor/github.com/DATA-DOG/go-sqlmock \
		Gurpartap:logrus-stack:89c00d8a28f4:gurpartap_logrus_stack/vendor/github.com/Gurpartap/logrus-stack \
		Workiva:go-datastructures:v1.0.53:workiva_go_datastructures/vendor/github.com/Workiva/go-datastructures \
		andybalholm:brotli:v1.0.1:andybalholm_brotli/vendor/github.com/andybalholm/brotli \
		asaskevich:govalidator:7a23bdc65eef:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		boombuler:barcode:6c824513bacc:boombuler_barcode/vendor/github.com/boombuler/barcode \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		deckarep:golang-set:v1.7.1:deckarep_golang_set/vendor/github.com/deckarep/golang-set \
		dgraph-io:ristretto:v0.0.3:dgraph_io_ristretto/vendor/github.com/dgraph-io/ristretto \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dgryski:go-rendezvous:9f7001d12a5f:dgryski_go_rendezvous/vendor/github.com/dgryski/go-rendezvous \
		duosecurity:duo_api_golang:0e07e9f869e3:duosecurity_duo_api_golang/vendor/github.com/duosecurity/duo_api_golang \
		facebookgo:stack:751773369052:facebookgo_stack/vendor/github.com/facebookgo/stack \
		fasthttp:router:v1.3.12:fasthttp_router/vendor/github.com/fasthttp/router \
		fasthttp:session:v2.3.2:fasthttp_session_v2/vendor/github.com/fasthttp/session/v2 \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-asn1-ber:asn1-ber:v1.5.1:go_asn1_ber_asn1_ber/vendor/github.com/go-asn1-ber/asn1-ber \
		go-ini:ini:v1.57.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-ldap:ldap:v3.3.0:go_ldap_ldap_v3/vendor/github.com/go-ldap/ldap \
		go-redis:redis:v8.3.4:go_redis_redis_v8/vendor/github.com/go-redis/redis/v8 \
		go-sql-driver:mysql:v1.6.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:0c34fe9e7dc2:golang_crypto/vendor/golang.org/x/crypto \
		golang:mock:v1.5.0:golang_mock/vendor/github.com/golang/mock \
		golang:sys:a50acf3fe073:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		golang:tools:9cf592e881e9:golang_tools/vendor/golang.org/x/tools \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jackc:chunkreader:v2.0.1:jackc_chunkreader_v2/vendor/github.com/jackc/chunkreader/v2 \
		jackc:pgconn:v1.8.1:jackc_pgconn/vendor/github.com/jackc/pgconn \
		jackc:pgio:v1.0.0:jackc_pgio/vendor/github.com/jackc/pgio \
		jackc:pgpassfile:v1.0.0:jackc_pgpassfile/vendor/github.com/jackc/pgpassfile \
		jackc:pgproto3:v2.0.6:jackc_pgproto3_v2/vendor/github.com/jackc/pgproto3/v2 \
		jackc:pgservicefile:2b9c44734f2b:jackc_pgservicefile/vendor/github.com/jackc/pgservicefile \
		jackc:pgtype:v1.7.0:jackc_pgtype/vendor/github.com/jackc/pgtype \
		jackc:pgx:v4.11.0:jackc_pgx_v4/vendor/github.com/jackc/pgx/v4 \
		klauspost:compress:v1.11.8:klauspost_compress/vendor/github.com/klauspost/compress \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-sqlite3:v1.14.7:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		mattn:goveralls:v0.0.6:mattn_goveralls/vendor/github.com/mattn/goveralls \
		mitchellh:mapstructure:v1.3.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mohae:deepcopy:c48cc78d4826:mohae_deepcopy/vendor/github.com/mohae/deepcopy \
		open-telemetry:opentelemetry-go:v0.13.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		ory:fosite:v0.39.0:ory_fosite/vendor/github.com/ory/fosite \
		ory:go-acc:v0.2.5:ory_go_acc/vendor/github.com/ory/go-acc \
		ory:go-convenience:v0.1.0:ory_go_convenience/vendor/github.com/ory/go-convenience \
		ory:viper:v1.7.5:ory_viper/vendor/github.com/ory/viper \
		ory:x:v0.0.162:ory_x/vendor/github.com/ory/x \
		otiai10:copy:v1.6.0:otiai10_copy/vendor/github.com/otiai10/copy \
		pborman:uuid:v1.2.0:pborman_uuid/vendor/github.com/pborman/uuid \
		pelletier:go-toml:v1.8.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		philhofer:fwd:v1.1.1:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		pquerna:otp:v1.3.0:pquerna_otp/vendor/github.com/pquerna/otp \
		savsgio:dictpool:6de1ea7c0e13:savsgio_dictpool/vendor/github.com/savsgio/dictpool \
		savsgio:gotils:c54912823645:savsgio_gotils/vendor/github.com/savsgio/gotils \
		simia-tech:crypt:v0.5.0:simia_tech_crypt/vendor/github.com/simia-tech/crypt \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.3.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.1.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.1:spf13_viper/vendor/github.com/spf13/viper \
		square:go-jose:v2.5.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		tebeka:selenium:v0.9.9:tebeka_selenium/vendor/github.com/tebeka/selenium \
		tinylib:msgp:v1.1.5:tinylib_msgp/vendor/github.com/tinylib/msgp \
		tstranex:u2f:v1.0.0:tstranex_u2f/vendor/github.com/tstranex/u2f \
		valyala:bytebufferpool:v1.0.0:valyala_bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		valyala:fasthttp:v1.24.0:valyala_fasthttp/vendor/github.com/valyala/fasthttp
GO_TARGET=	./cmd/${PORTNAME}

USER=		root # 'nobody' doesn't work well because authelia attempts to remove files, etc.
SUB_LIST=	USER=${USER}
USE_RC_SUBR=	${PORTNAME}

post-extract: # extract -public-html
	@${RM} -r ${WRKSRC}/internal/server/public_html
	@${MV} ${WRKDIR}/public_html ${WRKSRC}/internal/server
	@${CP} -r ${WRKSRC}/api ${WRKSRC}/internal/server/public_html/api

post-install: # install the config file
	${INSTALL_DATA} ${WRKSRC}/config.template.yml ${STAGEDIR}${PREFIX}/etc/authelia.yml.sample

.include <bsd.port.mk>
