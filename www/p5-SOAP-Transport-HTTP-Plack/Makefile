# $FreeBSD$

PORTNAME=	SOAP-Transport-HTTP-Plack
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension SOAP::Lite transport for Plack

RUN_DEPENDS=	\
	p5-SOAP-Lite>0:${PORTSDIR}/net/p5-SOAP-Lite
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	SOAP::Transport::HTTP::Plack.3 \
	XMLRPC::Transport::HTTP::Plack.3

.include <bsd.port.mk>
