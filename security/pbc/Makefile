# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pbc
PORTVERSION=	0.5.13
CATEGORIES=	security
MASTER_SITES=	http://crypto.stanford.edu/pbc/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of pairing-based cryptosystems

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp

GNU_CONFIGURE=	yes
USE_GCC=	4.6+
USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
