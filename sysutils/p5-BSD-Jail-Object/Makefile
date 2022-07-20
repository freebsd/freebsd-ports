PORTNAME=	BSD-Jail-Object
PORTVERSION=	0.02
PORTREVISION=	4
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mahlon@martini.nu
COMMENT=	Object oriented perl interface to jail(2)

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Inline>=0.44:devel/p5-Inline \
		p5-Inline-C>=0.44:devel/p5-Inline-C

MAKE_JOBS_UNSAFE=	yes

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
