# New ports collection makefile for:    tryst
# Date created:         18 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	tryst
PORTVERSION=	1.0.8
CATEGORIES=	net
MASTER_SITES=	http://gnustep.dyndns.org/Downloads/
DISTNAME=	tryst-108pl4
EXTRACT_SUFX=	.tgz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Implementation of Apples Bonjour for GNUstep

LIB_DEPENDS=	dns_sd:${PORTSDIR}/net/mDNSResponder

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${LOCALLIBDIR}

WRKSRC=		${WRKDIR}/Tryst-108.pl4

.include <bsd.port.mk>
