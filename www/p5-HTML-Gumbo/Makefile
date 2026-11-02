PORTNAME=	HTML-Gumbo
PORTVERSION=	0.20
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BPS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTML5 parser based on gumbo C library
WWW=		https://metacpan.org/pod/HTML::Gumbo

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Alien-Build>0:devel/p5-Alien-Build \
		p5-Alien-LibGumbo>0:devel/p5-Alien-LibGumbo \
		p5-PkgConfig>0:devel/p5-PkgConfig
RUN_DEPENDS=	p5-Alien-LibGumbo>0:devel/p5-Alien-LibGumbo

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
