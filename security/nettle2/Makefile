# ex:ts=8
# New ports collection makefile for:	nettle
# Date created:			Dec 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	nettle
PORTVERSION=	1.7
CATEGORIES=	security
MASTER_SITES=	http://www.lysator.liu.se/~nisse/archive/ \
		ftp://ftp.lysator.liu.se/pub/security/lsh/

MAINTAINER=	jim@corebsd.or.id
COMMENT=	A low-level cryptographic library

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		MAKEINFO="makeinfo --no-split"
LDFLAGS+=	-L${LOCALBASE}/lib

post-extract:
	@${RM} -f ${WRKSRC}/nettle.info*

.include <bsd.port.mk>
