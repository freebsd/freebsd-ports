# $FreeBSD$

PORTNAME=	batmon
PORTVERSION=	0.6
PORTREVISION=	3
CATEGORIES=	sysutils gnustep
MASTER_SITES=	SAVANNAH/gap

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep battery monitor for laptops

LICENSE=	GPLv2 # or later

USES=		gnustep
USE_GNUSTEP=	back build

post-patch:
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/batmon.app/batmon

.include <bsd.port.mk>
