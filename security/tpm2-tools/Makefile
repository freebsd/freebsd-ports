PORTNAME=	tpm2-tools
DISTVERSION=	5.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://github.com/tpm2-software/tpm2-tools/releases/download/${DISTVERSION}/

MAINTAINER=	tstruk@gmail.com
COMMENT=	TPM2 tools

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libtss2-esys.so:security/tpm2-tss \
		libcurl.so:ftp/curl \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		compiler:c11 gmake libtool pkgconfig ssl

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CRYPTO_CFLAGS="-I${OPENSSLINC}" CRYPTO_LIBS="-L${OPENSSLLIB} -lcrypto"
CONFIGURE_ARGS=	--disable-hardening --disable-fapi

.include <bsd.port.mk>
