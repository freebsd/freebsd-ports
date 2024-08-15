PORTNAME=	URI-Fast
PORTVERSION=	0.55
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast(er) URI parser
WWW=		https://metacpan.org/release/URI-Fast

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-URI-Encode-XS>=0.11:net/p5-URI-Encode-XS \
		p5-URI>=0:net/p5-URI \
		p5-Unicode-LineBreak>=0:textproc/p5-Unicode-LineBreak
TEST_DEPENDS=	p5-Pod-Parser>=0:textproc/p5-Pod-Parser \
		p5-Test-LeakTrace>=0.16:devel/p5-Test-LeakTrace \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/URI/Fast/Fast.so

.include <bsd.port.mk>
