# Created by: Philip M. Gollucci <pgollucci@p6m7g8.com>
# $FreeBSD$

PORTNAME=	Text-ParseWords
PORTVERSION=	3.29
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse text into an array of tokens or array of arrays

MAKE_JOBS_SAFE=	yes

PERL_CONFIGURE=	yes

MAN3=	Text::ParseWords.3

PLIST_FILES=	%%SITE_PERL%%/Text/ParseWords.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Text/ParseWords/.packlist

PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Text/ParseWords
PLIST_DIRSTRY=	%%SITE_PERL%%/Text \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Text

.include <bsd.port.mk>
