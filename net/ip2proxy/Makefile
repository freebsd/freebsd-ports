PORTNAME=	ip2proxy
PORTVERSION=	20230929
CATEGORIES=	net

MAINTAINER=	zi@FreeBSD.org
COMMENT=	C library to lookup proxies
WWW=		https://ip2location.com/development-libraries/ip2proxy/c

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	ip2location
GH_PROJECT=	${PORTNAME}-c
GH_TAGNAME=	f27a379

USES=		autoreconf libtool
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-install:
	(cd ${WRKSRC} && ${MAKE} install-data DESTDIR=${STAGEDIR})

.include <bsd.port.mk>
