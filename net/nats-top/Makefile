PORTNAME=	nats-top
PORTVERSION=	0.5.3
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Top like program monitor for NATS
WWW=		https://github.com/nats-io/nats-top

LICENSE=	MIT

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	nats-io
GH_TUPLE=	gizak:termui:e62b5929642a:gizak_termui/vendor/gopkg.in/gizak/termui.v1 \
		golang:crypto:eccd6366d1be:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:f11e5e49a4ec:golang_sys/vendor/golang.org/x/sys \
		golang:time:f3bd1da661af:golang_time/vendor/golang.org/x/time \
		klauspost:compress:v1.15.11:klauspost_compress/vendor/github.com/klauspost/compress \
		mattn:go-runewidth:v0.0.14:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		minio:highwayhash:v1.0.2:minio_highwayhash/vendor/github.com/minio/highwayhash \
		nats-io:jwt:v2.3.0:nats_io_jwt_v2/vendor/github.com/nats-io/jwt \
		nats-io:nats-server:v2.9.2:nats_io_nats_server_v2/vendor/github.com/nats-io/nats-server/v2 \
		nats-io:nkeys:v0.3.0:nats_io_nkeys/vendor/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/github.com/nats-io/nuid \
		nsf:termbox-go:v1.1.1:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		stretchr:testify:v1.8.0:stretchr_testify/vendor/github.com/stretchr/testify
GO_PKGNAME=	github.com/nats-io/nats-top
PLIST_FILES=	bin/nats-top

.include <bsd.port.mk>
