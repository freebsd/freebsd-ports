# Created by: Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
# $FreeBSD$

PORTNAME=	XML-Stream
DISTVERSION=	1.23_06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAPATRICK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	XML::Stream provides you with access to XML Stream

BUILD_DEPENDS=	p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL
RUN_DEPENDS=	p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL

USES=		perl5
USE_PERL5=	configure

MAN3=		XML::Stream.3 \
		XML::Stream::IO::Select::Win32.3 \
		XML::Stream::Namespace.3 \
		XML::Stream::Node.3 \
		XML::Stream::Parser.3 \
		XML::Stream::Parser::DTD.3 \
		XML::Stream::Tree.3

.include <bsd.port.mk>
