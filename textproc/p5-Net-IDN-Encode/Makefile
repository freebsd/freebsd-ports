# New ports collection makefile for:	p5-Net-IDN-Encode
# Date created:				10 Dec 2010
# Whom:					Timur Bakeyev <bat@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Net-IDN-Encode
PORTVERSION=	1.100
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	timur@FreeBSD.org
COMMENT=	Internationalizing Domain Names in Applications (RFC 3490)

RUN_DEPENDS=	${SITE_PERL}/Net/IDN/Nameprep.pm:${PORTSDIR}/converters/p5-Net-IDN-Nameprep
BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/Test/NoWarnings.pm:${PORTSDIR}/devel/p5-Test-NoWarnings

PERL_MODBUILD=	yes

MAN3=		Net::IDN::Encode.3 Net::IDN::Punycode.3 Net::IDN::Punycode::PP.3

.include <bsd.port.mk>
