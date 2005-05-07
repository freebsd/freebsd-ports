# ex:ts=8
# Ports collection makefile for:	p5-Text-Textile
# Date created:			May 4, 2005
# Whom:				Travis Campbell <hcoyote@ghostar.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Textile
PORTVERSION=	0.7
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/T/TO/TOMI
PKGNAMEPREFIX=	p5-

MAINTAINER=	hcoyote@ghostar.org
COMMENT=	A perl-based implementation of the Textile syntax by Dean Allen

PERL_MODBUILD=	yes

MAN3=	Text::Textile.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500601
IGNORE=	requires Perl 5.6. Install lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
