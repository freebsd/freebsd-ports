# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	Lingua-EN-AddressParse
PORTVERSION=	1.18
CATEGORIES=	textproc perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to manipulate geographical addresses

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Lingua-EN-NameParse>=1.24:${PORTSDIR}/textproc/p5-Lingua-EN-NameParse \
		p5-Locale-SubCountry>=1.41:${PORTSDIR}/misc/p5-Locale-SubCountry \
		p5-Parse-RecDescent>=1:${PORTSDIR}/devel/p5-Parse-RecDescent
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
