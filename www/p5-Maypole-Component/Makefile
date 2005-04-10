# New ports collection makefile for:	p5-Maypole-Component
# Date created:				Aug 26 2004
# Whom:					Marc G. Fournier
#
# $FreeBSD$

PORTNAME=	Maypole-Component
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/S/SI/SIMON/
PKGNAMEPREFIX=	p5-

MAINTAINER=	scrappy@FreeBSD.org
COMMENT=	Run Maypole sub-requests as components

PERL_CONFIGURE=	yes

MAN3=		Maypole::Component.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not build on FreeBSD 4.x"
.endif

.include <bsd.port.post.mk>
