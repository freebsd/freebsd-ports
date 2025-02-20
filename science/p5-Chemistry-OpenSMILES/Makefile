PORTNAME=	Chemistry-OpenSMILES
PORTVERSION=	0.11.6
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	OpenSMILES format reader and writer
WWW=		https://metacpan.org/release/Chemistry-OpenSMILES

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Module-Build-Parse-Yapp>=0:devel/p5-Module-Build-Parse-Yapp
RUN_DEPENDS=	p5-Graph>=0:math/p5-Graph \
		p5-Parse-Yapp>=0:devel/p5-Parse-Yapp
TEST_DEPENDS=	p5-Algorithm-Combinatorics>=0:math/p5-Algorithm-Combinatorics

USES=		perl5

USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
