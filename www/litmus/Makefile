PORTNAME=	litmus
DISTVERSION=	0.13
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/neon/litmus/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	WebDAV server protocol compliance test suite

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libneon.so:www/neon \
		libk5crypto.so:security/krb5

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ssl --with-neon=${LOCALBASE}

post-patch:
	@${REINPLACE_CMD} -e 's|25 26 27 28 29|& 30 31 32|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
