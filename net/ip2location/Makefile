# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	ip2location
PORTVERSION=	6.0.3
CATEGORIES=	net
MASTER_SITES=	http://www.ip2location.com/downloads/
DISTNAME=	${PORTNAME}-c-${PORTVERSION}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	C library to find user\'s location

LICENSE=	LGPL3

USES=		libtool:keepla perl5
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-configure:
	(cd ${WRKSRC}/data && ${MAKE} convert)

.include <bsd.port.mk>
