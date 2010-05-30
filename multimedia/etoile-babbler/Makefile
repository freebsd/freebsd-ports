# New ports collection makefile for:    etoile-babbler
# Date created:         22 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	babbler
PORTVERSION=	0.1.${SNAPSHOT}
PORTREVISION=	2
CATEGORIES=	multimedia gnustep
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex
PKGNAMEPREFIX=	etoile-
DISTNAME=	Etoile-${SNAPSHOT}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Simple media player for Etoile

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_SYSTEM_LIBS+=	XWindowServerKit:${XWINDOWSERVERKIT_PORT}
USE_GNUSTEP_LOCAL_LIBS+=	MultimediaKit:${MULTIMEDIAKIT_PORT}

SNAPSHOT=	20061221
WRKSRC=	${WRKDIR}/Etoile/
USE_GNUSTEP_MAKE_DIRS+=	Services/User/Babbler

XWINDOWSERVERKIT_PORT?=		x11/etoile-xwindowserverkit
MULTIMEDIAKIT_PORT?=	multimedia/etoile-multimediakit

.include <bsd.port.mk>
