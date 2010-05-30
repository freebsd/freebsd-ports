# New ports collection makefile for:    batmon
# Date created:         05 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	batmon
PORTVERSION=	0.4
CATEGORIES=	sysutils gnustep
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	gap

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep battery monitor for laptops

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

post-patch:
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
