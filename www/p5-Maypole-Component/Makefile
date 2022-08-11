PORTNAME=	Maypole-Component
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SIMON
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Run Maypole sub-requests as components

USES=		perl5
USE_PERL5=	configure patch

post-patch:
	@${PERL} -pi -e 's/use 5.006/use 5.005/' ${WRKSRC}/Makefile.PL
	@${PERL} -pi -e 's/^our (\S+)/use vars qw($$1); $$1/' ${WRKSRC}/Component.pm

.include <bsd.port.mk>
