PORTNAME=	gnupg-pkcs11-scd
DISTVERSION=	0.9.2
CATEGORIES=	security
MASTER_SITES=	https://github.com/alonbl/${PORTNAME}/releases/download/${DISTNAME}/

MAINTAINER=	mat@FreeBSD.org
COMMENT=	PKCS\#11 enabled gnupg scd

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls \
		libgpg-error.so:security/libgpg-error \
		libpkcs11-helper.so:security/pkcs11-helper

USES=		pkgconfig ssl tar:bz2

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-libassuan-prefix=${LOCALBASE} \
		--with-libgcrypt-prefix=${LOCALBASE} \
		--with-libgpg-error-prefix=${LOCALBASE} \
		--without-docs \
		--without-openssl

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/gnupg-pkcs11-scd/gnupg-pkcs11-scd.conf.example \
		${STAGEDIR}${EXAMPLESDIR}/gnupg-pkcs11-scd.conf

.include <bsd.port.mk>
