# $FreeBSD$

PORTNAME=	remotedesk
PORTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	net gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	RemoteDesk-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical interface to rdesktop

LICENSE=	GPLv2 # or later

RUN_DEPENDS=	rdesktop:${PORTSDIR}/net/rdesktop

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

post-patch:
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/RemoteDesk.app/RemoteDesk

.include <bsd.port.mk>
