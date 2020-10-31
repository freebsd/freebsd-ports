# $FreeBSD$

PORTNAME=	tailscale
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Mesh VPN that makes it easy to connect your devices

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_TUPLE=	\
		apenwarr:fixconsole:5a9f6489cc29:apenwarr_fixconsole/vendor/github.com/apenwarr/fixconsole \
		go4org:mem:185c595c3ecc:go4org_mem/vendor/go4.org/mem \
		golang:crypto:948cd5f35899:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mod:v0.3.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:c89045814202:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:sync:6e8e738ad208:golang_sync/vendor/golang.org/x/sync \
		golang:sys:6a926be9bd1d:golang_sys/vendor/golang.org/x/sys \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		inetaf:netaddr:56928fe48a98:inetaf_netaddr/vendor/inet.af/netaddr \
		klauspost:compress:v1.10.10:klauspost_compress/vendor/github.com/klauspost/compress \
		pborman:getopt:ee0cd42419d3:pborman_getopt/vendor/github.com/pborman/getopt \
		peterbourgon:ff:v2.0.0:peterbourgon_ff_v2/vendor/github.com/peterbourgon/ff/v2 \
		rsc:goversion:v1.2.0:rsc_goversion/vendor/rsc.io/goversion \
		tailscale:wireguard-go:a6168fd06b3f:tailscale_wireguard_go/vendor/github.com/tailscale/wireguard-go \
		tcnksm:go-httpstat:v0.2.0:tcnksm_go_httpstat/vendor/github.com/tcnksm/go-httpstat \
		toqueteos:webbrowser:v1.2.0:toqueteos_webbrowser/vendor/github.com/toqueteos/webbrowser

USE_RC_SUBR=	tailscaled

GO_TARGET=	./cmd/tailscale \
		./cmd/tailscaled

PLIST_FILES=	bin/tailscale  \
		bin/tailscaled

.include <bsd.port.mk>
