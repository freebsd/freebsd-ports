PORTNAME=	libzmq2
DISTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	https://github.com/zeromq/zeromq2-x/releases/download/${DISTVERSIONFULL}/zeromq-2.2.0.tar.gz
DISTNAME=	zeromq-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	ZeroMQ core library (Version 2)
WWW=		https://www.zeromq.org/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

DEPRECATED=	Last release was in 2012 switch to libzmq3
EXPIRATION_DATE=	2024-03-31

USES=		libtool pathfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFLICTS=	libzmq[^2]

OPTIONS_DEFINE=		DEBUG

DEBUG_CONFIGURE_ON=	--enable-debug

.include <bsd.port.mk>
