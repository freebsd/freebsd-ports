# $FreeBSD$

PORTNAME=		Mojo-IOLoop-ForkCall
PORTVERSION=		0.17
CATEGORIES=		www perl5
MASTER_SITES=		CPAN
MASTER_SITE_SUBDIR=	CPAN:JBERGER
PKGNAMEPREFIX=		p5-

MAINTAINER=		skalmanman@gmail.com
COMMENT=		Mojo::IOLoop::ForkCall

LICENSE=		ART10 GPLv1+
LICENSE_COMB=		dual

RUN_DEPENDS=		p5-Mojolicious>=5.08:www/p5-Mojolicious \
			p5-IO-Pipely>=0.005:devel/p5-IO-Pipely \
			p5-Perl-OSType>=0:devel/p5-Perl-OSType

USES=			perl5
USE_PERL5=		modbuild
PL_BUILD=		Build

.include <bsd.port.mk>
