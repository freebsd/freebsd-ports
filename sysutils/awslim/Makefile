PORTNAME=	awslim
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.12
PORTREVISION=	0
CATEGORIES=	sysutils

MAINTAINER=	nork@FreeBSD.org
COMMENT=	AWSCLi slim version for ${COMMENT_${FLAVOR}}
WWW=		https://github.com/fujiwara/awslim

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386

FLAVORS=	default compact

compact_PKGNAMESUFFIX=	-compact

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	fujiwara
GH_TUPLE=	alecthomas:kong:v1.10.0:alecthomas_kong/vendor/github.com/alecthomas/kong \
		aws:aws-sdk-go-v2:v${AWS_SDK_VER}:aws_aws_sdk_go_v2 \
		aws:smithy-go:v1.24.2:aws_smithy_go/vendor/github.com/aws/smithy-go \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		goccy:go-yaml:v1.19.2:goccy_go_yaml/vendor/github.com/goccy/go-yaml \
		google:go-cmp:v0.7.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-jsonnet:v0.20.0:google_go_jsonnet/vendor/github.com/google/go-jsonnet \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		kubernetes-sigs:yaml:v1.1.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		mattn:go-shellwords:v1.0.12:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords

GO_ENV+=	GO_CMD="${GO_CMD}"
GO_TARGET=	./cmd/awslim/main.go:awslim
GO_BUILDFLAGS=	-tags netgo -ldflags "-s -w -extldflags "-static" -X github.com/fujiwara/awslim.Version=${DISTVERSION}"

PLIST_FILES=	bin/awslim

COMMENT_default=	all services
COMMENT_compact=	selected services

AWS_SDK_VER=	1.41.4

post-extract:
	${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor/
	${CP} ${FILESDIR}/go.*        ${WRKSRC}/
	${LN} -s ../../../../aws-sdk-go-v2-${AWS_SDK_VER} ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2
.if ${FLAVOR:U} == compact
	${LN} -sf ${FILESDIR}/compact-gen.yaml ${WRKSRC}/gen.yaml
.else
	${LN} -sf all-services.yaml ${WRKSRC}/gen.yaml
.endif

pre-build:
	cd ${GO_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOMAXPROCS=${MAKE_JOBS_NUMBER} GOPROXY=off ${GO_CMD} generate ${GO_BUILDFLAGS} ./cmd/awslim-gen .

maintainer-check-update:	do-extract
	cd ${WRKSRC} && ${LN} -sf all-services.yaml gen.yaml
	${REINPLACE_CMD} -e "/go:generate/s|go |${GO_CMD} |" ${WRKSRC}/cmd/awslim-gen/main.go
	cd ${WRKSRC} && ${GO_CMD} generate ./cmd/awslim-gen .
	cd ${WRKSRC} && ${GO_CMD} mod tidy
	cd ${WRKSRC} && ${GO_CMD} mod vendor
	cd ${WRKSRC} && ${SETENV} M2T_OFFLINE=t ${_MODULES2TUPLE_CMD} vendor/modules.txt | grep -Fve aws_aws_sdk_go_v2_
	${CP} ${WRKSRC}/vendor/modules.txt ${WRKSRC}/go.* files/

.include <bsd.port.mk>
