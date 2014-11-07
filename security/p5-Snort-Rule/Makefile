# Created by: Paul Schmehl <pauls@utdallas.edu>
# $FreeBSD$

PORTNAME=	Snort-Rule
PORTVERSION=	1.07
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SAXJAZMAN/Snort
PKGNAMEPREFIX=	p5-

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Perl5 extension for dynamically building snort rules

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	%%SITE_PERL%%/Snort/Rule.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Snort/Rule/.packlist \
		%%PERL5_MAN3%%/Snort::Rule.3.gz
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Snort/Rule \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Snort \
		%%SITE_PERL%%/Snort

.include <bsd.port.mk>
