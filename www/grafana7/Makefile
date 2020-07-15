# $FreeBSD$

PORTNAME=	grafana
PORTVERSION=	7.0.6
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES+=	https://dl.grafana.com/oss/release/:public \
				https://gitea.com/xorm/builder/archive/:builder \
				https://gitea.com/xorm/core/archive/:core \
				https://gitea.com/xorm/xorm/archive/:xorm
PKGNAMESUFFIX=	${PORTVERSION:C/([0-9]).*/\1/1}
DISTFILES=	grafana-${PORTVERSION}.linux-amd64${EXTRACT_SUFX}:public \
			v0.3.6${EXTRACT_SUFX}:builder \
			v0.7.3${EXTRACT_SUFX}:core \
			v0.8.1${EXTRACT_SUFX}:xorm

MAINTAINER=	robsonmantovani@gmail.com
COMMENT=	Dashboard and graph editor for multiple data stores

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 i386

USES=		go:modules
USE_RC_SUBR=	grafana

USE_GITHUB=	yes
TAG=		aee1438

GO_TARGET=	./pkg/cmd/grafana-server \
		./pkg/cmd/grafana-cli
GO_BUILDFLAGS=	-ldflags="-w -X main.version=${PORTVERSION} -X main.commit=${TAG}"
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		VividCortex:mysqlerr:6c6b55f8796f:vividcortex_mysqlerr/vendor/github.com/VividCortex/mysqlerr \
		alexcesaro:quotedprintable:2caba252f4dc:alexcesaro_quotedprintable/vendor/gopkg.in/alexcesaro/quotedprintable.v3 \
		apache:arrow:89ce1cadb678:apache_arrow_arrow/vendor/github.com/apache/arrow \
		aws:aws-sdk-go:v1.29.20:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beevik:etree:v1.1.0:beevik_etree/vendor/github.com/beevik/etree \
		benbjohnson:clock:7dc76406b6d3:benbjohnson_clock/vendor/github.com/benbjohnson/clock \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bradfitz:gomemcache:551aad21a668:bradfitz_gomemcache/vendor/github.com/bradfitz/gomemcache \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		codahale:hdrhistogram:3a0bb77429bd:codahale_hdrhistogram/vendor/github.com/codahale/hdrhistogram \
		cpuguy83:go-md2man:f79a8a8ca69d:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		crewjam:saml:c42136edf9b1:crewjam_saml/vendor/github.com/crewjam/saml \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		denisenkom:go-mssqldb:2be1aa521ff4:denisenkom_go_mssqldb/vendor/github.com/denisenkom/go-mssqldb \
		facebookgo:ensure:b4ab57deab51:facebookgo_ensure/vendor/github.com/facebookgo/ensure \
		facebookgo:inject:f23751cae28b:facebookgo_inject/vendor/github.com/facebookgo/inject \
		facebookgo:stack:751773369052:facebookgo_stack/vendor/github.com/facebookgo/stack \
		facebookgo:structtag:217e25fb9691:facebookgo_structtag/vendor/github.com/facebookgo/structtag \
		facebookgo:subset:8dac2c3c4870:facebookgo_subset/vendor/github.com/facebookgo/subset \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		go-asn1-ber:asn1-ber:f715ec2f112d:go_asn1_ber_asn1_ber/vendor/gopkg.in/asn1-ber.v1 \
		go-ini:ini:v1.46.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-ldap:ldap:v3.0.2:go_ldap_ldap/vendor/gopkg.in/ldap.v3 \
		go-macaron:binding:0b4f37bab25b:go_macaron_binding/vendor/github.com/go-macaron/binding \
		go-macaron:gzip:cad1c6580a07:go_macaron_gzip/vendor/github.com/go-macaron/gzip \
		go-macaron:inject:d8a0b8677191:go_macaron_inject/vendor/github.com/go-macaron/inject \
		go-macaron:macaron:v1.3.4:go_macaron_macaron/vendor/gopkg.in/macaron.v1 \
		go-macaron:session:1a3cdc6f5659:go_macaron_session/vendor/github.com/go-macaron/session \
		go-mail:mail:v2.3.1:go_mail_mail/vendor/gopkg.in/mail.v2 \
		go-redis:redis:v5.2.9:go_redis_redis/vendor/gopkg.in/redis.v5 \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-yaml:yaml:v2.2.5:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		golang:appengine:v1.6.1:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:056763e48d71:golang_crypto/vendor/golang.org/x/crypto \
		golang:lint:fdd1cda4f05f:golang_lint/vendor/golang.org/x/lint \
		golang:net:16171245cfb2:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369cfe45:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.4:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:cd5d95a43a6e:golang_sync/vendor/golang.org/x/sync \
		golang:sys:d5e6a3e2c0ae:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:tools:04c2e8eff935:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		google:flatbuffers:v1.11.0:google_flatbuffers/vendor/github.com/google/flatbuffers \
		google:go-cmp:v0.3.1:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:24fa4b261c55:google_go_genproto/vendor/google.golang.org/genproto \
		googleapis:google-cloud-go:v0.37.4:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gopherjs:gopherjs:3e4dfb77656c:gopherjs_gopherjs/vendor/github.com/gopherjs/gopherjs \
		gorilla:websocket:v1.4.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
		gosimple:slug:v1.4.2:gosimple_slug/vendor/github.com/gosimple/slug \
		grafana:grafana-plugin-model:1fc953a61fb4:grafana_grafana_plugin_model/vendor/github.com/grafana/grafana-plugin-model \
		grafana:grafana-plugin-sdk-go:v0.60.0:grafana_grafana_plugin_sdk_go/vendor/github.com/grafana/grafana-plugin-sdk-go \
		grpc-ecosystem:go-grpc-middleware:v1.2.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:v1.2.0:grpc_ecosystem_go_grpc_prometheus/vendor/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc:grpc-go:v1.27.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:go-hclog:ff2cf002a8dd:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-plugin:v1.2.2:hashicorp_go_plugin/vendor/github.com/hashicorp/go-plugin \
		hashicorp:go-version:v1.1.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:yamux:2f1d1f20f75d:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		inconshreveable:log15:67afb5ed74ec:inconshreveable_log15/vendor/github.com/inconshreveable/log15 \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		jonboulle:clockwork:v0.1.0:jonboulle_clockwork/vendor/github.com/jonboulle/clockwork \
		json-iterator:go:v1.1.8:json_iterator_go/vendor/github.com/json-iterator/go \
		jtolds:gls:v4.20.0:jtolds_gls/vendor/github.com/jtolds/gls \
		jung-kurt:gofpdf:v1.10.1:jung_kurt_gofpdf/vendor/github.com/jung-kurt/gofpdf \
		k0kubun:colorstring:9440f1994b88:k0kubun_colorstring/vendor/github.com/k0kubun/colorstring \
		klauspost:compress:v1.4.1:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v1.2.0:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
		lib:pq:v1.2.0:lib_pq/vendor/github.com/lib/pq \
		linkedin:goavro:v2.9.7:linkedin_goavro_v2/vendor/github.com/linkedin/goavro/v2 \
		mattetti:filebuffer:v1.0.0:mattetti_filebuffer/vendor/github.com/mattetti/filebuffer \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.7:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-sqlite3:v1.11.0:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:go-testing-interface:a61a99592b77:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		oklog:run:v1.0.0:oklog_run/vendor/github.com/oklog/run \
		olekukonko:tablewriter:v0.0.4:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		opentracing:opentracing-go:v1.1.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.3.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.1.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.7.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.8:prometheus_procfs/vendor/github.com/prometheus/procfs \
		rainycape:unidecode:cb7f23ec59be:rainycape_unidecode/vendor/github.com/rainycape/unidecode \
		robfig:cron:b41be1df6967:robfig_cron/vendor/github.com/robfig/cron \
		robfig:cron:v3.0.0:robfig_cron_v3/vendor/github.com/robfig/cron/v3 \
		russellhaering:goxmldsig:7acd5e4a6ef7:russellhaering_goxmldsig/vendor/github.com/russellhaering/goxmldsig \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		sergi:go-diff:v1.0.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		smartystreets:assertions:v1.0.1:smartystreets_assertions/vendor/github.com/smartystreets/assertions \
		smartystreets:goconvey:505e41936337:smartystreets_goconvey/vendor/github.com/smartystreets/goconvey \
		square:go-jose:v2.4.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		teris-io:shortid:771a37caa5cf:teris_io_shortid/vendor/github.com/teris-io/shortid \
		timberio:go-datemath:74ddef604fff:timberio_go_datemath/vendor/github.com/timberio/go-datemath \
		ua-parser:uap-go:daf92ba38329:ua_parser_uap_go/vendor/github.com/ua-parser/uap-go \
		uber-go:atomic:v1.5.1:uber_go_atomic/vendor/go.uber.org/atomic \
		uber:jaeger-client-go:v2.20.1:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		uber:jaeger-lib:v2.2.0:uber_jaeger_lib/vendor/github.com/uber/jaeger-lib \
		unknwon:com:v1.0.1:unknwon_com/vendor/github.com/unknwon/com \
		urfave:cli:v2.1.1:urfave_cli_v2/vendor/github.com/urfave/cli/v2 \
		xorcare:pointer:v1.1.0:xorcare_pointer/vendor/github.com/xorcare/pointer \
		yudai:gojsondiff:v1.0.0:yudai_gojsondiff/vendor/github.com/yudai/gojsondiff \
		yudai:golcs:ecda9a501e82:yudai_golcs/vendor/github.com/yudai/golcs \
		yudai:pp:v2.0.1:yudai_pp/vendor/github.com/yudai/pp

		# Mirrors for the following packages are not currently known, please look them up and handle these tuples manually:
		#	::v0.3.6:group_name/vendor/xorm.io/builder (from gitea.com/xorm/builder@v0.3.6)
		#	::v0.7.3:group_name/vendor/xorm.io/core (from gitea.com/xorm/core@v0.7.3)
		#	::v0.8.1:group_name/vendor/xorm.io/xorm (from gitea.com/xorm/xorm@v0.8.1)

