PORTNAME=	CPAN-Audit
PORTVERSION=	20240826.002
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Audit CPAN distributions for known vulnerabilities
WWW=		https://metacpan.org/dist/CPAN-Audit

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CPAN-DistnameInfo>=0:devel/p5-CPAN-DistnameInfo \
		p5-IO-Interactive>=0,1:devel/p5-IO-Interactive \
		p5-JSON>=0:converters/p5-JSON \
		p5-Module-CPANfile>=0:devel/p5-Module-CPANfile \
		p5-Module-Extract-VERSION>=0:devel/p5-Module-Extract-VERSION
TEST_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
