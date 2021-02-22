# $FreeBSD$

PORTNAME=	chisel
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.6
CATEGORIES=	www

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Fast TCP tunnel over HTTP

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	jpillora
GH_TUPLE=	andrew-d:go-termutil:009166a695a2:andrew_d_go_termutil/vendor/github.com/andrew-d/go-termutil \
		armon:go-socks5:e75332964ef5:armon_go_socks5/vendor/github.com/armon/go-socks5 \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		golang:crypto:948cd5f35899:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:ab3426394381:golang_net/vendor/golang.org/x/net \
		golang:sync:6e8e738ad208:golang_sync/vendor/golang.org/x/sync \
		golang:sys:ddb9806d33ae:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		jpillora:ansi:v1.0.2:jpillora_ansi/vendor/github.com/jpillora/ansi \
		jpillora:backoff:v1.0.0:jpillora_backoff/vendor/github.com/jpillora/backoff \
		jpillora:requestlog:v1.0.0:jpillora_requestlog/vendor/github.com/jpillora/requestlog \
		jpillora:sizestr:v1.0.0:jpillora_sizestr/vendor/github.com/jpillora/sizestr \
		tomasen:realip:f0c99a92ddce:tomasen_realip/vendor/github.com/tomasen/realip

_BUILD_VERSION=	${DISTVERSION}

GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X github.com/${GH_ACCOUNT}/${GH_PROJECT}/share.BuildVersion=${_BUILD_VERSION}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
