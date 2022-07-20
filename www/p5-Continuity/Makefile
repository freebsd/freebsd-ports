PORTNAME=	Continuity
PORTVERSION=	1.6
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AWWAIID
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Stateful Web applications in Perl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Coro>=4.37:devel/p5-Coro \
		p5-Event>=0:devel/p5-Event \
		p5-HTTP-Daemon>=1.36:www/p5-HTTP-Daemon

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
