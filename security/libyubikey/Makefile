PORTNAME=	libyubikey
PORTVERSION=	1.13
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	https://developers.yubico.com/yubico-c/Releases/

MAINTAINER=	matt@mjslabs.com
COMMENT=	Library for decrypting and parsing YubiKey One-Time Passwords
WWW=		https://developers.yubico.com/yubico-c/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_FILES=	bin/modhex \
		bin/ykgenerate \
		bin/ykparse \
		include/yubikey.h \
		lib/libyubikey.so \
		lib/libyubikey.so.0 \
		lib/libyubikey.so.0.1.7 \
		share/man/man1/modhex.1.gz \
		share/man/man1/ykgenerate.1.gz \
		share/man/man1/ykparse.1.gz

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		STATIC

STATIC_CONFIGURE_ENABLE=	static
STATIC_PLIST_FILES=		lib/libyubikey.a

.include <bsd.port.mk>
