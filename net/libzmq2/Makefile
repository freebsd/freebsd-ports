# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	libzmq2
PORTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://download.zeromq.org/
DISTNAME=	zeromq-${DISTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	ZeroMQ core library (Version 2)

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool pathfix
USE_LDCONFIG=	yes
TEST_TARGET=	check

CONFLICTS=	libzmq[^2]-[0-9]*

OPTIONS_DEFINE=		DEBUG
DEBUG_CONFIGURE_ON=	--enable-debug

.include <bsd.port.mk>
