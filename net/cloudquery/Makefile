# $FreeBSD$

PORTNAME=	cloudquery
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.8
CATEGORIES=	net

MAINTAINER=	neel@neelc.org
COMMENT=	Transform cloud infrastructure into queryable SQL tables

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

GH_TUPLE=	\
		Azure:azure-sdk-for-go:v49.0.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-autorest:446f41b7d65b:azure_go_autorest_validation \
		Azure:go-autorest:55c0c4ebc34d:azure_go_autorest_cli \
		Azure:go-autorest:6afd852870d1:azure_go_autorest_auth \
		Azure:go-autorest:8a1ccef0030c:azure_go_autorest_adal \
		Azure:go-autorest:autorest/v0.11.13:azure_go_autorest_autorest \
		Azure:go-autorest:b3a0b30a7423:azure_go_autorest_date \
		Azure:go-autorest:logger/v0.2.0:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.6.0:azure_go_autorest_tracing \
		Azure:go-autorest:v14.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		aws:aws-sdk-go:v1.35.0:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		cenkalti:backoff:v4.1.0:cenkalti_backoff_v4/vendor/github.com/cenkalti/backoff/v4 \
		census-instrumentation:opencensus-go:v0.22.4:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		denisenkom:go-mssqldb:06a60b6afbbc:denisenkom_go_mssqldb/vendor/github.com/denisenkom/go-mssqldb \
		dimchansky:utfbom:v1.1.0:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		form3tech-oss:jwt-go:v3.2.2:form3tech_oss_jwt_go/vendor/github.com/form3tech-oss/jwt-go \
		go-gorm:gorm:v1.20.9:go_gorm_gorm/vendor/gorm.io/gorm \
		go-gorm:mysql:v1.0.2:go_gorm_mysql/vendor/gorm.io/driver/mysql \
		go-gorm:postgres:v1.0.2:go_gorm_postgres/vendor/gorm.io/driver/postgres \
		go-gorm:sqlite:v1.1.3:go_gorm_sqlite/vendor/gorm.io/driver/sqlite \
		go-gorm:sqlserver:v1.0.4:go_gorm_sqlserver/vendor/gorm.io/driver/sqlserver \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-logr:logr:v0.2.0:go_logr_logr/vendor/github.com/go-logr/logr \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-yaml:yaml:eeeca48fe776:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gocarina:gocsv:67c824bc04d4:gocarina_gocsv/vendor/github.com/gocarina/gocsv \
		gogo:protobuf:v1.3.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang-sql:civil:cb61b32ac6fe:golang_sql_civil/vendor/github.com/golang-sql/civil \
		golang:appengine:v1.6.6:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:9e8e0b390897:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:c89045814202:golang_net/vendor/golang.org/x/net \
		golang:oauth2:5d25da1a8d43:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:be1d3432aa8f:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		golang:tools:1610a49f37af:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-genproto:0bd0a958aa1d:google_go_genproto/vendor/google.golang.org/genproto \
		google:gofuzz:v1.1.0:google_gofuzz/vendor/github.com/google/gofuzz \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:gnostic:v0.4.1:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.35.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.65.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc:grpc-go:v1.31.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		imdario:mergo:v0.3.5:imdario_mergo/vendor/github.com/imdario/mergo \
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
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		json-iterator:go:v1.1.10:json_iterator_go/vendor/github.com/json-iterator/go \
		kelseyhightower:envconfig:v1.4.0:kelseyhightower_envconfig/vendor/github.com/kelseyhightower/envconfig \
		kubernetes-sigs:structured-merge-diff:v4.0.1:kubernetes_sigs_structured_merge_diff/vendor/sigs.k8s.io/structured-merge-diff/v4 \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.19.0:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:v0.19.0:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v0.19.0:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v2.2.0:kubernetes_klog/vendor/k8s.io/klog/v2 \
		kubernetes:utils:d5654de09c73:kubernetes_utils/vendor/k8s.io/utils \
		mattn:go-runewidth:v0.0.7:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-sqlite3:v1.14.3:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.3.3:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		okta:okta-sdk-golang:v2.2.1:okta_okta_sdk_golang_v2/vendor/github.com/okta/okta-sdk-golang/v2 \
		olekukonko:tablewriter:v0.0.4:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		patrickmn:go-cache:5633e0862627:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		shopspring:decimal:v1.2.0:shopspring_decimal/vendor/github.com/shopspring/decimal \
		spf13:cobra:v1.1.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		square:go-jose:v2.5.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		uber-go:atomic:v1.6.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.5.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.10.0:uber_go_zap/vendor/go.uber.org/zap

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RLN} ${WRKSRC_azure_go_autorest_autorest}/autorest ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RLN} ${WRKSRC_azure_go_autorest_adal}/autorest/adal ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/auth
	@${RLN} ${WRKSRC_azure_go_autorest_auth}/autorest/azure/auth ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/auth
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/cli
	@${RLN} ${WRKSRC_azure_go_autorest_cli}/autorest/azure/cli ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/cli
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RLN} ${WRKSRC_azure_go_autorest_date}/autorest/date ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/validation
	@${RLN} ${WRKSRC_azure_go_autorest_validation}/autorest/validation ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/validation
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing

.include <bsd.port.mk>
