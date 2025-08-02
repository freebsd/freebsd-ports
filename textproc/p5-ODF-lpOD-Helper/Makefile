PORTNAME=	ODF-lpOD_Helper
PORTVERSION=	6.015
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Fix and enhance ODF::lpOD
WWW=		https://metacpan.org/release/ODF-lpOD_Helper

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-ODF-lpOD>=0:textproc/p5-ODF-lpOD
TEST_DEPENDS=	p5-Data-Dumper-Interp>=0:devel/p5-Data-Dumper-Interp \
		p5-Import-Into>=0:devel/p5-Import-Into

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
