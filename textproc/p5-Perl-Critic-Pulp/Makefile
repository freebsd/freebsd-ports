# $FreeBSD$

PORTNAME=	Perl-Critic-Pulp
PORTVERSION=	92
CATEGORIES=	textproc devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	some add-on perlcritic policies

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Perl-Critic>=0:textproc/p5-Perl-Critic \
		p5-Perl-MinimumVersion>=0:textproc/p5-Perl-MinimumVersion \
		p5-Pod-MinimumVersion>=0:textproc/p5-Pod-MinimumVersion
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
