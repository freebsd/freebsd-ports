# Created by: Matthias Fechner <mfechner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitlab-elasticsearch-indexer
PORTVERSION=	2.3.0
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

USES=		gmake go:modules,no_targets pkgconfig
MAKE_ENV=	GOFLAGS="${GO_BUILDFLAGS}"

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find the commit hash here: https://gitlab.com/gitlab-org/gitlab-elasticsearch-indexer/-/tags
GL_COMMIT=	a9333a2083099b620ec4a6f65b6395626a8d4b25

# for go dependencies
USE_GITHUB=	nodefault
# generated with: make gomod-vendor
# 25dd
GH_TUPLE=	\
		aws:aws-sdk-go:v1.19.6:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		deoxxa:aws_signing_client:c20ee106809e:deoxxa_aws_signing_client/vendor/github.com/deoxxa/aws_signing_client \
		go-yaml:yaml:v2.2.4:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:net:6afb5195e5aa:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:86b910548bc1:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:tools:6fdc5776f4bb:golang_tools/vendor/golang.org/x/tools \
		google:go-genproto:ca5a22157cba:google_go_genproto/vendor/google.golang.org/genproto \
		grpc-ecosystem:go-grpc-middleware:v1.0.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc:grpc-go:v1.24.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		mailru:easyjson:1ea4449da983:mailru_easyjson/vendor/github.com/mailru/easyjson \
		olivere:elastic:v6.2.24:olivere_elastic/vendor/github.com/olivere/elastic \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		sirupsen:logrus:v1.4.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify

GL_TUPLE=	gitlab-org:gitaly:aa1ff2a76ac14e1ad3eca35cc05ea86ef59fffbb:gitlab_org_gitaly/vendor/gitlab.com/gitlab-org/gitaly \
		gitlab-org:labkit:0149780c759d60f61fcfe1648fb882ba7ec41f3f:gitlab_org_labkit/vendor/gitlab.com/gitlab-org/labkit \
		lupine:icu:54c89d9b1ef6931b4ff61fa9f4ca645d3b86d6dc:lupine_icu/vendor/gitlab.com/lupine/icu

PLIST_FILES=	bin/gitlab-elasticsearch-indexer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gitlab-elasticsearch-indexer ${STAGEDIR}${PREFIX}/bin/gitlab-elasticsearch-indexer

.include <bsd.port.mk>
