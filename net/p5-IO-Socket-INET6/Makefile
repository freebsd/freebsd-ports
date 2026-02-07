PORTNAME=	IO-Socket-INET6
DISTVERSION=	2.73
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SHLOMIF
PKGNAMEPREFIX=	p5-

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Perl module with object interface to AF_INET6 domain sockets
WWW=		https://metacpan.org/release/IO-Socket-INET6

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Socket6>=0.12:net/p5-Socket6
TEST_DEPENDS=	p5-Test-Pod-Coverage>=1.04:devel/p5-Test-Pod-Coverage \
		p5-Test-Pod>=1.14:devel/p5-Test-Pod \
		p5-Test-TrailingSpace>=0:devel/p5-Test-TrailingSpace

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