GRAFANA_USER?=	grafana
GRAFANA_GROUP?=	grafana

USERS=		${GRAFANA_USER}
GROUPS=		${GRAFANA_GROUP}

GRAFANAHOMEDIR=		${PREFIX}/share/grafana
GRAFANADATADIR=		/var/db/${PORTNAME}/
GRAFANALOGDIR=		/var/log/${PORTNAME}/
GRAFANAPIDDIR=		/var/run/${PORTNAME}/
GRAFANAPLUGINDIR=	/var/db/${PORTNAME}/plugins
GRAFANAPROVISIONINGDIR=	/var/db/${PORTNAME}/provisioning

SUB_FILES=	grafana grafana.conf
SUB_LIST+=	GRAFANA_USER=${GRAFANA_USER} \
		GRAFANA_GROUP=${GRAFANA_GROUP} \
		GRAFANADATADIR=${GRAFANADATADIR} \
		GRAFANALOGDIR=${GRAFANALOGDIR} \
		GRAFANAPIDDIR=${GRAFANAPIDDIR} \
		GRAFANAHOMEDIR=${GRAFANAHOMEDIR} \
		GRAFANAPLUGINDIR=${GRAFANAPLUGINDIR} \
		GRAFANAPROVISIONINGDIR=${GRAFANAPROVISIONINGDIR}

