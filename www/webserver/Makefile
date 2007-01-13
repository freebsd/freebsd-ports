# New ports collection makefile for:	webserver
# Date created:         29 Oct 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	webserver
PORTVERSION=	1.1.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	libs
DISTNAME=	WebServer-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Framework for a GNUstep to act as HTTP or HTTPS server

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BASE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
DEFAULT_LIBVERSION=	1.1
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

.include <bsd.port.mk>
