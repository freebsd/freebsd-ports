# Created by: Vivek Khera <vivek@khera.org>
# $FreeBSD$

PORTNAME=	HTML-Query
PORTVERSION=	0.09
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	JQuery-like selection queries for HTML::Element

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS+=	p5-Badger>=0.03:${PORTSDIR}/devel/p5-Badger \
		p5-HTML-Tree>=3.23:${PORTSDIR}/www/p5-HTML-Tree

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	%%SITE_PERL%%/HTML/Query.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/HTML-Query/.packlist \
		%%PERL5_MAN3%%/HTML::Query.3.gz
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/HTML-Query \
		%%SITE_PERL%%/HTML

.include <bsd.port.mk>
