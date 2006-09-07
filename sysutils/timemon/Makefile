# New ports collection makefile for:    timemon.app
# Date created:         28 Aug 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	timemon
PORTVERSION=	4.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	gap
DISTNAME=	TimeMon-gnustep
EXTRACT_SUFX=	.tgz

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	CPU time usage monitor for GNUstep

WRKSRC=		${WRKDIR}/TimeMon
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile

post-patch:
	${RM} ${WRKSRC}/shared_obj/loadave.o

.include <bsd.port.mk>
