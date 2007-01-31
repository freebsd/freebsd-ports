# New ports collection makefile for:    stepulator.app
# Date created:         30 Aug 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	stepulator
PORTVERSION=	1.0
CATEGORIES=	math gnustep
MASTER_SITES=	http://www.linuks.mine.nu/stepulator/ \
		${MASTER_SITE_GNUSTEP_CH}
DISTNAME=	${PORTNAME}-gs-${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	Scientific calculator implementing RPN notation for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/Stepulator-gs

.include <bsd.port.mk>
