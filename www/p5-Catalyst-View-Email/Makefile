# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	Catalyst-View-Email
PORTVERSION=	0.35
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Catalyst View for Email

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Authen-SASL>=2.13:${PORTSDIR}/security/p5-Authen-SASL \
		p5-Catalyst-Runtime>=5.70000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Email-MIME>=1.859:${PORTSDIR}/mail/p5-Email-MIME \
		p5-Email-Sender>=0.100110:${PORTSDIR}/mail/p5-Email-Sender \
		p5-Module-Runtime>=0.014:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Moose>=0.93:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Catalyst-View-Mason>=0.18:${PORTSDIR}/www/p5-Catalyst-View-Mason \
		p5-Catalyst-View-TT>=0.31:${PORTSDIR}/www/p5-Catalyst-View-TT \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
