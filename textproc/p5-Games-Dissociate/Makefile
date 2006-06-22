# New ports collection makefile for:	p5-Games-Dissociate
# Date created:				21 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Games-Dissociate
PORTVERSION=	0.17
CATEGORIES=	textproc games perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/A/AV/AVIF
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	A Dissociated Press algorithm and filter

MAN3=	Games::Dissociate.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
#IGNORE=	requires at least Perl 5.6.  Please install lang/perl5.8 and try again
#post-patch:
#	@${PERL} -pi -e 's/our ([^ ]+)/use vars qw($$1); $$1/g;' \
#		     -e '$$_ = "" if /use warnings/;' \
#		${WRKSRC}/lib/GraphViz/Traverse.pm \
#		${WRKSRC}/t/*.t \
#		${WRKSRC}/Makefile.PL
.endif

.include <bsd.port.post.mk>
