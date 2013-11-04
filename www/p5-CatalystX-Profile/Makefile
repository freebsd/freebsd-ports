# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CatalystX-Profile
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CYCLES
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Profile your Catalyst application with Devel::NYTProf

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.80020:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-CatalystX-InjectComponent>=0.024:${PORTSDIR}/www/p5-CatalystX-InjectComponent \
		devel/p5-Devel-NYTProf>=3.01:${PORTSDIR}/devel/p5-Devel-NYTProf \
		p5-Moose>=0.93:${PORTSDIR}/devel/p5-Moose \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS=	p5-Catalyst-Runtime>=5.80020:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-CatalystX-InjectComponent>=0.024:${PORTSDIR}/www/p5-CatalystX-InjectComponent \
		devel/p5-Devel-NYTProf>=3.01:${PORTSDIR}/devel/p5-Devel-NYTProf \
		p5-Moose>=0.93:${PORTSDIR}/devel/p5-Moose \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
