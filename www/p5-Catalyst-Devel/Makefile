# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Devel
PORTVERSION=	1.40
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Catalyst Development Tools

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-Module-Install>=1.02:devel/p5-Module-Install
RUN_DEPENDS=	p5-Catalyst-Action-RenderView>=0.10:www/p5-Catalyst-Action-RenderView \
		p5-Catalyst-Plugin-ConfigLoader>=0.30:www/p5-Catalyst-Plugin-ConfigLoader \
		p5-Catalyst-Plugin-Static-Simple>=0.28:www/p5-Catalyst-Plugin-Static-Simple \
		p5-Catalyst-Runtime>=5.90001:www/p5-Catalyst-Runtime \
		p5-Config-General>=2.42:devel/p5-Config-General \
		p5-File-ChangeNotify>=0.07:devel/p5-File-ChangeNotify \
		p5-File-Copy-Recursive>=0:devel/p5-File-Copy-Recursive \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Emulate-Class-Accessor-Fast>=0:devel/p5-MooseX-Emulate-Class-Accessor-Fast \
		p5-Path-Class>=0.09:devel/p5-Path-Class \
		p5-Template-Toolkit>=2.14:www/p5-Template-Toolkit \
		p5-YAML-Tiny>=0:textproc/p5-YAML-Tiny \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean \
		p5-namespace-clean>=0:devel/p5-namespace-clean
TEST_DEPENDS=	p5-IPC-Run3>=0:devel/p5-IPC-Run3 \
		p5-Test-Fatal>=0.003:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
