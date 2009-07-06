# New ports collection makefile for:    etoile-behavior
# Date created:         22 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	behavior
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	sysutils gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

PORTSCOUT=	limit:^0\.2

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project AppKit bundle for session

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Bundles/EtoileBehavior
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR="${GNUSTEP_SYSTEM_ROOT}"

.include <bsd.port.mk>
