# Created by: Bill "I hate Perl" Fumerola
# $FreeBSD$

PORTNAME=	Text-Template
PORTVERSION=	1.46
CATEGORIES=	textproc perl5
MASTER_SITES=	http://perl.plover.com/Template/ \
		CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Expand template text with embedded Perl

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

.include <bsd.port.mk>
