PORTNAME=	pkcs11-dump
PORTVERSION=	0.3.4
CATEGORIES=	security
MASTER_SITES=	https://github.com/alonbl/pkcs11-dump/releases/download/pkcs11-dump-${PORTVERSION}/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Allow dumping PKCS\#11 token content

LICENSE=	GPLv2

USES=		tar:bzip2 ssl dos2unix
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto"

PLIST_FILES=	bin/pkcs11-dump \
		man/man1/pkcs11-dump.1.gz

post-patch:
	@${REINPLACE_CMD} 's|install-data-am: install-dist_docDATA|install-data-am:|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
