# $FreeBSD$

PORTNAME=	Lingua-EN-AddressParse
PORTVERSION=	1.27
CATEGORIES=	textproc perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to manipulate geographical addresses

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Lingua-EN-NameParse>=1.24:textproc/p5-Lingua-EN-NameParse \
		p5-Locale-SubCountry>=1.41:misc/p5-Locale-SubCountry \
		p5-Parse-RecDescent>=1:devel/p5-Parse-RecDescent
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-JSON>=0:converters/p5-JSON

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
