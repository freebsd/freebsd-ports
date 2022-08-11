PORTNAME=	LaTeX-Table
PORTVERSION=	1.0.6
DISTVERSIONPREFIX=	v
PORTREVISION=	6
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for the automatic generation of LaTeX tables

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-LaTeX-Driver>=0:textproc/p5-LaTeX-Driver \
		p5-LaTeX-Encode>=0:textproc/p5-LaTeX-Encode \
		p5-Module-Pluggable>=0:devel/p5-Module-Pluggable \
		p5-Moose>=0.76:devel/p5-Moose \
		p5-Moose-Policy>=0:devel/p5-Moose-Policy \
		p5-MooseX-FollowPBP>=0.03:devel/p5-MooseX-FollowPBP \
		p5-Number-Format>=0:textproc/p5-Number-Format \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-Text-CSV>=0:textproc/p5-Text-CSV
TEST_DEPENDS=	p5-Test-NoWarnings>=0.084:devel/p5-Test-NoWarnings

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
