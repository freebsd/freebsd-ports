PORTNAME=	nats-top
PORTVERSION=	0.4.0
DISTVERSIONPREFIX=	v
PORTREVISION=	0
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Top like program monitor for NATS

LICENSE=	MIT

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	nats-io
GH_PROJECT=	nats-top
GH_TUPLE=	davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		gizak:termui:e62b5929642a:gizak_termui/vendor/gopkg.in/gizak/termui.v1 \
		golang:crypto:0ec3e9974c59:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:fc99dfbffb4e:golang_sys/vendor/golang.org/x/sys \
		mattn:go-runewidth:v0.0.1:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		nats-io:jwt:v1.1.0:nats_io_jwt/vendor/github.com/nats-io/jwt \
		nats-io:nats-server:v2.1.9:nats_io_nats_server_v2/vendor/github.com/nats-io/nats-server/v2 \
		nats-io:nkeys:v0.1.4:nats_io_nkeys/vendor/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/github.com/nats-io/nuid \
		nsf:termbox-go:e8f6d27f72a2:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify
GO_PKGNAME=	github.com/nats-io/nats-top
PLIST_FILES=	bin/nats-top

.include <bsd.port.mk>
