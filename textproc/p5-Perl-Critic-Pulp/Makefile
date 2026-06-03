PORTNAME=	Perl-Critic-Pulp
PORTVERSION=	100
CATEGORIES=	textproc devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Collection of add-on policies for Perl::Critic
WWW=		https://metacpan.org/release/Perl-Critic-Pulp

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Perl-Critic>=0:textproc/p5-Perl-Critic \
		p5-Perl-MinimumVersion>=0:textproc/p5-Perl-MinimumVersion \
		p5-Pod-MinimumVersion>=0:textproc/p5-Pod-MinimumVersion
TEST_DEPENDS=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
