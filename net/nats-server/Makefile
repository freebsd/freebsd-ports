PORTNAME=	nats-server
PORTVERSION=	2.7.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Messaging system written in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	nats-io
GH_TUPLE=	golang:crypto:5e0467b6c7ce:golang_crypto/vendor/golang.org/x/crypto \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:5a964db01320:golang_sys/vendor/golang.org/x/sys \
		golang:time:f0f3c7e86c11:golang_time/vendor/golang.org/x/time \
		klauspost:compress:v1.13.4:klauspost_compress/vendor/github.com/klauspost/compress \
		minio:highwayhash:v1.0.1:minio_highwayhash/vendor/github.com/minio/highwayhash \
		nats-io:jwt:58e87895b296:nats_io_jwt_v2/vendor/github.com/nats-io/jwt \
		nats-io:nats.go:972a071d373d:nats_io_nats_go/vendor/github.com/nats-io/nats.go \
		nats-io:nkeys:v0.3.0:nats_io_nkeys/vendor/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/github.com/nats-io/nuid \
		protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf

USE_RC_SUBR=	nats.sh

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
