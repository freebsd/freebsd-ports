# Ports collection makefile for:	libmal
# Date created:				4 september 2002
# Whom:					Adriaan de Groot <groot@kde.org>
#
#
# $FreeBSD$
#

PORTNAME=	libmal
PORTVERSION=	0.40
CATEGORIES=	palm
MASTER_SITES=	http://jasonday.home.att.net/code/libmal/

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	A library encapsulating malsync

LIB_DEPENDS=	pisock.8:${PORTSDIR}/palm/pilot-link

USE_GMAKE=	YES
USE_LIBTOOL_VER=13
HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-pilot-prefix=${LOCALBASE}
INSTALLS_SHLIB=	YES
CONFLICTS=	malsync-[0-9]*

.include <bsd.port.mk>
