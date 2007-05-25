# New ports collection makefile for:    addresses
# Date created:         13 Nov 2004
# Whom:                 Miguel Mendez <flynn@energyhq.es.eu.org>
#
# $FreeBSD$
#

PORTNAME=	addresses
PORTVERSION=	0.4.6
PORTREVISION=	1
CATEGORIES=	mail gnustep
MASTER_SITES=	http://giesler.biz/bjoern/downloads/ \
		http://www.energyhq.es.eu.org/files/
DISTNAME=	Addresses-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A versatile addressbook for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/Addresses-${PORTVERSION}
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=LOCAL
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR=${GNUSTEP_LOCAL_ROOT}
ADDITIONAL_LIB_DIRS+=	-L${WRKSRC}/Frameworks/AddressView/AddressView.framework/Versions/Current
ADDITIONAL_LIB_DIRS+=	-L${WRKSRC}/Frameworks/Addresses/Addresses.framework/Versions/Current

.include <bsd.port.mk>
