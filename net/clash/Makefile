# $FreeBSD$

PORTNAME=	clash
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rule-based tunnel in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	Dreamacro
GH_TUPLE=	\
		Dreamacro:go-shadowsocks2:v0.1.6:dreamacro_go_shadowsocks2/vendor/github.com/Dreamacro/go-shadowsocks2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-chi:chi:v4.1.2:go_chi_chi/vendor/github.com/go-chi/chi \
		go-chi:cors:v1.1.1:go_chi_cors/vendor/github.com/go-chi/cors \
		go-chi:render:v1.0.1:go_chi_render/vendor/github.com/go-chi/render \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gofrs:uuid:v4.0.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		golang:crypto:b8e89b74b9df:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:5f4716e94777:golang_net/vendor/golang.org/x/net \
		golang:sync:09787c993a3a:golang_sync/vendor/golang.org/x/sync \
		golang:sys:8ebf48af031b:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		magefile:mage:v1.10.0:magefile_mage/vendor/github.com/magefile/mage \
		miekg:dns:v1.1.38:miekg_dns/vendor/github.com/miekg/dns \
		oschwald:geoip2-golang:v1.4.0:oschwald_geoip2_golang/vendor/github.com/oschwald/geoip2-golang \
		oschwald:maxminddb-golang:v1.6.0:oschwald_maxminddb_golang/vendor/github.com/oschwald/maxminddb-golang \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		sirupsen:logrus:v1.8.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/go.uber.org/atomic

PLIST_FILES=	bin/${PORTNAME}

PORTSCOUT=	limit:^[0-9\.]*$$

pre-patch:
	@cd ${WRKSRC} && ${CP} proxy/redir/tcp_linux.go proxy/redir/tcp_freebsd.go

.include <bsd.port.mk>
