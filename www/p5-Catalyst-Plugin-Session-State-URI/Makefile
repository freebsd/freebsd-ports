# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Session-State-URI
PORTVERSION=	0.15
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Saves Catalyst Session IDs by rewriting URIs

BUILD_DEPENDS=	p5-Catalyst-Plugin-Session>=0.27:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-HTML-TokeParser-Simple>=0:${PORTSDIR}/www/p5-HTML-TokeParser-Simple \
		p5-MIME-Types>=0:${PORTSDIR}/mail/p5-MIME-Types \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Emulate-Class-Accessor-Fast>=0:${PORTSDIR}/devel/p5-MooseX-Emulate-Class-Accessor-Fast \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-URI-Find>=0:${PORTSDIR}/textproc/p5-URI-Find \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-MockObject>=1.01:${PORTSDIR}/devel/p5-Test-MockObject

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
