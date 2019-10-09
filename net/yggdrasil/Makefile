# $FreeBSD$

PORTNAME=	yggdrasil
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.6
CATEGORIES=	net

MAINTAINER=	freebsd@neilalexander.dev
COMMENT=	Experimental end-to-end encrypted self-arranging IPv6 network

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	yggdrasil-network
GH_PROJECT=	yggdrasil-go
GH_TUPLE=	\
		docker:libcontainer:v2.2.1:docker_libcontainer/vendor/github.com/docker/libcontainer \
		golang:crypto:4def268fd1a4:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:ca1201d0de80:golang_net/vendor/golang.org/x/net \
		golang:sys:cbf593c0f2f3:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		gologme:log:4e5d8ccb38e8:gologme_log/vendor/github.com/gologme/log \
		hashicorp:go-syslog:v1.0.0:hashicorp_go_syslog/vendor/github.com/hashicorp/go-syslog \
		hjson:hjson-go:a25ecf6bd222:hjson_hjson_go/vendor/github.com/hjson/hjson-go \
		kardianos:minwinsvc:cad6b2b879b0:kardianos_minwinsvc/vendor/github.com/kardianos/minwinsvc \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		songgao:packets:549a10cd4091:songgao_packets/vendor/github.com/songgao/packets \
		yggdrasil-network:water:a16161896c34:yggdrasil_network_water/vendor/github.com/yggdrasil-network/water
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${GH_PROJECT}

MAKE_ENV+=	GOFLAGS=-mod=vendor

PLIST_FILES=	bin/yggdrasil \
		bin/yggdrasilctl

USE_RC_SUBR=	yggdrasil

pre-build:
	@${REINPLACE_CMD} -e 's/set -ef/set -f/' ${WRKSRC}/build

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} PKGNAME=${PORTNAME} PKGVER=${PORTVERSION} ./build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yggdrasil ${STAGEDIR}${PREFIX}/bin/yggdrasil
	${INSTALL_PROGRAM} ${WRKSRC}/yggdrasilctl ${STAGEDIR}${PREFIX}/bin/yggdrasilctl

.include <bsd.port.mk>
