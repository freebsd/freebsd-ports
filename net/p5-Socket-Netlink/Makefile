PORTNAME=	Socket-Netlink
PORTVERSION=	0.05
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to PF_NETLINK socket family
WWW=		https://metacpan.org/dist/Socket-Netlink

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-ExtUtils-CChecker>=0.02:devel/p5-ExtUtils-CChecker \
		p5-ExtUtils-H2PM>=0.07:devel/p5-ExtUtils-H2PM \
		p5-Module-Build>=0:devel/p5-Module-Build
TEST_DEPENDS=	p5-Test-HexString>=0:devel/p5-Test-HexString \
		p5-Test-Pod>=1.00:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e '/include.*netlink/ { s,linux,netlink,; \
		s,genetlink,netlink_generic,; }' ${WRKSRC}/Build.PL \
		${WRKSRC}/lib/Socket/Netlink/Generic_const.pm.PL \
		${WRKSRC}/lib/Socket/Netlink.xs

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Socket/Netlink/Netlink.so

.include <bsd.port.mk>
