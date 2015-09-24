# Created by: Adriaan de Groot <groot@kde.org>
# $FreeBSD$

PORTNAME=	libmal
PORTVERSION=	0.44.1
PORTREVISION=	1
CATEGORIES=	palm
MASTER_SITES=	http://www.jlogday.com/code/libmal/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library encapsulating malsync

LICENSE=	MPL

LIB_DEPENDS=	libpisock.so:${PORTSDIR}/palm/pilot-link

USES=		gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pilot-prefix=${LOCALBASE}
USE_LDCONFIG=	YES
CONFLICTS=	malsync-[0-9]*

.include <bsd.port.mk>
