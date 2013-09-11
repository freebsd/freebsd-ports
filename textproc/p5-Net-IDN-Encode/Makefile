# Created by: Timur Bakeyev <bat@cpan.org>
# $FreeBSD$

PORTNAME=	Net-IDN-Encode
PORTVERSION=	2.003
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Internationalizing Domain Names in Applications (RFC 3490)

RUN_DEPENDS=	p5-Net-IDN-Nameprep>=0:${PORTSDIR}/converters/p5-Net-IDN-Nameprep
BUILD_DEPENDS:=	${RUN_DEPENDS} \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	modbuild

MAN3=		Net::IDN::Encode.3 Net::IDN::Overview.3 Net::IDN::Punycode.3 \
		Net::IDN::Punycode::PP.3 Net::IDN::Standards.3 \
		Net::IDN::UTS46.3 Net::IDN::UTS46::_Mapping.3

.include <bsd.port.mk>
