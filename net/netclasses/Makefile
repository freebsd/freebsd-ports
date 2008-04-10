# New ports collection makefile for:    netclasses
# Date created:         07 Sep 2006
# Whom:                 gurkan@phys.ethz.ch
#
# $FreeBSD$
#

PORTNAME=	netclasses
PORTVERSION=	1.06
CATEGORIES=	net gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gurkan@phys.ethz.ch
COMMENT=	Objective-C framework for socket programming with GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BASE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
