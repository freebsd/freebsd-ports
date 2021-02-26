# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zfs-stats
PORTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	GH

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Display human-readable ZFS statistics

LICENSE=	BSD2CLAUSE

USES=		perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	mmatuska

NO_BUILD=	yes
SHEBANG_FILES=	zfs-*
perl_OLD_CMD=	"/usr/bin/env -iS perl"

PLIST_FILES=	bin/zfs-stats \
		bin/zfs-mon

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zfs-stats ${STAGEDIR}${PREFIX}/bin/zfs-stats
	${INSTALL_SCRIPT} ${WRKSRC}/zfs-mon ${STAGEDIR}${PREFIX}/bin/zfs-mon

.include <bsd.port.mk>
