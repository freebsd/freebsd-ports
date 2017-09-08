# Created by: Andrew Thompson <thompsa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	czmq
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.zeromq.org/

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	High-level C Binding for ZeroMQ

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzmq.so:net/libzmq4

USES=		autoreconf libtool pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libzmq=${LOCALBASE} \
		--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

MAKE_ENV=	V=1
CPPFLAGS+=	-Wno-error

.include <bsd.port.mk>
