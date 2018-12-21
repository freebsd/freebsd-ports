# $FreeBSD$

PORTNAME=	clash
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.2
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rule-based tunnel in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	Dreamacro
GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}
GH_TUPLE=	aead:chacha20:8b13a72:chacha20/src/github.com/aead/chacha20 \
		eapache:channels:v1.1.0:channels/src/gopkg.in/eapache/channels.v1 \
		eapache:queue:v1.1.0:queue/src/github.com/eapache/queue \
		Dreamacro:go-shadowsocks2:v0.1.2:shadowsocks/src/github.com/Dreamacro/go-shadowsocks2 \
		go-chi:chi:v3.3.3:chi/src/github.com/go-chi/chi \
		go-chi:cors:07727c8:cors/src/github.com/go-chi/cors \
		go-chi:render:v1.0.1:render/src/github.com/go-chi/render \
		go-yaml:yaml:v2.2.1:yaml/src/gopkg.in/yaml.v2 \
		gofrs:uuid:v3.1.2:uuid/src/github.com/gofrs/uuid \
		gorilla:websocket:v1.4.0:websocket/src/github.com/gorilla/websocket \
		miekg:dns:v1.1.1:dns/src/github.com/miekg/dns \
		oschwald:geoip2-golang:v1.2.1:geoip2_golang/src/github.com/oschwald/geoip2-golang \
		oschwald:maxminddb-golang:v1.3.0:maxminddb_golang/src/github.com/oschwald/maxminddb-golang \
		sirupsen:logrus:v1.2.0:logrus/src/github.com/sirupsen/logrus \
		stretchr:testify:v1.2.2:testify/src/github.com/stretchr/testify \
		golang:crypto:505ab14:golang_crypto/src/golang.org/x/crypto \
		golang:sys:70b957f:golang_sys/src/golang.org/x/sys

PLIST_FILES=	bin/${PORTNAME}

pre-patch:
	@cd ${WRKSRC} && ${CP} proxy/redir/tcp_linux.go proxy/redir/tcp_freebsd.go

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
