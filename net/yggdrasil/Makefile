PORTNAME=	yggdrasil
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.3
PORTREVISION=	4
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
		Arceliar:ironwood:8951369625d0:arceliar_ironwood/vendor/github.com/Arceliar/ironwood \
		Arceliar:phony:dde1a8dca979:arceliar_phony/vendor/github.com/Arceliar/phony \
		VividCortex:ewma:v1.2.0:vividcortex_ewma/vendor/github.com/VividCortex/ewma \
		cheggaaa:pb:v3.0.8:cheggaaa_pb_v3/vendor/github.com/cheggaaa/pb \
		fatih:color:v1.12.0:fatih_color/vendor/github.com/fatih/color \
		golang:crypto:089bfa567519:golang_crypto/vendor/golang.org/x/crypto \
		golang:mobile:858099ff7816:golang_mobile/vendor/golang.org/x/mobile \
		golang:mod:v0.4.2:golang_mod/vendor/golang.org/x/mod \
		golang:net:4a448f8816b3:golang_net/vendor/golang.org/x/net \
		golang:sys:4dd72447c267:golang_sys/vendor/golang.org/x/sys \
		golang:text:5bd84dd9b33b:golang_text/vendor/golang.org/x/text \
		golang:tools:316ba0b74098:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		gologme:log:v1.2.0:gologme_log/vendor/github.com/gologme/log \
		hashicorp:go-syslog:v1.0.0:hashicorp_go_syslog/vendor/github.com/hashicorp/go-syslog \
		hjson:hjson-go:v3.1.0:hjson_hjson_go/vendor/github.com/hjson/hjson-go \
		kardianos:minwinsvc:v1.0.0:kardianos_minwinsvc/vendor/github.com/kardianos/minwinsvc \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.13:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:mapstructure:v1.4.1:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		vishvananda:netlink:v1.1.0:vishvananda_netlink/vendor/github.com/vishvananda/netlink \
		vishvananda:netns:2eb08e3e575f:vishvananda_netns/vendor/github.com/vishvananda/netns \
		wireguard:wireguard-go:f87e87af0d9a:wireguard_wireguard_go/vendor/golang.zx2c4.com/wireguard

GO_TARGET=	./cmd/yggdrasil \
		./cmd/yggdrasilctl

GO_BUILDFLAGS=	-ldflags="-s -w \
		-X github.com/yggdrasil-network/yggdrasil-go/src/version.buildName=${PORTNAME} \
		-X github.com/yggdrasil-network/yggdrasil-go/src/version.buildVersion=${PORTVERSION} \
		"

PLIST_FILES=	bin/yggdrasil \
		bin/yggdrasilctl

USE_RC_SUBR=	yggdrasil

.include <bsd.port.mk>
