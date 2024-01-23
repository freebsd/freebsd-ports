PORTNAME=	pbc
PORTVERSION=	0.5.14
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://crypto.stanford.edu/pbc/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of pairing-based cryptosystems
WWW=		https://crypto.stanford.edu/pbc/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Abandonware, last release in 2013 and no development since
EXPIRATION_DATE=2024-02-29

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		bison libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CFLAGS=$$|| ; \
		 s|-O3||' ${WRKSRC}/configure

.include <bsd.port.mk>
