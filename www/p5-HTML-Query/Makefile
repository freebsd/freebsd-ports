# New ports collection makefile for:	p5-HTML-Query
# Date created:				Wed Oct 24 10:09:12 EDT 2007
# Whom:					Vivek Khera <vivek@khera.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-Query
PORTVERSION=	0.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	JQuery-like selection queries for HTML::Element

RUN_DEPENDS+=	p5-Badger>0.0:${PORTSDIR}/devel/p5-Badger \
		p5-HTML-Tree>=3.23:${PORTSDIR}/www/p5-HTML-Tree

PERL_CONFIGURE=	yes

MAN3=		HTML::Query.3
PLIST_FILES=	%%SITE_PERL%%/HTML/Query.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/HTML-Query/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/HTML-Query

.include <bsd.port.mk>
