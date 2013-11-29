# Created by: Andrew Thompson <thompsa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	czmq
PORTVERSION=	2.0.3
CATEGORIES=	net
MASTER_SITES=	http://download.zeromq.org/

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	High-level C Binding for ZeroMQ

LICENSE=	LGPL3

LIB_DEPENDS=	libzmq.so:${PORTSDIR}/net/libzmq4

USES=		pathfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libzmq=${LOCALBASE}

regression-test: build
	@cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
