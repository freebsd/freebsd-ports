# New ports collection makefile for:    aclock
# Date created:         6 Oct 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	aclock
PORTVERSION=	0.2.3
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.linuks.mine.nu/aclock/ \
		http://florida.ethz.ch/ports/distfiles/
DISTNAME=	aclock-${PORTVERSION}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	Analog Clock for GNUstep

WRKSRC=		${WRKDIR}/${DISTNAME}/
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile

.include <bsd.port.mk>
