PORTNAME=	tlsdate
PORTVERSION=	0.0.13
DISTVERSIONPREFIX=	tlsdate-
PORTREVISION=	5
CATEGORIES=	sysutils

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Secure parasitic rdate replacement

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		autoreconf libtool pkgconfig ssl

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
GNU_CONFIGURE=	yes
TEST_TARGET=	test

PORTDOCS=	*

USE_GITHUB=	yes
GH_ACCOUNT=	ioerror

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
