# New ports collection makefile for:	p5-Protocol-SocketIO
# Date created:		2012-01-23
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Protocol-SocketIO
PORTVERSION=	0.00.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VTI
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Socket.IO protocol implementation

BUILD_DEPENDS=	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON
RUN_DEPENDS=	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON

PERL_CONFIGURE=	yes
REINPLACE_ARGS=	-i ''

MAN3=		Protocol::SocketIO.3 \
		Protocol::SocketIO::Handshake.3 \
		Protocol::SocketIO::Message.3 \
		Protocol::SocketIO::Path.3

post-patch:
	@${REINPLACE_CMD} -e 's|Protocol::SocketiO|Protocol::SocketIO|' \
		${WRKSRC}/lib/Protocol/SocketIO.pm ${WRKSRC}/lib/Protocol/SocketIO/*.pm
	@${REINPLACE_CMD} -e 's|Protocol::SocketIO::Handhskae|Protocol::SocketIO::Handshake|' \
		${WRKSRC}/lib/Protocol/SocketIO/Handshake.pm

.include <bsd.port.mk>
