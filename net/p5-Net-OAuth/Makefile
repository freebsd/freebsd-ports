PORTNAME=	Net-OAuth
PORTVERSION=	0.33
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RRWO
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of the OAuth protocol
WWW=		https://metacpan.org/release/Net-OAuth \
		https://oauth.net/

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>=0.31:devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0.06:devel/p5-Class-Data-Inheritable \
		p5-Crypt-SysRandom>=0.006:security/p5-Crypt-SysRandom \
		p5-URI>=5.15:net/p5-URI \
		p5-libwww>=1:www/p5-libwww
TEST_DEPENDS=	p5-Test-Warn>=0.21:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	RECOMMENDED
RECOMMENDED_DESC=	Recommended dependencies by upstream

RECOMMENDED_BUILD_DEPENDS=	p5-Crypt-OpenSSL-RSA>=0.38:security/p5-Crypt-OpenSSL-RSA \
			p5-Crypt-SysRandom-XS>=0.010:security/p5-Crypt-SysRandom-XS
RECOMMENDED_RUN_DEPENDS=p5-Crypt-OpenSSL-RSA>=0.38:security/p5-Crypt-OpenSSL-RSA \
			p5-Crypt-SysRandom-XS>=0.010:security/p5-Crypt-SysRandom-XS

.include <bsd.port.mk>
