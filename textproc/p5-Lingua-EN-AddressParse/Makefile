# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	Lingua-EN-AddressParse
PORTVERSION=	1.16
CATEGORIES=	textproc perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to manipulate geographical addresses

RUN_DEPENDS=	p5-Lingua-EN-NameParse>=0:${PORTSDIR}/textproc/p5-Lingua-EN-NameParse \
		p5-Locale-SubCountry>=0:${PORTSDIR}/misc/p5-Locale-SubCountry \
		p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Lingua::EN::AddressParse.3 \
		Lingua::EN::AddressParse::Grammar.3

.include <bsd.port.mk>
