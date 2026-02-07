PORTNAME=	ip2proxy
PORTVERSION=	20251118
CATEGORIES=	net

MAINTAINER=	zi@FreeBSD.org
COMMENT=	C library to lookup proxies
WWW=		https://ip2location.com/development-libraries/ip2proxy/c

LICENSE=	MIT

USES=		autoreconf libtool

USE_GITHUB=	yes
GH_ACCOUNT=	ip2location
GH_PROJECT=	${PORTNAME}-c
GH_TAGNAME=	7966220

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-install:
	(cd ${WRKSRC} && ${MAKE} install-data DESTDIR=${STAGEDIR})

.include <bsd.port.mk>
