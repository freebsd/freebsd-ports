# New ports collection makefile for:	www/p5-Catalyst-Plugin-HTML-Widget
# Date created:				21 Nov 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-HTML-Widget
PORTVERSION=	1.1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/S/SR/SRI
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	HTML Widget And Validation Framework

BUILD_DEPENDS=	p5-Catalyst>=5.5:${PORTSDIR}/www/p5-Catalyst \
		p5-HTML-Widget>=0:${PORTSDIR}/www/p5-HTML-Widget
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::HTML::Widget.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500801
IGNORE=	requires Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
