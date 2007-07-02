# New ports collection makefile for:	www/p5-Catalyst-Plugin-Static-Simple
# Date created:				July 11, 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Static-Simple
PORTVERSION=	0.18
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Make serving static pages painless

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.70:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-MIME-Types>=1.15:${PORTSDIR}/mail/p5-MIME-Types
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::Static::Simple.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif
.include <bsd.port.post.mk>
