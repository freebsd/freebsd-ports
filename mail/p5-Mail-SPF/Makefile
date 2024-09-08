PORTNAME=	Mail-SPF
PORTVERSION=	3.20240827
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Object-oriented implementation of Sender Policy Framework
WWW=		https://metacpan.org/release/Mail-SPF \
		http://www.open-spf.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Error>=0:lang/p5-Error \
		p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-NetAddr-IP>=0:net-mgmt/p5-NetAddr-IP \
		p5-URI>=1.13:net/p5-URI
TEST_DEPENDS=	p5-Net-DNS-Resolver-Programmable>=0:dns/p5-Net-DNS-Resolver-Programmable

USES=		perl5 shebangfix
USE_PERL5=	configure

NO_ARCH=	yes

SHEBANG_FILES=	bin/spfd bin/spfquery

post-patch:
	@${MV} ${WRKSRC}/bin/spfd ${WRKSRC}/bin/spfd.pl
	@${MV} ${WRKSRC}/bin/spfquery ${WRKSRC}/bin/spfquery.pl

.include <bsd.port.mk>
