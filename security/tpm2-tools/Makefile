# $FreeBSD$

PORTNAME=	tpm2-tools
DISTVERSION=	4.0
CATEGORIES=	security
MASTER_SITES=	https://github.com/tpm2-software/tpm2-tools/releases/download/${DISTVERSION}/

MAINTAINER=	tstruk@gmail.com
COMMENT=	TPM2 tools

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libtss2-esys.so:security/tpm2-tss \
		libcurl.so:ftp/curl

USES=	gmake libtool pkgconfig ssl

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CRYPTO_CFLAGS="-I${OPENSSLINC}" CRYPTO_LIBS="-L${OPENSSLLIB} -lcrypto"
CONFIGURE_ARGS=	--disable-hardening

BROKEN_SSL=	openssl

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200085
BROKEN_SSL+=	base
.endif

.include <bsd.port.post.mk>
