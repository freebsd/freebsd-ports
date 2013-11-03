# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CatalystX-REPL
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FLORA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read-Eval-Print-Loop for debugging your Catalyst application

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Carp-REPL>=0:${PORTSDIR}/devel/p5-Carp-REPL \
		p5-Catalyst-Runtime>0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS=	p5-Carp-REPL>=0:${PORTSDIR}/devel/p5-Carp-REPL \
		p5-Catalyst-Runtime>0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
TEST_DEPENDS=	p5-Test-Expect>=0:${PORTSDIR}/devel/p5-Test-Expect

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
