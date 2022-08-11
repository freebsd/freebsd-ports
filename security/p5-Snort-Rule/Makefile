PORTNAME=	Snort-Rule
PORTVERSION=	1.07
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SAXJAZMAN/Snort
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl5 extension for dynamically building snort rules

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	%%SITE_PERL%%/Snort/Rule.pm \
		%%PERL5_MAN3%%/Snort::Rule.3.gz

.include <bsd.port.mk>
