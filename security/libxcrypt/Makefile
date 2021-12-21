PORTNAME=	libxcrypt
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.27
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extended crypt library for descrypt, md5crypt, bcrypt, and others

LICENSE=	LGPL21

USES=		autoreconf gmake libtool
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	besser82

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

CFLAGS+=	-Wno-gnu-statement-expression

TEST_TARGET=	check

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcrypt.so.2.0.0

.include <bsd.port.mk>
