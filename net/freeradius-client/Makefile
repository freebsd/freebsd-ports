PORTNAME=	freeradius-client
PORTVERSION=	1.1.8
CATEGORIES=	net

MAINTAINER=	netch@portaone.com
COMMENT=	Client library and basic utilities for RADIUS AAA
WWW=		https://wiki.freeradius.org/project/Radiusclient

USES=		gmake libtool
USE_GITHUB=	yes
GH_ACCOUNT=	FreeRADIUS
GH_TAGNAME=	release_1_1_8

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	radiusclient

.include <bsd.port.mk>
