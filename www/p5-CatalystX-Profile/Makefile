# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CatalystX-Profile
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Profile your Catalyst application with Devel::NYTProf

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Catalyst-Runtime>=5.80020:www/p5-Catalyst-Runtime \
		p5-CatalystX-InjectComponent>=0.024:www/p5-CatalystX-InjectComponent \
		p5-Devel-NYTProf>=3.01:devel/p5-Devel-NYTProf \
		p5-Moose>=0.93:devel/p5-Moose \
		p5-Sub-Identify>=0.04:devel/p5-Sub-Identify \
		p5-namespace-autoclean>=0.09:devel/p5-namespace-autoclean

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
