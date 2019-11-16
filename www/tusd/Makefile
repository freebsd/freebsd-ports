# $FreeBSD$

PORTNAME=	tusd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Reference server implementation in Go of tus

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	tus
GH_TUPLE=	\
		Acconut:lockfile:v1.1.0:acconut_lockfile/vendor/gopkg.in/Acconut/lockfile.v1 \
		aws:aws-sdk-go:v1.20.1:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.0:beorn7_perks/vendor/github.com/beorn7/perks \
		bmizerany:pat:6226ea591a40:bmizerany_pat/vendor/github.com/bmizerany/pat \
		census-instrumentation:opencensus-go:v0.21.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		golang:appengine:v1.5.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:mock:v1.3.1:golang_mock/vendor/github.com/golang/mock \
		golang:net:f4e77d36d62c:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369cfe45:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:ecd444e8653b:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-genproto:fb225487d101:google_go_genproto/vendor/google.golang.org/genproto \
		googleapis:gax-go:v2.0.4:googleapis_gax_go/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.6.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.40.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc:grpc-go:v1.20.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		h2non:gock:v1.0.14:h2non_gock/vendor/gopkg.in/h2non/gock.v1 \
		h2non:parth:b4df798d6542:h2non_parth/vendor/github.com/h2non/parth \
		hashicorp:golang-lru:v0.5.1:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.0.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:fd36f4220a90:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.4.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.2:prometheus_procfs/vendor/github.com/prometheus/procfs \
		sethgrid:pester:68a33a018ad0:sethgrid_pester/vendor/github.com/sethgrid/pester \
		stretchr:testify:v1.3.0:stretchr_testify/vendor/github.com/stretchr/testify \
		vimeo:go-util:v1.2.0:vimeo_go_util/vendor/github.com/vimeo/go-util

GO_TARGET=	./cmd/tusd

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

USERS=		www
GROUPS=		www

TUSD_UPLOAD_DIR?=	/var/spool/tusd

USE_RC_SUBR=	tusd
SUB_FILES=	tusd
SUB_LIST=	TUSD_USER=${USERS} \
		TUSD_GROUP=${GROUPS} \
		TUSD_UPLOAD_DIR=${TUSD_UPLOAD_DIR}

PLIST_SUB+=	${SUB_LIST}

post-install:
	${MKDIR} ${STAGEDIR}${TUSD_UPLOAD_DIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/hooks.md ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/apache2.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/nginx.conf ${STAGEDIR}${EXAMPLESDIR}
.for FILE in post-create post-finish post-receive post-terminate pre-create
	${INSTALL_SCRIPT} ${WRKSRC}/examples/hooks/${FILE} ${STAGEDIR}${EXAMPLESDIR}/hooks
.endfor

.include <bsd.port.mk>
