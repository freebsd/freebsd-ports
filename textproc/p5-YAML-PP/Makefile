PORTNAME=	YAML-PP
DISTVERSIONPREFIX=	v
DISTVERSION=	0.39.0
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	YAML which aims to parse YAML 1.2 & conform to the spec
WWW=		https://metacpan.org/dist/YAML-PP

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Warn>=0.37:devel/p5-Test-Warn \
		p5-Tie-IxHash>=0:devel/p5-Tie-IxHash

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
