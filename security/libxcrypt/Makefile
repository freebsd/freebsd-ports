PORTNAME=	libxcrypt
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.26
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extended crypt library for descrypt, md5crypt, bcrypt, and others

LICENSE=	LGPL21

USES=		autoreconf gmake libtool

USE_GITHUB=	yes
GH_ACCOUNT=	besser82

GNU_CONFIGURE=	yes

USE_LDCONFIG=	yes

CFLAGS+=	-Wno-gnu-statement-expression
CONFIGURE_ARGS=	--disable-static

.include <bsd.port.mk>
