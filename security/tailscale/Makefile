# $FreeBSD$

PORTNAME=	tailscale
PORTVERSION=	1.4.2
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
		go4org:unsafe-assume-no-moving-gc:1025295fd063:go4org_go4_2/vendor/go4.org/unsafe/assume-no-moving-gc \
		go4org:intern:7cab76ca296a:go4org_go4/vendor/go4.org/intern \
		go4org:mem:c04c5a6ff174:go4org_go4_1/vendor/go4.org/mem \
		golang:crypto:c8d3bf9c5392:golang_crypto/vendor/golang.org/x/crypto \
		golang:mod:v0.4.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:986b41b23924:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:sync:67f06af15bc9:golang_sync/vendor/golang.org/x/sync \
		golang:sys:7d0127a74742:golang_sys/vendor/golang.org/x/sys \
		golang:term:ee85cb95a76b:golang_term/vendor/golang.org/x/term \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		google:btree:v1.0.0:google_btree/vendor/github.com/google/btree \
		google:gvisor:3ff3110fcdd6:google_gvisor/vendor/gvisor.dev/gvisor \
		inetaf:netaddr:648fbc18a69d:inetaf_netaddr/vendor/inet.af/netaddr \
		klauspost:compress:v1.10.10:klauspost_compress/vendor/github.com/klauspost/compress \
		pborman:getopt:ee0cd42419d3:pborman_getopt/vendor/github.com/pborman/getopt \
		peterbourgon:ff:v2.0.0:peterbourgon_ff_v2/vendor/github.com/peterbourgon/ff/v2 \
		rsc:goversion:v1.2.0:rsc_goversion/vendor/rsc.io/goversion \
		tailscale:wireguard-go:7ad8a0443bd3:tailscale_wireguard_go/vendor/github.com/tailscale/wireguard-go \
		tcnksm:go-httpstat:v0.2.0:tcnksm_go_httpstat/vendor/github.com/tcnksm/go-httpstat \
		toqueteos:webbrowser:v1.2.0:toqueteos_webbrowser/vendor/github.com/toqueteos/webbrowser

USE_RC_SUBR=	tailscaled

GO_TARGET=	./cmd/tailscale \
		./cmd/tailscaled

PLIST_FILES=	bin/tailscale  \
		bin/tailscaled

.include <bsd.port.mk>
