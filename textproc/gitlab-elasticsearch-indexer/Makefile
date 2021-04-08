# Created by: Matthias Fechner <mfechner@FreeBSD.org>

PORTNAME=	gitlab-elasticsearch-indexer
PORTVERSION=	2.16.0
PORTREVISION=	1
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
GL_COMMIT=	16bf7ce3b308ef505f6624cae32a9ae6b6db93ea

# for go dependencies
USE_GITHUB=	nodefault
# generated with: make gomod-vendor
# 32dd
GH_TUPLE=	\
		aws:aws-sdk-go:v1.27.0:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		deoxxa:aws_signing_client:c20ee106809e:deoxxa_aws_signing_client/vendor/github.com/deoxxa/aws_signing_client \
		fortytw2:leaktest:v1.3.0:fortytw2_leaktest/vendor/github.com/fortytw2/leaktest \
		go-enry:go-enry:v2.7.1:go_enry_go_enry_v2/vendor/github.com/go-enry/go-enry/v2 \
		go-enry:go-oniguruma:v1.2.1:go_enry_go_oniguruma/vendor/github.com/go-enry/go-oniguruma \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:mod:v0.4.1:golang_mod/vendor/golang.org/x/mod \
		golang:net:5f4716e94777:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:22da62e12c0c:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.5:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.1.0:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-genproto:e7f2df4ecc2d:google_go_genproto/vendor/google.golang.org/genproto \
		grpc-ecosystem:go-grpc-middleware:f849b5445de4:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc:grpc-go:v1.35.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		magefile:mage:v1.10.0:magefile_mage/vendor/github.com/magefile/mage \
		mailru:easyjson:1ea4449da983:mailru_easyjson/vendor/github.com/mailru/easyjson \
		oklog:ulid:v2.0.2:oklog_ulid_v2/vendor/github.com/oklog/ulid/v2 \
		olivere:elastic:v6.2.24:olivere_elastic/vendor/github.com/olivere/elastic \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		sirupsen:logrus:v1.7.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify

GL_TUPLE=	gitlab-org:gitaly:aa1ff2a76ac14e1ad3eca35cc05ea86ef59fffbb:gitlab_org_gitaly/vendor/gitlab.com/gitlab-org/gitaly \
		gitlab-org:labkit:d04f253f79d934e8e3d6872f56fd392df9a934da:gitlab_org_labkit/vendor/gitlab.com/gitlab-org/labkit \
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
