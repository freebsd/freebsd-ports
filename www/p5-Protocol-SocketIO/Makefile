# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Protocol-SocketIO
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VTI
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Socket.IO protocol implementation

LICENSE=	ART20

BUILD_DEPENDS=	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

MAN3=		Protocol::SocketIO.3 \
		Protocol::SocketIO::Handshake.3 \
		Protocol::SocketIO::Message.3 \
		Protocol::SocketIO::Path.3

.include <bsd.port.mk>
