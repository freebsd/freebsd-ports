# $FreeBSD$

PORTNAME=	libyubikey
PORTVERSION=	1.11
CATEGORIES=	security devel
MASTER_SITES=	http://opensource.yubico.com/yubico-c/releases/

MAINTAINER=	matt@mjslabs.com
COMMENT=	Library for decrypting and parsing YubiKey One-Time Passwords

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	bin/modhex \
		bin/ykgenerate \
		bin/ykparse \
		include/yubikey.h \
		lib/libyubikey.la \
		lib/libyubikey.so \
		lib/libyubikey.so.1 \
		man/man1/modhex.1.gz \
		man/man1/ykgenerate.1.gz \
		man/man1/ykparse.1.gz

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		STATIC

STATIC_CONFIGURE_ENABLE=	static
STATIC_PLIST_FILES=		lib/libyubikey.a

regression-test: build
	@(cd ${WRKSRC}; ${MAKE} check)

.include <bsd.port.mk>
