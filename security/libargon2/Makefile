# Created by: Christopher Hall <hsw@bitmark.com>
# $FreeBSD$

PORTNAME=	libargon2
PORTVERSION=	20160530
CATEGORIES=	security devel

MAINTAINER=	hsw@bitmark.com
COMMENT=	Memory hard password hashing program and library

LICENSE=	CC0-1.0

USE_GITHUB=	yes
GH_ACCOUNT=	P-H-C
GH_PROJECT=	phc-winner-argon2
GH_TAGNAME=	4625cc5

USES=		gmake
USE_LDCONFIG=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/argon2.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libargon2.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libargon2.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/argon2 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/argon2.1  ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
