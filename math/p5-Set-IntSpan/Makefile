# New ports collection makefile for:	p5-Set-IntSpan
# Date created:		February 7, 1998
# Whom:			Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	Set-IntSpan
PORTVERSION=	1.09
PORTREVISION=	0
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Set
PKGNAMEPREFIX=	p5-

MAINTAINER=	croyle@gelemna.org
COMMENT=	Manages sets of integers

PERL_CONFIGURE=	yes

MAN3=		Set::IntSpan.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	${PERL} -pi -e 's/^our (\S+)/use vars qw($$1); $$1/' ${WRKSRC}/IntSpan.pm
.endif

.include <bsd.port.post.mk>
