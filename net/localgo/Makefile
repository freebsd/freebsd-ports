PORTNAME=	localgo
PORTVERSION=	0.3.8
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Go implementation of LocalSend v2.1 prototol
WWW=		https://github.com/bethropolis/localgo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	bethropolis
GH_TUPLE=	\
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:sys:v0.29.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.28.0:golang_term/vendor/golang.org/x/term \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:mux:v1.8.1:gorilla_mux/vendor/github.com/gorilla/mux \
		mitchellh:colorstring:d06e56a500db:mitchellh_colorstring/vendor/github.com/mitchellh/colorstring \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg \
		schollz:progressbar:v3.19.0:schollz_progressbar/vendor/github.com/schollz/progressbar/v3 \
		stretchr:testify:v1.10.0:stretchr_testify/vendor/github.com/stretchr/testify \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.27.1:uber_go_zap/vendor/go.uber.org/zap

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "-X main.Version=${PORVERSION} \
		-X main.GitCommit=4915afb -X main.BuildDate=${_GET_DATE:sh}"
PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${LN} -sf ${FILESDIR}/modules.txt ${WRKSRC}/vendor

.include <bsd.port.mk>

_GET_DATE=	TZ= ${STAT} -f %Sm -t %FT%TZ ${WRKSRC}/.gitignore
