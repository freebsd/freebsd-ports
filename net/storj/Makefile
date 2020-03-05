# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	storj
PORTVERSION=	0.34.6
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Decentralized cloud object storage

LICENSE=	AGPLv3

USES=		go:modules
USE_GITHUB=	yes

.include "${.CURDIR}/Makefile.deps"

STORJ_CMDS=	certificates gateway identity inspector linksharing \
		s3-benchmark satellite segment-reaper statreceiver \
		storagenode storagenode-updater storj-sim uplink \
		versioncontrol

GO_TARGET=	${STORJ_CMDS:S,^,./cmd/,}

post-patch:
	@${REINPLACE_CMD} -e 's,"github\.com/nats-io/nats,&.go,' \
		${WRKSRC}/vendor/github.com/minio/minio/pkg/event/target/nats.go

post-stage:
# Avoid conflict with `graphics/mesa-demos'
	@${MV} ${STAGEDIR}${PREFIX}/bin/identity \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-identity

.include <bsd.port.mk>
