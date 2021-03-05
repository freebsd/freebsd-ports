# $FreeBSD$

PORTNAME=	step-certificates
DISTVERSIONPREFIX=v
DISTVERSION=	0.15.8
CATEGORIES=	security

MAINTAINER=	mw@wipp.bayern
COMMENT=	Smallstep step-ca certificates server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pcsc-lite>0:devel/pcsc-lite
LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite
RUN_DEPENDS=	step:security/step-cli

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	smallstep
GH_PROJECT=	certificates

GH_TUPLE=	\
		AndreasBriese:bbloom:46b345b51c96:andreasbriese_bbloom/vendor/github.com/AndreasBriese/bbloom \
		DataDog:zstd:v1.4.5:datadog_zstd/vendor/github.com/DataDog/zstd \
		Masterminds:goutils:v1.1.0:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v3.1.0:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Masterminds:sprig:v3.1.0:masterminds_sprig_v3/vendor/github.com/Masterminds/sprig/v3 \
		ThalesIgnite:crypto11:v1.2.4:thalesignite_crypto11/vendor/github.com/ThalesIgnite/crypto11 \
		aws:aws-sdk-go:v1.30.29:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		census-instrumentation:opencensus-go:v0.22.5:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		dgraph-io:badger:5d1bab4fc658:dgraph_io_badger_v2/vendor/github.com/dgraph-io/badger/v2 \
		dgraph-io:badger:v1.6.2:dgraph_io_badger/vendor/github.com/dgraph-io/badger \
		dgraph-io:ristretto:41ebdbffecfd:dgraph_io_ristretto/vendor/github.com/dgraph-io/ristretto \
		dgryski:go-farm:a6ae2369ad13:dgryski_go_farm/vendor/github.com/dgryski/go-farm \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		etcd-io:bbolt:v1.3.5:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		go-chi:chi:v4.0.2:go_chi_chi/vendor/github.com/go-chi/chi \
		go-piv:piv-go:v1.7.0:go_piv_piv_go/vendor/github.com/go-piv/piv-go \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		golang:appengine:v1.6.6:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:9e8e0b390897:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mock:v1.4.4:golang_mock/vendor/github.com/golang/mock \
		golang:net:5f4716e94777:golang_net/vendor/golang.org/x/net \
		golang:oauth2:5d25da1a8d43:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.2:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:22da62e12c0c:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.5.2:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:1ed22bb0c154:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.33.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.70.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc:grpc-go:v1.32.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		huandu:xstrings:v1.3.1:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v0.3.8:imdario_mergo/vendor/github.com/imdario/mergo \
		jmespath:go-jmespath:v0.3.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		juju:ansiterm:720a0952cc2a:juju_ansiterm/vendor/github.com/juju/ansiterm \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		lunixbochs:vtclean:v1.0.0:lunixbochs_vtclean/vendor/github.com/lunixbochs/vtclean \
		manifoldco:promptui:v0.8.0:manifoldco_promptui/vendor/github.com/manifoldco/promptui \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.11:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		miekg:pkcs11:a667d056470f:miekg_pkcs11/vendor/github.com/miekg/pkcs11 \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:reflectwalk:v1.0.0:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		newrelic:go-agent:v2.15.0:newrelic_go_agent/vendor/github.com/newrelic/go-agent \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rs:xid:v1.2.1:rs_xid/vendor/github.com/rs/xid \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		samfoo:ansi:b6bd2ded7189:samfoo_ansi/vendor/github.com/samfoo/ansi \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		smallstep:assert:82e2b9b3b262:smallstep_assert/vendor/github.com/smallstep/assert \
		smallstep:cli-utils:v0.1.0:smallstep_cli_utils/vendor/go.step.sm/cli-utils \
		smallstep:crypto:v0.7.3:smallstep_crypto/vendor/go.step.sm/crypto \
		smallstep:nosql:v0.3.6:smallstep_nosql/vendor/github.com/smallstep/nosql \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		square:go-jose:v2.5.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		thales-e-security:pool:v0.0.2:thales_e_security_pool/vendor/github.com/thales-e-security/pool \
		urfave:cli:v1.22.4:urfave_cli/vendor/github.com/urfave/cli

USE_RC_SUBR=	step-ca

GO_TARGET=	./cmd/step-ca:${PREFIX}/sbin/step-ca  \
		./cmd/step-cloudkms-init

GO_BUILDFLAGS=	-ldflags "-w -X main.Version=${PORTVERSION}"

USERS=		step
GROUPS=		step

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/step
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
