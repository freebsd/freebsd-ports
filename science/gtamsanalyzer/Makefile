# New ports collection makefile for:    gtamsanalyzer
# Date created:         26 Sep 2006
# Whom:                 gurkan@phys.ethz.ch
#
# $FreeBSD$
#

PORTNAME=	gtamsanalyzer
PORTVERSION=	0.42
PORTREVISION=	2
CATEGORIES=	science gnustep
MASTER_SITES=	SF/tamsys/gnustep%20tams/GTAMSAnalyzer%2${PORTVERSION}
DISTNAME=	GTAMSAnalyzer.src.${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Qualitative Research Software for the Free World for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=	${WRKDIR}/${DISTNAME}/Source

post-patch:	
	${RM} "${WRKSRC}/obj"

.include <bsd.port.mk>
