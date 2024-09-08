PORTNAME=	Spreadsheet-ReadSXC
PORTVERSION=	0.39
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CORION
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extract OpenOffice 1.x spreadsheet data
WWW=		https://metacpan.org/release/Spreadsheet-ReadSXC

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Archive-Zip>=1.34:archivers/p5-Archive-Zip \
		p5-Moo>=2:devel/p5-Moo \
		p5-PerlIO-gzip>=0:archivers/p5-PerlIO-gzip \
		p5-PerlX-Maybe>=0:devel/p5-PerlX-Maybe \
		p5-XML-Twig>=3.50:textproc/p5-XML-Twig \
		p5-XML-XPath>=0:textproc/p5-XML-XPath

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
