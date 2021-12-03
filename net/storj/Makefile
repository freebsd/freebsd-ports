# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	storj
PORTVERSION=	1.44.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Decentralized cloud object storage

LICENSE=	AGPLv3

USES=		go:modules
USE_GITHUB=	yes

.include "${.CURDIR}/Makefile.deps"

STORJ_CMDS=	certificates connect-test crashcollect identity inspector \
		metabase-orphaned-segments metabase-verify metric-receiver \
		multinode satellite storagenode storagenode-updater \
		storj-admin storj-sim uplink uplinkng versioncontrol

GO_TARGET=	${STORJ_CMDS:S,^,./cmd/,}

post-stage:
# Avoid conflict with `graphics/mesa-demos'
	@${MV} ${STAGEDIR}${PREFIX}/bin/identity \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-identity

.include <bsd.port.mk>
