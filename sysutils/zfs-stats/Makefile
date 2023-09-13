PORTNAME=	zfs-stats
DISTVERSION=	1.3.2
CATEGORIES=	sysutils

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Displays general ZFS information and human-readable statistics
WWW=		https://github.com/mmatuska/zfs-stats

LICENSE=	BSD2CLAUSE

USES=		perl5
USE_GITHUB=	yes
GH_ACCOUNT=	mmatuska

NO_BUILD=	yes

PLIST_FILES=	bin/zfs-mon \
		bin/zfs-stats

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zfs-stats ${STAGEDIR}${PREFIX}/bin/zfs-stats
	${INSTALL_SCRIPT} ${WRKSRC}/zfs-mon ${STAGEDIR}${PREFIX}/bin/zfs-mon

.include <bsd.port.mk>
