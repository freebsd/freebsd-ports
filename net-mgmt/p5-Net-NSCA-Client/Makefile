# $FreeBSD$

PORTNAME=	Net-NSCA-Client
PORTVERSION=	0.009002
PORTREVISION=	1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Perl extension for sending passive service checks to nagios

RUN_DEPENDS=	p5-Const-Fast>=0.013:devel/p5-Const-Fast \
		p5-Convert-Binary-C>=0.76:converters/p5-Convert-Binary-C \
		p5-Data-Rand>=0.0.4:devel/p5-Data-Rand \
		p5-Data-Rand-Obscure>=0.021:devel/p5-Data-Rand-Obscure \
		p5-Data-Validate-Domain>=0.10:dns/p5-Data-Validate-Domain \
		p5-Digest-CRC>=0.18:security/p5-Digest-CRC \
		p5-Moose>=0.89:devel/p5-Moose \
		p5-MooseX-Clone>=0.05:devel/p5-MooseX-Clone \
		p5-MooseX-StrictConstructor>=0.08:devel/p5-MooseX-StrictConstructor \
		p5-MooseX-Types>=0.35:devel/p5-MooseX-Types \
		p5-MooseX-Types-PortNumber>=0.02:devel/p5-MooseX-Types-PortNumber \
		p5-namespace-clean>=0.04:devel/p5-namespace-clean
BUILD_DEPENDS=	p5-Const-Fast>=0.013:devel/p5-Const-Fast \
		p5-Convert-Binary-C>=0.76:converters/p5-Convert-Binary-C \
		p5-Data-Rand>=0.0.4:devel/p5-Data-Rand \
		p5-Data-Rand-Obscure>=0.021:devel/p5-Data-Rand-Obscure \
		p5-Data-Section>=0.101621:devel/p5-Data-Section \
		p5-Data-Validate-Domain>=0.10:dns/p5-Data-Validate-Domain \
		p5-Digest-CRC>=0.18:security/p5-Digest-CRC \
		p5-Moose>=0.89:devel/p5-Moose \
		p5-MooseX-Clone>=0.05:devel/p5-MooseX-Clone \
		p5-MooseX-StrictConstructor>=0.08:devel/p5-MooseX-StrictConstructor \
		p5-MooseX-Types>=0.35:devel/p5-MooseX-Types \
		p5-MooseX-Types-PortNumber>=0.02:devel/p5-MooseX-Types-PortNumber \
		p5-namespace-clean>=0.04:devel/p5-namespace-clean
TEST_DEPENDS=	p5-Test-Class>=0.37:devel/p5-Test-Class \
		p5-Test-Command>=0.08:devel/p5-Test-Command \
		p5-Test-Fatal>=0.010:devel/p5-Test-Fatal \
		p5-Test-Requires>=0.06:devel/p5-Test-Requires \
		p5-Test-TCP>=1.17:devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	modbuild

post-patch:
	@cd ${WRKSRC} && ${RM} -f bin/send_nsca
	@cd ${WRKSRC} && ${RM} -f t/send_nsca.t

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build test

.include <bsd.port.mk>
