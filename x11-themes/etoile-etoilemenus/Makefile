# New ports collection makefile for:    etoile-etoilemenus
# Date created:         18 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	etoilemenus
PORTVERSION=	0.4.1
CATEGORIES=	x11-themes gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project EtoileMenus bundle

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Bundles/EtoileWildMenus

post-configure:
	${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/etoile.make

.include <bsd.port.mk>
