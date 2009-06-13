# New ports collection makefile for:	p5-Maypole-Component
# Date created:				Aug 26 2004
# Whom:					Marc G. Fournier
#
# $FreeBSD$

PORTNAME=	Maypole-Component
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/S/SI/SIMON/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Run Maypole sub-requests as components

PERL_CONFIGURE=	yes

MAN3=		Maypole::Component.3

post-patch:
	@${PERL} -pi -e 's/use 5.006/use 5.005/' ${WRKSRC}/Makefile.PL
	@${PERL} -pi -e 's/^our (\S+)/use vars qw($$1); $$1/' ${WRKSRC}/Component.pm

.include <bsd.port.mk>
