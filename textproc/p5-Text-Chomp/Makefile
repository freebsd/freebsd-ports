# New ports collection makefile for:	p5-Text-Chomp
# Date created:				08 Oct 2005
# Whom:					Jason Burgess <dev@fenux.net>
#
# $FreeBSD$
#

PORTNAME=	Text-Chomp
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A module implementing a portable chomp

PERL_CONFIGURE=	yes

MAN3=		Text::Chomp.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500806
IGNORE=		needs Perl 5.8.6 or above (lang/perl5.8)
.endif

.include <bsd.port.post.mk>
