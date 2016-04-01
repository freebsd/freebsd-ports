# Created by: Vivek Khera <vivek@khera.org>
# $FreeBSD$

PORTNAME=	HTML-Query
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	JQuery-like selection queries for HTML::Element

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS+=	p5-Badger>=0.03:devel/p5-Badger \
		p5-HTML-Tree>=3.23:www/p5-HTML-Tree

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	%%SITE_PERL%%/HTML/Query.pm \
		%%PERL5_MAN3%%/HTML::Query.3.gz

.include <bsd.port.mk>
