PORTNAME=	nats-top
PORTVERSION=	0.5.2
PORTREVISION=	3
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Top like program monitor for NATS

LICENSE=	MIT

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	nats-io
GH_TUPLE=	davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		gizak:termui:e62b5929642a:gizak_termui/vendor/gopkg.in/gizak/termui.v1 \
		golang:crypto:5e0467b6c7ce:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:5a964db01320:golang_sys/vendor/golang.org/x/sys \
		golang:time:f0f3c7e86c11:golang_time/vendor/golang.org/x/time \
		klauspost:compress:v1.14.4:klauspost_compress/vendor/github.com/klauspost/compress \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		minio:highwayhash:v1.0.2:minio_highwayhash/vendor/github.com/minio/highwayhash \
		nats-io:jwt:58e87895b296:nats_io_jwt_v2/vendor/github.com/nats-io/jwt \
		nats-io:nats-server:v2.7.4:nats_io_nats_server_v2/vendor/github.com/nats-io/nats-server/v2 \
		nats-io:nkeys:v0.3.0:nats_io_nkeys/vendor/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/github.com/nats-io/nuid \
		nsf:termbox-go:v1.1.1:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify
GO_PKGNAME=	github.com/nats-io/nats-top
PLIST_FILES=	bin/nats-top

.include <bsd.port.mk>
