# New ports collection makefile for:    pantomime
# Date created:         17 Sep 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pantomime
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	mail gnustep
MASTER_SITES=	http://www.collaboration-world.com/pantomime.data/releases/Stable/
DISTNAME=	Pantomime-${PORTVERSION}pre3

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Mail/MIME handling library for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/Pantomime
DEFAULT_LIBVERSION=	1.2

.include <bsd.port.mk>
