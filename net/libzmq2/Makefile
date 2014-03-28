# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	libzmq2
PORTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://download.zeromq.org/
DISTNAME=	zeromq-${DISTVERSION}

MAINTAINER=	gslin@gslin.org
COMMENT=	ZeroMQ core library (Version 2)

LICENSE=	LGPL3

USES=		pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CONFLICTS=	libzmq[^2]-[0-9]*

OPTIONS_DEFINE=		DEBUG
DEBUG_CONFIGURE_ON=	--enable-debug

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
WITH_DEBUG=	yes
.endif

post-patch:
	${REINPLACE_CMD} -e '9s|$$| -pthread|' ${WRKSRC}/src/libzmq.pc.in

regression-test: build
	cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
