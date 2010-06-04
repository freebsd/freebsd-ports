# New ports collection makefile for:    etoile-azbackground
# Date created:         22 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	azbackground
PORTVERSION=	0.4.1
CATEGORIES=	x11-themes gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Small GNUstep application to set xwindow background

LICENSE=	BSD

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_SYSTEM_LIBS+=	XWindowServerKit:${XWINDOWSERVERKIT_PORT}

WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Services/Private/AZBackground
#ADDITIONAL_INCLUDE_DIRS+=	-I${LOCALBASE}/include
#ADDITIONAL_LIB_DIRS+=	-L${LOCALBASE}/lib

XWINDOWSERVERKIT_PORT?=	x11/etoile-xwindowserverkit

.include <bsd.port.mk>
