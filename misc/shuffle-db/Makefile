PORTNAME=	shuffle-db
DISTVERSION=	1.0-rc1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/rebuild_db/1.0-rc1
DISTNAME=	rebuild_db-${DISTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	IPod shuffle database builder

USES=		python shebangfix
NO_ARCH=	yes
NO_BUILD=	yes
SHEBANG_FILES=	rebuild_db.py

WRKSRC=		${WRKDIR}/rebuild_db
PLIST_FILES=	bin/rebuild_db.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rebuild_db.py ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
