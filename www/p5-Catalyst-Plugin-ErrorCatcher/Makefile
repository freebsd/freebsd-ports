# Created by: andrey@kostenko.name
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-ErrorCatcher
PORTVERSION=	0.0.8.21
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CHISEL
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Catch application errors and emit them somewhere

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.80000:www/p5-Catalyst-Runtime \
		p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-File-Type>=0:devel/p5-File-Type \
		p5-MIME-Lite>=0:mail/p5-MIME-Lite \
		p5-Module-Pluggable>=0:devel/p5-Module-Pluggable \
		p5-Moose>=0:devel/p5-Moose \
		p5-Path-Class>=0:devel/p5-Path-Class
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Catalyst-Plugin-Authentication>=0.10010:www/p5-Catalyst-Plugin-Authentication \
		p5-Catalyst-Plugin-ConfigLoader>=0.22:www/p5-Catalyst-Plugin-ConfigLoader \
		p5-Catalyst-Plugin-Session-State-Cookie>=0:www/p5-Catalyst-Plugin-Session-State-Cookie \
		p5-Catalyst-Plugin-Session-Store-File>=0:www/p5-Catalyst-Plugin-Session-Store-File \
		p5-Catalyst-Plugin-Session>=0:www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Plugin-StackTrace>=0.10:www/p5-Catalyst-Plugin-StackTrace \
		p5-Config-General>=0:devel/p5-Config-General \
		p5-File-Find-Rule>=0:devel/p5-File-Find-Rule \
		p5-FindBin-libs>=0:devel/p5-FindBin-libs \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-NoTabs>=0:devel/p5-Test-NoTabs \
		p5-Test-UseAllModules>=0:devel/p5-Test-UseAllModules \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
