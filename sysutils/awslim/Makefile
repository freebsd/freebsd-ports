PORTNAME=	awslim
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	nork@FreeBSD.org
COMMENT=	AWSCLi slim version for ${COMMENT_${FLAVOR}}
WWW=		https://github.com/fujiwara/awslim

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=	default compact

compact_PKGNAMESUFFIX=	-compact

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	fujiwara
GH_TUPLE=	alecthomas:kong:v1.10.0:alecthomas_kong/vendor/github.com/alecthomas/kong \
		aws:aws-sdk-go-v2:v1.36.3:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go-v2 \
		aws:smithy-go:v1.22.2:aws_smithy_go/vendor/github.com/aws/smithy-go \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		goccy:go-yaml:v1.17.1:go_yaml/vendor/github.com/goccy/go-yaml \
		google:go-jsonnet:v0.20.0:google_go_jsonnet/vendor/github.com/google/go-jsonnet \
		kubernetes-sigs:yaml:v1.1.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		mattn:go-shellwords:v1.0.12:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords

GO_ENV+=	GO_CMD="${GO_CMD}"
GO_TARGET=	./cmd/awslim/main.go:awslim
GO_BUILDFLAGS=	-tags netgo -ldflags "-s -w -extldflags "-static" -X github.com/fujiwara/awslim.Version=${DISTVERSION}"

PLIST_FILES=	bin/awslim

COMMENT_default=	all services
COMMENT_compact=	selected services

.if ${FLAVOR:U} == compact
post-extract:
	${LN} -sf ${FILESDIR}/compact-gen.yaml ${WRKSRC}/gen.yaml
.else
post-extract:
	${LN} -sf all-services.yaml ${WRKSRC}/gen.yaml
.endif

pre-build:
	cd ${GO_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOMAXPROCS=${MAKE_JOBS_NUMBER} GOPROXY=off ${GO_CMD} generate ${GO_BUILDFLAGS} ./cmd/awslim-gen .

.include <bsd.port.pre.mk>

.if ${ARCH} != i386
FLAVOR?=	${FLAVORS:[1]}
.else
FLAVOR?=	${FLAVORS:[2]}
.endif

.include <bsd.port.post.mk>
