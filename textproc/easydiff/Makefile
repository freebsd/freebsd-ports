# New ports collection makefile for:    easydiff
# Date created:         15 Mar 2003
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	easydiff
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	textproc
# outdated:	http://www.rivaille.net/EasyDiff/
MASTER_SITES=	http://debian.uni-essen.de/misc/GNUstep/Apps/EasyDiff/
DISTNAME=	EasyDiff-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep graphical diff

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/EasyDiff
GUN_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile

.include <bsd.port.mk>
