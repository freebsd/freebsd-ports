# New ports collection makefile for:    etoile-azbackground
# Date created:         22 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	azbackground
PORTVERSION=	0.1.${SNAPSHOT}
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~%%SUBDIR%%/distfiles/
MASTER_SITE_SUBDIR=	dinoex
PKGNAMEPREFIX=	etoile-
DISTNAME=	Etoile-${SNAPSHOT}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Small GNUstep application to set xwindow background

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_SYSTEM_LIBS+=	XWindowServerKit:${XWINDOWSERVERKIT_PORT}

SNAPSHOT=	20061221
WRKSRC=	${WRKDIR}/Etoile/
USE_GNUSTEP_MAKE_DIRS+=	Services/Private/AZBackground
ADDITIONAL_OBJCFLAGS+=	-I${X11BASE}/include
ADDITIONAL_LDFLAGS+=	-L${X11BASE}/lib

XWINDOWSERVERKIT_PORT?=	x11/etoile-xwindowserverkit

.include <bsd.port.mk>
