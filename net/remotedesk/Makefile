# New ports collection makefile for:    remotedesk
# Date created:         09 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	remotedesk
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	net gnustep
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	gap
DISTNAME=	RemoteDesk-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Graphical interface to rdesktop

RUN_DEPENDS=	rdesktop:${PORTSDIR}/net/rdesktop

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

post-patch:
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
