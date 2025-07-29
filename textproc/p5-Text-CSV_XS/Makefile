PORTNAME=	Text-CSV_XS
DISTVERSION=	1.61
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HMBRAND
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Comma-separated values manipulation routines
WWW=		https://metacpan.org/release/Text-CSV_XS

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/README

TEST_DEPENDS=	p5-Test-Pod-Coverage>=1.10:devel/p5-Test-Pod-Coverage \
		p5-Test-Pod>=1.51:devel/p5-Test-Pod

USES=		perl5 tar:tgz
USE_PERL5=	configure

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Text/CSV_XS/CSV_XS.so

.include <bsd.port.mk>
