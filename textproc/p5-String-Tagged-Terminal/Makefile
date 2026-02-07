PORTNAME=	String-Tagged-Terminal
PORTVERSION=	0.08
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Format terminal output using String::Tagged
WWW=		https://metacpan.org/release/String-Tagged-Terminal

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Convert-Color>=0:graphics/p5-Convert-Color \
		p5-Convert-Color-XTerm>=0:graphics/p5-Convert-Color-XTerm \
		p5-String-Tagged>=0:textproc/p5-String-Tagged
TEST_DEPENDS=	p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
