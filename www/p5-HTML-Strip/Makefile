# New ports collection makefile for:	p5-HTML-Strip
# Date Created:				13 Oct 2003
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	HTML-Strip
PORTVERSION=	1.04
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for strip HTML tag

PERL_CONFIGURE=	yes

MAN3=		HTML::Strip.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	The port needs at least perl 5.6. Install lang/perl5.8 or lang/perl5 and try again
.endif

.include <bsd.port.post.mk>
