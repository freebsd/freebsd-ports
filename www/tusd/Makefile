PORTNAME=	tusd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.0
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
		Azure:azure-pipeline-go:v0.2.3:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-storage-blob-go:v0.14.0:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		aws:aws-sdk-go:v1.43.31:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bmizerany:pat:6226ea591a40:bmizerany_pat/vendor/github.com/bmizerany/pat \
		census-instrumentation:opencensus-go:v0.23.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mock:v1.6.0:golang_mock/vendor/github.com/golang/mock \
		golang:net:de3da57026de:golang_net/vendor/golang.org/x/net \
		golang:oauth2:6242fa91716a:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:d36c6a25d886:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.7:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:acbaeb5b85eb:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.2.0:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.74.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:compute/v1.5.0:googleapis_google_cloud_go_compute \
		googleapis:google-cloud-go:iam/v0.1.1:googleapis_google_cloud_go_iam \
		googleapis:google-cloud-go:storage/v1.21.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.100.2:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc-ecosystem:go-grpc-middleware:v1.3.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc:grpc-go:v1.45.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		h2non:gock:v1.1.2:h2non_gock/vendor/gopkg.in/h2non/gock.v1 \
		h2non:parth:b4df798d6542:h2non_parth/vendor/github.com/h2non/parth \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		mattn:go-ieproxy:v0.0.1:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.12.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.32.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.7.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		sethgrid:pester:68a33a018ad0:sethgrid_pester/vendor/github.com/sethgrid/pester \
		stretchr:testify:v1.7.1:stretchr_testify/vendor/github.com/stretchr/testify \
		vimeo:go-util:v1.4.1:vimeo_go_util/vendor/github.com/vimeo/go-util

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

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/compute
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_compute}/compute ${WRKSRC}/vendor/cloud.google.com/go/compute
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/iam
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_iam}/iam ${WRKSRC}/vendor/cloud.google.com/go/iam
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage

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
