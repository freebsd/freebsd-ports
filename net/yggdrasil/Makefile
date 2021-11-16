PORTNAME=	yggdrasil
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
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
		Arceliar:ironwood:6ad55cae5031:arceliar_ironwood/vendor/github.com/Arceliar/ironwood \
		Arceliar:phony:dde1a8dca979:arceliar_phony/vendor/github.com/Arceliar/phony \
		VividCortex:ewma:v1.2.0:vividcortex_ewma/vendor/github.com/VividCortex/ewma \
		cheggaaa:pb:v3.0.8:cheggaaa_pb_v3/vendor/github.com/cheggaaa/pb \
		fatih:color:v1.12.0:fatih_color/vendor/github.com/fatih/color \
		golang:crypto:c07d793c2f9a:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:84b48f89b13b:golang_net/vendor/golang.org/x/net \
		golang:sys:a4fc73990273:golang_sys/vendor/golang.org/x/sys \
		golang:text:5c7c50ebbd4f:golang_text/vendor/golang.org/x/text \
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
		wireguard:wireguard-go:f9b48a961cd2:wireguard_wireguard_go/vendor/golang.zx2c4.com/wireguard \

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
