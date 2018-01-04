# Created by: Christopher Hall <hsw@bitmark.com>
# $FreeBSD$

PORTNAME=	libargon2
PORTVERSION=	20161029
PORTREVISION=	1
CATEGORIES=	security devel

MAINTAINER=	hsw@bitmark.com
COMMENT=	Memory hard password hashing program and library

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	P-H-C
GH_PROJECT=	phc-winner-argon2

MAKE_JOBS_UNSAFE=	yes
LIBARGON2=	libargon2.so.0
MAKE_ARGS+=	SO_LDFLAGS="-shared -Wl,-soname=${LIBARGON2}"

# remove multiarch as this is only for Linux
SUBST=		s/@HOST_MULTIARCH@//g;
SUBST+=		s/@UPSTREAM_VER@/${PORTVERSION}/g;
SUBST+=		s@/usr@${PREFIX}@g;
SUBST+=		s/-lrt//g;s/-ldl//g;
SUBST+=		s@Cflags:@Cflags: -I$${includedir}/@;

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/argon2.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libargon2.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libargon2.so ${STAGEDIR}${PREFIX}/lib/libargon2.so.0
	${RLN} ${STAGEDIR}${PREFIX}/lib/${LIBARGON2} ${STAGEDIR}${PREFIX}/lib/libargon2.so
	${INSTALL_PROGRAM} ${WRKSRC}/argon2 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/argon2.1  ${STAGEDIR}${PREFIX}/man/man1
	${SED} '${SUBST}' < ${WRKSRC}/libargon2.pc > ${STAGEDIR}${PREFIX}/libdata/pkgconfig/libargon2.pc

.include <bsd.port.mk>
