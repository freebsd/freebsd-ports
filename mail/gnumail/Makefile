# New ports collection makefile for:    GNUMail
# Date created:         11 Jun 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnumail
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	mail gnustep
MASTER_SITES=	http://www.collaboration-world.com/gnumail.data/releases/Stable/
DISTNAME=	GNUMail-${PORTVERSION}pre3

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep mail client

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	Pantomime:${PANTOMIME_PORT}
USE_GNUSTEP_LOCAL_LIBS+=	Addresses:${ADDRESSES_PORT}
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/GNUMail
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR=${GNUSTEP_LOCAL_ROOT}

PANTOMIME_PORT?=	mail/pantomime
ADDRESSES_PORT?=	mail/addresses

.include <bsd.port.mk>
