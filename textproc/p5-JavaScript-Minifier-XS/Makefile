PORTNAME=	JavaScript-Minifier-XS
PORTVERSION=	0.15
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XS based JavaScript minifier

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-DiagINC>=0.002:devel/p5-Test-DiagINC

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/JavaScript/Minifier/XS/XS.so

.include <bsd.port.mk>
