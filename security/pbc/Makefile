# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pbc
PORTVERSION=	0.5.14
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://crypto.stanford.edu/pbc/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of pairing-based cryptosystems

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

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
