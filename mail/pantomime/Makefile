# New ports collection makefile for:    pantomime
# Date created:         17 Sep 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pantomime
PORTVERSION=	1.2.0
PORTREVISION=	4
CATEGORIES=	mail gnustep
MASTER_SITES=	http://download.gna.org/gnustep-nonfsf/
DISTNAME=	Pantomime-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Mail/MIME handling library for GNUstep

LICENSE=	LGPL21

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

DEFAULT_LIBVERSION=	1.2

.if !defined(WITH_GNUSTEP_DEVEL)
EXTRA_PATCHES=	${FILESDIR}/NSString+Extensions.m.patch
.endif

.include <bsd.port.mk>
