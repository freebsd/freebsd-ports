# New ports collection makefile for:    aclock
# Date created:         6 Oct 2006
# Whom:                 gurkan@phys.ethz.ch
#
# $FreeBSD$
#

PORTNAME=	aclock
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	x11-clocks gnustep
MASTER_SITES=	http://www.linuks.mine.nu/aclock/ \
		${MASTER_SITE_GNUSTEP_CH}
DISTNAME=	aclock-${PORTVERSION}

MAINTAINER=	gurkan@phys.ethz.ch
COMMENT=	Analog Clock for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.mk>
