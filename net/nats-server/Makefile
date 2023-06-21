PORTNAME=	nats-server
PORTVERSION=	2.9.19
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Messaging system written in Go
WWW=		https://nats.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	nats-io
GH_TUPLE=	golang:crypto:v0.9.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.8.0:golang_sys/vendor/golang.org/x/sys \
		golang:time:v0.3.0:golang_time/vendor/golang.org/x/time \
		klauspost:compress:v1.16.5:klauspost_compress/vendor/github.com/klauspost/compress \
		minio:highwayhash:v1.0.2:minio_highwayhash/vendor/github.com/minio/highwayhash \
		nats-io:jwt:v2.4.1:nats_io_jwt_v2/vendor/github.com/nats-io/jwt \
		nats-io:nats.go:v1.27.0:nats_io_nats_go/vendor/github.com/nats-io/nats.go \
		nats-io:nkeys:v0.4.4:nats_io_nkeys/vendor/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/github.com/nats-io/nuid \
		protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		uber-go:automaxprocs:v1.5.1:uber_go_automaxprocs/vendor/go.uber.org/automaxprocs

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
