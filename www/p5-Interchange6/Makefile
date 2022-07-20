PORTNAME=	Interchange6
PORTVERSION=	0.120
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HORNBURG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Open Source Shop Machine

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Interchange6-Schema>=0:databases/p5-Interchange6-Schema \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moo>=2.000000:devel/p5-Moo \
		p5-Type-Tiny>=0:devel/p5-Type-Tiny \
		p5-Safe-Isa>=0:devel/p5-Safe-Isa \
		p5-MooX-HandlesVia>=0:devel/p5-MooX-HandlesVia \
		p5-MooseX-CoverableModifiers>=0:devel/p5-MooseX-CoverableModifiers \
		p5-aliased>=0:devel/p5-aliased

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
