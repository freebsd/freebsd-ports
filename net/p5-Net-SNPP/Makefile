# Created by: devin@spamcop.net
# $FreeBSD$

PORTNAME=	Net-SNPP
PORTVERSION=	1.17
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Net::SNPP - Perl Simple Network Pager Protocol Client

PERL_CONFIGURE=	yes

MAN3=		Net::SNPP.3 \
		Net::SNPP::Server.3

post-patch:
	@${REINPLACE_CMD} -i '' -e '/warnings/d' \
		${WRKSRC}/lib/Net/SNPP/Server.pm

.include <bsd.port.mk>
