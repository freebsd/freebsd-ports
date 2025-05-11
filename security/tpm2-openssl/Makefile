PORTNAME=	tpm2-openssl
DISTVERSION=	1.3.0
CATEGORIES=	security
MASTER_SITES=	https://github.com/tpm2-software/tpm2-openssl/releases/download/${DISTVERSION}/

MAINTAINER=	blackye@gmail.com
COMMENT=	Provider for integration of TPM 2.0 into OpenSSL 3.x
WWW=		https://github.com/tpm2-software/tpm2-openssl

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=    libtss2-esys.so:security/tpm2-tss
RUN_DEPENDS=    tpm2-abrmd:security/tpm2-abrmd

USES=		gmake libtool pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=/usr/local
GNU_CONFIGURE_LIBPREFIX=${PREFIX}/lib
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INSTALL_TARGET=	install-strip


.include <bsd.port.mk>
