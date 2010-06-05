# New ports collection makefile for:    lusernet
# Date created:         17 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	lusernet
PORTVERSION=	0.4.2
PORTREVISION=	2
CATEGORIES=	news gnustep
MASTER_SITES=	http://web.telia.com/~u42308495/alex/LuserNET/
DISTNAME=	LuserNET-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep news reader

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	Pantomime:${PANTOMIME_PORT}

PANTOMIME_PORT?=	mail/pantomime

.include <bsd.port.mk>
