PORTNAME=	timemon
PORTVERSION=	4.2
PORTREVISION=	7
CATEGORIES=	sysutils gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	TimeMon-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CPU time usage monitor for GNUstep
WWW=		https://www.nongnu.org/gap/timemon/index.html

# Converted from NO_CDROM
LICENSE=	TimeMon
LICENSE_NAME=	TimeMon
LICENSE_TEXT=	distribute without fee
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		gnustep
USE_GNUSTEP=	back build

post-patch:
	${RM} ${WRKSRC}/shared_obj/*.*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/TimeMon.app/TimeMon

.include <bsd.port.mk>
