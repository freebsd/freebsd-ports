PORTNAME=	JE
PORTVERSION=	0.066
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SPROUT
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Pure-Perl ECMAScript (JavaScript) Engine

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-TimeDate>0:devel/p5-TimeDate \
		p5-Tie-RefHash-Weak>0:devel/p5-Tie-RefHash-Weak

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

# Wrong versioning upstream
PORTSCOUT=	skipv:0.54

.include <bsd.port.mk>