PLIST_SUB+=	${SUB_LIST}

post-extract:
	@${RM} -r ${WRKSRC}/public
	@(cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/grafana-${PORTVERSION}.linux-amd64${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS} grafana-${PORTVERSION}/public)
	@(cd ${WRKDIR} && ${MKDIR} grafana-${PORTVERSION}/vendor/xorm.io && ${MV} builder grafana-${PORTVERSION}/vendor/xorm.io/ && ${MV} core grafana-${PORTVERSION}/vendor/xorm.io/ && ${MV} xorm grafana-${PORTVERSION}/vendor/xorm.io/)

post-install:
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} public ${STAGEDIR}${PREFIX}/share/grafana
	${MKDIR} ${STAGEDIR}${GRAFANAPIDDIR}
	${MKDIR} ${STAGEDIR}${GRAFANALOGDIR}
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}
	${MKDIR} ${STAGEDIR}${GRAFANADATADIR}
	${MKDIR} ${STAGEDIR}${GRAFANAPLUGINDIR}
	${MKDIR} ${STAGEDIR}${GRAFANAPROVISIONINGDIR}
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}/conf
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}/data
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}/data/log
	${INSTALL_DATA} ${WRKSRC}/conf/defaults.ini \
		${STAGEDIR}${GRAFANAHOMEDIR}/conf/defaults.ini
	${INSTALL_DATA} ${WRKDIR}/grafana.conf ${STAGEDIR}${PREFIX}/etc/grafana.conf.sample

.include <bsd.port.mk>
