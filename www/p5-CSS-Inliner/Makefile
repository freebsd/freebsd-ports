# New ports collection makefile for:    p5-HTML-Query
# Date created:                         Sat Oct 10 17:28:20 EDT 2009
# Whom:                                 Vivek Khera <vivek@khera.org>
#
# $FreeBSD$
#

PORTNAME=	CSS-Inliner
PORTVERSION=	2544
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
#MASTER_SITE_SUBDIR=	../by-authors/id/K/KA/KAMELKEV
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	Library for converting CSS <style> blocks to inline styles

RUN_DEPENDS+=	p5-CSS-Tiny>=1.15:${PORTSDIR}/textproc/p5-CSS-Tiny \
		p5-HTML-Query>=0.02:${PORTSDIR}/www/p5-HTML-Query \
		p5-HTML-Tree>=3.23:${PORTSDIR}/www/p5-HTML-Tree

PERL_CONFIGURE=	yes

MAN3=		CSS::Inliner.3
PLIST_FILES=	%%SITE_PERL%%/CSS/Inliner.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/CSS/Inliner/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/CSS/Inliner

.include <bsd.port.mk>
