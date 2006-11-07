# New ports collection makefile for:    Pantomime-SSL
# Date created:				27.October 2002
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	pantomime
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.collaboration-world.com/pantomime.data/releases/Stable/
PKGNAMESUFFIX?=	-ssl${PKGNAMESUFFIX2}
DISTNAME=	Pantomime-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	SSL Connections for pantomime

WRKSRC=		${WRKDIR}/Pantomime/Bundles/SSL
USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	Pantomime:${PANTOMIME_PORT}
MAKEFILE=	GNUmakefile
PANTOMIME_PORT?=	mail/pantomime

IGNORE=		is obsolete, it is now part of mail/pantomime
EXPIRATION_DATE=2006-12-01

.include <bsd.port.mk>
