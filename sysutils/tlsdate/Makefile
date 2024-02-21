PORTNAME=	tlsdate
PORTVERSION=	0.0.13
DISTVERSIONPREFIX=	tlsdate-
PORTREVISION=	5
CATEGORIES=	sysutils

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Secure parasitic rdate replacement
WWW=		https://github.com/ioerror/tlsdate

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		autoreconf libtool pkgconfig ssl

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
TEST_TARGET=	test

USE_GITHUB=	yes
GH_ACCOUNT=	ioerror

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
