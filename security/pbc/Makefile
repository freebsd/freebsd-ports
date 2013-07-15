# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pbc
PORTVERSION=	0.5.14
CATEGORIES=	security
MASTER_SITES=	http://crypto.stanford.edu/pbc/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of pairing-based cryptosystems

LICENSE=	LGPL3

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp

USES=		bison
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CFLAGS=$$|| ; \
		 s|-O3||' ${WRKSRC}/configure

.include <bsd.port.mk>
