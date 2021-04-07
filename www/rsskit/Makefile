PORTNAME=	rsskit
PORTVERSION=	0.4
PORTREVISION=	8
CATEGORIES=	www gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	RSSKit-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Etoile Project RSSKit framework

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnustep
USE_GNUSTEP=	back build
USE_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/Frameworks/RSSKit.framework/Versions/0/libRSSKit.so

.include <bsd.port.mk>
