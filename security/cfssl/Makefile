PORTNAME=	cfssl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0
CATEGORIES=	security
MASTER_SITES=	https://bitbucket.org/${GOOSE_ACCOUNT}/${GOOSE_PROJECT}/get/${GOOSE_COMMIT}.tar.gz?dummy=goose-${GOOSE_COMMIT}.tar.gz/:goose
DISTFILES=	goose-${GOOSE_COMMIT}.tar.gz:goose

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cloudflare's PKI and TLS toolkit

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		go:modules gmake
USE_GITHUB=	yes
GH_ACCOUNT=	cloudflare
GH_TUPLE=	\
		GeertJohan:go.incremental:v1.0.0:geertjohan_go_incremental/vendor/github.com/GeertJohan/go.incremental \
		GeertJohan:go.rice:v1.0.0:geertjohan_go_rice/vendor/github.com/GeertJohan/go.rice \
		akavel:rsrc:v0.8.0:akavel_rsrc/vendor/github.com/akavel/rsrc \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		certifi:gocertifi:deb3ae2ef261:certifi_gocertifi/vendor/github.com/certifi/gocertifi \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cloudflare:backoff:647f3cdfc87a:cloudflare_backoff/vendor/github.com/cloudflare/backoff \
		cloudflare:redoctober:746a508df14c:cloudflare_redoctober/vendor/github.com/cloudflare/redoctober \
		daaku:go.zipexe:v1.0.0:daaku_go_zipexe/vendor/github.com/daaku/go.zipexe \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		getsentry:raven-go:563b81fc02b7:getsentry_raven_go/vendor/github.com/getsentry/raven-go \
		go-sql-driver:mysql:v1.4.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.6:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:c8d3bf9c5392:golang_crypto/vendor/golang.org/x/crypto \
		golang:lint:16217165b5de:golang_lint/vendor/golang.org/x/lint \
		golang:net:69a78807bb2b:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:f9fddec55a1e:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.4:golang_text/vendor/golang.org/x/text \
		golang:tools:774c71fcf114:golang_tools/vendor/golang.org/x/tools \
		google:certificate-transparency-go:v1.0.21:google_certificate_transparency_go/vendor/github.com/google/certificate-transparency-go \
		jessevdk:go-flags:v1.4.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		jmhodges:clock:880ee4c33548:jmhodges_clock/vendor/github.com/jmhodges/clock \
		jmoiron:sqlx:v1.2.0:jmoiron_sqlx/vendor/github.com/jmoiron/sqlx \
		kisielk:sqlstruct:648daed35d49:kisielk_sqlstruct/vendor/github.com/kisielk/sqlstruct \
		kisom:goutils:v1.1.0:kisom_goutils/vendor/github.com/kisom/goutils \
		kylelemons:go-gypsy:08cad365cd28:kylelemons_go_gypsy/vendor/github.com/kylelemons/go-gypsy \
		lib:pq:v1.3.0:lib_pq/vendor/github.com/lib/pq \
		mattn:go-sqlite3:v1.10.0:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		nkovacs:streamquote:49af9bddb229:nkovacs_streamquote/vendor/github.com/nkovacs/streamquote \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.9.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.15.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.2.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		valyala:bytebufferpool:v1.0.0:valyala_bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		valyala:fasttemplate:v1.0.1:valyala_fasttemplate/vendor/github.com/valyala/fasttemplate \
		weppos:publicsuffix-go:v0.13.0:weppos_publicsuffix_go/vendor/github.com/weppos/publicsuffix-go \
		ziutek:mymysql:v1.5.4:ziutek_mymysql/vendor/github.com/ziutek/mymysql \
		zmap:zcrypto:3719af1573cf:zmap_zcrypto/vendor/github.com/zmap/zcrypto \
		zmap:zlint:v3.0.0:zmap_zlint_v3/vendor/github.com/zmap/zlint

GOOSE_ACCOUNT=	liamstask
GOOSE_PROJECT=	goose
GOOSE_COMMIT=	8488cc47d90c

EXES=		cfssl cfssl-bundle cfssl-certinfo cfssl-newkey cfssl-scan cfssljson mkbundle multirootca

PLIST_FILES=	${EXES:S/^/bin\//}

pre-configure:
	${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|g' ${WRKSRC}/cli/version/version.go

# the project uses Makefile for build and installation
do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} all

do-install:
	# Makefile is used but the install target uses go install.
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} GOBIN=${STAGEDIR}${PREFIX}/bin ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} install
.for F in cfssl cfssl-certinfo multirootca
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${F}
.endfor

.include <bsd.port.mk>
