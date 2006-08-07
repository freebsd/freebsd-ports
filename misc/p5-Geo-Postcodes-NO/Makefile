# New ports collection makefile for:	p5-Geo-Postcodes-NO
# Date created:		2006-07-19
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Geo-Postcodes-NO
PORTVERSION=	0.03
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Geo
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Norwegian postcodes with associated information

RUN_DEPENDS=	p5-Geo-Postcodes>=0.03:${PORTSDIR}/misc/p5-Geo-Postcodes

PERL_CONFIGURE=	yes

MAN3=		Geo::Postcodes::NO.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600	# Inherited from misc/p5-Geo-Postcodes
IGNORE=		requires Perl 5.6.0 or newer. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
