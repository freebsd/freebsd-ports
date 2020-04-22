# $FreeBSD$

PORTNAME=	tailscale
PORTVERSION=	0.98
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
		golang:crypto:1b76d66859c6:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:244492dfa37a:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:sync:cd5d95a43a6e:golang_sync/vendor/golang.org/x/sync \
		golang:sys:5766fd39f98d:golang_sys/vendor/golang.org/x/sys \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		klauspost:compress:v1.9.8:klauspost_compress/vendor/github.com/klauspost/compress \
		pborman:getopt:ee0cd42419d3:pborman_getopt/vendor/github.com/pborman/getopt \
		peterbourgon:ff:v2.0.0:peterbourgon_ff/vendor/github.com/peterbourgon/ff/v2 \
		rsc:goversion:v1.2.0:rsc_goversion/vendor/rsc.io/goversion \
		tailscale:wireguard-go:23aababa2084:tailscale_wireguard_go/vendor/github.com/tailscale/wireguard-go \
		go4org:mem:f77f31c81751:go4org_mem/vendor/go4.org/mem \
		inetaf:netaddr:f9e5bcc2d6ea:inetaf_netaddr/vendor/inet.af/netaddr \
		toqueteos:webbrowser:v1.2.0:toqueteos_webbrowser/vendor/github.com/toqueteos/webbrowser

USE_RC_SUBR=	tailscaled

GO_TARGET=	./cmd/tailscale \
		./cmd/tailscaled

PLIST_FILES=	bin/tailscale  \
		bin/tailscaled

.include <bsd.port.mk>
