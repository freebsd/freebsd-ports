# $FreeBSD$

PORTNAME=	lusernet
PORTVERSION=	0.4.2
PORTREVISION=	6
CATEGORIES=	news gnustep
MASTER_SITES=	LOCAL/dinoex
DISTNAME=	LuserNET-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep news reader

LICENSE=	GPLv2

USES=		gnustep
USE_GNUSTEP=	back build
LIB_DEPENDS=	libPantomime.so:mail/pantomime

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/LuserNET.app/LuserNET

.include <bsd.port.mk>
