# $FreeBSD$

PORTNAME=	step-certificates
DISTVERSIONPREFIX=v
DISTVERSION=	0.14.4
CATEGORIES=	security

MAINTAINER=	mw@wipp.bayern
COMMENT=	Smallstep step-ca certificates server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	step:security/step-cli

USES=		go:modules

USERS=		step
GROUPS=		step

USE_RC_SUBR=	step-ca

USE_GITHUB=	yes
GH_ACCOUNT=	smallstep
GH_PROJECT=	certificates

GO_TARGET=	./cmd/step-ca:${PREFIX}/sbin/step-ca  \
		./cmd/step-cloudkms-init

GO_BUILDFLAGS=	-ldflags "-w -X main.Version=${PORTVERSION}"

GH_TUPLE=	\
		AndreasBriese:bbloom:e2d15f34fcf9:andreasbriese_bbloom/vendor/github.com/AndreasBriese/bbloom \
		DataDog:zstd:v1.4.1:datadog_zstd/vendor/github.com/DataDog/zstd \
		Masterminds:goutils:v1.1.0:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v3.0.1:masterminds_semver/vendor/github.com/Masterminds/semver/v3 \
		Masterminds:sprig:v3.0.0:masterminds_sprig/vendor/github.com/Masterminds/sprig/v3 \
		census-instrumentation:opencensus-go:v0.22.2:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man/vendor/github.com/cpuguy83/go-md2man/v2 \
		dgraph-io:badger:09dd2e1a4195:dgraph_io_badger/vendor/github.com/dgraph-io/badger/v2 \
		dgraph-io:badger:v1.5.3:dgraph_io_badger_1/vendor/github.com/dgraph-io/badger \
		dgraph-io:ristretto:8f368f2f2ab3:dgraph_io_ristretto/vendor/github.com/dgraph-io/ristretto \
		dgryski:go-farm:6a90982ecee2:dgryski_go_farm/vendor/github.com/dgryski/go-farm \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		etcd-io:bbolt:v1.3.2:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		go-chi:chi:v4.0.2:go_chi_chi/vendor/github.com/go-chi/chi \
		go-sql-driver:mysql:v1.4.1:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:0ec3e9974c59:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:215e87163ea7:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:c0dbc17a3553:golang_net/vendor/golang.org/x/net \
		golang:oauth2:858c2ad4c8b6:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:b016eb3dc98e:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.3.1:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:f3c370f40bfb:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.15.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.51.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc:grpc-go:v1.26.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		huandu:xstrings:v1.2.0:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v0.3.7:imdario_mergo/vendor/github.com/imdario/mergo \
		juju:ansiterm:720a0952cc2a:juju_ansiterm/vendor/github.com/juju/ansiterm \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		lunixbochs:vtclean:v1.0.0:lunixbochs_vtclean/vendor/github.com/lunixbochs/vtclean \
		manifoldco:promptui:v0.3.1:manifoldco_promptui/vendor/github.com/manifoldco/promptui \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.11:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:reflectwalk:v1.0.0:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		newrelic:go-agent:v2.15.0:newrelic_go_agent/vendor/github.com/newrelic/go-agent \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		rs:xid:v1.2.1:rs_xid/vendor/github.com/rs/xid \
		russross:blackfriday:v2.0.1:russross_blackfriday/vendor/github.com/russross/blackfriday/v2 \
		samfoo:ansi:b6bd2ded7189:samfoo_ansi/vendor/github.com/samfoo/ansi \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		smallstep:assert:b99dc1097b15:smallstep_assert/vendor/github.com/smallstep/assert \
		smallstep:cli:v0.14.3:smallstep_cli/vendor/github.com/smallstep/cli \
		smallstep:nosql:v0.3.0:smallstep_nosql/vendor/github.com/smallstep/nosql \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		square:go-jose:v2.4.0:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		urfave:cli:v1.22.2:urfave_cli/vendor/github.com/urfave/cli
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/step
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
