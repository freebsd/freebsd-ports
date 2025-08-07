PORTNAME=	revsocks
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8
PORTREVISION=	14
CATEGORIES=	net

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Reverse SOCKS5 implementation in Go
WWW=		https://github.com/kost/revsocks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	kost

GH_TUPLE=	Jeffail:tunny:v0.1.4:jeffail_tunny/vendor/github.com/Jeffail/tunny \
		acomagu:bufpipe:v1.0.4:acomagu_bufpipe/vendor/github.com/acomagu/bufpipe \
		armon:go-socks5:e75332964ef5:armon_go_socks5/vendor/github.com/armon/go-socks5 \
		golang:crypto:v0.14.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:mod:v0.10.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.17.0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.13.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.13.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.9.1:golang_tools/vendor/golang.org/x/tools \
		hashicorp:yamux:v0.1.1:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		kost:chashell:cf0fbd106275:kost_chashell/vendor/github.com/kost/chashell \
		kost:dnstun:6e7f5656a900:kost_dnstun/vendor/github.com/kost/dnstun \
		kost:go-ntlmssp:a22bdd33b2a4:kost_go_ntlmssp/vendor/github.com/kost/go-ntlmssp \
		miekg:dns:v1.1.54:miekg_dns/vendor/github.com/miekg/dns \
		nhooyr:websocket:v1.8.10:nhooyr_websocket/vendor/nhooyr.io/websocket \
		protocolbuffers:protobuf-go:v1.30.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rs:xid:v1.5.0:rs_xid/vendor/github.com/rs/xid

PLIST_FILES=	bin/revsocks

.include <bsd.port.mk>
