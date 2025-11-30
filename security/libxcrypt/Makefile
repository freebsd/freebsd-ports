PORTNAME=	libxcrypt
DISTVERSIONPREFIX=	v
DISTVERSION=	4.5.2
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extended crypt library for descrypt, md5crypt, bcrypt, and others
WWW=		https://github.com/besser82/libxcrypt

LICENSE=	LGPL21

USES=		autoreconf gmake libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	besser82

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--disable-static

CFLAGS+=	-Wno-gnu-statement-expression

TEST_TARGET=	check

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcrypt.so.2.0.0

# tests as of 4.5.2:
# TOTAL: 52
# PASS:  51
# SKIP:  1
# XFAIL: 0
# FAIL:  0
# XPASS: 0
# ERROR: 0

.include <bsd.port.mk>
