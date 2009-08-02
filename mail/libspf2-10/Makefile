# New ports collection makefile for:   libspf2
# Date created:        07 July 2004
# Whom:                snowchyld
#
# $FreeBSD$
#

PORTNAME=	libspf2
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.libspf2.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	spf

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	Sender Rewriting Scheme 2 C Implementation

CONFLICTS=	${PORTNAME}-1.2.*

LATEST_LINK=	${PORTNAME}-${PORTVERSION:S/.//:R}

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
