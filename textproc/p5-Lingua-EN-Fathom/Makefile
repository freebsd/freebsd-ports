# New ports collection makefile for:	textproc/p5-Lingua-EN-Fathom
# Date created:				28 February 2006
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Lingua-EN-Fathom
PORTVERSION=	1.09
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Lingua::EN::Fathom - Measure readability of English text

BUILD_DEPENDS=	${SITE_PERL}/Lingua/EN/Syllable.pm:${PORTSDIR}/textproc/p5-Lingua-EN-Syllable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Lingua::EN::Fathom.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
