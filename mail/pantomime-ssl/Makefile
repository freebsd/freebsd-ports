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

BUILD_DEPENDS+=	${LOCALLIBDIR}/libPantomime.so:${PORTSDIR}/${PANTOMIME_PORT}
RUN_DEPENDS+=	${LOCALLIBDIR}/libPantomime.so:${PORTSDIR}/${PANTOMIME_PORT}

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/Pantomime/Bundles/SSL
USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile

.include <bsd.port.pre.mk>

PANTOMIME_PORT?=	mail/pantomime

.include <bsd.port.post.mk>
