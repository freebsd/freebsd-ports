# New ports collection makefile for:	p5-Catalyst-Plugin-Pluggable
# Date created:				2005-09-02
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Pluggable
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/S/SR/SRI
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	A plugin for pluggable Catalyst applications

BUILD_DEPENDS=	p5-Catalyst>=5.50:${PORTSDIR}/www/p5-Catalyst
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Plugin::Pluggable.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500801
IGNORE=	requires at least Perl 5.8.1. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
