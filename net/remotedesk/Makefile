# $FreeBSD$

PORTNAME=	remotedesk
PORTVERSION=	0.1
PORTREVISION=	5
CATEGORIES=	net gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	RemoteDesk-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical interface to rdesktop

LICENSE=	GPLv2+

RUN_DEPENDS=	rdesktop:net/rdesktop

USES=		gnustep
USE_GNUSTEP=	back build

post-patch:
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/RemoteDesk.app/RemoteDesk

.include <bsd.port.mk>
