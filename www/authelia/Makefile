# $FreeBSD$

PORTNAME=	authelia
DISTVERSIONPREFIX=	v
DISTVERSION=	4.6.0
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Single sign-on multi-factor portal for web apps

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_TUPLE=	\
		Gurpartap:logrus-stack:89c00d8a28f4:gurpartap_logrus_stack/vendor/github.com/Gurpartap/logrus-stack \
		Workiva:go-datastructures:v1.0.50:workiva_go_datastructures/vendor/github.com/Workiva/go-datastructures \
		asaskevich:govalidator:f61b66f89f4a:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		boombuler:barcode:6c824513bacc:boombuler_barcode/vendor/github.com/boombuler/barcode \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		deckarep:golang-set:v1.7.1:deckarep_golang_set/vendor/github.com/deckarep/golang-set \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		duosecurity:duo_api_golang:6c680f768e74:duosecurity_duo_api_golang/vendor/github.com/duosecurity/duo_api_golang \
		facebookgo:stack:751773369052:facebookgo_stack/vendor/github.com/facebookgo/stack \
		fasthttp:router:v0.5.2:fasthttp_router/vendor/github.com/fasthttp/router \
		fasthttp:session:v1.1.3:fasthttp_session/vendor/github.com/fasthttp/session \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-asn1-ber:asn1-ber:f715ec2f112d:go_asn1_ber_asn1_ber/vendor/gopkg.in/asn1-ber.v1 \
		go-ini:ini:v1.51.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-ldap:ldap:v3.1.0:go_ldap_ldap/vendor/gopkg.in/ldap.v3 \
		go-redis:redis:v6.15.2:go_redis_redis/vendor/github.com/go-redis/redis \
		go-sql-driver:mysql:v1.4.1:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-yaml:yaml:v2.2.4:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:f99c8df09eb5:golang_crypto/vendor/golang.org/x/crypto \
		golang:mock:v1.3.1:golang_mock/vendor/github.com/golang/mock \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:112230192c58:golang_sync/vendor/golang.org/x/sync \
		golang:sys:c5567b49c5d0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		klauspost:compress:v1.8.2:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v1.2.1:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		lib:pq:v1.2.0:lib_pq/vendor/github.com/lib/pq \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-sqlite3:v1.11.0:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mongodb:mongo-go-driver:v1.1.3:mongodb_mongo_go_driver/vendor/go.mongodb.org/mongo-driver \
		otiai10:copy:v1.0.2:otiai10_copy/vendor/github.com/otiai10/copy \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		philhofer:fwd:v1.0.0:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		pquerna:otp:v1.2.0:pquerna_otp/vendor/github.com/pquerna/otp \
		savsgio:dictpool:a886cee3358a:savsgio_dictpool/vendor/github.com/savsgio/dictpool \
		savsgio:gotils:524bc4f47500:savsgio_gotils/vendor/github.com/savsgio/gotils \
		simia-tech:crypt:v0.4.2:simia_tech_crypt/vendor/github.com/simia-tech/crypt \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.6.2:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		tebeka:selenium:v0.9.9:tebeka_selenium/vendor/github.com/tebeka/selenium \
		tinylib:msgp:v1.1.0:tinylib_msgp/vendor/github.com/tinylib/msgp \
		tstranex:u2f:v1.0.0:tstranex_u2f/vendor/github.com/tstranex/u2f \
		valyala:bytebufferpool:v1.0.0:valyala_bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		valyala:fasthttp:v1.6.0:valyala_fasthttp/vendor/github.com/valyala/fasthttp \
		xdg:scram:7eeb5667e42c:xdg_scram/vendor/github.com/xdg/scram \
		xdg:stringprep:v1.0.0:xdg_stringprep/vendor/github.com/xdg/stringprep
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
