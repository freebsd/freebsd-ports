# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Devel
PORTVERSION=	1.38
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BOBTFISH
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Catalyst Development Tools

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Action-RenderView>=0.10:${PORTSDIR}/www/p5-Catalyst-Action-RenderView \
		p5-Catalyst-Plugin-ConfigLoader>=0.30:${PORTSDIR}/www/p5-Catalyst-Plugin-ConfigLoader \
		p5-Catalyst-Plugin-Static-Simple>=0.28:${PORTSDIR}/www/p5-Catalyst-Plugin-Static-Simple \
		p5-Catalyst-Runtime>=5.90001:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Config-General>=2.42:${PORTSDIR}/devel/p5-Config-General \
		p5-File-ChangeNotify>=0.07:${PORTSDIR}/devel/p5-File-ChangeNotify \
		p5-File-Copy-Recursive>=0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		p5-File-ShareDir>=0:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Emulate-Class-Accessor-Fast>=0:${PORTSDIR}/devel/p5-MooseX-Emulate-Class-Accessor-Fast \
		p5-Path-Class>=0.09:${PORTSDIR}/devel/p5-Path-Class \
		p5-Template-Toolkit>=2.14:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-YAML-Tiny>=0:${PORTSDIR}/textproc/p5-YAML-Tiny \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
BUILD_DEPENDS+=	p5-Module-Install>=1.02:${PORTSDIR}/devel/p5-Module-Install
TEST_DEPENDS=	p5-IPC-Run3>=0:${PORTSDIR}/devel/p5-IPC-Run3 \
		p5-Test-Fatal>=0.003:${PORTSDIR}/devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
