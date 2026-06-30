PORTNAME=	tun2socks
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.0
CATEGORIES=	net

MAINTAINER=	dasun4@pm.me
COMMENT=	Tunnel TCP/UDP traffic through a SOCKS5/HTTP proxy via TUN interface
WWW=		https://github.com/${GH_ACCOUNT}/${PORTNAME}

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	xjasonlyu
GH_TUPLE=	ajg:form:v1.5.1:ajg_form/vendor/github.com/ajg/form \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		docker:go-units:v0.5.0:docker_go_units/vendor/github.com/docker/go-units \
		go-chi:chi:v5.2.1:go_chi_chi_v5/vendor/github.com/go-chi/chi/v5 \
		go-chi:cors:v1.2.1:go_chi_cors/vendor/github.com/go-chi/cors \
		go-chi:render:v1.0.3:go_chi_render/vendor/github.com/go-chi/render \
		go-gost:relay:v0.5.0:go_gost_relay/vendor/github.com/go-gost/relay \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:v0.38.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.40.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.33.0:golang_sys/vendor/golang.org/x/sys \
		golang:time:v0.11.0:golang_time/vendor/golang.org/x/time \
		google:btree:v1.1.3:google_btree/vendor/github.com/google/btree \
		google:gvisor:eede7a881b20:google_gvisor/vendor/gvisor.dev/gvisor \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:schema:v1.4.1:gorilla_schema/vendor/github.com/gorilla/schema \
		gorilla:websocket:v1.5.3:gorilla_websocket/vendor/github.com/gorilla/websocket \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		stretchr:testify:v1.9.0:stretchr_testify/vendor/github.com/stretchr/testify \
		uber-go:atomic:v1.11.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:automaxprocs:v1.6.0:uber_go_automaxprocs/vendor/go.uber.org/automaxprocs \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.27.0:uber_go_zap/vendor/go.uber.org/zap \
		wireguard:wireguard-go:f333402bd9cb:wireguard_wireguard_go/vendor/golang.zx2c4.com/wireguard

GO_TARGET=	.
GO_BUILDFLAGS=	-ldflags="-w -s \
		-X github.com/${GH_ACCOUNT}/${PORTNAME}/v2/internal/version.Version=v${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor

.include <bsd.port.mk>
