# New ports collection makefile for:	p5-Socket
# Date created:		2008-05-30
# Whom:			BluePex Security Solutions <freebsd-ports@bluepex.com>
#
# $FreeBSD$
#

PORTNAME=	Socket
PORTVERSION=	1.5
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsd-ports@bluepex.com
COMMENT=	Load the C socket.h defines and structure manipulators

PERL_CONFIGURE=	yes

MAN3=	Socket.3

post-patch:
	@${REINPLACE_CMD} -e '/MAN3PODS/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
