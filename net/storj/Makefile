PORTNAME=	storj
PORTVERSION=	1.68.2
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Decentralized cloud object storage
WWW=		https://storj.io/

LICENSE=	AGPLv3

USES=		go:modules
USE_GITHUB=	yes

.include "${.CURDIR}/Makefile.deps"

STORJ_CMDS=	certificates crashcollect identity inspector metric-receiver \
		multinode satellite storagenode storagenode-updater \
		storj-admin storj-sim uplink versioncontrol

GO_TARGET=	${STORJ_CMDS:S,^,./cmd/,}

USERS=		storj
GROUPS=		storj
USE_RC_SUBR=	storagenode
SUB_LIST=	USER=${USERS} GROUP=${GROUPS}
PLIST_SUB=	USER=${USERS} GROUP=${GROUPS}

post-stage:
# Avoid conflict with `graphics/mesa-demos'
	@${MV} ${STAGEDIR}${PREFIX}/bin/identity \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-identity

.include <bsd.port.mk>
