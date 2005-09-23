# New ports collection makefile for:	Lingua::EN::Squeeze
# Date created:				31 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Lingua-EN-Squeeze
PORTVERSION=	2005.0216
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Shorten text to minimum syllables by using hash table

# requires ExtUtils::MakeMaker 6.25 or above
BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/MakeMaker.pm:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker

PERL_CONFIGURE=	yes

MAN3=	Lingua::EN::Squeeze.3

.include <bsd.port.pre.mk>

# ExtUtils::MakeMaker requires perl 5.6.1
.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.1 or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
