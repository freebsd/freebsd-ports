PORTNAME=	yggdrasil
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.16
CATEGORIES=	net

MAINTAINER=	freebsd@neilalexander.dev
COMMENT=	Experimental end-to-end encrypted self-arranging IPv6 network

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	yggdrasil-network
GH_PROJECT=	yggdrasil-go
GH_TUPLE=	\
		Arceliar:phony:dde1a8dca979:arceliar_phony/vendor/github.com/Arceliar/phony \
		VividCortex:ewma:v1.1.1:vividcortex_ewma/vendor/github.com/VividCortex/ewma \
		cheggaaa:pb:v3.0.6:cheggaaa_pb_v3/vendor/github.com/cheggaaa/pb \
		fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		golang:crypto:5ea612d1eb83:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:e18ecbb05110:golang_net/vendor/golang.org/x/net \
		golang:sys:8fe3ee5dd75b:golang_sys/vendor/golang.org/x/sys \
		golang:text:8f690f22cf1c:golang_text/vendor/golang.org/x/text \
		gologme:log:4e5d8ccb38e8:gologme_log/vendor/github.com/gologme/log \
		hashicorp:go-syslog:v1.0.0:hashicorp_go_syslog/vendor/github.com/hashicorp/go-syslog \
		hjson:hjson-go:v3.1.0:hjson_hjson_go/vendor/github.com/hjson/hjson-go \
		kardianos:minwinsvc:cad6b2b879b0:kardianos_minwinsvc/vendor/github.com/kardianos/minwinsvc \
		mattn:go-colorable:v0.1.2:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.10:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.7:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		vishvananda:netlink:v1.0.0:vishvananda_netlink/vendor/github.com/vishvananda/netlink \
		vishvananda:netns:7109fa855b0f:vishvananda_netns/vendor/github.com/vishvananda/netns \
		wireguard:wireguard-go:v0.0.20200320:wireguard_wireguard_go/vendor/golang.zx2c4.com/wireguard \
		WireGuard:wireguard-windows:v0.1.0:wireguard_wireguard_windows/vendor/golang.zx2c4.com/wireguard/windows
USE_RC_SUBR=	yggdrasil

GO_TARGET=	./cmd/yggdrasil \
		./cmd/yggdrasilctl
GO_BUILDFLAGS=	-ldflags="-s -w \
		-X github.com/yggdrasil-network/yggdrasil-go/src/version.buildName=${PORTNAME} \
		-X github.com/yggdrasil-network/yggdrasil-go/src/version.buildVersion=${PORTVERSION} \
		"

PLIST_FILES=	bin/yggdrasil \
		bin/yggdrasilctl

.include <bsd.port.mk>
