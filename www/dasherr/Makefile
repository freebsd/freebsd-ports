PORTNAME=	dasherr
DISTVERSION=	1.05.01
CATEGORIES=	www
MASTER_SITES=	https://github.com/erohtar/Dasherr/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}.${DISTVERSION}

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Lightweight dashboard for self-hosted services (and bookmarks)
WWW=		https://github.com/erohtar/Dasherr/

LICENSE=	GPLv3

USES=		php zip

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/www

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
