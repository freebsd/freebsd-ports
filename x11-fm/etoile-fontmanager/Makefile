# New ports collection makefile for:    etoile-fontmanager
# Date created:         26 Nov 2008
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	fontmanager
PORTVERSION=	0.4.1
CATEGORIES=	x11-fm x11-fonts gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project application for managing fonts

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Services/User/FontManager

post-configure:
	${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/etoile.make

.include <bsd.port.mk>
