# $FreeBSD$

PORTNAME=	yubico-piv-tool
PORTVERSION=	1.4.0
#PORTREVISION=	0
CATEGORIES=	security
MASTER_SITES=	https://developers.yubico.com/yubico-piv-tool/Releases/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Yubico PIV tool

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPENSSL_CFLAGS="$(OPENSSL_CFLAGS)" \
		OPENSSL_LIBS="-L$(OPENSSLLIB) -lcrypto"
OPENSSL_CFLAGS=-I$(OPENSSLINC)

PLIST_FILES=	bin/yubico-piv-tool \
		include/ykcs11/ykcs11-version.h \
		include/ykpiv/ykpiv-version.h \
		include/ykpiv/ykpiv.h \
		lib/libykcs11.a \
		lib/libykcs11.so \
		lib/libykcs11.so.1 \
		lib/libykcs11.so.1.3.2 \
		lib/libykpiv.a \
		lib/libykpiv.so \
		lib/libykpiv.so.1 \
		lib/libykpiv.so.1.3.2 \
		libdata/pkgconfig/ykcs11.pc \
		libdata/pkgconfig/ykpiv.pc \
		man/man1/yubico-piv-tool.1.gz

.include <bsd.port.mk>
