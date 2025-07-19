PORTNAME=	Catalyst-Plugin-Session
PORTVERSION=	0.44
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generic Catalyst Session plugin
WWW=		https://metacpan.org/release/Catalyst-Plugin-Session

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Catalyst-Runtime>=5.71001:www/p5-Catalyst-Runtime \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-Moose>=0.76,1:devel/p5-Moose \
		p5-MooseX-Emulate-Class-Accessor-Fast>=0.00801:devel/p5-MooseX-Emulate-Class-Accessor-Fast \
		p5-MRO-Compat>=0:devel/p5-MRO-Compat \
		p5-namespace-clean>=0.10:devel/p5-namespace-clean \
		p5-Object-Signature>=0:devel/p5-Object-Signature
TEST_DEPENDS=	p5-Crypt-SysRandom>=0:security/p5-Crypt-SysRandom \
		p5-Plack>=0:www/p5-Plack \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Needs>=0:devel/p5-Test-Needs

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^is_upgrading_needed/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
