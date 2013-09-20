# Created by: gugu
# $FreeBSD$

PORTNAME=	XML-RPC-Fast
PORTVERSION=	0.8
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mons@cpan.org
COMMENT=	Fast and modular implementation for an XML-RPC client and server

BUILD_DEPENDS=	p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-WWW-Curl>=0:${PORTSDIR}/www/p5-WWW-Curl \
		p5-XML-Hash-LX>=0.05:${PORTSDIR}/textproc/p5-XML-Hash-LX \
		p5-XML-LibXML>=1.58:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	configure

MAN3=		XML::RPC::Enc.3 \
		XML::RPC::Enc::LibXML.3 \
		XML::RPC::Fast.3 \
		XML::RPC::README.3 \
		XML::RPC::UA.3 \
		XML::RPC::UA::AnyEvent.3 \
		XML::RPC::UA::AnyEventSync.3 \
		XML::RPC::UA::Curl.3 \
		XML::RPC::UA::LWP.3

NO_STAGE=	yes
.include <bsd.port.mk>
