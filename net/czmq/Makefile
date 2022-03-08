# Created by: Andrew Thompson <thompsa@FreeBSD.org>

PORTNAME=	czmq
PORTVERSION=	4.1.1
CATEGORIES=	net
MASTER_SITES=	https://github.com/zeromq/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	High-level C Binding for ZeroMQ

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzmq.so:net/libzmq4

USES=		autoreconf libtool pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libzmq=${LOCALBASE} \
		--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig \
		--without-docs

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CFLAGS+=	-Wno-error

.include <bsd.port.mk>
