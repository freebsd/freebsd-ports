# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	libscrypt
PORTVERSION=	1.14
CATEGORIES=	security

MAINTAINER=	horia@racoviceanu.com
COMMENT=	C library for the scrypt key derivation function

LICENSE=	BSD

NO_STAGE=	yes
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	technion
GH_COMMIT=	8e6966e
GH_TAGNAME=	${GH_COMMIT}

PLIST_FILES=	include/libscrypt.h \
		lib/libscrypt.a \
		lib/libscrypt.so \
		lib/libscrypt.so.0

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^CC=gcc/d' -e '/CFLAGS=/s,$$, ${CFLAGS},' \
		-e 's,/usr/local,${PREFIX},' -e 's,install: library,& install-static,' \
		-e 's,$$(LDFLAGS),,' ${WRKSRC}/Makefile

regression-test: build
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check)

.if ${ARCH} == i386
CCVERSION!= ${CC} --version
.if !empty(CCVERSION:tl:M*gcc*)
CFLAGS+=    -fno-stack-protector
.endif
.endif

.include <bsd.port.post.mk>
