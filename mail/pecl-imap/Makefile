PORTNAME=	imap
DISTVERSION=	1.0.3
CATEGORIES=	mail

MAINTAINER=	mickael.maillot@gmail.com
COMMENT=	PHP extension to operate with the IMAP protocol
WWW=		https://github.com/php/pecl-mail-imap

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libc-client.so.2010:mail/panda-cclient

USES=		php:pecl localbase ssl
IGNORE_WITH_PHP=	82 83

CONFIGURE_ARGS+=	--with-imap-ssl=${OPENSSLBASE} --with-imap=${LOCALBASE}
CONFIGURE_ENV+=	OPENSSL_CFLAGS="-I${OPENSSLINC}" OPENSSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"

TEST_TARGET=	test

LDFLAGS+=	-L${OPENSSLLIB} -lcrypto -lssl

.include <bsd.port.mk>
