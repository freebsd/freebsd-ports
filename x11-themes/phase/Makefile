# New ports collection makefile for:	Phase
# Date created:			July 9th, 2004
# Whom:		 		David Johnson <david@usermode.org>
#
# $FreeBSD$
#

PORTNAME=	phase
PORTVERSION=	0.7
PORTREVISION=	5
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://www.usermode.org/code/

MAINTAINER=	david@usermode.org
COMMENT=	An original Qt/KDE widget style

CONFLICTS=	kdeartwork-3.4.*

USE_KDEBASE_VER=3
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_LDCONFIG=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib/kde3

.include <bsd.port.mk>
