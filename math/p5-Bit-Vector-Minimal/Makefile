# New ports collection makefile for:	Bit-Vector-Minimal
# Date created:				Wed Jul 28 11:59:00 2004
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	Bit-Vector-Minimal
PORTVERSION=	1.0
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Bit
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	"Object-oriented wrapper around Perl's vec()"

PERL_CONFIGURE=	yes

MAN3=		Bit::Vector::Minimal.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	"This port requires perl 5.6 or above."
.endif

.include <bsd.port.post.mk>
