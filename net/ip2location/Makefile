PORTNAME=	ip2location
PORTVERSION=	8.7.0
CATEGORIES=	net

MAINTAINER=	zi@FreeBSD.org
COMMENT=	C library to find user\'s location
WWW=		https://www.ip2location.com/c.aspx

LICENSE=	LGPL3

USES=		autoreconf libtool perl5
USE_GITHUB=	yes
GH_ACCOUNT=	chrislim2888
GH_PROJECT=	IP2Location-C-Library

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-install:
	(cd ${WRKSRC}/data && ${MAKE} convert install-data DESTDIR=${STAGEDIR})

.include <bsd.port.mk>
