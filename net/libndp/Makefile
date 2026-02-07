PORTNAME=	libndp
PORTVERSION=	1.9
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Neighbor discovery library
WWW=		https://github.com/jpirko/libndp

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	jpirko

.include <bsd.port.mk>
