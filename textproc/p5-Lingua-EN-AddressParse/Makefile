# New ports collection makefile for:	Lingua::EN::AddressParse
# Date created:				30 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Lingua-EN-AddressParse
PORTVERSION=	1.15
CATEGORIES=	textproc perl5 geography
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to manipulate geographical addresses

BUILD_DEPENDS=	${SITE_PERL}/Lingua/EN/NameParse.pm:${PORTSDIR}/textproc/p5-Lingua-EN-NameParse \
		${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent \
		${SITE_PERL}/Locale/SubCountry.pm:${PORTSDIR}/misc/p5-Locale-SubCountry
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Lingua::EN::AddressGrammar.3 \
	Lingua::EN::AddressParse.3

.include <bsd.port.mk>
