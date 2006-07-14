# New ports collection makefile for:	p5-Text-Tags
# Date created:		2006-07-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Tags
PORTVERSION=	0.04
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Parses folksonomy space-separated tags

PERL_CONFIGURE=	yes

MAN3=		Text::Tags.3 Text::Tags::Parser.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
