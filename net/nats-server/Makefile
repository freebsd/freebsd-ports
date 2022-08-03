PORTNAME=	nats-server
PORTVERSION=	2.8.4
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Messaging system written in Go

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	nats-io
GH_TUPLE=	golang:crypto:3147a52a75dd:golang_crypto/vendor/golang.org/x/crypto \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:5a964db01320:golang_sys/vendor/golang.org/x/sys \
		golang:time:f0f3c7e86c11:golang_time/vendor/golang.org/x/time \
		klauspost:compress:v1.14.4:klauspost_compress/vendor/github.com/klauspost/compress \
		minio:highwayhash:v1.0.2:minio_highwayhash/vendor/github.com/minio/highwayhash \
		nats-io:jwt:442af02fd36a:nats_io_jwt_v2/vendor/github.com/nats-io/jwt \
		nats-io:nats.go:v1.15.0:nats_io_nats_go/vendor/github.com/nats-io/nats.go \
		nats-io:nkeys:v0.3.0:nats_io_nkeys/vendor/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/github.com/nats-io/nuid \
		protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf

USE_RC_SUBR=	nats.sh

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

USERS=		nats
GROUPS=		nats

OPTIONS_DEFINE=	DOCS

post-patch:
	@${LN} -s ${WRKSRC} ${WRKSRC}/vendor/${GO_PKGNAME}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${FILESDIR}/nats.conf ${STAGEDIR}${PREFIX}/etc/nats.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/server && ${COPYTREE_SHARE} configs ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
