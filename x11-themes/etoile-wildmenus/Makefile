# New ports collection makefile for:    etoile-wildmenus
# Date created:         18 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	wildmenus
PORTVERSION=	0.1.${SNAPSHOT}
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~%%SUBDIR%%/distfiles/
MASTER_SITE_SUBDIR=	dinoex
PKGNAMEPREFIX=	etoile-
DISTNAME=	Etoile-${SNAPSHOT}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project WildMenus bundle

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${LOCALLIBDIR}

SNAPSHOT=	20061221
WRKSRC=	${WRKDIR}/Etoile/
USE_GNUSTEP_MAKE_DIRS+=	Bundles/WildMenus

.include <bsd.port.mk>
