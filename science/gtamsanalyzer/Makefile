# New ports collection makefile for:    gtamsanalyzer
# Date created:         26 Sep 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	gtamsanalyzer
PORTVERSION=	0.42
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tamsys
DISTNAME=	GTAMSAnalyzer.src.${PORTVERSION}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	Qualitative Research Software for the Free World for GNUstep

WRKSRC=	${WRKDIR}/${DISTNAME}/Source
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile

.include <bsd.port.mk>
