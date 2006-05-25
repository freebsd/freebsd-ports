# New ports collection makefile for:	p5-Text-Unaccent
# Date created:				25 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Unaccent
PORTVERSION=	1.08
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Remove accents from a string

MAN3=	Text::Unaccent.3

USE_ICONV=	yes
PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl 5.6.0.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
