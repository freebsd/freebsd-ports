# $FreeBSD$

PORTNAME=	Perl-Critic-Moose
PORTVERSION=	1.05
CATEGORIES=	textproc devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Policies for Perl::Critic concerned with using Moose

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-namespace-autoclean>=0:devel/p5-namespace-autoclean \
		p5-Perl-Critic>=0:textproc/p5-Perl-Critic

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
