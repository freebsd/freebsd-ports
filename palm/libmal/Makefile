# Ports collection makefile for:	libmal
# Date created:				4 september 2002
# Whom:					Adriaan de Groot <groot@kde.org>
#
#
# $FreeBSD$
#

PORTNAME=	libmal
PORTVERSION=	0.44.1
CATEGORIES=	palm
MASTER_SITES=	http://www.jlogday.com/code/libmal/

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	A library encapsulating malsync

LIB_DEPENDS=	pisock.9:${PORTSDIR}/palm/pilot-link

USE_GMAKE=	YES
GNU_CONFIGURE=	yes
HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-pilot-prefix=${LOCALBASE}
USE_LDCONFIG=	YES
CONFLICTS=	malsync-[0-9]*

.include <bsd.port.mk>
