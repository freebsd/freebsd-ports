PORTNAME=	Net-Dict
PORTVERSION=	2.22
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple client API for the DICT protocol

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Differences>=0.620:devel/p5-Test-Differences \
		p5-Test-RequiresInternet>=0.05:devel/p5-Test-RequiresInternet

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

post-patch:
	@${CP} ${FILESDIR}/test_host.cfg ${WRKSRC}/t/test_host.cfg

.include <bsd.port.mk>
