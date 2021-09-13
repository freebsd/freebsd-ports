PORTNAME=	cinny
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
CATEGORIES=	www
MASTER_SITES=	https://distfiles.pirateparty.in/ashish/ \
		LOCAL/ashish

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Yet another Matrix client for the web

LICENSE=	MIT

USES=		tar:xz
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/dist

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
