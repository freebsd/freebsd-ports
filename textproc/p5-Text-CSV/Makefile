PORTNAME=	Text-CSV
PORTVERSION=	2.01
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Composition and decomposition of comma-separated values

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	XS

XS_BUILD_DEPENDS=	p5-Text-CSV_XS>=1.46:textproc/p5-Text-CSV_XS
XS_RUN_DEPENDS=		p5-Text-CSV_XS>=1.46:textproc/p5-Text-CSV_XS

.include <bsd.port.mk>
