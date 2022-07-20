PORTNAME=	reproxy
PORTVERSION=	0.11.0
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple edge HTTP(S) server and reverse proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	umputun
GH_TUPLE=	\
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.2:cespare_xxhash/vendor/github.com/cespare/xxhash/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		didip:tollbooth:v6.1.1:didip_tollbooth/vendor/github.com/didip/tollbooth/v6 \
		felixge:httpsnoop:v1.0.2:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		go-pkgz:expirable-cache:v0.0.3:go_pkgz_expirable_cache/vendor/github.com/go-pkgz/expirable-cache \
		go-pkgz:lgr:v0.10.4:go_pkgz_lgr/vendor/github.com/go-pkgz/lgr \
		go-pkgz:repeater:v1.1.3:go_pkgz_repeater/vendor/github.com/go-pkgz/repeater \
		go-pkgz:rest:v1.11.0:go_pkgz_rest/vendor/github.com/go-pkgz/rest \
		go-yaml:yaml:496545a6307b:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:32db794688a5:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:a5e095526f91:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:751e447fb3d0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:time:1f47c861a9ac:golang_time/vendor/golang.org/x/time \
		gorilla:handlers:v1.5.1:gorilla_handlers/vendor/github.com/gorilla/handlers \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		natefinch:lumberjack:v2.0.0:natefinch_lumberjack/vendor/gopkg.in/natefinch/lumberjack.v2 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.11.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.30.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.7.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		umputun:go-flags:v1.5.1:umputun_go_flags/vendor/github.com/umputun/go-flags

BUILD_WRKSRC=	${WRKSRC}/app
PLIST_FILES=	bin/reproxy

post-patch:
	@${REINPLACE_CMD} -e '/var revision/s,unknown,${PORTVERSION},' \
		${BUILD_WRKSRC}/main.go

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} \
		GOPROXY=off ${GO_CMD} build ${GO_BUILDFLAGS} \
		-o ${GO_WRKDIR_BIN}/${PORTNAME}

.include <bsd.port.mk>
