PORTNAME=	storj
PORTVERSION=	1.59.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Decentralized cloud object storage

LICENSE=	AGPLv3

USES=		go:1.18,modules
USE_GITHUB=	yes

.include "${.CURDIR}/Makefile.deps"

STORJ_CMDS=	certificates connect-test crashcollect identity inspector \
		metabase-orphaned-segments metabase-verify metric-receiver \
		multinode nullify-bad-user-agents satellite storagenode \
		storagenode-updater \
		storj-admin storj-sim uplink versioncontrol

GO_TARGET=	${STORJ_CMDS:S,^,./cmd/,}

post-stage:
# Avoid conflict with `graphics/mesa-demos'
	@${MV} ${STAGEDIR}${PREFIX}/bin/identity \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-identity

.include <bsd.port.mk>
