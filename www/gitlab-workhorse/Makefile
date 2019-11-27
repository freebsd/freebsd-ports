# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitlab-workhorse
PORTVERSION=	8.14.1
CATEGORIES=	www

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Smart reverse proxy for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	git>=2.16.2:devel/git
RUN_DEPENDS=	p5-Image-ExifTool>=0:graphics/p5-Image-ExifTool

USES=		gmake go:modules,no_targets
MAKE_ENV=	GOFLAGS="${GO_BUILDFLAGS}"

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find the commit hash here: https://gitlab.com/gitlab-org/gitlab-workhorse/tags
GL_COMMIT=	01bfb916e54cb25154db69f3b4d5481b7b77f16f

# for go dependencies
USE_GITHUB=	nodefault
# generated with: make gomod-vendor
# 51dd
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		DataDog:dd-trace-go:v1.7.0:datadog_dd_trace_go/vendor/gopkg.in/DataDog/dd-trace-go.v1 \
		FZambia:sentinel:v1.0.0:fzambia_sentinel/vendor/github.com/FZambia/sentinel \
		beorn7:perks:v1.0.0:beorn7_perks/vendor/github.com/beorn7/perks \
		certifi:gocertifi:ee1a9a0726d2:certifi_gocertifi/vendor/github.com/certifi/gocertifi \
		client9:reopen:v1.0.0:client9_reopen/vendor/github.com/client9/reopen \
		codahale:hdrhistogram:3a0bb77429bd:codahale_hdrhistogram/vendor/github.com/codahale/hdrhistogram \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		getsentry:raven-go:v0.1.2:getsentry_raven_go/vendor/github.com/getsentry/raven-go \
		golang:crypto:20be4c3c3ed5:golang_crypto/vendor/golang.org/x/crypto \
		golang:gddo:af0f2af80721:golang_gddo/vendor/github.com/golang/gddo \
		golang:lint:06c8688daad7:golang_lint/vendor/golang.org/x/lint \
		golang:net:d28f0bde5980:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:953cdadca894:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		golang:tools:6e04913cbbac:golang_tools/vendor/golang.org/x/tools \
		gomodule:redigo:v2.0.0:gomodule_redigo/vendor/github.com/gomodule/redigo \
		google:go-genproto:bd91e49a0898:google_go_genproto/vendor/google.golang.org/genproto \
		gorilla:websocket:v1.4.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc-ecosystem:go-grpc-middleware:v1.0.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:v1.2.0:grpc_ecosystem_go_grpc_prometheus/vendor/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc:grpc-go:v1.16.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		jfbus:httprs:b0af8319bb15:jfbus_httprs/vendor/github.com/jfbus/httprs \
		jpillora:backoff:8eab2debe79d:jpillora_backoff/vendor/github.com/jpillora/backoff \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		lightstep:lightstep-tracer-go:v0.15.6:lightstep_lightstep_tracer_go/vendor/github.com/lightstep/lightstep-tracer-go \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:reflectwalk:v1.0.0:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		opentracing:opentracing-go:v1.0.2:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		philhofer:fwd:v1.0.0:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pkg:errors:v0.8.0:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.0.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:fd36f4220a90:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.4.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.2:prometheus_procfs/vendor/github.com/prometheus/procfs \
		rafaeljusto:redigomock:257e089e14a1:rafaeljusto_redigomock/vendor/github.com/rafaeljusto/redigomock \
		sebest:xff:6c115e0ffa35:sebest_xff/vendor/github.com/sebest/xff \
		sirupsen:logrus:v1.3.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		stretchr:testify:v1.3.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tinylib:msgp:v1.1.0:tinylib_msgp/vendor/github.com/tinylib/msgp \
		uber:jaeger-client-go:v2.15.0:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		uber:jaeger-lib:v1.5.0:uber_jaeger_lib/vendor/github.com/uber/jaeger-lib

GL_TUPLE=	\
		gitlab-org:gitaly:a8e2980b1ffe1a728ab13032dc81f90f4b990a03:gitlab_org_gitaly/vendor/gitlab.com/gitlab-org/gitaly \
		gitlab-org:labkit:905271af7abbfaa1d3549f46ac0394c50cef9b28:gitlab_org_labkit/vendor/gitlab.com/gitlab-org/labkit

PLIST_FILES=	bin/gitlab-workhorse \
		bin/gitlab-zip-cat \
		bin/gitlab-zip-metadata
PLIST_DIRS=	${WWWDIR}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}

.include <bsd.port.mk>
