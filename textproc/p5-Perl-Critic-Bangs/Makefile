# Created by: Vany <ivan@serezhkin.com>
# $FreeBSD$

PORTNAME=	Perl-Critic-Bangs
PORTVERSION=	1.08
PORTREVISION=	1
CATEGORIES=	textproc devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ivan@serezhkin.com
COMMENT=	Collection of handy Perl::Critic policies

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Perl-Critic>=0:textproc/p5-Perl-Critic
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Perl-Critic>=0:textproc/p5-Test-Perl-Critic \
		p5-Perl-Critic-Deprecated>=0:devel/p5-Perl-Critic-Deprecated

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
