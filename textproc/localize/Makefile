PORTNAME=	localize
PORTVERSION=	0.0.1
PORTREVISION=	11
CATEGORIES=	textproc gnustep
MASTER_SITES=	http://www.eskimo.com/~pburns/Localize/files/
DISTNAME=	Localize-20040424

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application to aid in the translation of .strings files

LICENSE=	GPLv2

USES=		gnustep
USE_GNUSTEP=	back build

WRKSRC=		${WRKDIR}/Localize

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Localize.app/Localize

.include <bsd.port.mk>
