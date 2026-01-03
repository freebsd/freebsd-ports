PORTNAME=	libxcrypt
DISTVERSION=	4.5.2
CATEGORIES=	security
MASTER_SITES=	https://github.com/besser82/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extended crypt library for descrypt, md5crypt, bcrypt, and others
WWW=		https://github.com/besser82/libxcrypt

LICENSE=	LGPL21

USES=		gmake libtool pathfix perl5 tar:xz
USE_PERL5=	build
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CFLAGS+=	-Wno-gnu-statement-expression

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFIGURE_ARGS=	--disable-static

.include <bsd.port.mk>
