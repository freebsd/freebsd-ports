# New ports collection makefile for:    webservices
# Date created:         25 Jan 2009
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	webservices
PORTVERSION=	0.5.5
CATEGORIES=	www gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	libs
DISTNAME=	WebServices-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Classes for building web services

LICENSE=	LGPL21

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}
USE_GNUSTEP_LOCAL_LIBS+=	Performance:${PERFORMANCE_PORT}

DEFAULT_LIBVERSION=	0.5.0
DEFAULT_LIBVERSION2=	0.5
PLIST_SUB+=	LIBVERSION2=${DEFAULT_LIBVERSION2}
PLIST_SUB+=	MAJORLIBVERSION2=${DEFAULT_LIBVERSION2:C/([0-9]).*/\1/1}

PERFORMANCE_PORT?=	devel/performance

.include <bsd.port.mk>
