# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	libscrypt
PORTVERSION=	1.1
CATEGORIES=	security

MAINTAINER=	horia@racoviceanu.com
COMMENT=	C library for the scrypt key derivation function

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	technion
GH_COMMIT=	49f9136
GH_TAGNAME=	v${PORTVERSION}

PLIST_FILES+=	include/libscrypt.h \
		lib/libscrypt.a \
		lib/libscrypt.so \
		lib/libscrypt.so.0

post-patch:
	${REINPLACE_CMD} -e '/^CC=gcc/d' -e '/CFLAGS=/s,$$, ${CFLAGS},' \
	    -e 's,/usr/local,${PREFIX},' ${WRKSRC}/Makefile

regression-test: build
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check)

.include <bsd.port.mk>
