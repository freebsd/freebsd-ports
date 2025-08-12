PORTNAME=	aclock
PORTVERSION=	0.4.0
PORTREVISION=	11
CATEGORIES=	x11-clocks gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	AClock-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Analog Clock for GNUstep
WWW=		https://gap.nongnu.org/aclock/index.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnustep
USE_GNUSTEP=	back build

WRKSRC=		${WRKDIR}/${DISTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/AClock.app/AClock

.include <bsd.port.mk>
