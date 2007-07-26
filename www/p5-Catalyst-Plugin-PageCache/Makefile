# Ports collection makefile for:	p5-Catalyst-Plugin-PageCache
# Date created:				Dec 19, 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-PageCache
PORTVERSION=	0.16
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Cache the output of entire pages

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::PageCache.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500801
IGNORE=	requires at least Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
