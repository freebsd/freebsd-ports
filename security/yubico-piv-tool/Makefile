# $FreeBSD$

PORTNAME=	yubico-piv-tool
PORTVERSION=	2.0.0
#PORTREVISION=	0
CATEGORIES=	security
MASTER_SITES=	https://developers.yubico.com/yubico-piv-tool/Releases/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Yubico PIV tool

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/check.pc:devel/check
LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

USES=		compiler gmake libtool pathfix pkgconfig ssl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPENSSL_CFLAGS="${OPENSSL_CFLAGS}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto"
OPENSSL_CFLAGS=	-I${OPENSSLINC}

PLIST_FILES=	bin/yubico-piv-tool \
		include/ykpiv/ykpiv-version.h \
		include/ykpiv/ykpiv.h \
		lib/libykcs11.a \
		lib/libykcs11.so \
		lib/libykcs11.so.1 \
		lib/libykcs11.so.1.6.0 \
		lib/libykpiv.a \
		lib/libykpiv.so \
		lib/libykpiv.so.1 \
		lib/libykpiv.so.1.6.0 \
		libdata/pkgconfig/ykcs11.pc \
		libdata/pkgconfig/ykpiv.pc \
		man/man1/yubico-piv-tool.1.gz

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
post-patch:
	@${REINPLACE_CMD} -e '/#pragma GCC diagnostic/d' \
		${WRKSRC}/lib/ykpiv.c \
		${WRKSRC}/lib/util.c \
		${WRKSRC}/lib/internal.c \
		${WRKSRC}/tool/yubico-piv-tool.c
.endif

.include <bsd.port.post.mk>
