# New ports collection makefile for:   freeradius-client
# Date created:			Wed Nov 26 18:14:37 EET 2008
# Whom:				netch@netch.kiev.ua
#
# $FreeBSD$
#

PORTNAME=	freeradius-client
PORTVERSION=	1.1.6
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freeradius.org/pub/freeradius/ \
		ftp://ftp.suntel.com.tr/pub/freeradius/

MAINTAINER=	netch@portaone.com
COMMENT=	Client library and basic utilities for RADIUS AAA

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

CONFLICTS=	radiusclient-ng-[0-9]*

.include <bsd.port.mk>
