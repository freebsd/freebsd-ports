# Created by: Takefu <takefu@airport.fm>
# $FreeBSD$

PORTNAME=	SOAP-Transport-HTTP-Plack
PORTVERSION=	0.03
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	takefu@airport.fm
COMMENT=	Transport for Plack PSGI toolkit

BUILD_DEPENDS=	p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

MAN3=		SOAP::Transport::HTTP::Plack.3 \
		XMLRPC::Transport::HTTP::Plack.3

.include <bsd.port.mk>
