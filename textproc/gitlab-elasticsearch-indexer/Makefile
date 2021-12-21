# Created by: Matthias Fechner <mfechner@FreeBSD.org>

PORTNAME=	gitlab-elasticsearch-indexer
PORTVERSION=	2.17.0
PORTREVISION=	0
CATEGORIES=	textproc

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Elasticsearch indexer for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	git>=2.16.2:devel/git
LIB_DEPENDS=	libicui18n.so:devel/icu \
		libicuuc.so:devel/icu
#RUN_DEPENDS=	p5-Image-ExifTool>=0:graphics/p5-Image-ExifTool

USES=		gmake go:modules pkgconfig

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find the commit hash here: https://gitlab.com/gitlab-org/gitlab-elasticsearch-indexer/-/tags
GL_COMMIT=	ef1440548effec15831eda2d246dacc43233cefb

# for go dependencies
USE_GITHUB=	nodefault
# generated with: make gomod-vendor
# 39dd
GH_TUPLE=	\
		aws:aws-sdk-go:v1.38.35:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		deoxxa:aws_signing_client:c20ee106809e:deoxxa_aws_signing_client/vendor/github.com/deoxxa/aws_signing_client \
		go-enry:go-enry:v2.7.1:go_enry_go_enry_v2/vendor/github.com/go-enry/go-enry/v2 \
		go-enry:go-oniguruma:v1.2.1:go_enry_go_oniguruma/vendor/github.com/go-enry/go-oniguruma \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:mod:v0.4.2:golang_mod/vendor/golang.org/x/mod \
		golang:net:0714010a04ed:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:97ca703d548d:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.1.0:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-genproto:4a47615972c2:google_go_genproto/vendor/google.golang.org/genproto \
		grpc-ecosystem:go-grpc-middleware:v1.3.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc:grpc-go:v1.38.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:yamux:a95892c5f864:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		mailru:easyjson:1ea4449da983:mailru_easyjson/vendor/github.com/mailru/easyjson \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		oklog:ulid:v2.0.2:oklog_ulid_v2/vendor/github.com/oklog/ulid/v2 \
		olivere:elastic:v6.2.24:olivere_elastic/vendor/github.com/olivere/elastic \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.10.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.18.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify

GL_TUPLE=	gitlab-org:gitaly:00071e4ab87eaae7c4f68705613191046cd023be:gitlab_org_gitaly_v14/vendor/gitlab.com/gitlab-org/gitaly/v14 \
		gitlab-org:labkit:397363e2404ac0276b1959373a1c1c2bc1610d67:gitlab_org_labkit/vendor/gitlab.com/gitlab-org/labkit \
		lupine:icu:54c89d9b1ef6931b4ff61fa9f4ca645d3b86d6dc:lupine_icu/vendor/gitlab.com/lupine/icu

_BUILD_DATE=	$$(date -u "+%Y-%m-%d-%H%M UTC")

GO_BUILDFLAGS=	-ldflags "\
		-X 'main.Version=v${PORTVERSION}' \
		-X 'main.BuildTime=${_BUILD_DATE}'"
GO_TARGET=	gitlab.com/gitlab-org/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
