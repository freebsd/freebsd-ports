# New ports collection makefile for:    addresses
# Date created:         13 Nov 2004
# Whom:                 Miguel Mendez <flynn@energyhq.es.eu.org>
#
# $FreeBSD$
#

PORTNAME=	addresses
PORTVERSION=	0.4.7
CATEGORIES=	mail gnustep
MASTER_SITES=	http://download.savannah.gnu.org/releases/gap/
DISTNAME=	Addresses-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A versatile addressbook for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/Addresses

.include <bsd.port.mk>
