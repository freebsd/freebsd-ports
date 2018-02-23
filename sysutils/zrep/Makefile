# $FreeBSD$

PORTNAME=	zrep
PORTVERSION=	1.7.3
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	neel@neelc.org
COMMENT=	ZFS based replication and failover solution

LICENSE=	bolthole
LICENSE_NAME=	bolthole
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell

RUN_DEPENDS=	ksh93:shells/ksh93

USE_GITHUB=	yes
GH_ACCOUNT=	bolthole

PLIST_FILES=	bin/zrep

NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|#!/bin/ksh -p|#!${LOCALBASE}/bin/ksh93 -p|' ${WRKSRC}/zrep

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.mk>
